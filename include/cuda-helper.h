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

#ifndef HIJACK_CUDA_HELPER_H
#define HIJACK_CUDA_HELPER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <dlfcn.h>

#include "cuda-subset.h"
#include "hijack.h"

/**
 *  CUDA library prefix
 */
#define CUDA_LIBRARY_PREFIX "libcuda.so"

#define CUDA_ENTRY_ENUM(x) ENTRY_##x

#define CUDA_FIND_ENTRY(table, sym) ({ (table)[CUDA_ENTRY_ENUM(sym)].fn_ptr; })

#define CUDA_ENTRY_CALL(table, sym, ...)                                       \
  ({                                                                           \
    cuda_sym_t _entry = CUDA_FIND_ENTRY(table, sym);                           \
    _entry(__VA_ARGS__);                                                       \
  })

#define CUDA_ENTRY_DEBUG_VOID_CALL(table, sym, ...)                            \
  ({                                                                           \
    cuda_debug_void_sym_t _entry = CUDA_FIND_ENTRY(table, sym);                \
    _entry(__VA_ARGS__);                                                       \
  })

#define CUDA_ENTRY_DEBUG_RESULT_CALL(table, sym, ...)                          \
  ({                                                                           \
    cuda_debug_result_sym_t _entry = CUDA_FIND_ENTRY(table, sym);              \
    _entry(__VA_ARGS__);                                                       \
  })

/**
 * CUDA library enumerator entry
 */
typedef enum {
  /** cuInit */
  CUDA_ENTRY_ENUM(cuInit),
  /** cuDeviceGet */
  CUDA_ENTRY_ENUM(cuDeviceGet),
  /** cuDeviceGetCount */
  CUDA_ENTRY_ENUM(cuDeviceGetCount),
  /** cuDeviceGetName */
  CUDA_ENTRY_ENUM(cuDeviceGetName),
  /** cuDeviceTotalMem_v2 */
  CUDA_ENTRY_ENUM(cuDeviceTotalMem_v2),
  /** cuDeviceGetAttribute */
  CUDA_ENTRY_ENUM(cuDeviceGetAttribute),
  /** cuDeviceGetP2PAttribute */
  CUDA_ENTRY_ENUM(cuDeviceGetP2PAttribute),
  /** cuDriverGetVersion */
  CUDA_ENTRY_ENUM(cuDriverGetVersion),
  /** cuDeviceGetByPCIBusId */
  CUDA_ENTRY_ENUM(cuDeviceGetByPCIBusId),
  /** cuDeviceGetPCIBusId */
  CUDA_ENTRY_ENUM(cuDeviceGetPCIBusId),
  /** cuDevicePrimaryCtxRetain */
  CUDA_ENTRY_ENUM(cuDevicePrimaryCtxRetain),
  /** cuDevicePrimaryCtxRelease */
  CUDA_ENTRY_ENUM(cuDevicePrimaryCtxRelease),
  /** cuDevicePrimaryCtxSetFlags */
  CUDA_ENTRY_ENUM(cuDevicePrimaryCtxSetFlags),
  /** cuDevicePrimaryCtxGetState */
  CUDA_ENTRY_ENUM(cuDevicePrimaryCtxGetState),
  /** cuDevicePrimaryCtxReset */
  CUDA_ENTRY_ENUM(cuDevicePrimaryCtxReset),
  /** cuCtxCreate_v2 */
  CUDA_ENTRY_ENUM(cuCtxCreate_v2),
  /** cuCtxGetFlags */
  CUDA_ENTRY_ENUM(cuCtxGetFlags),
  /** cuCtxSetCurrent */
  CUDA_ENTRY_ENUM(cuCtxSetCurrent),
  /** cuCtxGetCurrent */
  CUDA_ENTRY_ENUM(cuCtxGetCurrent),
  /** cuCtxDetach */
  CUDA_ENTRY_ENUM(cuCtxDetach),
  /** cuCtxGetApiVersion */
  CUDA_ENTRY_ENUM(cuCtxGetApiVersion),
  /** cuCtxGetDevice */
  CUDA_ENTRY_ENUM(cuCtxGetDevice),
  /** cuCtxGetLimit */
  CUDA_ENTRY_ENUM(cuCtxGetLimit),
  /** cuCtxSetLimit */
  CUDA_ENTRY_ENUM(cuCtxSetLimit),
  /** cuCtxGetCacheConfig */
  CUDA_ENTRY_ENUM(cuCtxGetCacheConfig),
  /** cuCtxSetCacheConfig */
  CUDA_ENTRY_ENUM(cuCtxSetCacheConfig),
  /** cuCtxGetSharedMemConfig */
  CUDA_ENTRY_ENUM(cuCtxGetSharedMemConfig),
  /** cuCtxGetStreamPriorityRange */
  CUDA_ENTRY_ENUM(cuCtxGetStreamPriorityRange),
  /** cuCtxSetSharedMemConfig */
  CUDA_ENTRY_ENUM(cuCtxSetSharedMemConfig),
  /** cuCtxSynchronize */
  CUDA_ENTRY_ENUM(cuCtxSynchronize),
  /** cuModuleLoad */
  CUDA_ENTRY_ENUM(cuModuleLoad),
  /** cuModuleLoadData */
  CUDA_ENTRY_ENUM(cuModuleLoadData),
  /** cuModuleLoadFatBinary */
  CUDA_ENTRY_ENUM(cuModuleLoadFatBinary),
  /** cuModuleUnload */
  CUDA_ENTRY_ENUM(cuModuleUnload),
  /** cuModuleGetFunction */
  CUDA_ENTRY_ENUM(cuModuleGetFunction),
  /** cuModuleGetGlobal_v2 */
  CUDA_ENTRY_ENUM(cuModuleGetGlobal_v2),
  /** cuModuleGetTexRef */
  CUDA_ENTRY_ENUM(cuModuleGetTexRef),
  /** cuModuleGetSurfRef */
  CUDA_ENTRY_ENUM(cuModuleGetSurfRef),
  /** cuLinkCreate */
  CUDA_ENTRY_ENUM(cuLinkCreate),
  /** cuLinkAddData */
  CUDA_ENTRY_ENUM(cuLinkAddData),
  /** cuLinkAddFile */
  CUDA_ENTRY_ENUM(cuLinkAddFile),
  /** cuLinkComplete */
  CUDA_ENTRY_ENUM(cuLinkComplete),
  /** cuLinkDestroy */
  CUDA_ENTRY_ENUM(cuLinkDestroy),
  /** cuMemGetInfo_v2 */
  CUDA_ENTRY_ENUM(cuMemGetInfo_v2),
  /** cuMemAllocManaged */
  CUDA_ENTRY_ENUM(cuMemAllocManaged),
  /** cuMemAlloc_v2 */
  CUDA_ENTRY_ENUM(cuMemAlloc_v2),
  /** cuMemAllocPitch_v2 */
  CUDA_ENTRY_ENUM(cuMemAllocPitch_v2),
  /** cuMemFree_v2 */
  CUDA_ENTRY_ENUM(cuMemFree_v2),
  /** cuMemGetAddressRange_v2 */
  CUDA_ENTRY_ENUM(cuMemGetAddressRange_v2),
  /** cuMemFreeHost */
  CUDA_ENTRY_ENUM(cuMemFreeHost),
  /** cuMemHostAlloc */
  CUDA_ENTRY_ENUM(cuMemHostAlloc),
  /** cuMemHostGetDevicePointer_v2 */
  CUDA_ENTRY_ENUM(cuMemHostGetDevicePointer_v2),
  /** cuMemHostGetFlags */
  CUDA_ENTRY_ENUM(cuMemHostGetFlags),
  /** cuMemHostRegister_v2 */
  CUDA_ENTRY_ENUM(cuMemHostRegister_v2),
  /** cuMemHostUnregister */
  CUDA_ENTRY_ENUM(cuMemHostUnregister),
  /** cuPointerGetAttribute */
  CUDA_ENTRY_ENUM(cuPointerGetAttribute),
  /** cuPointerGetAttributes */
  CUDA_ENTRY_ENUM(cuPointerGetAttributes),
  /** cuMemcpy */
  CUDA_ENTRY_ENUM(cuMemcpy),
  /** cuMemcpy_ptds */
  CUDA_ENTRY_ENUM(cuMemcpy_ptds),
  /** cuMemcpyAsync */
  CUDA_ENTRY_ENUM(cuMemcpyAsync),
  /** cuMemcpyAsync_ptsz */
  CUDA_ENTRY_ENUM(cuMemcpyAsync_ptsz),
  /** cuMemcpyPeer */
  CUDA_ENTRY_ENUM(cuMemcpyPeer),
  /** cuMemcpyPeer_ptds */
  CUDA_ENTRY_ENUM(cuMemcpyPeer_ptds),
  /** cuMemcpyPeerAsync */
  CUDA_ENTRY_ENUM(cuMemcpyPeerAsync),
  /** cuMemcpyPeerAsync_ptsz */
  CUDA_ENTRY_ENUM(cuMemcpyPeerAsync_ptsz),
  /** cuMemcpyHtoD_v2 */
  CUDA_ENTRY_ENUM(cuMemcpyHtoD_v2),
  /** cuMemcpyHtoD_v2_ptds */
  CUDA_ENTRY_ENUM(cuMemcpyHtoD_v2_ptds),
  /** cuMemcpyHtoDAsync_v2 */
  CUDA_ENTRY_ENUM(cuMemcpyHtoDAsync_v2),
  /** cuMemcpyHtoDAsync_v2_ptsz */
  CUDA_ENTRY_ENUM(cuMemcpyHtoDAsync_v2_ptsz),
  /** cuMemcpyDtoH_v2 */
  CUDA_ENTRY_ENUM(cuMemcpyDtoH_v2),
  /** cuMemcpyDtoH_v2_ptds */
  CUDA_ENTRY_ENUM(cuMemcpyDtoH_v2_ptds),
  /** cuMemcpyDtoHAsync_v2 */
  CUDA_ENTRY_ENUM(cuMemcpyDtoHAsync_v2),
  /** cuMemcpyDtoHAsync_v2_ptsz */
  CUDA_ENTRY_ENUM(cuMemcpyDtoHAsync_v2_ptsz),
  /** cuMemcpyDtoD_v2 */
  CUDA_ENTRY_ENUM(cuMemcpyDtoD_v2),
  /** cuMemcpyDtoD_v2_ptds */
  CUDA_ENTRY_ENUM(cuMemcpyDtoD_v2_ptds),
  /** cuMemcpyDtoDAsync_v2 */
  CUDA_ENTRY_ENUM(cuMemcpyDtoDAsync_v2),
  /** cuMemcpyDtoDAsync_v2_ptsz */
  CUDA_ENTRY_ENUM(cuMemcpyDtoDAsync_v2_ptsz),
  /** cuMemcpy2DUnaligned_v2 */
  CUDA_ENTRY_ENUM(cuMemcpy2DUnaligned_v2),
  /** cuMemcpy2DUnaligned_v2_ptds */
  CUDA_ENTRY_ENUM(cuMemcpy2DUnaligned_v2_ptds),
  /** cuMemcpy2DAsync_v2 */
  CUDA_ENTRY_ENUM(cuMemcpy2DAsync_v2),
  /** cuMemcpy2DAsync_v2_ptsz */
  CUDA_ENTRY_ENUM(cuMemcpy2DAsync_v2_ptsz),
  /** cuMemcpy3D_v2 */
  CUDA_ENTRY_ENUM(cuMemcpy3D_v2),
  /** cuMemcpy3D_v2_ptds */
  CUDA_ENTRY_ENUM(cuMemcpy3D_v2_ptds),
  /** cuMemcpy3DAsync_v2 */
  CUDA_ENTRY_ENUM(cuMemcpy3DAsync_v2),
  /** cuMemcpy3DAsync_v2_ptsz */
  CUDA_ENTRY_ENUM(cuMemcpy3DAsync_v2_ptsz),
  /** cuMemcpy3DPeer */
  CUDA_ENTRY_ENUM(cuMemcpy3DPeer),
  /** cuMemcpy3DPeer_ptds */
  CUDA_ENTRY_ENUM(cuMemcpy3DPeer_ptds),
  /** cuMemcpy3DPeerAsync */
  CUDA_ENTRY_ENUM(cuMemcpy3DPeerAsync),
  /** cuMemcpy3DPeerAsync_ptsz */
  CUDA_ENTRY_ENUM(cuMemcpy3DPeerAsync_ptsz),
  /** cuMemsetD8_v2 */
  CUDA_ENTRY_ENUM(cuMemsetD8_v2),
  /** cuMemsetD8_v2_ptds */
  CUDA_ENTRY_ENUM(cuMemsetD8_v2_ptds),
  /** cuMemsetD8Async */
  CUDA_ENTRY_ENUM(cuMemsetD8Async),
  /** cuMemsetD8Async_ptsz */
  CUDA_ENTRY_ENUM(cuMemsetD8Async_ptsz),
  /** cuMemsetD2D8_v2 */
  CUDA_ENTRY_ENUM(cuMemsetD2D8_v2),
  /** cuMemsetD2D8_v2_ptds */
  CUDA_ENTRY_ENUM(cuMemsetD2D8_v2_ptds),
  /** cuMemsetD2D8Async */
  CUDA_ENTRY_ENUM(cuMemsetD2D8Async),
  /** cuMemsetD2D8Async_ptsz */
  CUDA_ENTRY_ENUM(cuMemsetD2D8Async_ptsz),
  /** cuFuncSetCacheConfig */
  CUDA_ENTRY_ENUM(cuFuncSetCacheConfig),
  /** cuFuncSetSharedMemConfig */
  CUDA_ENTRY_ENUM(cuFuncSetSharedMemConfig),
  /** cuFuncGetAttribute */
  CUDA_ENTRY_ENUM(cuFuncGetAttribute),
  /** cuArrayCreate_v2 */
  CUDA_ENTRY_ENUM(cuArrayCreate_v2),
  /** cuArrayGetDescriptor_v2 */
  CUDA_ENTRY_ENUM(cuArrayGetDescriptor_v2),
  /** cuArray3DCreate_v2 */
  CUDA_ENTRY_ENUM(cuArray3DCreate_v2),
  /** cuArray3DGetDescriptor_v2 */
  CUDA_ENTRY_ENUM(cuArray3DGetDescriptor_v2),
  /** cuArrayDestroy */
  CUDA_ENTRY_ENUM(cuArrayDestroy),
  /** cuMipmappedArrayCreate */
  CUDA_ENTRY_ENUM(cuMipmappedArrayCreate),
  /** cuMipmappedArrayGetLevel */
  CUDA_ENTRY_ENUM(cuMipmappedArrayGetLevel),
  /** cuMipmappedArrayDestroy */
  CUDA_ENTRY_ENUM(cuMipmappedArrayDestroy),
  /** cuTexRefCreate */
  CUDA_ENTRY_ENUM(cuTexRefCreate),
  /** cuTexRefDestroy */
  CUDA_ENTRY_ENUM(cuTexRefDestroy),
  /** cuTexRefSetArray */
  CUDA_ENTRY_ENUM(cuTexRefSetArray),
  /** cuTexRefSetMipmappedArray */
  CUDA_ENTRY_ENUM(cuTexRefSetMipmappedArray),
  /** cuTexRefSetAddress_v2 */
  CUDA_ENTRY_ENUM(cuTexRefSetAddress_v2),
  /** cuTexRefSetAddress2D_v3 */
  CUDA_ENTRY_ENUM(cuTexRefSetAddress2D_v3),
  /** cuTexRefSetFormat */
  CUDA_ENTRY_ENUM(cuTexRefSetFormat),
  /** cuTexRefSetAddressMode */
  CUDA_ENTRY_ENUM(cuTexRefSetAddressMode),
  /** cuTexRefSetFilterMode */
  CUDA_ENTRY_ENUM(cuTexRefSetFilterMode),
  /** cuTexRefSetMipmapFilterMode */
  CUDA_ENTRY_ENUM(cuTexRefSetMipmapFilterMode),
  /** cuTexRefSetMipmapLevelBias */
  CUDA_ENTRY_ENUM(cuTexRefSetMipmapLevelBias),
  /** cuTexRefSetMipmapLevelClamp */
  CUDA_ENTRY_ENUM(cuTexRefSetMipmapLevelClamp),
  /** cuTexRefSetMaxAnisotropy */
  CUDA_ENTRY_ENUM(cuTexRefSetMaxAnisotropy),
  /** cuTexRefSetFlags */
  CUDA_ENTRY_ENUM(cuTexRefSetFlags),
  /** cuTexRefSetBorderColor */
  CUDA_ENTRY_ENUM(cuTexRefSetBorderColor),
  /** cuTexRefGetBorderColor */
  CUDA_ENTRY_ENUM(cuTexRefGetBorderColor),
  /** cuSurfRefSetArray */
  CUDA_ENTRY_ENUM(cuSurfRefSetArray),
  /** cuTexObjectCreate */
  CUDA_ENTRY_ENUM(cuTexObjectCreate),
  /** cuTexObjectDestroy */
  CUDA_ENTRY_ENUM(cuTexObjectDestroy),
  /** cuTexObjectGetResourceDesc */
  CUDA_ENTRY_ENUM(cuTexObjectGetResourceDesc),
  /** cuTexObjectGetTextureDesc */
  CUDA_ENTRY_ENUM(cuTexObjectGetTextureDesc),
  /** cuTexObjectGetResourceViewDesc */
  CUDA_ENTRY_ENUM(cuTexObjectGetResourceViewDesc),
  /** cuSurfObjectCreate */
  CUDA_ENTRY_ENUM(cuSurfObjectCreate),
  /** cuSurfObjectDestroy */
  CUDA_ENTRY_ENUM(cuSurfObjectDestroy),
  /** cuSurfObjectGetResourceDesc */
  CUDA_ENTRY_ENUM(cuSurfObjectGetResourceDesc),
  /** cuLaunchKernel */
  CUDA_ENTRY_ENUM(cuLaunchKernel),
  /** cuLaunchKernel_ptsz */
  CUDA_ENTRY_ENUM(cuLaunchKernel_ptsz),
  /** cuEventCreate */
  CUDA_ENTRY_ENUM(cuEventCreate),
  /** cuEventRecord */
  CUDA_ENTRY_ENUM(cuEventRecord),
  /** cuEventRecord_ptsz */
  CUDA_ENTRY_ENUM(cuEventRecord_ptsz),
  /** cuEventQuery */
  CUDA_ENTRY_ENUM(cuEventQuery),
  /** cuEventSynchronize */
  CUDA_ENTRY_ENUM(cuEventSynchronize),
  /** cuEventDestroy_v2 */
  CUDA_ENTRY_ENUM(cuEventDestroy_v2),
  /** cuEventElapsedTime */
  CUDA_ENTRY_ENUM(cuEventElapsedTime),
  /** cuStreamWaitValue32 */
  CUDA_ENTRY_ENUM(cuStreamWaitValue32),
  /** cuStreamWaitValue32_ptsz */
  CUDA_ENTRY_ENUM(cuStreamWaitValue32_ptsz),
  /** cuStreamWriteValue32 */
  CUDA_ENTRY_ENUM(cuStreamWriteValue32),
  /** cuStreamWriteValue32_ptsz */
  CUDA_ENTRY_ENUM(cuStreamWriteValue32_ptsz),
  /** cuStreamBatchMemOp */
  CUDA_ENTRY_ENUM(cuStreamBatchMemOp),
  /** cuStreamBatchMemOp_ptsz */
  CUDA_ENTRY_ENUM(cuStreamBatchMemOp_ptsz),
  /** cuStreamCreate */
  CUDA_ENTRY_ENUM(cuStreamCreate),
  /** cuStreamCreateWithPriority */
  CUDA_ENTRY_ENUM(cuStreamCreateWithPriority),
  /** cuStreamGetPriority */
  CUDA_ENTRY_ENUM(cuStreamGetPriority),
  /** cuStreamGetPriority_ptsz */
  CUDA_ENTRY_ENUM(cuStreamGetPriority_ptsz),
  /** cuStreamGetFlags */
  CUDA_ENTRY_ENUM(cuStreamGetFlags),
  /** cuStreamGetFlags_ptsz */
  CUDA_ENTRY_ENUM(cuStreamGetFlags_ptsz),
  /** cuStreamDestroy_v2 */
  CUDA_ENTRY_ENUM(cuStreamDestroy_v2),
  /** cuStreamWaitEvent */
  CUDA_ENTRY_ENUM(cuStreamWaitEvent),
  /** cuStreamWaitEvent_ptsz */
  CUDA_ENTRY_ENUM(cuStreamWaitEvent_ptsz),
  /** cuStreamAddCallback */
  CUDA_ENTRY_ENUM(cuStreamAddCallback),
  /** cuStreamAddCallback_ptsz */
  CUDA_ENTRY_ENUM(cuStreamAddCallback_ptsz),
  /** cuStreamSynchronize */
  CUDA_ENTRY_ENUM(cuStreamSynchronize),
  /** cuStreamSynchronize_ptsz */
  CUDA_ENTRY_ENUM(cuStreamSynchronize_ptsz),
  /** cuStreamQuery */
  CUDA_ENTRY_ENUM(cuStreamQuery),
  /** cuStreamQuery_ptsz */
  CUDA_ENTRY_ENUM(cuStreamQuery_ptsz),
  /** cuStreamAttachMemAsync */
  CUDA_ENTRY_ENUM(cuStreamAttachMemAsync),
  /** cuStreamAttachMemAsync_ptsz */
  CUDA_ENTRY_ENUM(cuStreamAttachMemAsync_ptsz),
  /** cuDeviceCanAccessPeer */
  CUDA_ENTRY_ENUM(cuDeviceCanAccessPeer),
  /** cuCtxEnablePeerAccess */
  CUDA_ENTRY_ENUM(cuCtxEnablePeerAccess),
  /** cuCtxDisablePeerAccess */
  CUDA_ENTRY_ENUM(cuCtxDisablePeerAccess),
  /** cuIpcGetEventHandle */
  CUDA_ENTRY_ENUM(cuIpcGetEventHandle),
  /** cuIpcOpenEventHandle */
  CUDA_ENTRY_ENUM(cuIpcOpenEventHandle),
  /** cuIpcGetMemHandle */
  CUDA_ENTRY_ENUM(cuIpcGetMemHandle),
  /** cuIpcOpenMemHandle */
  CUDA_ENTRY_ENUM(cuIpcOpenMemHandle),
  /** cuIpcCloseMemHandle */
  CUDA_ENTRY_ENUM(cuIpcCloseMemHandle),
  /** cuGLCtxCreate_v2 */
  CUDA_ENTRY_ENUM(cuGLCtxCreate_v2),
  /** cuGLInit */
  CUDA_ENTRY_ENUM(cuGLInit),
  /** cuGLGetDevices */
  CUDA_ENTRY_ENUM(cuGLGetDevices),
  /** cuGLRegisterBufferObject */
  CUDA_ENTRY_ENUM(cuGLRegisterBufferObject),
  /** cuGLMapBufferObject_v2 */
  CUDA_ENTRY_ENUM(cuGLMapBufferObject_v2),
  /** cuGLMapBufferObject_v2_ptds */
  CUDA_ENTRY_ENUM(cuGLMapBufferObject_v2_ptds),
  /** cuGLMapBufferObjectAsync_v2 */
  CUDA_ENTRY_ENUM(cuGLMapBufferObjectAsync_v2),
  /** cuGLMapBufferObjectAsync_v2_ptsz */
  CUDA_ENTRY_ENUM(cuGLMapBufferObjectAsync_v2_ptsz),
  /** cuGLUnmapBufferObject */
  CUDA_ENTRY_ENUM(cuGLUnmapBufferObject),
  /** cuGLUnmapBufferObjectAsync */
  CUDA_ENTRY_ENUM(cuGLUnmapBufferObjectAsync),
  /** cuGLUnregisterBufferObject */
  CUDA_ENTRY_ENUM(cuGLUnregisterBufferObject),
  /** cuGLSetBufferObjectMapFlags */
  CUDA_ENTRY_ENUM(cuGLSetBufferObjectMapFlags),
  /** cuGraphicsGLRegisterImage */
  CUDA_ENTRY_ENUM(cuGraphicsGLRegisterImage),
  /** cuGraphicsGLRegisterBuffer */
  CUDA_ENTRY_ENUM(cuGraphicsGLRegisterBuffer),
  /** cuGraphicsUnregisterResource */
  CUDA_ENTRY_ENUM(cuGraphicsUnregisterResource),
  /** cuGraphicsMapResources */
  CUDA_ENTRY_ENUM(cuGraphicsMapResources),
  /** cuGraphicsMapResources_ptsz */
  CUDA_ENTRY_ENUM(cuGraphicsMapResources_ptsz),
  /** cuGraphicsUnmapResources */
  CUDA_ENTRY_ENUM(cuGraphicsUnmapResources),
  /** cuGraphicsUnmapResources_ptsz */
  CUDA_ENTRY_ENUM(cuGraphicsUnmapResources_ptsz),
  /** cuGraphicsResourceSetMapFlags_v2 */
  CUDA_ENTRY_ENUM(cuGraphicsResourceSetMapFlags_v2),
  /** cuGraphicsSubResourceGetMappedArray */
  CUDA_ENTRY_ENUM(cuGraphicsSubResourceGetMappedArray),
  /** cuGraphicsResourceGetMappedMipmappedArray */
  CUDA_ENTRY_ENUM(cuGraphicsResourceGetMappedMipmappedArray),
  /** cuGraphicsResourceGetMappedPointer_v2 */
  CUDA_ENTRY_ENUM(cuGraphicsResourceGetMappedPointer_v2),
  /** cuProfilerInitialize */
  CUDA_ENTRY_ENUM(cuProfilerInitialize),
  /** cuProfilerStart */
  CUDA_ENTRY_ENUM(cuProfilerStart),
  /** cuProfilerStop */
  CUDA_ENTRY_ENUM(cuProfilerStop),
  /** cuVDPAUGetDevice */
  CUDA_ENTRY_ENUM(cuVDPAUGetDevice),
  /** cuVDPAUCtxCreate_v2 */
  CUDA_ENTRY_ENUM(cuVDPAUCtxCreate_v2),
  /** cuGraphicsVDPAURegisterVideoSurface */
  CUDA_ENTRY_ENUM(cuGraphicsVDPAURegisterVideoSurface),
  /** cuGraphicsVDPAURegisterOutputSurface */
  CUDA_ENTRY_ENUM(cuGraphicsVDPAURegisterOutputSurface),
  /** cuGetExportTable */
  CUDA_ENTRY_ENUM(cuGetExportTable),
  /** cuOccupancyMaxActiveBlocksPerMultiprocessor */
  CUDA_ENTRY_ENUM(cuOccupancyMaxActiveBlocksPerMultiprocessor),
  /** cuMemAdvise */
  CUDA_ENTRY_ENUM(cuMemAdvise),
  /** cuMemPrefetchAsync */
  CUDA_ENTRY_ENUM(cuMemPrefetchAsync),
  /** cuMemPrefetchAsync_ptsz */
  CUDA_ENTRY_ENUM(cuMemPrefetchAsync_ptsz),
  /** cuMemRangeGetAttribute */
  CUDA_ENTRY_ENUM(cuMemRangeGetAttribute),
  /** cuMemRangeGetAttributes */
  CUDA_ENTRY_ENUM(cuMemRangeGetAttributes),
  /** cuGetErrorString */
  CUDA_ENTRY_ENUM(cuGetErrorString),
  /** cuGetErrorName */
  CUDA_ENTRY_ENUM(cuGetErrorName),
  /** cuArray3DCreate */
  CUDA_ENTRY_ENUM(cuArray3DCreate),
  /** cuArray3DGetDescriptor */
  CUDA_ENTRY_ENUM(cuArray3DGetDescriptor),
  /** cuArrayCreate */
  CUDA_ENTRY_ENUM(cuArrayCreate),
  /** cuArrayGetDescriptor */
  CUDA_ENTRY_ENUM(cuArrayGetDescriptor),
  /** cuCtxAttach */
  CUDA_ENTRY_ENUM(cuCtxAttach),
  /** cuCtxCreate */
  CUDA_ENTRY_ENUM(cuCtxCreate),
  /** cuCtxDestroy */
  CUDA_ENTRY_ENUM(cuCtxDestroy),
  /** cuCtxDestroy_v2 */
  CUDA_ENTRY_ENUM(cuCtxDestroy_v2),
  /** cuCtxPopCurrent */
  CUDA_ENTRY_ENUM(cuCtxPopCurrent),
  /** cuCtxPopCurrent_v2 */
  CUDA_ENTRY_ENUM(cuCtxPopCurrent_v2),
  /** cuCtxPushCurrent */
  CUDA_ENTRY_ENUM(cuCtxPushCurrent),
  /** cuCtxPushCurrent_v2 */
  CUDA_ENTRY_ENUM(cuCtxPushCurrent_v2),
  /** cudbgApiAttach */
  CUDA_ENTRY_ENUM(cudbgApiAttach),
  /** cudbgApiDetach */
  CUDA_ENTRY_ENUM(cudbgApiDetach),
  /** cudbgApiInit */
  CUDA_ENTRY_ENUM(cudbgApiInit),
  /** cudbgGetAPI */
  CUDA_ENTRY_ENUM(cudbgGetAPI),
  /** cudbgGetAPIVersion */
  CUDA_ENTRY_ENUM(cudbgGetAPIVersion),
  /** cudbgMain */
  CUDA_ENTRY_ENUM(cudbgMain),
  /** cudbgReportDriverApiError */
  CUDA_ENTRY_ENUM(cudbgReportDriverApiError),
  /** cudbgReportDriverInternalError */
  CUDA_ENTRY_ENUM(cudbgReportDriverInternalError),
  /** cuDeviceComputeCapability */
  CUDA_ENTRY_ENUM(cuDeviceComputeCapability),
  /** cuDeviceGetProperties */
  CUDA_ENTRY_ENUM(cuDeviceGetProperties),
  /** cuDeviceTotalMem */
  CUDA_ENTRY_ENUM(cuDeviceTotalMem),
  /** cuEGLInit */
  CUDA_ENTRY_ENUM(cuEGLInit),
  /** cuEGLStreamConsumerAcquireFrame */
  CUDA_ENTRY_ENUM(cuEGLStreamConsumerAcquireFrame),
  /** cuEGLStreamConsumerConnect */
  CUDA_ENTRY_ENUM(cuEGLStreamConsumerConnect),
  /** cuEGLStreamConsumerConnectWithFlags */
  CUDA_ENTRY_ENUM(cuEGLStreamConsumerConnectWithFlags),
  /** cuEGLStreamConsumerDisconnect */
  CUDA_ENTRY_ENUM(cuEGLStreamConsumerDisconnect),
  /** cuEGLStreamConsumerReleaseFrame */
  CUDA_ENTRY_ENUM(cuEGLStreamConsumerReleaseFrame),
  /** cuEGLStreamProducerConnect */
  CUDA_ENTRY_ENUM(cuEGLStreamProducerConnect),
  /** cuEGLStreamProducerDisconnect */
  CUDA_ENTRY_ENUM(cuEGLStreamProducerDisconnect),
  /** cuEGLStreamProducerPresentFrame */
  CUDA_ENTRY_ENUM(cuEGLStreamProducerPresentFrame),
  /** cuEGLStreamProducerReturnFrame */
  CUDA_ENTRY_ENUM(cuEGLStreamProducerReturnFrame),
  /** cuEventDestroy */
  CUDA_ENTRY_ENUM(cuEventDestroy),
  /** cuFuncSetAttribute */
  CUDA_ENTRY_ENUM(cuFuncSetAttribute),
  /** cuFuncSetBlockShape */
  CUDA_ENTRY_ENUM(cuFuncSetBlockShape),
  /** cuFuncSetSharedSize */
  CUDA_ENTRY_ENUM(cuFuncSetSharedSize),
  /** cuGLCtxCreate */
  CUDA_ENTRY_ENUM(cuGLCtxCreate),
  /** cuGLGetDevices_v2 */
  CUDA_ENTRY_ENUM(cuGLGetDevices_v2),
  /** cuGLMapBufferObject */
  CUDA_ENTRY_ENUM(cuGLMapBufferObject),
  /** cuGLMapBufferObjectAsync */
  CUDA_ENTRY_ENUM(cuGLMapBufferObjectAsync),
  /** cuGraphicsEGLRegisterImage */
  CUDA_ENTRY_ENUM(cuGraphicsEGLRegisterImage),
  /** cuGraphicsResourceGetMappedEglFrame */
  CUDA_ENTRY_ENUM(cuGraphicsResourceGetMappedEglFrame),
  /** cuGraphicsResourceGetMappedPointer */
  CUDA_ENTRY_ENUM(cuGraphicsResourceGetMappedPointer),
  /** cuGraphicsResourceSetMapFlags */
  CUDA_ENTRY_ENUM(cuGraphicsResourceSetMapFlags),
  /** cuLaunch */
  CUDA_ENTRY_ENUM(cuLaunch),
  /** cuLaunchCooperativeKernel */
  CUDA_ENTRY_ENUM(cuLaunchCooperativeKernel),
  /** cuLaunchCooperativeKernelMultiDevice */
  CUDA_ENTRY_ENUM(cuLaunchCooperativeKernelMultiDevice),
  /** cuLaunchCooperativeKernel_ptsz */
  CUDA_ENTRY_ENUM(cuLaunchCooperativeKernel_ptsz),
  /** cuLaunchGrid */
  CUDA_ENTRY_ENUM(cuLaunchGrid),
  /** cuLaunchGridAsync */
  CUDA_ENTRY_ENUM(cuLaunchGridAsync),
  /** cuLinkAddData_v2 */
  CUDA_ENTRY_ENUM(cuLinkAddData_v2),
  /** cuLinkAddFile_v2 */
  CUDA_ENTRY_ENUM(cuLinkAddFile_v2),
  /** cuLinkCreate_v2 */
  CUDA_ENTRY_ENUM(cuLinkCreate_v2),
  /** cuMemAlloc */
  CUDA_ENTRY_ENUM(cuMemAlloc),
  /** cuMemAllocHost */
  CUDA_ENTRY_ENUM(cuMemAllocHost),
  /** cuMemAllocHost_v2 */
  CUDA_ENTRY_ENUM(cuMemAllocHost_v2),
  /** cuMemAllocPitch */
  CUDA_ENTRY_ENUM(cuMemAllocPitch),
  /** cuMemcpy2D */
  CUDA_ENTRY_ENUM(cuMemcpy2D),
  /** cuMemcpy2DAsync */
  CUDA_ENTRY_ENUM(cuMemcpy2DAsync),
  /** cuMemcpy2DUnaligned */
  CUDA_ENTRY_ENUM(cuMemcpy2DUnaligned),
  /** cuMemcpy2D_v2 */
  CUDA_ENTRY_ENUM(cuMemcpy2D_v2),
  /** cuMemcpy2D_v2_ptds */
  CUDA_ENTRY_ENUM(cuMemcpy2D_v2_ptds),
  /** cuMemcpy3D */
  CUDA_ENTRY_ENUM(cuMemcpy3D),
  /** cuMemcpy3DAsync */
  CUDA_ENTRY_ENUM(cuMemcpy3DAsync),
  /** cuMemcpyAtoA */
  CUDA_ENTRY_ENUM(cuMemcpyAtoA),
  /** cuMemcpyAtoA_v2 */
  CUDA_ENTRY_ENUM(cuMemcpyAtoA_v2),
  /** cuMemcpyAtoA_v2_ptds */
  CUDA_ENTRY_ENUM(cuMemcpyAtoA_v2_ptds),
  /** cuMemcpyAtoD */
  CUDA_ENTRY_ENUM(cuMemcpyAtoD),
  /** cuMemcpyAtoD_v2 */
  CUDA_ENTRY_ENUM(cuMemcpyAtoD_v2),
  /** cuMemcpyAtoD_v2_ptds */
  CUDA_ENTRY_ENUM(cuMemcpyAtoD_v2_ptds),
  /** cuMemcpyAtoH */
  CUDA_ENTRY_ENUM(cuMemcpyAtoH),
  /** cuMemcpyAtoHAsync */
  CUDA_ENTRY_ENUM(cuMemcpyAtoHAsync),
  /** cuMemcpyAtoHAsync_v2 */
  CUDA_ENTRY_ENUM(cuMemcpyAtoHAsync_v2),
  /** cuMemcpyAtoHAsync_v2_ptsz */
  CUDA_ENTRY_ENUM(cuMemcpyAtoHAsync_v2_ptsz),
  /** cuMemcpyAtoH_v2 */
  CUDA_ENTRY_ENUM(cuMemcpyAtoH_v2),
  /** cuMemcpyAtoH_v2_ptds */
  CUDA_ENTRY_ENUM(cuMemcpyAtoH_v2_ptds),
  /** cuMemcpyDtoA */
  CUDA_ENTRY_ENUM(cuMemcpyDtoA),
  /** cuMemcpyDtoA_v2 */
  CUDA_ENTRY_ENUM(cuMemcpyDtoA_v2),
  /** cuMemcpyDtoA_v2_ptds */
  CUDA_ENTRY_ENUM(cuMemcpyDtoA_v2_ptds),
  /** cuMemcpyDtoD */
  CUDA_ENTRY_ENUM(cuMemcpyDtoD),
  /** cuMemcpyDtoDAsync */
  CUDA_ENTRY_ENUM(cuMemcpyDtoDAsync),
  /** cuMemcpyDtoH */
  CUDA_ENTRY_ENUM(cuMemcpyDtoH),
  /** cuMemcpyDtoHAsync */
  CUDA_ENTRY_ENUM(cuMemcpyDtoHAsync),
  /** cuMemcpyHtoA */
  CUDA_ENTRY_ENUM(cuMemcpyHtoA),
  /** cuMemcpyHtoAAsync */
  CUDA_ENTRY_ENUM(cuMemcpyHtoAAsync),
  /** cuMemcpyHtoAAsync_v2 */
  CUDA_ENTRY_ENUM(cuMemcpyHtoAAsync_v2),
  /** cuMemcpyHtoAAsync_v2_ptsz */
  CUDA_ENTRY_ENUM(cuMemcpyHtoAAsync_v2_ptsz),
  /** cuMemcpyHtoA_v2 */
  CUDA_ENTRY_ENUM(cuMemcpyHtoA_v2),
  /** cuMemcpyHtoA_v2_ptds */
  CUDA_ENTRY_ENUM(cuMemcpyHtoA_v2_ptds),
  /** cuMemcpyHtoD */
  CUDA_ENTRY_ENUM(cuMemcpyHtoD),
  /** cuMemcpyHtoDAsync */
  CUDA_ENTRY_ENUM(cuMemcpyHtoDAsync),
  /** cuMemFree */
  CUDA_ENTRY_ENUM(cuMemFree),
  /** cuMemGetAddressRange */
  CUDA_ENTRY_ENUM(cuMemGetAddressRange),
  // Deprecated
  // CUDA_ENTRY_ENUM(cuMemGetAttribute),
  // CUDA_ENTRY_ENUM(cuMemGetAttribute_v2),
  /** cuMemGetInfo */
  CUDA_ENTRY_ENUM(cuMemGetInfo),
  /** cuMemHostGetDevicePointer */
  CUDA_ENTRY_ENUM(cuMemHostGetDevicePointer),
  /** cuMemHostRegister */
  CUDA_ENTRY_ENUM(cuMemHostRegister),
  /** cuMemsetD16 */
  CUDA_ENTRY_ENUM(cuMemsetD16),
  /** cuMemsetD16Async */
  CUDA_ENTRY_ENUM(cuMemsetD16Async),
  /** cuMemsetD16Async_ptsz */
  CUDA_ENTRY_ENUM(cuMemsetD16Async_ptsz),
  /** cuMemsetD16_v2 */
  CUDA_ENTRY_ENUM(cuMemsetD16_v2),
  /** cuMemsetD16_v2_ptds */
  CUDA_ENTRY_ENUM(cuMemsetD16_v2_ptds),
  /** cuMemsetD2D16 */
  CUDA_ENTRY_ENUM(cuMemsetD2D16),
  /** cuMemsetD2D16Async */
  CUDA_ENTRY_ENUM(cuMemsetD2D16Async),
  /** cuMemsetD2D16Async_ptsz */
  CUDA_ENTRY_ENUM(cuMemsetD2D16Async_ptsz),
  /** cuMemsetD2D16_v2 */
  CUDA_ENTRY_ENUM(cuMemsetD2D16_v2),
  /** cuMemsetD2D16_v2_ptds */
  CUDA_ENTRY_ENUM(cuMemsetD2D16_v2_ptds),
  /** cuMemsetD2D32 */
  CUDA_ENTRY_ENUM(cuMemsetD2D32),
  /** cuMemsetD2D32Async */
  CUDA_ENTRY_ENUM(cuMemsetD2D32Async),
  /** cuMemsetD2D32Async_ptsz */
  CUDA_ENTRY_ENUM(cuMemsetD2D32Async_ptsz),
  /** cuMemsetD2D32_v2 */
  CUDA_ENTRY_ENUM(cuMemsetD2D32_v2),
  /** cuMemsetD2D32_v2_ptds */
  CUDA_ENTRY_ENUM(cuMemsetD2D32_v2_ptds),
  /** cuMemsetD2D8 */
  CUDA_ENTRY_ENUM(cuMemsetD2D8),
  /** cuMemsetD32 */
  CUDA_ENTRY_ENUM(cuMemsetD32),
  /** cuMemsetD32Async */
  CUDA_ENTRY_ENUM(cuMemsetD32Async),
  /** cuMemsetD32Async_ptsz */
  CUDA_ENTRY_ENUM(cuMemsetD32Async_ptsz),
  /** cuMemsetD32_v2 */
  CUDA_ENTRY_ENUM(cuMemsetD32_v2),
  /** cuMemsetD32_v2_ptds */
  CUDA_ENTRY_ENUM(cuMemsetD32_v2_ptds),
  /** cuMemsetD8 */
  CUDA_ENTRY_ENUM(cuMemsetD8),
  /** cuModuleGetGlobal */
  CUDA_ENTRY_ENUM(cuModuleGetGlobal),
  /** cuModuleLoadDataEx */
  CUDA_ENTRY_ENUM(cuModuleLoadDataEx),
  /** cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags */
  CUDA_ENTRY_ENUM(cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags),
  /** cuOccupancyMaxPotentialBlockSize */
  CUDA_ENTRY_ENUM(cuOccupancyMaxPotentialBlockSize),
  /** cuOccupancyMaxPotentialBlockSizeWithFlags */
  CUDA_ENTRY_ENUM(cuOccupancyMaxPotentialBlockSizeWithFlags),
  /** cuParamSetf */
  CUDA_ENTRY_ENUM(cuParamSetf),
  /** cuParamSeti */
  CUDA_ENTRY_ENUM(cuParamSeti),
  /** cuParamSetSize */
  CUDA_ENTRY_ENUM(cuParamSetSize),
  /** cuParamSetTexRef */
  CUDA_ENTRY_ENUM(cuParamSetTexRef),
  /** cuParamSetv */
  CUDA_ENTRY_ENUM(cuParamSetv),
  /** cuPointerSetAttribute */
  CUDA_ENTRY_ENUM(cuPointerSetAttribute),
  /** cuStreamDestroy */
  CUDA_ENTRY_ENUM(cuStreamDestroy),
  /** cuStreamWaitValue64 */
  CUDA_ENTRY_ENUM(cuStreamWaitValue64),
  /** cuStreamWaitValue64_ptsz */
  CUDA_ENTRY_ENUM(cuStreamWaitValue64_ptsz),
  /** cuStreamWriteValue64 */
  CUDA_ENTRY_ENUM(cuStreamWriteValue64),
  /** cuStreamWriteValue64_ptsz */
  CUDA_ENTRY_ENUM(cuStreamWriteValue64_ptsz),
  /** cuSurfRefGetArray */
  CUDA_ENTRY_ENUM(cuSurfRefGetArray),
  /** cuTexRefGetAddress */
  CUDA_ENTRY_ENUM(cuTexRefGetAddress),
  /** cuTexRefGetAddressMode */
  CUDA_ENTRY_ENUM(cuTexRefGetAddressMode),
  /** cuTexRefGetAddress_v2 */
  CUDA_ENTRY_ENUM(cuTexRefGetAddress_v2),
  /** cuTexRefGetArray */
  CUDA_ENTRY_ENUM(cuTexRefGetArray),
  /** cuTexRefGetFilterMode */
  CUDA_ENTRY_ENUM(cuTexRefGetFilterMode),
  /** cuTexRefGetFlags */
  CUDA_ENTRY_ENUM(cuTexRefGetFlags),
  /** cuTexRefGetFormat */
  CUDA_ENTRY_ENUM(cuTexRefGetFormat),
  /** cuTexRefGetMaxAnisotropy */
  CUDA_ENTRY_ENUM(cuTexRefGetMaxAnisotropy),
  /** cuTexRefGetMipmapFilterMode */
  CUDA_ENTRY_ENUM(cuTexRefGetMipmapFilterMode),
  /** cuTexRefGetMipmapLevelBias */
  CUDA_ENTRY_ENUM(cuTexRefGetMipmapLevelBias),
  /** cuTexRefGetMipmapLevelClamp */
  CUDA_ENTRY_ENUM(cuTexRefGetMipmapLevelClamp),
  /** cuTexRefGetMipmappedArray */
  CUDA_ENTRY_ENUM(cuTexRefGetMipmappedArray),
  /** cuTexRefSetAddress */
  CUDA_ENTRY_ENUM(cuTexRefSetAddress),
  /** cuTexRefSetAddress2D */
  CUDA_ENTRY_ENUM(cuTexRefSetAddress2D),
  /** cuTexRefSetAddress2D_v2 */
  CUDA_ENTRY_ENUM(cuTexRefSetAddress2D_v2),
  /** cuVDPAUCtxCreate */
  CUDA_ENTRY_ENUM(cuVDPAUCtxCreate),
  /** cuEGLApiInit */
  CUDA_ENTRY_ENUM(cuEGLApiInit),
  /** cuDestroyExternalMemory */
  CUDA_ENTRY_ENUM(cuDestroyExternalMemory),
  /** cuDestroyExternalSemaphore */
  CUDA_ENTRY_ENUM(cuDestroyExternalSemaphore),
  /** cuDeviceGetUuid */
  CUDA_ENTRY_ENUM(cuDeviceGetUuid),
  /** cuExternalMemoryGetMappedBuffer */
  CUDA_ENTRY_ENUM(cuExternalMemoryGetMappedBuffer),
  /** cuExternalMemoryGetMappedMipmappedArray */
  CUDA_ENTRY_ENUM(cuExternalMemoryGetMappedMipmappedArray),
  /** cuGraphAddChildGraphNode */
  CUDA_ENTRY_ENUM(cuGraphAddChildGraphNode),
  /** cuGraphAddDependencies */
  CUDA_ENTRY_ENUM(cuGraphAddDependencies),
  /** cuGraphAddEmptyNode */
  CUDA_ENTRY_ENUM(cuGraphAddEmptyNode),
  /** cuGraphAddHostNode */
  CUDA_ENTRY_ENUM(cuGraphAddHostNode),
  /** cuGraphAddKernelNode */
  CUDA_ENTRY_ENUM(cuGraphAddKernelNode),
  /** cuGraphAddMemcpyNode */
  CUDA_ENTRY_ENUM(cuGraphAddMemcpyNode),
  /** cuGraphAddMemsetNode */
  CUDA_ENTRY_ENUM(cuGraphAddMemsetNode),
  /** cuGraphChildGraphNodeGetGraph */
  CUDA_ENTRY_ENUM(cuGraphChildGraphNodeGetGraph),
  /** cuGraphClone */
  CUDA_ENTRY_ENUM(cuGraphClone),
  /** cuGraphCreate */
  CUDA_ENTRY_ENUM(cuGraphCreate),
  /** cuGraphDestroy */
  CUDA_ENTRY_ENUM(cuGraphDestroy),
  /** cuGraphDestroyNode */
  CUDA_ENTRY_ENUM(cuGraphDestroyNode),
  /** cuGraphExecDestroy */
  CUDA_ENTRY_ENUM(cuGraphExecDestroy),
  /** cuGraphGetEdges */
  CUDA_ENTRY_ENUM(cuGraphGetEdges),
  /** cuGraphGetNodes */
  CUDA_ENTRY_ENUM(cuGraphGetNodes),
  /** cuGraphGetRootNodes */
  CUDA_ENTRY_ENUM(cuGraphGetRootNodes),
  /** cuGraphHostNodeGetParams */
  CUDA_ENTRY_ENUM(cuGraphHostNodeGetParams),
  /** cuGraphHostNodeSetParams */
  CUDA_ENTRY_ENUM(cuGraphHostNodeSetParams),
  /** cuGraphInstantiate */
  CUDA_ENTRY_ENUM(cuGraphInstantiate),
  /** cuGraphKernelNodeGetParams */
  CUDA_ENTRY_ENUM(cuGraphKernelNodeGetParams),
  /** cuGraphKernelNodeSetParams */
  CUDA_ENTRY_ENUM(cuGraphKernelNodeSetParams),
  /** cuGraphLaunch */
  CUDA_ENTRY_ENUM(cuGraphLaunch),
  /** cuGraphLaunch_ptsz */
  CUDA_ENTRY_ENUM(cuGraphLaunch_ptsz),
  /** cuGraphMemcpyNodeGetParams */
  CUDA_ENTRY_ENUM(cuGraphMemcpyNodeGetParams),
  /** cuGraphMemcpyNodeSetParams */
  CUDA_ENTRY_ENUM(cuGraphMemcpyNodeSetParams),
  /** cuGraphMemsetNodeGetParams */
  CUDA_ENTRY_ENUM(cuGraphMemsetNodeGetParams),
  /** cuGraphMemsetNodeSetParams */
  CUDA_ENTRY_ENUM(cuGraphMemsetNodeSetParams),
  /** cuGraphNodeFindInClone */
  CUDA_ENTRY_ENUM(cuGraphNodeFindInClone),
  /** cuGraphNodeGetDependencies */
  CUDA_ENTRY_ENUM(cuGraphNodeGetDependencies),
  /** cuGraphNodeGetDependentNodes */
  CUDA_ENTRY_ENUM(cuGraphNodeGetDependentNodes),
  /** cuGraphNodeGetType */
  CUDA_ENTRY_ENUM(cuGraphNodeGetType),
  /** cuGraphRemoveDependencies */
  CUDA_ENTRY_ENUM(cuGraphRemoveDependencies),
  /** cuImportExternalMemory */
  CUDA_ENTRY_ENUM(cuImportExternalMemory),
  /** cuImportExternalSemaphore */
  CUDA_ENTRY_ENUM(cuImportExternalSemaphore),
  /** cuLaunchHostFunc */
  CUDA_ENTRY_ENUM(cuLaunchHostFunc),
  /** cuLaunchHostFunc_ptsz */
  CUDA_ENTRY_ENUM(cuLaunchHostFunc_ptsz),
  /** cuSignalExternalSemaphoresAsync */
  CUDA_ENTRY_ENUM(cuSignalExternalSemaphoresAsync),
  /** cuSignalExternalSemaphoresAsync_ptsz */
  CUDA_ENTRY_ENUM(cuSignalExternalSemaphoresAsync_ptsz),
  /** cuStreamBeginCapture */
  CUDA_ENTRY_ENUM(cuStreamBeginCapture),
  /** cuStreamBeginCapture_ptsz */
  CUDA_ENTRY_ENUM(cuStreamBeginCapture_ptsz),
  /** cuStreamEndCapture */
  CUDA_ENTRY_ENUM(cuStreamEndCapture),
  /** cuStreamEndCapture_ptsz */
  CUDA_ENTRY_ENUM(cuStreamEndCapture_ptsz),
  /** cuStreamGetCtx */
  CUDA_ENTRY_ENUM(cuStreamGetCtx),
  /** cuStreamGetCtx_ptsz */
  CUDA_ENTRY_ENUM(cuStreamGetCtx_ptsz),
  /** cuStreamIsCapturing */
  CUDA_ENTRY_ENUM(cuStreamIsCapturing),
  /** cuStreamIsCapturing_ptsz */
  CUDA_ENTRY_ENUM(cuStreamIsCapturing_ptsz),
  /** cuWaitExternalSemaphoresAsync */
  CUDA_ENTRY_ENUM(cuWaitExternalSemaphoresAsync),
  /** cuWaitExternalSemaphoresAsync_ptsz */
  CUDA_ENTRY_ENUM(cuWaitExternalSemaphoresAsync_ptsz),
  /** cuGraphExecKernelNodeSetParams */
  CUDA_ENTRY_ENUM(cuGraphExecKernelNodeSetParams),
  /** cuStreamBeginCapture_v2 */
  CUDA_ENTRY_ENUM(cuStreamBeginCapture_v2),
  /** cuStreamBeginCapture_v2_ptsz */
  CUDA_ENTRY_ENUM(cuStreamBeginCapture_v2_ptsz),
  /** cuStreamGetCaptureInfo */
  CUDA_ENTRY_ENUM(cuStreamGetCaptureInfo),
  /** cuStreamGetCaptureInfo_ptsz */
  CUDA_ENTRY_ENUM(cuStreamGetCaptureInfo_ptsz),
  /** cuThreadExchangeStreamCaptureMode */
  CUDA_ENTRY_ENUM(cuThreadExchangeStreamCaptureMode),
  /** cuDeviceGetNvSciSyncAttributes */
  CUDA_ENTRY_ENUM(cuDeviceGetNvSciSyncAttributes),
  /** cuGraphExecHostNodeSetParams */
  CUDA_ENTRY_ENUM(cuGraphExecHostNodeSetParams),
  /** cuGraphExecMemcpyNodeSetParams */
  CUDA_ENTRY_ENUM(cuGraphExecMemcpyNodeSetParams),
  /** cuGraphExecMemsetNodeSetParams */
  CUDA_ENTRY_ENUM(cuGraphExecMemsetNodeSetParams),
  /** cuGraphExecUpdate */
  CUDA_ENTRY_ENUM(cuGraphExecUpdate),
  /** cuMemAddressFree */
  CUDA_ENTRY_ENUM(cuMemAddressFree),
  /** cuMemAddressReserve */
  CUDA_ENTRY_ENUM(cuMemAddressReserve),
  /** cuMemCreate */
  CUDA_ENTRY_ENUM(cuMemCreate),
  /** cuMemExportToShareableHandle */
  CUDA_ENTRY_ENUM(cuMemExportToShareableHandle),
  /** cuMemGetAccess */
  CUDA_ENTRY_ENUM(cuMemGetAccess),
  /** cuMemGetAllocationGranularity */
  CUDA_ENTRY_ENUM(cuMemGetAllocationGranularity),
  /** cuMemGetAllocationPropertiesFromHandle */
  CUDA_ENTRY_ENUM(cuMemGetAllocationPropertiesFromHandle),
  /** cuMemImportFromShareableHandle */
  CUDA_ENTRY_ENUM(cuMemImportFromShareableHandle),
  /** cuMemMap */
  CUDA_ENTRY_ENUM(cuMemMap),
  /** cuMemRelease */
  CUDA_ENTRY_ENUM(cuMemRelease),
  /** cuMemSetAccess */
  CUDA_ENTRY_ENUM(cuMemSetAccess),
  /** cuMemUnmap */
  CUDA_ENTRY_ENUM(cuMemUnmap),
  /** cuCtxResetPersistingL2Cache */
  CUDA_ENTRY_ENUM(cuCtxResetPersistingL2Cache),
  /** cuDevicePrimaryCtxRelease_v2 */
  CUDA_ENTRY_ENUM(cuDevicePrimaryCtxRelease_v2),
  /** cuDevicePrimaryCtxReset_v2 */
  CUDA_ENTRY_ENUM(cuDevicePrimaryCtxReset_v2),
  /** cuDevicePrimaryCtxSetFlags_v2 */
  CUDA_ENTRY_ENUM(cuDevicePrimaryCtxSetFlags_v2),
  /** cuFuncGetModule */
  CUDA_ENTRY_ENUM(cuFuncGetModule),
  /** cuGraphInstantiate_v2 */
  CUDA_ENTRY_ENUM(cuGraphInstantiate_v2),
  /** cuGraphKernelNodeCopyAttributes */
  CUDA_ENTRY_ENUM(cuGraphKernelNodeCopyAttributes),
  /** cuGraphKernelNodeGetAttribute */
  CUDA_ENTRY_ENUM(cuGraphKernelNodeGetAttribute),
  /** cuGraphKernelNodeSetAttribute */
  CUDA_ENTRY_ENUM(cuGraphKernelNodeSetAttribute),
  /** cuMemRetainAllocationHandle */
  CUDA_ENTRY_ENUM(cuMemRetainAllocationHandle),
  /** cuOccupancyAvailableDynamicSMemPerBlock */
  CUDA_ENTRY_ENUM(cuOccupancyAvailableDynamicSMemPerBlock),
  /** cuStreamCopyAttributes */
  CUDA_ENTRY_ENUM(cuStreamCopyAttributes),
  /** cuStreamCopyAttributes_ptsz */
  CUDA_ENTRY_ENUM(cuStreamCopyAttributes_ptsz),
  /** cuStreamGetAttribute */
  CUDA_ENTRY_ENUM(cuStreamGetAttribute),
  /** cuStreamGetAttribute_ptsz */
  CUDA_ENTRY_ENUM(cuStreamGetAttribute_ptsz),
  /** cuStreamSetAttribute */
  CUDA_ENTRY_ENUM(cuStreamSetAttribute),
  /** cuStreamSetAttribute_ptsz */
  CUDA_ENTRY_ENUM(cuStreamSetAttribute_ptsz),
  /** 11.2 */
  /** cuArrayGetPlane */
  CUDA_ENTRY_ENUM(cuArrayGetPlane),
  /** cuArrayGetSparseProperties */
  CUDA_ENTRY_ENUM(cuArrayGetSparseProperties),
  /** cuDeviceGetDefaultMemPool */
  CUDA_ENTRY_ENUM(cuDeviceGetDefaultMemPool),
  /** cuDeviceGetLuid */
  CUDA_ENTRY_ENUM(cuDeviceGetLuid),
  /** cuDeviceGetMemPool */
  CUDA_ENTRY_ENUM(cuDeviceGetMemPool),
  /** cuDeviceGetTexture1DLinearMaxWidth */
  CUDA_ENTRY_ENUM(cuDeviceGetTexture1DLinearMaxWidth),
  /** cuDeviceSetMemPool */
  CUDA_ENTRY_ENUM(cuDeviceSetMemPool),
  /** cuEventRecordWithFlags */
  CUDA_ENTRY_ENUM(cuEventRecordWithFlags),
  /** cuEventRecordWithFlags_ptsz */
  CUDA_ENTRY_ENUM(cuEventRecordWithFlags_ptsz),
  /** cuGraphAddEventRecordNode */
  CUDA_ENTRY_ENUM(cuGraphAddEventRecordNode),
  /** cuGraphAddEventWaitNode */
  CUDA_ENTRY_ENUM(cuGraphAddEventWaitNode),
  /** cuGraphAddExternalSemaphoresSignalNode */
  CUDA_ENTRY_ENUM(cuGraphAddExternalSemaphoresSignalNode),
  /** cuGraphAddExternalSemaphoresWaitNode */
  CUDA_ENTRY_ENUM(cuGraphAddExternalSemaphoresWaitNode),
  /** cuGraphEventRecordNodeGetEvent */
  CUDA_ENTRY_ENUM(cuGraphEventRecordNodeGetEvent),
  /** cuGraphEventRecordNodeSetEvent */
  CUDA_ENTRY_ENUM(cuGraphEventRecordNodeSetEvent),
  /** cuGraphEventWaitNodeGetEvent */
  CUDA_ENTRY_ENUM(cuGraphEventWaitNodeGetEvent),
  /** cuGraphEventWaitNodeSetEvent */
  CUDA_ENTRY_ENUM(cuGraphEventWaitNodeSetEvent),
  /** cuGraphExecChildGraphNodeSetParams */
  CUDA_ENTRY_ENUM(cuGraphExecChildGraphNodeSetParams),
  /** cuGraphExecEventRecordNodeSetEvent */
  CUDA_ENTRY_ENUM(cuGraphExecEventRecordNodeSetEvent),
  /** cuGraphExecEventWaitNodeSetEvent */
  CUDA_ENTRY_ENUM(cuGraphExecEventWaitNodeSetEvent),
  /** cuGraphExecExternalSemaphoresSignalNodeSetParams */
  CUDA_ENTRY_ENUM(cuGraphExecExternalSemaphoresSignalNodeSetParams),
  /** cuGraphExecExternalSemaphoresWaitNodeSetParams */
  CUDA_ENTRY_ENUM(cuGraphExecExternalSemaphoresWaitNodeSetParams),
  /** cuGraphExternalSemaphoresSignalNodeGetParams */
  CUDA_ENTRY_ENUM(cuGraphExternalSemaphoresSignalNodeGetParams),
  /** cuGraphExternalSemaphoresSignalNodeSetParams */
  CUDA_ENTRY_ENUM(cuGraphExternalSemaphoresSignalNodeSetParams),
  /** cuGraphExternalSemaphoresWaitNodeGetParams */
  CUDA_ENTRY_ENUM(cuGraphExternalSemaphoresWaitNodeGetParams),
  /** cuGraphExternalSemaphoresWaitNodeSetParams */
  CUDA_ENTRY_ENUM(cuGraphExternalSemaphoresWaitNodeSetParams),
  /** cuGraphUpload */
  CUDA_ENTRY_ENUM(cuGraphUpload),
  /** cuGraphUpload_ptsz */
  CUDA_ENTRY_ENUM(cuGraphUpload_ptsz),
  /** cuIpcOpenMemHandle_v2 */
  CUDA_ENTRY_ENUM(cuIpcOpenMemHandle_v2),
  /** memory pool should be concerned ? */
  /** cuMemAllocAsync */
  CUDA_ENTRY_ENUM(cuMemAllocAsync),
  /** cuMemAllocAsync_ptsz */
  CUDA_ENTRY_ENUM(cuMemAllocAsync_ptsz),
  /** cuMemAllocFromPoolAsync */
  CUDA_ENTRY_ENUM(cuMemAllocFromPoolAsync),
  /** cuMemAllocFromPoolAsync_ptsz */
  CUDA_ENTRY_ENUM(cuMemAllocFromPoolAsync_ptsz),
  /** cuMemFreeAsync */
  CUDA_ENTRY_ENUM(cuMemFreeAsync),
  /** cuMemFreeAsync_ptsz */
  CUDA_ENTRY_ENUM(cuMemFreeAsync_ptsz),
  /** cuMemMapArrayAsync */
  CUDA_ENTRY_ENUM(cuMemMapArrayAsync),
  /** cuMemMapArrayAsync_ptsz */
  CUDA_ENTRY_ENUM(cuMemMapArrayAsync_ptsz),
  /** cuMemPoolCreate */
  CUDA_ENTRY_ENUM(cuMemPoolCreate),
  /** cuMemPoolDestroy */
  CUDA_ENTRY_ENUM(cuMemPoolDestroy),
  /** cuMemPoolExportPointer */
  CUDA_ENTRY_ENUM(cuMemPoolExportPointer),
  /** cuMemPoolExportToShareableHandle */
  CUDA_ENTRY_ENUM(cuMemPoolExportToShareableHandle),
  /** cuMemPoolGetAccess */
  CUDA_ENTRY_ENUM(cuMemPoolGetAccess),
  /** cuMemPoolGetAttribute */
  CUDA_ENTRY_ENUM(cuMemPoolGetAttribute),
  /** cuMemPoolImportFromShareableHandle */
  CUDA_ENTRY_ENUM(cuMemPoolImportFromShareableHandle),
  /** cuMemPoolImportPointer */
  CUDA_ENTRY_ENUM(cuMemPoolImportPointer),
  /** cuMemPoolSetAccess */
  CUDA_ENTRY_ENUM(cuMemPoolSetAccess),
  /** cuMemPoolSetAttribute */
  CUDA_ENTRY_ENUM(cuMemPoolSetAttribute),
  /** cuMemPoolTrimTo */
  CUDA_ENTRY_ENUM(cuMemPoolTrimTo),
  /** cuMipmappedArrayGetSparseProperties */
  CUDA_ENTRY_ENUM(cuMipmappedArrayGetSparseProperties),
  CUDA_ENTRY_ENUM(cuCtxCreate_v3),
  CUDA_ENTRY_ENUM(cuCtxGetExecAffinity),
  CUDA_ENTRY_ENUM(cuDeviceGetExecAffinitySupport),
  CUDA_ENTRY_ENUM(cuDeviceGetGraphMemAttribute),
  CUDA_ENTRY_ENUM(cuDeviceGetUuid_v2),
  CUDA_ENTRY_ENUM(cuDeviceGraphMemTrim),
  CUDA_ENTRY_ENUM(cuDeviceSetGraphMemAttribute),
  CUDA_ENTRY_ENUM(cuFlushGPUDirectRDMAWrites),
  CUDA_ENTRY_ENUM(cuGetProcAddress),
  CUDA_ENTRY_ENUM(cuGraphAddMemAllocNode),
  CUDA_ENTRY_ENUM(cuGraphAddMemFreeNode),
  CUDA_ENTRY_ENUM(cuGraphDebugDotPrint),
  CUDA_ENTRY_ENUM(cuGraphInstantiateWithFlags),
  CUDA_ENTRY_ENUM(cuGraphMemAllocNodeGetParams),
  CUDA_ENTRY_ENUM(cuGraphMemFreeNodeGetParams),
  CUDA_ENTRY_ENUM(cuGraphReleaseUserObject),
  CUDA_ENTRY_ENUM(cuGraphRetainUserObject),
  CUDA_ENTRY_ENUM(cuStreamGetCaptureInfo_v2),
  CUDA_ENTRY_ENUM(cuStreamGetCaptureInfo_v2_ptsz),
  CUDA_ENTRY_ENUM(cuStreamUpdateCaptureDependencies),
  CUDA_ENTRY_ENUM(cuStreamUpdateCaptureDependencies_ptsz),
  CUDA_ENTRY_ENUM(cuUserObjectCreate),
  CUDA_ENTRY_ENUM(cuUserObjectRelease),
  CUDA_ENTRY_ENUM(cuUserObjectRetain),
  CUDA_ENTRY_END
} cuda_entry_enum_t;

/**
 * CUDA library function pointer
 */
typedef CUresult (*cuda_sym_t)();

/**
 * CUDA library debug function pointer
 */
typedef void (*cuda_debug_void_sym_t)();

/**
 * CUDA library debug result function pointer
 */
typedef CUDBGResult (*cuda_debug_result_sym_t)();

#ifdef __cplusplus
}
#endif

#endif // HIJACK_CUDA_HELPER_H
