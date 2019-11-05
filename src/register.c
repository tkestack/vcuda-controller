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
// Created by Thomas Song on 2019-04-15.
//
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#include "include/hijack.h"

static const struct timespec g_cycle = {
    .tv_sec = 0,
    .tv_nsec = TIME_TICK * MILLISEC,
};

// #lizard forgives
void register_to_remote_with_data(const char* bus_id, const char* pod_uid,
                                  const char* container) {
  pid_t register_pid;
  int wstatus = 0, wret = 0;
  pid_t child_pid;
  int pipe_fd[2];
  int ret = -1;

  ret = pipe(pipe_fd);
  if (unlikely(ret)) {
    LOGGER(FATAL, "create pipe failed, error %s", strerror(errno));
  }

  register_pid = fork();
  if (!register_pid) {
    close(pipe_fd[1]);
    while (read(pipe_fd[0], &child_pid, sizeof(pid_t)) == 0) {
      nanosleep(&g_cycle, NULL);
    }

    // child
    if (is_custom_config_path()) {
      ret = execl((RPC_CLIENT_PATH RPC_CLIENT_NAME), RPC_CLIENT_NAME, "--addr",
                  RPC_ADDR, "--bus-id", bus_id, "--pod-uid", pod_uid,
                  "--cont-id", container, (char*)NULL);
    } else {
      ret = execl((RPC_CLIENT_PATH RPC_CLIENT_NAME), RPC_CLIENT_NAME, "--addr",
                  RPC_ADDR, "--bus-id", bus_id, "--pod-uid", pod_uid,
                  "--cont-name", container, (char*)NULL);
    }
    if (unlikely(ret == -1)) {
      LOGGER(FATAL, "can't register to manager, error %s", strerror(errno));
    }

    close(pipe_fd[0]);
    _exit(EXIT_SUCCESS);
  } else {
    close(pipe_fd[0]);

    while (write(pipe_fd[1], &register_pid, sizeof(pid_t)) == 0) {
      nanosleep(&g_cycle, NULL);
    }

    do {
      wret = waitpid(register_pid, &wstatus, WUNTRACED | WCONTINUED);
      if (unlikely(wret == -1)) {
        LOGGER(FATAL, "waitpid failed, error %s", strerror(errno));
      }
    } while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));

    ret = WEXITSTATUS(wstatus);
    if (unlikely(ret)) {
      LOGGER(FATAL, "rpc client exit with %d", ret);
    }

    close(pipe_fd[1]);
  }
}
