/*
 * Tencent is pleased to support the open source community by making TKEStack
 * available.
 *
 * Copyright (C) 2012-2019 Tencent. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * https://opensource.org/licenses/Apache-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OF ANY KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations under the License.
 */

#ifndef HIJACK_NVML_HELPER_H
#define HIJACK_NVML_HELPER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <dlfcn.h>

#include "hijack.h"
#include "nvml-subset.h"

/**
 * NVML management library prefix
 */
#define DRIVER_ML_LIBRARY_PREFIX "libnvidia-ml.so"

#define NVML_ENTRY_ENUM(x) ENTRY_##x

#define NVML_FIND_ENTRY(table, sym) ({ (table)[NVML_ENTRY_ENUM(sym)].fn_ptr; })

#define NVML_ENTRY_CALL(table, sym, ...)                                       \
  ({                                                                           \
    LOGGER(5, "Hijacking %s\n", #sym);                                         \
    driver_sym_t _entry = NVML_FIND_ENTRY(table, sym);                         \
    _entry(__VA_ARGS__);                                                       \
  })

typedef nvmlReturn_t (*driver_sym_t)();

/**
 * NVML management library enumerator entry
 */
typedef enum {
  /** nvmlInit */
  NVML_ENTRY_ENUM(nvmlInit),
  /** nvmlShutdown */
  NVML_ENTRY_ENUM(nvmlShutdown),
  /** nvmlErrorString */
  NVML_ENTRY_ENUM(nvmlErrorString),
  /** nvmlDeviceGetHandleByIndex */
  NVML_ENTRY_ENUM(nvmlDeviceGetHandleByIndex),
  /** nvmlDeviceGetComputeRunningProcesses */
  NVML_ENTRY_ENUM(nvmlDeviceGetComputeRunningProcesses),
  /** nvmlDeviceGetPciInfo */
  NVML_ENTRY_ENUM(nvmlDeviceGetPciInfo),
  /** nvmlDeviceGetProcessUtilization */
  NVML_ENTRY_ENUM(nvmlDeviceGetProcessUtilization),
  /** nvmlDeviceGetCount */
  NVML_ENTRY_ENUM(nvmlDeviceGetCount),
  /** nvmlDeviceClearAccountingPids */
  NVML_ENTRY_ENUM(nvmlDeviceClearAccountingPids),
  /** nvmlDeviceClearCpuAffinity */
  NVML_ENTRY_ENUM(nvmlDeviceClearCpuAffinity),
  /** nvmlDeviceClearEccErrorCounts */
  NVML_ENTRY_ENUM(nvmlDeviceClearEccErrorCounts),
  /** nvmlDeviceDiscoverGpus */
  NVML_ENTRY_ENUM(nvmlDeviceDiscoverGpus),
  /** nvmlDeviceFreezeNvLinkUtilizationCounter */
  NVML_ENTRY_ENUM(nvmlDeviceFreezeNvLinkUtilizationCounter),
  /** nvmlDeviceGetAccountingBufferSize */
  NVML_ENTRY_ENUM(nvmlDeviceGetAccountingBufferSize),
  /** nvmlDeviceGetAccountingMode */
  NVML_ENTRY_ENUM(nvmlDeviceGetAccountingMode),
  /** nvmlDeviceGetAccountingPids */
  NVML_ENTRY_ENUM(nvmlDeviceGetAccountingPids),
  /** nvmlDeviceGetAccountingStats */
  NVML_ENTRY_ENUM(nvmlDeviceGetAccountingStats),
  /** nvmlDeviceGetActiveVgpus */
  NVML_ENTRY_ENUM(nvmlDeviceGetActiveVgpus),
  /** nvmlDeviceGetAPIRestriction */
  NVML_ENTRY_ENUM(nvmlDeviceGetAPIRestriction),
  /** nvmlDeviceGetApplicationsClock */
  NVML_ENTRY_ENUM(nvmlDeviceGetApplicationsClock),
  /** nvmlDeviceGetAutoBoostedClocksEnabled */
  NVML_ENTRY_ENUM(nvmlDeviceGetAutoBoostedClocksEnabled),
  /** nvmlDeviceGetBAR1MemoryInfo */
  NVML_ENTRY_ENUM(nvmlDeviceGetBAR1MemoryInfo),
  /** nvmlDeviceGetBoardId */
  NVML_ENTRY_ENUM(nvmlDeviceGetBoardId),
  /** nvmlDeviceGetBoardPartNumber */
  NVML_ENTRY_ENUM(nvmlDeviceGetBoardPartNumber),
  /** nvmlDeviceGetBrand */
  NVML_ENTRY_ENUM(nvmlDeviceGetBrand),
  /** nvmlDeviceGetBridgeChipInfo */
  NVML_ENTRY_ENUM(nvmlDeviceGetBridgeChipInfo),
  /** nvmlDeviceGetClock */
  NVML_ENTRY_ENUM(nvmlDeviceGetClock),
  /** nvmlDeviceGetClockInfo */
  NVML_ENTRY_ENUM(nvmlDeviceGetClockInfo),
  /** nvmlDeviceGetComputeMode */
  NVML_ENTRY_ENUM(nvmlDeviceGetComputeMode),
  /** nvmlDeviceGetCount_v2 */
  NVML_ENTRY_ENUM(nvmlDeviceGetCount_v2),
  /** nvmlDeviceGetCpuAffinity */
  NVML_ENTRY_ENUM(nvmlDeviceGetCpuAffinity),
  /** nvmlDeviceGetCreatableVgpus */
  NVML_ENTRY_ENUM(nvmlDeviceGetCreatableVgpus),
  /** nvmlDeviceGetCudaComputeCapability */
  NVML_ENTRY_ENUM(nvmlDeviceGetCudaComputeCapability),
  /** nvmlDeviceGetCurrentClocksThrottleReasons */
  NVML_ENTRY_ENUM(nvmlDeviceGetCurrentClocksThrottleReasons),
  /** nvmlDeviceGetCurrPcieLinkGeneration */
  NVML_ENTRY_ENUM(nvmlDeviceGetCurrPcieLinkGeneration),
  /** nvmlDeviceGetCurrPcieLinkWidth */
  NVML_ENTRY_ENUM(nvmlDeviceGetCurrPcieLinkWidth),
  /** nvmlDeviceGetDecoderUtilization */
  NVML_ENTRY_ENUM(nvmlDeviceGetDecoderUtilization),
  /** nvmlDeviceGetDefaultApplicationsClock */
  NVML_ENTRY_ENUM(nvmlDeviceGetDefaultApplicationsClock),
  /** nvmlDeviceGetDetailedEccErrors */
  NVML_ENTRY_ENUM(nvmlDeviceGetDetailedEccErrors),
  /** nvmlDeviceGetDisplayActive */
  NVML_ENTRY_ENUM(nvmlDeviceGetDisplayActive),
  /** nvmlDeviceGetDisplayMode */
  NVML_ENTRY_ENUM(nvmlDeviceGetDisplayMode),
  /** nvmlDeviceGetDriverModel */
  NVML_ENTRY_ENUM(nvmlDeviceGetDriverModel),
  /** nvmlDeviceGetEccMode */
  NVML_ENTRY_ENUM(nvmlDeviceGetEccMode),
  /** nvmlDeviceGetEncoderCapacity */
  NVML_ENTRY_ENUM(nvmlDeviceGetEncoderCapacity),
  /** nvmlDeviceGetEncoderSessions */
  NVML_ENTRY_ENUM(nvmlDeviceGetEncoderSessions),
  /** nvmlDeviceGetEncoderStats */
  NVML_ENTRY_ENUM(nvmlDeviceGetEncoderStats),
  /** nvmlDeviceGetEncoderUtilization */
  NVML_ENTRY_ENUM(nvmlDeviceGetEncoderUtilization),
  /** nvmlDeviceGetEnforcedPowerLimit */
  NVML_ENTRY_ENUM(nvmlDeviceGetEnforcedPowerLimit),
  /** nvmlDeviceGetFanSpeed */
  NVML_ENTRY_ENUM(nvmlDeviceGetFanSpeed),
  /** nvmlDeviceGetFanSpeed_v2 */
  NVML_ENTRY_ENUM(nvmlDeviceGetFanSpeed_v2),
  /** nvmlDeviceGetFieldValues */
  NVML_ENTRY_ENUM(nvmlDeviceGetFieldValues),
  /** nvmlDeviceGetGpuOperationMode */
  NVML_ENTRY_ENUM(nvmlDeviceGetGpuOperationMode),
  /** nvmlDeviceGetGraphicsRunningProcesses */
  NVML_ENTRY_ENUM(nvmlDeviceGetGraphicsRunningProcesses),
  /** nvmlDeviceGetGridLicensableFeatures */
  NVML_ENTRY_ENUM(nvmlDeviceGetGridLicensableFeatures),
  /** nvmlDeviceGetHandleByIndex_v2 */
  NVML_ENTRY_ENUM(nvmlDeviceGetHandleByIndex_v2),
  /** nvmlDeviceGetHandleByPciBusId */
  NVML_ENTRY_ENUM(nvmlDeviceGetHandleByPciBusId),
  /** nvmlDeviceGetHandleByPciBusId_v2 */
  NVML_ENTRY_ENUM(nvmlDeviceGetHandleByPciBusId_v2),
  /** nvmlDeviceGetHandleBySerial */
  NVML_ENTRY_ENUM(nvmlDeviceGetHandleBySerial),
  /** nvmlDeviceGetHandleByUUID */
  NVML_ENTRY_ENUM(nvmlDeviceGetHandleByUUID),
  /** nvmlDeviceGetIndex */
  NVML_ENTRY_ENUM(nvmlDeviceGetIndex),
  /** nvmlDeviceGetInforomConfigurationChecksum */
  NVML_ENTRY_ENUM(nvmlDeviceGetInforomConfigurationChecksum),
  /** nvmlDeviceGetInforomImageVersion */
  NVML_ENTRY_ENUM(nvmlDeviceGetInforomImageVersion),
  /** nvmlDeviceGetInforomVersion */
  NVML_ENTRY_ENUM(nvmlDeviceGetInforomVersion),
  /** nvmlDeviceGetMaxClockInfo */
  NVML_ENTRY_ENUM(nvmlDeviceGetMaxClockInfo),
  /** nvmlDeviceGetMaxCustomerBoostClock */
  NVML_ENTRY_ENUM(nvmlDeviceGetMaxCustomerBoostClock),
  /** nvmlDeviceGetMaxPcieLinkGeneration */
  NVML_ENTRY_ENUM(nvmlDeviceGetMaxPcieLinkGeneration),
  /** nvmlDeviceGetMaxPcieLinkWidth */
  NVML_ENTRY_ENUM(nvmlDeviceGetMaxPcieLinkWidth),
  /** nvmlDeviceGetMemoryErrorCounter */
  NVML_ENTRY_ENUM(nvmlDeviceGetMemoryErrorCounter),
  /** nvmlDeviceGetMemoryInfo */
  NVML_ENTRY_ENUM(nvmlDeviceGetMemoryInfo),
  /** nvmlDeviceGetMinorNumber */
  NVML_ENTRY_ENUM(nvmlDeviceGetMinorNumber),
  /** nvmlDeviceGetMPSComputeRunningProcesses */
  NVML_ENTRY_ENUM(nvmlDeviceGetMPSComputeRunningProcesses),
  /** nvmlDeviceGetMultiGpuBoard */
  NVML_ENTRY_ENUM(nvmlDeviceGetMultiGpuBoard),
  /** nvmlDeviceGetName */
  NVML_ENTRY_ENUM(nvmlDeviceGetName),
  /** nvmlDeviceGetNvLinkCapability */
  NVML_ENTRY_ENUM(nvmlDeviceGetNvLinkCapability),
  /** nvmlDeviceGetNvLinkErrorCounter */
  NVML_ENTRY_ENUM(nvmlDeviceGetNvLinkErrorCounter),
  /** nvmlDeviceGetNvLinkRemotePciInfo */
  NVML_ENTRY_ENUM(nvmlDeviceGetNvLinkRemotePciInfo),
  /** nvmlDeviceGetNvLinkRemotePciInfo_v2 */
  NVML_ENTRY_ENUM(nvmlDeviceGetNvLinkRemotePciInfo_v2),
  /** nvmlDeviceGetNvLinkState */
  NVML_ENTRY_ENUM(nvmlDeviceGetNvLinkState),
  /** nvmlDeviceGetNvLinkUtilizationControl */
  NVML_ENTRY_ENUM(nvmlDeviceGetNvLinkUtilizationControl),
  /** nvmlDeviceGetNvLinkUtilizationCounter */
  NVML_ENTRY_ENUM(nvmlDeviceGetNvLinkUtilizationCounter),
  /** nvmlDeviceGetNvLinkVersion */
  NVML_ENTRY_ENUM(nvmlDeviceGetNvLinkVersion),
  /** nvmlDeviceGetP2PStatus */
  NVML_ENTRY_ENUM(nvmlDeviceGetP2PStatus),
  /** nvmlDeviceGetPcieReplayCounter */
  NVML_ENTRY_ENUM(nvmlDeviceGetPcieReplayCounter),
  /** nvmlDeviceGetPcieThroughput */
  NVML_ENTRY_ENUM(nvmlDeviceGetPcieThroughput),
  /** nvmlDeviceGetPciInfo_v2 */
  NVML_ENTRY_ENUM(nvmlDeviceGetPciInfo_v2),
  /** nvmlDeviceGetPciInfo_v3 */
  NVML_ENTRY_ENUM(nvmlDeviceGetPciInfo_v3),
  /** nvmlDeviceGetPerformanceState */
  NVML_ENTRY_ENUM(nvmlDeviceGetPerformanceState),
  /** nvmlDeviceGetPersistenceMode */
  NVML_ENTRY_ENUM(nvmlDeviceGetPersistenceMode),
  /** nvmlDeviceGetPowerManagementDefaultLimit */
  NVML_ENTRY_ENUM(nvmlDeviceGetPowerManagementDefaultLimit),
  /** nvmlDeviceGetPowerManagementLimit */
  NVML_ENTRY_ENUM(nvmlDeviceGetPowerManagementLimit),
  /** nvmlDeviceGetPowerManagementLimitConstraints */
  NVML_ENTRY_ENUM(nvmlDeviceGetPowerManagementLimitConstraints),
  /** nvmlDeviceGetPowerManagementMode */
  NVML_ENTRY_ENUM(nvmlDeviceGetPowerManagementMode),
  /** nvmlDeviceGetPowerState */
  NVML_ENTRY_ENUM(nvmlDeviceGetPowerState),
  /** nvmlDeviceGetPowerUsage */
  NVML_ENTRY_ENUM(nvmlDeviceGetPowerUsage),
  /** nvmlDeviceGetRetiredPages */
  NVML_ENTRY_ENUM(nvmlDeviceGetRetiredPages),
  /** nvmlDeviceGetRetiredPagesPendingStatus */
  NVML_ENTRY_ENUM(nvmlDeviceGetRetiredPagesPendingStatus),
  /** nvmlDeviceGetSamples */
  NVML_ENTRY_ENUM(nvmlDeviceGetSamples),
  /** nvmlDeviceGetSerial */
  NVML_ENTRY_ENUM(nvmlDeviceGetSerial),
  /** nvmlDeviceGetSupportedClocksThrottleReasons */
  NVML_ENTRY_ENUM(nvmlDeviceGetSupportedClocksThrottleReasons),
  /** nvmlDeviceGetSupportedEventTypes */
  NVML_ENTRY_ENUM(nvmlDeviceGetSupportedEventTypes),
  /** nvmlDeviceGetSupportedGraphicsClocks */
  NVML_ENTRY_ENUM(nvmlDeviceGetSupportedGraphicsClocks),
  /** nvmlDeviceGetSupportedMemoryClocks */
  NVML_ENTRY_ENUM(nvmlDeviceGetSupportedMemoryClocks),
  /** nvmlDeviceGetSupportedVgpus */
  NVML_ENTRY_ENUM(nvmlDeviceGetSupportedVgpus),
  /** nvmlDeviceGetTemperature */
  NVML_ENTRY_ENUM(nvmlDeviceGetTemperature),
  /** nvmlDeviceGetTemperatureThreshold */
  NVML_ENTRY_ENUM(nvmlDeviceGetTemperatureThreshold),
  /** nvmlDeviceGetTopologyCommonAncestor */
  NVML_ENTRY_ENUM(nvmlDeviceGetTopologyCommonAncestor),
  /** nvmlDeviceGetTopologyNearestGpus */
  NVML_ENTRY_ENUM(nvmlDeviceGetTopologyNearestGpus),
  /** nvmlDeviceGetTotalEccErrors */
  NVML_ENTRY_ENUM(nvmlDeviceGetTotalEccErrors),
  /** nvmlDeviceGetTotalEnergyConsumption */
  NVML_ENTRY_ENUM(nvmlDeviceGetTotalEnergyConsumption),
  /** nvmlDeviceGetUtilizationRates */
  NVML_ENTRY_ENUM(nvmlDeviceGetUtilizationRates),
  /** nvmlDeviceGetUUID */
  NVML_ENTRY_ENUM(nvmlDeviceGetUUID),
  /** nvmlDeviceGetVbiosVersion */
  NVML_ENTRY_ENUM(nvmlDeviceGetVbiosVersion),
  /** nvmlDeviceGetVgpuMetadata */
  NVML_ENTRY_ENUM(nvmlDeviceGetVgpuMetadata),
  /** nvmlDeviceGetVgpuProcessUtilization */
  NVML_ENTRY_ENUM(nvmlDeviceGetVgpuProcessUtilization),
  /** nvmlDeviceGetVgpuUtilization */
  NVML_ENTRY_ENUM(nvmlDeviceGetVgpuUtilization),
  /** nvmlDeviceGetViolationStatus */
  NVML_ENTRY_ENUM(nvmlDeviceGetViolationStatus),
  /** nvmlDeviceGetVirtualizationMode */
  NVML_ENTRY_ENUM(nvmlDeviceGetVirtualizationMode),
  /** nvmlDeviceModifyDrainState */
  NVML_ENTRY_ENUM(nvmlDeviceModifyDrainState),
  /** nvmlDeviceOnSameBoard */
  NVML_ENTRY_ENUM(nvmlDeviceOnSameBoard),
  /** nvmlDeviceQueryDrainState */
  NVML_ENTRY_ENUM(nvmlDeviceQueryDrainState),
  /** nvmlDeviceRegisterEvents */
  NVML_ENTRY_ENUM(nvmlDeviceRegisterEvents),
  /** nvmlDeviceRemoveGpu */
  NVML_ENTRY_ENUM(nvmlDeviceRemoveGpu),
  /** nvmlDeviceRemoveGpu_v2 */
  NVML_ENTRY_ENUM(nvmlDeviceRemoveGpu_v2),
  /** nvmlDeviceResetApplicationsClocks */
  NVML_ENTRY_ENUM(nvmlDeviceResetApplicationsClocks),
  /** nvmlDeviceResetNvLinkErrorCounters */
  NVML_ENTRY_ENUM(nvmlDeviceResetNvLinkErrorCounters),
  /** nvmlDeviceResetNvLinkUtilizationCounter */
  NVML_ENTRY_ENUM(nvmlDeviceResetNvLinkUtilizationCounter),
  /** nvmlDeviceSetAccountingMode */
  NVML_ENTRY_ENUM(nvmlDeviceSetAccountingMode),
  /** nvmlDeviceSetAPIRestriction */
  NVML_ENTRY_ENUM(nvmlDeviceSetAPIRestriction),
  /** nvmlDeviceSetApplicationsClocks */
  NVML_ENTRY_ENUM(nvmlDeviceSetApplicationsClocks),
  /** nvmlDeviceSetAutoBoostedClocksEnabled */
  NVML_ENTRY_ENUM(nvmlDeviceSetAutoBoostedClocksEnabled),
  /** nvmlDeviceSetComputeMode */
  NVML_ENTRY_ENUM(nvmlDeviceSetComputeMode),
  /** nvmlDeviceSetCpuAffinity */
  NVML_ENTRY_ENUM(nvmlDeviceSetCpuAffinity),
  /** nvmlDeviceSetDefaultAutoBoostedClocksEnabled */
  NVML_ENTRY_ENUM(nvmlDeviceSetDefaultAutoBoostedClocksEnabled),
  /** nvmlDeviceSetDriverModel */
  NVML_ENTRY_ENUM(nvmlDeviceSetDriverModel),
  /** nvmlDeviceSetEccMode */
  NVML_ENTRY_ENUM(nvmlDeviceSetEccMode),
  /** nvmlDeviceSetGpuOperationMode */
  NVML_ENTRY_ENUM(nvmlDeviceSetGpuOperationMode),
  /** nvmlDeviceSetNvLinkUtilizationControl */
  NVML_ENTRY_ENUM(nvmlDeviceSetNvLinkUtilizationControl),
  /** nvmlDeviceSetPersistenceMode */
  NVML_ENTRY_ENUM(nvmlDeviceSetPersistenceMode),
  /** nvmlDeviceSetPowerManagementLimit */
  NVML_ENTRY_ENUM(nvmlDeviceSetPowerManagementLimit),
  /** nvmlDeviceSetVirtualizationMode */
  NVML_ENTRY_ENUM(nvmlDeviceSetVirtualizationMode),
  /** nvmlDeviceValidateInforom */
  NVML_ENTRY_ENUM(nvmlDeviceValidateInforom),
  /** nvmlEventSetCreate */
  NVML_ENTRY_ENUM(nvmlEventSetCreate),
  /** nvmlEventSetFree */
  NVML_ENTRY_ENUM(nvmlEventSetFree),
  /** nvmlEventSetWait */
  NVML_ENTRY_ENUM(nvmlEventSetWait),
  /** nvmlGetVgpuCompatibility */
  NVML_ENTRY_ENUM(nvmlGetVgpuCompatibility),
  /** nvmlInit_v2 */
  NVML_ENTRY_ENUM(nvmlInit_v2),
  /** nvmlInitWithFlags */
  NVML_ENTRY_ENUM(nvmlInitWithFlags),
  /** nvmlInternalGetExportTable */
  NVML_ENTRY_ENUM(nvmlInternalGetExportTable),
  /** nvmlSystemGetCudaDriverVersion */
  NVML_ENTRY_ENUM(nvmlSystemGetCudaDriverVersion),
  /** nvmlSystemGetCudaDriverVersion_v2 */
  NVML_ENTRY_ENUM(nvmlSystemGetCudaDriverVersion_v2),
  /** nvmlSystemGetDriverVersion */
  NVML_ENTRY_ENUM(nvmlSystemGetDriverVersion),
  /** nvmlSystemGetHicVersion */
  NVML_ENTRY_ENUM(nvmlSystemGetHicVersion),
  /** nvmlSystemGetNVMLVersion */
  NVML_ENTRY_ENUM(nvmlSystemGetNVMLVersion),
  /** nvmlSystemGetProcessName */
  NVML_ENTRY_ENUM(nvmlSystemGetProcessName),
  /** nvmlSystemGetTopologyGpuSet */
  NVML_ENTRY_ENUM(nvmlSystemGetTopologyGpuSet),
  /** nvmlUnitGetCount */
  NVML_ENTRY_ENUM(nvmlUnitGetCount),
  /** nvmlUnitGetDevices */
  NVML_ENTRY_ENUM(nvmlUnitGetDevices),
  /** nvmlUnitGetFanSpeedInfo */
  NVML_ENTRY_ENUM(nvmlUnitGetFanSpeedInfo),
  /** nvmlUnitGetHandleByIndex */
  NVML_ENTRY_ENUM(nvmlUnitGetHandleByIndex),
  /** nvmlUnitGetLedState */
  NVML_ENTRY_ENUM(nvmlUnitGetLedState),
  /** nvmlUnitGetPsuInfo */
  NVML_ENTRY_ENUM(nvmlUnitGetPsuInfo),
  /** nvmlUnitGetTemperature */
  NVML_ENTRY_ENUM(nvmlUnitGetTemperature),
  /** nvmlUnitGetUnitInfo */
  NVML_ENTRY_ENUM(nvmlUnitGetUnitInfo),
  /** nvmlUnitSetLedState */
  NVML_ENTRY_ENUM(nvmlUnitSetLedState),
  /** nvmlVgpuInstanceGetEncoderCapacity */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetEncoderCapacity),
  /** nvmlVgpuInstanceGetEncoderSessions */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetEncoderSessions),
  /** nvmlVgpuInstanceGetEncoderStats */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetEncoderStats),
  /** nvmlVgpuInstanceGetFbUsage */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetFbUsage),
  /** nvmlVgpuInstanceGetFrameRateLimit */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetFrameRateLimit),
  /** nvmlVgpuInstanceGetLicenseStatus */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetLicenseStatus),
  /** nvmlVgpuInstanceGetMetadata */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetMetadata),
  /** nvmlVgpuInstanceGetType */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetType),
  /** nvmlVgpuInstanceGetUUID */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetUUID),
  /** nvmlVgpuInstanceGetVmDriverVersion */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetVmDriverVersion),
  /** nvmlVgpuInstanceGetVmID */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetVmID),
  /** nvmlVgpuInstanceSetEncoderCapacity */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceSetEncoderCapacity),
  /** nvmlVgpuTypeGetClass */
  NVML_ENTRY_ENUM(nvmlVgpuTypeGetClass),
  /** nvmlVgpuTypeGetDeviceID */
  NVML_ENTRY_ENUM(nvmlVgpuTypeGetDeviceID),
  /** nvmlVgpuTypeGetFramebufferSize */
  NVML_ENTRY_ENUM(nvmlVgpuTypeGetFramebufferSize),
  /** nvmlVgpuTypeGetFrameRateLimit */
  NVML_ENTRY_ENUM(nvmlVgpuTypeGetFrameRateLimit),
  /** nvmlVgpuTypeGetLicense */
  NVML_ENTRY_ENUM(nvmlVgpuTypeGetLicense),
  /** nvmlVgpuTypeGetMaxInstances */
  NVML_ENTRY_ENUM(nvmlVgpuTypeGetMaxInstances),
  /** nvmlVgpuTypeGetName */
  NVML_ENTRY_ENUM(nvmlVgpuTypeGetName),
  /** nvmlVgpuTypeGetNumDisplayHeads */
  NVML_ENTRY_ENUM(nvmlVgpuTypeGetNumDisplayHeads),
  /** nvmlVgpuTypeGetResolution */
  NVML_ENTRY_ENUM(nvmlVgpuTypeGetResolution),
  /** nvmlDeviceGetFBCSessions */
  NVML_ENTRY_ENUM(nvmlDeviceGetFBCSessions),
  /** nvmlDeviceGetFBCStats */
  NVML_ENTRY_ENUM(nvmlDeviceGetFBCStats),
  /** nvmlDeviceGetGridLicensableFeatures_v2 */
  NVML_ENTRY_ENUM(nvmlDeviceGetGridLicensableFeatures_v2),
  /** nvmlDeviceGetRetiredPages_v2 */
  NVML_ENTRY_ENUM(nvmlDeviceGetRetiredPages_v2),
  /** nvmlDeviceResetGpuLockedClocks */
  NVML_ENTRY_ENUM(nvmlDeviceResetGpuLockedClocks),
  /** nvmlDeviceSetGpuLockedClocks */
  NVML_ENTRY_ENUM(nvmlDeviceSetGpuLockedClocks),
  /** nvmlGetBlacklistDeviceCount */
  NVML_ENTRY_ENUM(nvmlGetBlacklistDeviceCount),
  /** nvmlGetBlacklistDeviceInfoByIndex */
  NVML_ENTRY_ENUM(nvmlGetBlacklistDeviceInfoByIndex),
  /** nvmlVgpuInstanceGetAccountingMode */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetAccountingMode),
  /** nvmlVgpuInstanceGetAccountingPids */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetAccountingPids),
  /** nvmlVgpuInstanceGetAccountingStats */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetAccountingStats),
  /** nvmlVgpuInstanceGetFBCSessions */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetFBCSessions),
  /** nvmlVgpuInstanceGetFBCStats */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetFBCStats),
  /** nvmlVgpuTypeGetMaxInstancesPerVm */
  NVML_ENTRY_ENUM(nvmlVgpuTypeGetMaxInstancesPerVm),
  /** nvmlGetVgpuVersion */
  NVML_ENTRY_ENUM(nvmlGetVgpuVersion),
  /** nvmlSetVgpuVersion */
  NVML_ENTRY_ENUM(nvmlSetVgpuVersion),
  /** nvmlDeviceGetGridLicensableFeatures_v3 */
  NVML_ENTRY_ENUM(nvmlDeviceGetGridLicensableFeatures_v3),
  /** nvmlDeviceGetHostVgpuMode */
  NVML_ENTRY_ENUM(nvmlDeviceGetHostVgpuMode),
  /** nvmlDeviceGetPgpuMetadataString */
  NVML_ENTRY_ENUM(nvmlDeviceGetPgpuMetadataString),
  /** nvmlVgpuInstanceGetEccMode */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetEccMode),
  /** nvmlComputeInstanceDestroy */
  NVML_ENTRY_ENUM(nvmlComputeInstanceDestroy),
  /** nvmlComputeInstanceGetInfo */
  NVML_ENTRY_ENUM(nvmlComputeInstanceGetInfo),
  /** nvmlDeviceCreateGpuInstance */
  NVML_ENTRY_ENUM(nvmlDeviceCreateGpuInstance),
  /** nvmlDeviceGetArchitecture */
  NVML_ENTRY_ENUM(nvmlDeviceGetArchitecture),
  /** nvmlDeviceGetAttributes */
  NVML_ENTRY_ENUM(nvmlDeviceGetAttributes),
  /** nvmlDeviceGetAttributes_v2 */
  NVML_ENTRY_ENUM(nvmlDeviceGetAttributes_v2),
  /** nvmlDeviceGetComputeInstanceId */
  NVML_ENTRY_ENUM(nvmlDeviceGetComputeInstanceId),
  /** nvmlDeviceGetCpuAffinityWithinScope */
  NVML_ENTRY_ENUM(nvmlDeviceGetCpuAffinityWithinScope),
  /** nvmlDeviceGetDeviceHandleFromMigDeviceHandle */
  NVML_ENTRY_ENUM(nvmlDeviceGetDeviceHandleFromMigDeviceHandle),
  /** nvmlDeviceGetGpuInstanceById */
  NVML_ENTRY_ENUM(nvmlDeviceGetGpuInstanceById),
  /** nvmlDeviceGetGpuInstanceId */
  NVML_ENTRY_ENUM(nvmlDeviceGetGpuInstanceId),
  /** nvmlDeviceGetGpuInstancePossiblePlacements */
  NVML_ENTRY_ENUM(nvmlDeviceGetGpuInstancePossiblePlacements),
  /** nvmlDeviceGetGpuInstanceProfileInfo */
  NVML_ENTRY_ENUM(nvmlDeviceGetGpuInstanceProfileInfo),
  /** nvmlDeviceGetGpuInstanceRemainingCapacity */
  NVML_ENTRY_ENUM(nvmlDeviceGetGpuInstanceRemainingCapacity),
  /** nvmlDeviceGetGpuInstances */
  NVML_ENTRY_ENUM(nvmlDeviceGetGpuInstances),
  /** nvmlDeviceGetMaxMigDeviceCount */
  NVML_ENTRY_ENUM(nvmlDeviceGetMaxMigDeviceCount),
  /** nvmlDeviceGetMemoryAffinity */
  NVML_ENTRY_ENUM(nvmlDeviceGetMemoryAffinity),
  /** nvmlDeviceGetMigDeviceHandleByIndex */
  NVML_ENTRY_ENUM(nvmlDeviceGetMigDeviceHandleByIndex),
  /** nvmlDeviceGetMigMode */
  NVML_ENTRY_ENUM(nvmlDeviceGetMigMode),
  /** nvmlDeviceGetRemappedRows */
  NVML_ENTRY_ENUM(nvmlDeviceGetRemappedRows),
  /** nvmlDeviceGetRowRemapperHistogram */
  NVML_ENTRY_ENUM(nvmlDeviceGetRowRemapperHistogram),
  /** nvmlDeviceIsMigDeviceHandle */
  NVML_ENTRY_ENUM(nvmlDeviceIsMigDeviceHandle),
  /** nvmlDeviceSetMigMode */
  NVML_ENTRY_ENUM(nvmlDeviceSetMigMode),
  /** nvmlEventSetWait_v2 */
  NVML_ENTRY_ENUM(nvmlEventSetWait_v2),
  /** nvmlGpuInstanceCreateComputeInstance */
  NVML_ENTRY_ENUM(nvmlGpuInstanceCreateComputeInstance),
  /** nvmlGpuInstanceDestroy */
  NVML_ENTRY_ENUM(nvmlGpuInstanceDestroy),
  /** nvmlGpuInstanceGetComputeInstanceById */
  NVML_ENTRY_ENUM(nvmlGpuInstanceGetComputeInstanceById),
  /** nvmlGpuInstanceGetComputeInstanceProfileInfo */
  NVML_ENTRY_ENUM(nvmlGpuInstanceGetComputeInstanceProfileInfo),
  /** nvmlGpuInstanceGetComputeInstanceRemainingCapacity */
  NVML_ENTRY_ENUM(nvmlGpuInstanceGetComputeInstanceRemainingCapacity),
  /** nvmlGpuInstanceGetComputeInstances */
  NVML_ENTRY_ENUM(nvmlGpuInstanceGetComputeInstances),
  /** nvmlGpuInstanceGetInfo */
  NVML_ENTRY_ENUM(nvmlGpuInstanceGetInfo),
  /** nvmlVgpuInstanceClearAccountingPids */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceClearAccountingPids),
  /** nvmlVgpuInstanceGetMdevUUID */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetMdevUUID),
  /** nvmlComputeInstanceGetInfo_v2 */
  NVML_ENTRY_ENUM(nvmlComputeInstanceGetInfo_v2),
  /** nvmlDeviceGetComputeRunningProcesses_v2 */
  NVML_ENTRY_ENUM(nvmlDeviceGetComputeRunningProcesses_v2),
  /** nvmlDeviceGetGraphicsRunningProcesses_v2 */
  NVML_ENTRY_ENUM(nvmlDeviceGetGraphicsRunningProcesses_v2),
  /** nvmlDeviceSetTemperatureThreshold */
  NVML_ENTRY_ENUM(nvmlDeviceSetTemperatureThreshold),
  /** nvmlRetry_NvRmControl */
  NVML_ENTRY_ENUM(nvmlRetry_NvRmControl),
  /** nvmlVgpuInstanceGetGpuInstanceId */
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetGpuInstanceId),
  /** nvmlVgpuTypeGetGpuInstanceProfileId */
  NVML_ENTRY_ENUM(nvmlVgpuTypeGetGpuInstanceProfileId),
  NVML_ENTRY_ENUM(nvmlDeviceCreateGpuInstanceWithPlacement),
  NVML_ENTRY_ENUM(nvmlDeviceGetBusType),
  NVML_ENTRY_ENUM(nvmlDeviceGetClkMonStatus),
  NVML_ENTRY_ENUM(nvmlDeviceGetGpuInstancePossiblePlacements_v2),
  NVML_ENTRY_ENUM(nvmlDeviceGetGridLicensableFeatures_v4),
  NVML_ENTRY_ENUM(nvmlDeviceGetIrqNum),
  NVML_ENTRY_ENUM(nvmlDeviceGetMPSComputeRunningProcesses_v2),
  NVML_ENTRY_ENUM(nvmlDeviceGetNvLinkRemoteDeviceType),
  NVML_ENTRY_ENUM(nvmlDeviceResetMemoryLockedClocks),
  NVML_ENTRY_ENUM(nvmlDeviceSetMemoryLockedClocks),
  NVML_ENTRY_ENUM(nvmlGetExcludedDeviceCount),
  NVML_ENTRY_ENUM(nvmlGetExcludedDeviceInfoByIndex),
  NVML_ENTRY_ENUM(nvmlVgpuInstanceGetLicenseInfo),
  NVML_ENTRY_END
} nvml_entry_enum_t;

#ifdef __cplusplus
}
#endif

#endif // HIJACK_NVML_HELPER_H
