/*
 * Tencent is pleased to support the open source community by making TKEStack available.
 *
 * Copyright (C) 2012-2019 Tencent. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of the
 * License at
 *
 * https://opensource.org/licenses/Apache-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OF ANY KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations under the License.
 */

//
// Created by thomas on 5/17/18.
//

#include <fcntl.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#include "include/hijack.h"
#include "include/nvml-helper.h"

extern entry_t nvml_library_entry[];
extern char pid_path[];
extern char driver_version[];

static void load_driver_libraries() {
  void *table = NULL;
  char driver_filename[FILENAME_MAX];
  int i;

  snprintf(driver_filename, FILENAME_MAX - 1, "%s.%s", DRIVER_ML_LIBRARY_PREFIX,
           driver_version);
  driver_filename[FILENAME_MAX - 1] = '\0';

  table = dlopen(driver_filename, RTLD_NOW | RTLD_NODELETE);
  if (unlikely(!table)) {
    LOGGER(FATAL, "can't find library %s", driver_filename);
  }

  for (i = 0; i < NVML_ENTRY_END; i++) {
    nvml_library_entry[i].fn_ptr = dlsym(table, nvml_library_entry[i].name);
    if (unlikely(!nvml_library_entry[i].fn_ptr)) {
      LOGGER(4, "can't find function %s in %s", nvml_library_entry[i].name,
             driver_filename);
    }
  }

  dlclose(table);
}

int main(void) {
  int ret = 0;

  int fd = 0;
  int item = 0;
  int rsize = 0;

  int i = 0, j = 0, k = 0;

  int pids_table[MAX_PIDS];
  int pids_table_size = 0;

  int device_num = 0;
  nvmlDevice_t dev;
  nvmlProcessInfo_t pids_on_device[MAX_PIDS];
  unsigned int size_on_device = MAX_PIDS;

  struct timeval cur;
  size_t microsec;
  nvmlProcessUtilizationSample_t processes_sample[MAX_PIDS];
  int processes_num = MAX_PIDS;

  int sm_util = 0;
  uint64_t memory = 0;
  nvmlProcessInfo_t *process_match = NULL;
  nvmlProcessUtilizationSample_t *sample_match = NULL;

  fd = open(pid_path, O_RDONLY);
  if (unlikely(fd == -1)) {
    LOGGER(5, "can't open %s", pid_path);
    return 0;
  }

  for (item = 0; item < MAX_PIDS; item++) {
    rsize = (int) read(fd, pids_table + item, sizeof(int));
    if (unlikely(rsize != sizeof(int))) {
      break;
    }
  }

  for (i = 0; i < item; i++) {
    LOGGER(5, "pid: %d", pids_table[i]);
  }

  pids_table_size = item;

  LOGGER(5, "read %d items from %s", pids_table_size, pid_path);

  if (unlikely(read_controller_configuration())) {
    LOGGER(5, "can't read controller file");
    return 1;
  }

  load_driver_libraries();

  NVML_ENTRY_CALL(nvml_library_entry, nvmlInit);

  ret = NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCount, &device_num);
  if (unlikely(ret)) {
    LOGGER(ERROR, "Get device number return %d", ret);
    return 1;
  }

  for (i = 0; i < device_num; i++) {
    ret = NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleByIndex, i,
                          &dev);
    if (unlikely(ret)) {
      LOGGER(ERROR, "Get device %d return %d", i, ret);
      continue;
    }

    size_on_device = MAX_PIDS;
    ret = NVML_ENTRY_CALL(nvml_library_entry,
                          nvmlDeviceGetComputeRunningProcesses, dev,
                          &size_on_device, pids_on_device);
    if (unlikely(ret)) {
      LOGGER(ERROR, "Get process gpu memory return %d", ret);
      continue;
    }

    for (j = 0; j < size_on_device; j++) {
      LOGGER(4, "summary: %d used %lld", pids_on_device[j].pid,
             pids_on_device[j].usedGpuMemory);
    }

    processes_num = MAX_PIDS;
    gettimeofday(&cur, NULL);
    microsec = (cur.tv_sec - 1) * 1000UL * 1000UL + cur.tv_usec;
    ret = NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetProcessUtilization,
                          dev, processes_sample, &processes_num, microsec);
    if (unlikely(ret)) {
      LOGGER(ERROR, "Get process utilization return %d", ret);
      continue;
    }

    for (j = 0; j < processes_num; j++) {
      LOGGER(4, "summary: %d util %d", processes_sample[j].pid,
             processes_sample[j].smUtil);
    }

    fprintf(stderr, "Device\tProcess\tUtilization\tMemory\n");
    for (j = 0; j < pids_table_size; j++) {
      process_match = NULL;
      sample_match = NULL;

      for (k = 0; k < size_on_device; k++) {
        if (pids_on_device[k].pid == pids_table[j]) {
          process_match = &pids_on_device[k];
        }
      }

      for (k = 0; k < processes_num; k++) {
        if (processes_sample[k].pid == pids_table[j]) {
          sample_match = &processes_sample[k];
        }
      }

      if (process_match) {
        memory = process_match->usedGpuMemory;
        memory >>= 20;
        if (sample_match) {
          sm_util = sample_match->smUtil;
        } else {
          sm_util = 0;
        }
        fprintf(stderr, "%-6d\txxx\t%-11d\t%-6" PRIu64 " MB\n", i, sm_util,
                memory);
      }
    }
  }

  NVML_ENTRY_CALL(nvml_library_entry, nvmlShutdown);
  close(fd);
}
