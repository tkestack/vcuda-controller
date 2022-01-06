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

//
// Created by thomas on 18-4-16.
//
#include <assert.h>

#include "include/cuda-helper.h"
#include "include/hijack.h"

extern entry_t cuda_library_entry[];

CUresult cuDeviceGet(CUdevice *device, int ordinal) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGet, device, ordinal);
}

CUresult cuDeviceGetCount(int *count) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetCount, count);
}

CUresult cuDeviceGetName(char *name, int len, CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetName, name, len, dev);
}

CUresult cuDeviceGetP2PAttribute(int *value, CUdevice_P2PAttribute attrib,
                                 CUdevice srcDevice, CUdevice dstDevice) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetP2PAttribute, value,
                         attrib, srcDevice, dstDevice);
}

CUresult cuDeviceGetByPCIBusId(CUdevice *dev, const char *pciBusId) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetByPCIBusId, dev,
                         pciBusId);
}

CUresult cuDeviceGetPCIBusId(char *pciBusId, int len, CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetPCIBusId, pciBusId, len,
                         dev);
}

CUresult cuDevicePrimaryCtxRetain(CUcontext *pctx, CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxRetain, pctx,
                         dev);
}

CUresult cuDevicePrimaryCtxRelease(CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxRelease, dev);
}

CUresult cuDevicePrimaryCtxSetFlags(CUdevice dev, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxSetFlags, dev,
                         flags);
}

CUresult cuDevicePrimaryCtxGetState(CUdevice dev, unsigned int *flags,
                                    int *active) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxGetState, dev,
                         flags, active);
}

CUresult cuDevicePrimaryCtxReset(CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxReset, dev);
}

CUresult cuCtxCreate_v3(CUcontext *pctx, unsigned int flags, CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxCreate_v3, pctx, flags, dev);
}

CUresult cuCtxCreate_v2(CUcontext *pctx, unsigned int flags, CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxCreate_v2, pctx, flags, dev);
}

CUresult cuCtxCreate(CUcontext *pctx, unsigned int flags, CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxCreate, pctx, flags, dev);
}

CUresult cuCtxGetFlags(unsigned int *flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetFlags, flags);
}

CUresult cuCtxSetCurrent(CUcontext ctx) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetCurrent, ctx);
}

CUresult cuCtxGetCurrent(CUcontext *pctx) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetCurrent, pctx);
}

CUresult cuCtxDetach(CUcontext ctx) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxDetach, ctx);
}

CUresult cuCtxGetApiVersion(CUcontext ctx, unsigned int *version) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetApiVersion, ctx, version);
}

CUresult cuCtxGetDevice(CUdevice *device) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetDevice, device);
}

CUresult cuCtxGetLimit(size_t *pvalue, CUlimit limit) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetLimit, pvalue, limit);
}

CUresult cuCtxGetCacheConfig(CUfunc_cache *pconfig) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetCacheConfig, pconfig);
}

CUresult cuCtxSetCacheConfig(CUfunc_cache config) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetCacheConfig, config);
}

CUresult cuCtxGetSharedMemConfig(CUsharedconfig *pConfig) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetSharedMemConfig, pConfig);
}

CUresult cuCtxGetStreamPriorityRange(int *leastPriority,
                                     int *greatestPriority) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetStreamPriorityRange,
                         leastPriority, greatestPriority);
}

CUresult cuCtxSetSharedMemConfig(CUsharedconfig config) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetSharedMemConfig, config);
}

CUresult cuCtxSynchronize(void) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSynchronize);
}

CUresult cuModuleUnload(CUmodule hmod) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleUnload, hmod);
}

CUresult cuModuleGetFunction(CUfunction *hfunc, CUmodule hmod,
                             const char *name) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetFunction, hfunc, hmod,
                         name);
}

CUresult cuModuleGetGlobal_v2(CUdeviceptr *dptr, size_t *bytes, CUmodule hmod,
                              const char *name) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetGlobal_v2, dptr, bytes,
                         hmod, name);
}

CUresult cuModuleGetGlobal(CUdeviceptr *dptr, size_t *bytes, CUmodule hmod,
                           const char *name) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetGlobal, dptr, bytes,
                         hmod, name);
}

CUresult cuModuleGetTexRef(CUtexref *pTexRef, CUmodule hmod, const char *name) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetTexRef, pTexRef, hmod,
                         name);
}

CUresult cuModuleGetSurfRef(CUsurfref *pSurfRef, CUmodule hmod,
                            const char *name) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetSurfRef, pSurfRef, hmod,
                         name);
}

CUresult cuLinkCreate_v2(unsigned int numOptions, CUjit_option *options,
                         void **optionValues, CUlinkState *stateOut) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkCreate_v2, numOptions,
                         options, optionValues, stateOut);
}

CUresult cuLinkCreate(unsigned int numOptions, CUjit_option *options,
                      void **optionValues, CUlinkState *stateOut) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkCreate, numOptions, options,
                         optionValues, stateOut);
}

CUresult cuLinkAddData_v2(CUlinkState state, CUjitInputType type, void *data,
                          size_t size, const char *name,
                          unsigned int numOptions, CUjit_option *options,
                          void **optionValues) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkAddData_v2, state, type,
                         data, size, name, numOptions, options, optionValues);
}

CUresult cuLinkAddData(CUlinkState state, CUjitInputType type, void *data,
                       size_t size, const char *name, unsigned int numOptions,
                       CUjit_option *options, void **optionValues) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkAddData, state, type, data,
                         size, name, numOptions, options, optionValues);
}

CUresult cuLinkAddFile_v2(CUlinkState state, CUjitInputType type,
                          const char *path, unsigned int numOptions,
                          CUjit_option *options, void **optionValues) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkAddFile_v2, state, type,
                         path, numOptions, options, optionValues);
}

CUresult cuLinkAddFile(CUlinkState state, CUjitInputType type, const char *path,
                       unsigned int numOptions, CUjit_option *options,
                       void **optionValues) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkAddFile, state, type, path,
                         numOptions, options, optionValues);
}

CUresult cuLinkComplete(CUlinkState state, void **cubinOut, size_t *sizeOut) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkComplete, state, cubinOut,
                         sizeOut);
}

CUresult cuLinkDestroy(CUlinkState state) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkDestroy, state);
}

CUresult cuMemFree_v2(CUdeviceptr dptr) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemFree_v2, dptr);
}

CUresult cuMemFree(CUdeviceptr dptr) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemFree, dptr);
}

CUresult cuMemGetAddressRange_v2(CUdeviceptr *pbase, size_t *psize,
                                 CUdeviceptr dptr) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetAddressRange_v2, pbase,
                         psize, dptr);
}

CUresult cuMemGetAddressRange(CUdeviceptr *pbase, size_t *psize,
                              CUdeviceptr dptr) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetAddressRange, pbase, psize,
                         dptr);
}

CUresult cuMemFreeHost(void *p) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemFreeHost, p);
}

CUresult cuMemHostAlloc(void **pp, size_t bytesize, unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostAlloc, pp, bytesize,
                         Flags);
}

CUresult cuMemHostGetDevicePointer_v2(CUdeviceptr *pdptr, void *p,
                                      unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostGetDevicePointer_v2,
                         pdptr, p, Flags);
}

CUresult cuMemHostGetDevicePointer(CUdeviceptr *pdptr, void *p,
                                   unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostGetDevicePointer, pdptr,
                         p, Flags);
}

CUresult cuMemHostGetFlags(unsigned int *pFlags, void *p) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostGetFlags, pFlags, p);
}

CUresult cuMemHostRegister_v2(void *p, size_t bytesize, unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostRegister_v2, p, bytesize,
                         Flags);
}

CUresult cuMemHostRegister(void *p, size_t bytesize, unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostRegister, p, bytesize,
                         Flags);
}

CUresult cuMemHostUnregister(void *p) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostUnregister, p);
}

CUresult cuPointerGetAttribute(void *data, CUpointer_attribute attribute,
                               CUdeviceptr ptr) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuPointerGetAttribute, data,
                         attribute, ptr);
}

CUresult cuPointerGetAttributes(unsigned int numAttributes,
                                CUpointer_attribute *attributes, void **data,
                                CUdeviceptr ptr) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuPointerGetAttributes,
                         numAttributes, attributes, data, ptr);
}

CUresult cuMemcpy_ptds(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy_ptds, dst, src,
                         ByteCount);
}

CUresult cuMemcpy(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy, dst, src, ByteCount);
}

CUresult cuMemcpyAsync_ptsz(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount,
                            CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAsync_ptsz, dst, src,
                         ByteCount, hStream);
}

CUresult cuMemcpyAsync(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount,
                       CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAsync, dst, src, ByteCount,
                         hStream);
}

CUresult cuMemcpyPeer_ptds(CUdeviceptr dstDevice, CUcontext dstContext,
                           CUdeviceptr srcDevice, CUcontext srcContext,
                           size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyPeer_ptds, dstDevice,
                         dstContext, srcDevice, srcContext, ByteCount);
}

CUresult cuMemcpyPeer(CUdeviceptr dstDevice, CUcontext dstContext,
                      CUdeviceptr srcDevice, CUcontext srcContext,
                      size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyPeer, dstDevice,
                         dstContext, srcDevice, srcContext, ByteCount);
}

CUresult cuMemcpyPeerAsync_ptsz(CUdeviceptr dstDevice, CUcontext dstContext,
                                CUdeviceptr srcDevice, CUcontext srcContext,
                                size_t ByteCount, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyPeerAsync_ptsz, dstDevice,
                         dstContext, srcDevice, srcContext, ByteCount, hStream);
}

CUresult cuMemcpyPeerAsync(CUdeviceptr dstDevice, CUcontext dstContext,
                           CUdeviceptr srcDevice, CUcontext srcContext,
                           size_t ByteCount, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyPeerAsync, dstDevice,
                         dstContext, srcDevice, srcContext, ByteCount, hStream);
}

CUresult cuMemcpyHtoD_v2_ptds(CUdeviceptr dstDevice, const void *srcHost,
                              size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoD_v2_ptds, dstDevice,
                         srcHost, ByteCount);
}

CUresult cuMemcpyHtoD_v2(CUdeviceptr dstDevice, const void *srcHost,
                         size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoD_v2, dstDevice,
                         srcHost, ByteCount);
}

CUresult cuMemcpyHtoD(CUdeviceptr dstDevice, const void *srcHost,
                      size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoD, dstDevice, srcHost,
                         ByteCount);
}

CUresult cuMemcpyHtoDAsync_v2_ptsz(CUdeviceptr dstDevice, const void *srcHost,
                                   size_t ByteCount, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoDAsync_v2_ptsz,
                         dstDevice, srcHost, ByteCount, hStream);
}

CUresult cuMemcpyHtoDAsync_v2(CUdeviceptr dstDevice, const void *srcHost,
                              size_t ByteCount, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoDAsync_v2, dstDevice,
                         srcHost, ByteCount, hStream);
}

CUresult cuMemcpyHtoDAsync(CUdeviceptr dstDevice, const void *srcHost,
                           size_t ByteCount, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoDAsync, dstDevice,
                         srcHost, ByteCount, hStream);
}

CUresult cuMemcpyDtoH_v2_ptds(void *dstHost, CUdeviceptr srcDevice,
                              size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoH_v2_ptds, dstHost,
                         srcDevice, ByteCount);
}

CUresult cuMemcpyDtoH_v2(void *dstHost, CUdeviceptr srcDevice,
                         size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoH_v2, dstHost,
                         srcDevice, ByteCount);
}

CUresult cuMemcpyDtoH(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoH, dstHost, srcDevice,
                         ByteCount);
}

CUresult cuMemcpyDtoHAsync_v2_ptsz(void *dstHost, CUdeviceptr srcDevice,
                                   size_t ByteCount, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoHAsync_v2_ptsz, dstHost,
                         srcDevice, ByteCount, hStream);
}

CUresult cuMemcpyDtoHAsync_v2(void *dstHost, CUdeviceptr srcDevice,
                              size_t ByteCount, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoHAsync_v2, dstHost,
                         srcDevice, ByteCount, hStream);
}

CUresult cuMemcpyDtoHAsync(void *dstHost, CUdeviceptr srcDevice,
                           size_t ByteCount, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoHAsync, dstHost,
                         srcDevice, ByteCount, hStream);
}

CUresult cuMemcpyDtoD_v2_ptds(CUdeviceptr dstDevice, CUdeviceptr srcDevice,
                              size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoD_v2_ptds, dstDevice,
                         srcDevice, ByteCount);
}

CUresult cuMemcpyDtoD_v2(CUdeviceptr dstDevice, CUdeviceptr srcDevice,
                         size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoD_v2, dstDevice,
                         srcDevice, ByteCount);
}

CUresult cuMemcpyDtoD(CUdeviceptr dstDevice, CUdeviceptr srcDevice,
                      size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoD, dstDevice, srcDevice,
                         ByteCount);
}

CUresult cuMemcpyDtoDAsync_v2_ptsz(CUdeviceptr dstDevice, CUdeviceptr srcDevice,
                                   size_t ByteCount, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoDAsync_v2_ptsz,
                         dstDevice, srcDevice, ByteCount, hStream);
}

CUresult cuMemcpyDtoDAsync_v2(CUdeviceptr dstDevice, CUdeviceptr srcDevice,
                              size_t ByteCount, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoDAsync_v2, dstDevice,
                         srcDevice, ByteCount, hStream);
}

CUresult cuMemcpyDtoDAsync(CUdeviceptr dstDevice, CUdeviceptr srcDevice,
                           size_t ByteCount, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoDAsync, dstDevice,
                         srcDevice, ByteCount, hStream);
}

CUresult cuMemcpy2DUnaligned_v2_ptds(const CUDA_MEMCPY2D *pCopy) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DUnaligned_v2_ptds,
                         pCopy);
}

CUresult cuMemcpy2DUnaligned_v2(const CUDA_MEMCPY2D *pCopy) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DUnaligned_v2, pCopy);
}

CUresult cuMemcpy2DUnaligned(const CUDA_MEMCPY2D *pCopy) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DUnaligned, pCopy);
}

CUresult cuMemcpy2DAsync_v2_ptsz(const CUDA_MEMCPY2D *pCopy, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DAsync_v2_ptsz, pCopy,
                         hStream);
}

CUresult cuMemcpy2DAsync_v2(const CUDA_MEMCPY2D *pCopy, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DAsync_v2, pCopy,
                         hStream);
}

CUresult cuMemcpy2DAsync(const CUDA_MEMCPY2D *pCopy, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DAsync, pCopy, hStream);
}

CUresult cuMemcpy3D_v2_ptds(const CUDA_MEMCPY3D *pCopy) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3D_v2_ptds, pCopy);
}

CUresult cuMemcpy3D_v2(const CUDA_MEMCPY3D *pCopy) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3D_v2, pCopy);
}

CUresult cuMemcpy3D(const CUDA_MEMCPY3D *pCopy) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3D, pCopy);
}

CUresult cuMemcpy3DAsync_v2_ptsz(const CUDA_MEMCPY3D *pCopy, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DAsync_v2_ptsz, pCopy,
                         hStream);
}

CUresult cuMemcpy3DAsync_v2(const CUDA_MEMCPY3D *pCopy, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DAsync_v2, pCopy,
                         hStream);
}

CUresult cuMemcpy3DAsync(const CUDA_MEMCPY3D *pCopy, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DAsync, pCopy, hStream);
}

CUresult cuMemcpy3DPeer_ptds(const CUDA_MEMCPY3D_PEER *pCopy) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DPeer_ptds, pCopy);
}

CUresult cuMemcpy3DPeer(const CUDA_MEMCPY3D_PEER *pCopy) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DPeer, pCopy);
}

CUresult cuMemcpy3DPeerAsync_ptsz(const CUDA_MEMCPY3D_PEER *pCopy,
                                  CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DPeerAsync_ptsz, pCopy,
                         hStream);
}

CUresult cuMemcpy3DPeerAsync(const CUDA_MEMCPY3D_PEER *pCopy,
                             CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DPeerAsync, pCopy,
                         hStream);
}

CUresult cuMemsetD8_v2_ptds(CUdeviceptr dstDevice, unsigned char uc, size_t N) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD8_v2_ptds, dstDevice, uc,
                         N);
}

CUresult cuMemsetD8_v2(CUdeviceptr dstDevice, unsigned char uc, size_t N) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD8_v2, dstDevice, uc, N);
}

CUresult cuMemsetD8(CUdeviceptr dstDevice, unsigned char uc, size_t N) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD8, dstDevice, uc, N);
}

CUresult cuMemsetD8Async_ptsz(CUdeviceptr dstDevice, unsigned char uc, size_t N,
                              CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD8Async_ptsz, dstDevice,
                         uc, N, hStream);
}

CUresult cuMemsetD8Async(CUdeviceptr dstDevice, unsigned char uc, size_t N,
                         CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD8Async, dstDevice, uc, N,
                         hStream);
}

CUresult cuMemsetD2D8_v2_ptds(CUdeviceptr dstDevice, size_t dstPitch,
                              unsigned char uc, size_t Width, size_t Height) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D8_v2_ptds, dstDevice,
                         dstPitch, uc, Width, Height);
}

CUresult cuMemsetD2D8_v2(CUdeviceptr dstDevice, size_t dstPitch,
                         unsigned char uc, size_t Width, size_t Height) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D8_v2, dstDevice,
                         dstPitch, uc, Width, Height);
}

CUresult cuMemsetD2D8(CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc,
                      size_t Width, size_t Height) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D8, dstDevice, dstPitch,
                         uc, Width, Height);
}

CUresult cuMemsetD2D8Async_ptsz(CUdeviceptr dstDevice, size_t dstPitch,
                                unsigned char uc, size_t Width, size_t Height,
                                CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D8Async_ptsz, dstDevice,
                         dstPitch, uc, Width, Height, hStream);
}

CUresult cuMemsetD2D8Async(CUdeviceptr dstDevice, size_t dstPitch,
                           unsigned char uc, size_t Width, size_t Height,
                           CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D8Async, dstDevice,
                         dstPitch, uc, Width, Height, hStream);
}

CUresult cuFuncSetCacheConfig(CUfunction hfunc, CUfunc_cache config) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetCacheConfig, hfunc,
                         config);
}

CUresult cuFuncSetSharedMemConfig(CUfunction hfunc, CUsharedconfig config) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetSharedMemConfig, hfunc,
                         config);
}

CUresult cuFuncGetAttribute(int *pi, CUfunction_attribute attrib,
                            CUfunction hfunc) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncGetAttribute, pi, attrib,
                         hfunc);
}

CUresult cuArrayGetDescriptor_v2(CUDA_ARRAY_DESCRIPTOR *pArrayDescriptor,
                                 CUarray hArray) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayGetDescriptor_v2,
                         pArrayDescriptor, hArray);
}

CUresult cuArrayGetDescriptor(CUDA_ARRAY_DESCRIPTOR *pArrayDescriptor,
                              CUarray hArray) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayGetDescriptor,
                         pArrayDescriptor, hArray);
}

CUresult cuArray3DGetDescriptor_v2(CUDA_ARRAY3D_DESCRIPTOR *pArrayDescriptor,
                                   CUarray hArray) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuArray3DGetDescriptor_v2,
                         pArrayDescriptor, hArray);
}

CUresult cuArray3DGetDescriptor(CUDA_ARRAY3D_DESCRIPTOR *pArrayDescriptor,
                                CUarray hArray) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuArray3DGetDescriptor,
                         pArrayDescriptor, hArray);
}

CUresult cuArrayDestroy(CUarray hArray) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayDestroy, hArray);
}

CUresult cuMipmappedArrayGetLevel(CUarray *pLevelArray,
                                  CUmipmappedArray hMipmappedArray,
                                  unsigned int level) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMipmappedArrayGetLevel,
                         pLevelArray, hMipmappedArray, level);
}

CUresult cuMipmappedArrayDestroy(CUmipmappedArray hMipmappedArray) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMipmappedArrayDestroy,
                         hMipmappedArray);
}

CUresult cuTexRefCreate(CUtexref *pTexRef) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefCreate, pTexRef);
}

CUresult cuTexRefDestroy(CUtexref hTexRef) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefDestroy, hTexRef);
}

CUresult cuTexRefSetArray(CUtexref hTexRef, CUarray hArray,
                          unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetArray, hTexRef, hArray,
                         Flags);
}

CUresult cuTexRefSetMipmappedArray(CUtexref hTexRef,
                                   CUmipmappedArray hMipmappedArray,
                                   unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMipmappedArray, hTexRef,
                         hMipmappedArray, Flags);
}

CUresult cuTexRefSetAddress_v2(size_t *ByteOffset, CUtexref hTexRef,
                               CUdeviceptr dptr, size_t bytes) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddress_v2, ByteOffset,
                         hTexRef, dptr, bytes);
}

CUresult cuTexRefSetAddress2D_v3(CUtexref hTexRef,
                                 const CUDA_ARRAY_DESCRIPTOR *desc,
                                 CUdeviceptr dptr, size_t Pitch) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddress2D_v3, hTexRef,
                         desc, dptr, Pitch);
}

CUresult cuTexRefSetAddress2D_v2(CUtexref hTexRef,
                                 const CUDA_ARRAY_DESCRIPTOR *desc,
                                 CUdeviceptr dptr, size_t Pitch) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddress2D_v2, hTexRef,
                         desc, dptr, Pitch);
}

CUresult cuTexRefSetAddress2D(CUtexref hTexRef,
                              const CUDA_ARRAY_DESCRIPTOR *desc,
                              CUdeviceptr dptr, size_t Pitch) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddress2D, hTexRef,
                         desc, dptr, Pitch);
}

CUresult cuTexRefSetFormat(CUtexref hTexRef, CUarray_format fmt,
                           int NumPackedComponents) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetFormat, hTexRef, fmt,
                         NumPackedComponents);
}

CUresult cuTexRefSetAddressMode(CUtexref hTexRef, int dim, CUaddress_mode am) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddressMode, hTexRef,
                         dim, am);
}

CUresult cuTexRefSetFilterMode(CUtexref hTexRef, CUfilter_mode fm) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetFilterMode, hTexRef,
                         fm);
}

CUresult cuTexRefSetMipmapFilterMode(CUtexref hTexRef, CUfilter_mode fm) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMipmapFilterMode,
                         hTexRef, fm);
}

CUresult cuTexRefSetMipmapLevelBias(CUtexref hTexRef, float bias) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMipmapLevelBias,
                         hTexRef, bias);
}

CUresult cuTexRefSetMipmapLevelClamp(CUtexref hTexRef,
                                     float minMipmapLevelClamp,
                                     float maxMipmapLevelClamp) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMipmapLevelClamp,
                         hTexRef, minMipmapLevelClamp, maxMipmapLevelClamp);
}

CUresult cuTexRefSetMaxAnisotropy(CUtexref hTexRef, unsigned int maxAniso) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMaxAnisotropy, hTexRef,
                         maxAniso);
}

CUresult cuTexRefSetFlags(CUtexref hTexRef, unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetFlags, hTexRef, Flags);
}

CUresult cuTexRefSetBorderColor(CUtexref hTexRef, float *pBorderColor) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetBorderColor, hTexRef,
                         pBorderColor);
}

CUresult cuTexRefGetBorderColor(float *pBorderColor, CUtexref hTexRef) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetBorderColor,
                         pBorderColor, hTexRef);
}

CUresult cuSurfRefSetArray(CUsurfref hSurfRef, CUarray hArray,
                           unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfRefSetArray, hSurfRef,
                         hArray, Flags);
}

CUresult cuTexObjectCreate(CUtexObject *pTexObject,
                           const CUDA_RESOURCE_DESC *pResDesc,
                           const CUDA_TEXTURE_DESC *pTexDesc,
                           const CUDA_RESOURCE_VIEW_DESC *pResViewDesc) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectCreate, pTexObject,
                         pResDesc, pTexDesc, pResViewDesc);
}

CUresult cuTexObjectDestroy(CUtexObject texObject) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectDestroy, texObject);
}

CUresult cuTexObjectGetResourceDesc(CUDA_RESOURCE_DESC *pResDesc,
                                    CUtexObject texObject) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectGetResourceDesc,
                         pResDesc, texObject);
}

CUresult cuTexObjectGetTextureDesc(CUDA_TEXTURE_DESC *pTexDesc,
                                   CUtexObject texObject) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectGetTextureDesc,
                         pTexDesc, texObject);
}

CUresult cuTexObjectGetResourceViewDesc(CUDA_RESOURCE_VIEW_DESC *pResViewDesc,
                                        CUtexObject texObject) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectGetResourceViewDesc,
                         pResViewDesc, texObject);
}

CUresult cuSurfObjectCreate(CUsurfObject *pSurfObject,
                            const CUDA_RESOURCE_DESC *pResDesc) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfObjectCreate, pSurfObject,
                         pResDesc);
}

CUresult cuSurfObjectDestroy(CUsurfObject surfObject) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfObjectDestroy, surfObject);
}

CUresult cuSurfObjectGetResourceDesc(CUDA_RESOURCE_DESC *pResDesc,
                                     CUsurfObject surfObject) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfObjectGetResourceDesc,
                         pResDesc, surfObject);
}

CUresult cuEventCreate(CUevent *phEvent, unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEventCreate, phEvent, Flags);
}

CUresult cuEventRecord(CUevent hEvent, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEventRecord, hEvent, hStream);
}

CUresult cuEventRecord_ptsz(CUevent hEvent, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEventRecord_ptsz, hEvent,
                         hStream);
}

CUresult cuEventQuery(CUevent hEvent) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEventQuery, hEvent);
}

CUresult cuEventSynchronize(CUevent hEvent) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEventSynchronize, hEvent);
}

CUresult cuEventDestroy_v2(CUevent hEvent) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEventDestroy_v2, hEvent);
}

CUresult cuEventDestroy(CUevent hEvent) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEventDestroy, hEvent);
}

CUresult cuEventElapsedTime(float *pMilliseconds, CUevent hStart,
                            CUevent hEnd) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEventElapsedTime, pMilliseconds,
                         hStart, hEnd);
}

CUresult cuStreamWaitValue32(CUstream stream, CUdeviceptr addr,
                             cuuint32_t value, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitValue32, stream, addr,
                         value, flags);
}

CUresult cuStreamWaitValue32_ptsz(CUstream stream, CUdeviceptr addr,
                                  cuuint32_t value, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitValue32_ptsz, stream,
                         addr, value, flags);
}

CUresult cuStreamWriteValue32(CUstream stream, CUdeviceptr addr,
                              cuuint32_t value, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWriteValue32, stream, addr,
                         value, flags);
}

CUresult cuStreamWriteValue32_ptsz(CUstream stream, CUdeviceptr addr,
                                   cuuint32_t value, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWriteValue32_ptsz, stream,
                         addr, value, flags);
}

CUresult cuStreamBatchMemOp(CUstream stream, unsigned int count,
                            CUstreamBatchMemOpParams *paramArray,
                            unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBatchMemOp, stream, count,
                         paramArray, flags);
}

CUresult cuStreamBatchMemOp_ptsz(CUstream stream, unsigned int count,
                                 CUstreamBatchMemOpParams *paramArray,
                                 unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBatchMemOp_ptsz, stream,
                         count, paramArray, flags);
}

CUresult cuStreamCreate(CUstream *phStream, unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamCreate, phStream, Flags);
}

CUresult cuStreamCreateWithPriority(CUstream *phStream, unsigned int flags,
                                    int priority) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamCreateWithPriority,
                         phStream, flags, priority);
}

CUresult cuStreamGetPriority(CUstream hStream, int *priority) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetPriority, hStream,
                         priority);
}

CUresult cuStreamGetPriority_ptsz(CUstream hStream, int *priority) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetPriority_ptsz, hStream,
                         priority);
}

CUresult cuStreamGetFlags(CUstream hStream, unsigned int *flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetFlags, hStream, flags);
}

CUresult cuStreamGetFlags_ptsz(CUstream hStream, unsigned int *flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetFlags_ptsz, hStream,
                         flags);
}

CUresult cuStreamDestroy_v2(CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamDestroy_v2, hStream);
}

CUresult cuStreamDestroy(CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamDestroy, hStream);
}

CUresult cuStreamWaitEvent(CUstream hStream, CUevent hEvent,
                           unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitEvent, hStream, hEvent,
                         Flags);
}

CUresult cuStreamWaitEvent_ptsz(CUstream hStream, CUevent hEvent,
                                unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitEvent_ptsz, hStream,
                         hEvent, Flags);
}

CUresult cuStreamAddCallback(CUstream hStream, CUstreamCallback callback,
                             void *userData, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamAddCallback, hStream,
                         callback, userData, flags);
}

CUresult cuStreamAddCallback_ptsz(CUstream hStream, CUstreamCallback callback,
                                  void *userData, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamAddCallback_ptsz, hStream,
                         callback, userData, flags);
}

CUresult cuStreamSynchronize(CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamSynchronize, hStream);
}

CUresult cuStreamSynchronize_ptsz(CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamSynchronize_ptsz, hStream);
}

CUresult cuStreamQuery(CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamQuery, hStream);
}

CUresult cuStreamQuery_ptsz(CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamQuery_ptsz, hStream);
}

CUresult cuStreamAttachMemAsync(CUstream hStream, CUdeviceptr dptr,
                                size_t length, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamAttachMemAsync, hStream,
                         dptr, length, flags);
}

CUresult cuStreamAttachMemAsync_ptsz(CUstream hStream, CUdeviceptr dptr,
                                     size_t length, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamAttachMemAsync_ptsz,
                         hStream, dptr, length, flags);
}

CUresult cuDeviceCanAccessPeer(int *canAccessPeer, CUdevice dev,
                               CUdevice peerDev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceCanAccessPeer,
                         canAccessPeer, dev, peerDev);
}

CUresult cuCtxEnablePeerAccess(CUcontext peerContext, unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxEnablePeerAccess, peerContext,
                         Flags);
}

CUresult cuCtxDisablePeerAccess(CUcontext peerContext) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxDisablePeerAccess,
                         peerContext);
}

CUresult cuIpcGetEventHandle(CUipcEventHandle *pHandle, CUevent event) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcGetEventHandle, pHandle,
                         event);
}

CUresult cuIpcOpenEventHandle(CUevent *phEvent, CUipcEventHandle handle) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcOpenEventHandle, phEvent,
                         handle);
}

CUresult cuIpcGetMemHandle(CUipcMemHandle *pHandle, CUdeviceptr dptr) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcGetMemHandle, pHandle, dptr);
}

CUresult cuIpcOpenMemHandle(CUdeviceptr *pdptr, CUipcMemHandle handle,
                            unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcOpenMemHandle, pdptr, handle,
                         Flags);
}

CUresult cuIpcCloseMemHandle(CUdeviceptr dptr) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcCloseMemHandle, dptr);
}

CUresult cuGLCtxCreate_v2(CUcontext *pCtx, unsigned int Flags,
                          CUdevice device) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLCtxCreate_v2, pCtx, Flags,
                         device);
}

CUresult cuGLCtxCreate(CUcontext *pCtx, unsigned int Flags, CUdevice device) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLCtxCreate, pCtx, Flags,
                         device);
}

CUresult cuGLInit(void) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLInit);
}

CUresult cuGLGetDevices_v2(unsigned int *pCudaDeviceCount,
                           CUdevice *pCudaDevices, unsigned int cudaDeviceCount,
                           CUGLDeviceList deviceList) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLGetDevices_v2,
                         pCudaDeviceCount, pCudaDevices, cudaDeviceCount,
                         deviceList);
}

CUresult cuGLGetDevices(unsigned int *pCudaDeviceCount, CUdevice *pCudaDevices,
                        unsigned int cudaDeviceCount,
                        CUGLDeviceList deviceList) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLGetDevices, pCudaDeviceCount,
                         pCudaDevices, cudaDeviceCount, deviceList);
}

CUresult cuGLRegisterBufferObject(GLuint buffer) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLRegisterBufferObject, buffer);
}

CUresult cuGLMapBufferObject_v2_ptds(CUdeviceptr *dptr, size_t *size,
                                     GLuint buffer) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLMapBufferObject_v2_ptds, dptr,
                         size, buffer);
}

CUresult cuGLMapBufferObject_v2(CUdeviceptr *dptr, size_t *size,
                                GLuint buffer) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLMapBufferObject_v2, dptr, size,
                         buffer);
}

CUresult cuGLMapBufferObject(CUdeviceptr *dptr, size_t *size, GLuint buffer) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLMapBufferObject, dptr, size,
                         buffer);
}

CUresult cuGLMapBufferObjectAsync_v2_ptsz(CUdeviceptr *dptr, size_t *size,
                                          GLuint buffer, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLMapBufferObjectAsync_v2_ptsz,
                         dptr, size, buffer, hStream);
}

CUresult cuGLMapBufferObjectAsync_v2(CUdeviceptr *dptr, size_t *size,
                                     GLuint buffer, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLMapBufferObjectAsync_v2, dptr,
                         size, buffer, hStream);
}

CUresult cuGLMapBufferObjectAsync(CUdeviceptr *dptr, size_t *size,
                                  GLuint buffer, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLMapBufferObjectAsync, dptr,
                         size, buffer, hStream);
}

CUresult cuGLUnmapBufferObject(GLuint buffer) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLUnmapBufferObject, buffer);
}

CUresult cuGLUnmapBufferObjectAsync(GLuint buffer, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLUnmapBufferObjectAsync, buffer,
                         hStream);
}

CUresult cuGLUnregisterBufferObject(GLuint buffer) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLUnregisterBufferObject,
                         buffer);
}

CUresult cuGLSetBufferObjectMapFlags(GLuint buffer, unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGLSetBufferObjectMapFlags,
                         buffer, Flags);
}

CUresult cuGraphicsGLRegisterImage(CUgraphicsResource *pCudaResource,
                                   GLuint image, GLenum target,
                                   unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsGLRegisterImage,
                         pCudaResource, image, target, Flags);
}

CUresult cuGraphicsGLRegisterBuffer(CUgraphicsResource *pCudaResource,
                                    GLuint buffer, unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsGLRegisterBuffer,
                         pCudaResource, buffer, Flags);
}

CUresult cuGraphicsUnregisterResource(CUgraphicsResource resource) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsUnregisterResource,
                         resource);
}

CUresult cuGraphicsMapResources_ptsz(unsigned int count,
                                     CUgraphicsResource *resources,
                                     CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsMapResources_ptsz, count,
                         resources, hStream);
}

CUresult cuGraphicsMapResources(unsigned int count,
                                CUgraphicsResource *resources,
                                CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsMapResources, count,
                         resources, hStream);
}

CUresult cuGraphicsUnmapResources_ptsz(unsigned int count,
                                       CUgraphicsResource *resources,
                                       CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsUnmapResources_ptsz,
                         count, resources, hStream);
}

CUresult cuGraphicsUnmapResources(unsigned int count,
                                  CUgraphicsResource *resources,
                                  CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsUnmapResources, count,
                         resources, hStream);
}

CUresult cuGraphicsResourceSetMapFlags_v2(CUgraphicsResource resource,
                                          unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsResourceSetMapFlags_v2,
                         resource, flags);
}

CUresult cuGraphicsSubResourceGetMappedArray(CUarray *pArray,
                                             CUgraphicsResource resource,
                                             unsigned int arrayIndex,
                                             unsigned int mipLevel) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuGraphicsSubResourceGetMappedArray, pArray, resource,
                         arrayIndex, mipLevel);
}

CUresult
cuGraphicsResourceGetMappedMipmappedArray(CUmipmappedArray *pMipmappedArray,
                                          CUgraphicsResource resource) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuGraphicsResourceGetMappedMipmappedArray,
                         pMipmappedArray, resource);
}

CUresult cuGraphicsResourceGetMappedPointer_v2(CUdeviceptr *pDevPtr,
                                               size_t *pSize,
                                               CUgraphicsResource resource) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuGraphicsResourceGetMappedPointer_v2, pDevPtr, pSize,
                         resource);
}

CUresult cuProfilerInitialize(const char *configFile, const char *outputFile,
                              CUoutput_mode outputMode) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuProfilerInitialize, configFile,
                         outputFile, outputMode);
}

CUresult cuProfilerStart(void) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuProfilerStart);
}

CUresult cuProfilerStop(void) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuProfilerStop);
}

CUresult cuVDPAUGetDevice(CUdevice *pDevice, VdpDevice vdpDevice,
                          VdpGetProcAddress *vdpGetProcAddress) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuVDPAUGetDevice, pDevice,
                         vdpDevice, vdpGetProcAddress);
}

CUresult cuVDPAUCtxCreate_v2(CUcontext *pCtx, unsigned int flags,
                             CUdevice device, VdpDevice vdpDevice,
                             VdpGetProcAddress *vdpGetProcAddress) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuVDPAUCtxCreate_v2, pCtx, flags,
                         device, vdpDevice, vdpGetProcAddress);
}

CUresult cuVDPAUCtxCreate(CUcontext *pCtx, unsigned int flags, CUdevice device,
                          VdpDevice vdpDevice,
                          VdpGetProcAddress *vdpGetProcAddress) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuVDPAUCtxCreate, pCtx, flags,
                         device, vdpDevice, vdpGetProcAddress);
}

CUresult cuGraphicsVDPAURegisterVideoSurface(CUgraphicsResource *pCudaResource,
                                             VdpVideoSurface vdpSurface,
                                             unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuGraphicsVDPAURegisterVideoSurface, pCudaResource,
                         vdpSurface, flags);
}

CUresult cuGraphicsVDPAURegisterOutputSurface(CUgraphicsResource *pCudaResource,
                                              VdpOutputSurface vdpSurface,
                                              unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuGraphicsVDPAURegisterOutputSurface, pCudaResource,
                         vdpSurface, flags);
}

CUresult cuGetExportTable(const void **ppExportTable,
                          const CUuuid *pExportTableId) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGetExportTable, ppExportTable,
                         pExportTableId);
}

CUresult cuOccupancyMaxActiveBlocksPerMultiprocessor(int *numBlocks,
                                                     CUfunction func,
                                                     int blockSize,
                                                     size_t dynamicSMemSize) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuOccupancyMaxActiveBlocksPerMultiprocessor, numBlocks,
                         func, blockSize, dynamicSMemSize);
}

CUresult cuMemAdvise(CUdeviceptr devPtr, size_t count, CUmem_advise advice,
                     CUdevice device) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAdvise, devPtr, count, advice,
                         device);
}

CUresult cuMemPrefetchAsync_ptsz(CUdeviceptr devPtr, size_t count,
                                 CUdevice dstDevice, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPrefetchAsync_ptsz, devPtr,
                         count, dstDevice, hStream);
}

CUresult cuMemPrefetchAsync(CUdeviceptr devPtr, size_t count,
                            CUdevice dstDevice, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPrefetchAsync, devPtr, count,
                         dstDevice, hStream);
}

CUresult cuMemRangeGetAttribute(void *data, size_t dataSize,
                                CUmem_range_attribute attribute,
                                CUdeviceptr devPtr, size_t count) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemRangeGetAttribute, data,
                         dataSize, attribute, devPtr, count);
}

CUresult cuMemRangeGetAttributes(void **data, size_t *dataSizes,
                                 CUmem_range_attribute *attributes,
                                 size_t numAttributes, CUdeviceptr devPtr,
                                 size_t count) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemRangeGetAttributes, data,
                         dataSizes, attributes, numAttributes, devPtr, count);
}

CUresult cuCtxSetLimit(CUlimit limit, size_t value) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetLimit, limit, value);
}

CUresult cuModuleLoad(CUmodule *module, const char *fname) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoad, module, fname);
}

CUresult cuModuleLoadData(CUmodule *module, const void *image) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoadData, module, image);
}

CUresult cuModuleLoadFatBinary(CUmodule *module, const void *fatCubin) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoadFatBinary, module,
                         fatCubin);
}

CUresult cuGetErrorString(CUresult error, const char **pStr) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGetErrorString, error, pStr);
}

CUresult cuGetErrorName(CUresult error, const char **pStr) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGetErrorName, error, pStr);
}

CUresult cuCtxAttach(CUcontext *pctx, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxAttach, pctx, flags);
}

CUresult cuCtxDestroy_v2(CUcontext ctx) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxDestroy_v2, ctx);
}

CUresult cuCtxDestroy(CUcontext ctx) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxDestroy, ctx);
}

CUresult cuCtxPopCurrent_v2(CUcontext *pctx) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxPopCurrent_v2, pctx);
}

CUresult cuCtxPopCurrent(CUcontext *pctx) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxPopCurrent, pctx);
}

CUresult cuCtxPushCurrent_v2(CUcontext ctx) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxPushCurrent_v2, ctx);
}

CUresult cuCtxPushCurrent(CUcontext ctx) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxPushCurrent, ctx);
}

void cudbgApiInit(uint32_t arg) {
  return CUDA_ENTRY_DEBUG_VOID_CALL(cuda_library_entry, cudbgApiInit, arg);
}

void cudbgApiAttach(void) {
  return CUDA_ENTRY_DEBUG_VOID_CALL(cuda_library_entry, cudbgApiAttach);
}

void cudbgApiDetach(void) {
  return CUDA_ENTRY_DEBUG_VOID_CALL(cuda_library_entry, cudbgApiDetach);
}

CUDBGResult cudbgGetAPI(uint32_t major, uint32_t minor, uint32_t rev,
                        CUDBGAPI *api) {
  return CUDA_ENTRY_DEBUG_RESULT_CALL(cuda_library_entry, cudbgGetAPI, major,
                                      minor, rev, api);
}

CUDBGResult cudbgGetAPIVersion(uint32_t *major, uint32_t *minor,
                               uint32_t *rev) {
  return CUDA_ENTRY_DEBUG_RESULT_CALL(cuda_library_entry, cudbgGetAPIVersion,
                                      major, minor, rev);
}

CUDBGResult cudbgMain(int apiClientPid, uint32_t apiClientRevision,
                      int sessionId, int attachState,
                      int attachEventInitialized, int writeFd, int detachFd,
                      int attachStubInUse, int enablePreemptionDebugging) {
  return CUDA_ENTRY_DEBUG_RESULT_CALL(
      cuda_library_entry, cudbgMain, apiClientPid, apiClientRevision, sessionId,
      attachState, attachEventInitialized, writeFd, detachFd, attachStubInUse,
      enablePreemptionDebugging);
}

void cudbgReportDriverApiError(void) {
  return CUDA_ENTRY_DEBUG_VOID_CALL(cuda_library_entry,
                                    cudbgReportDriverApiError);
}

void cudbgReportDriverInternalError(void) {
  return CUDA_ENTRY_DEBUG_VOID_CALL(cuda_library_entry,
                                    cudbgReportDriverInternalError);
}

CUresult cuDeviceComputeCapability(int *major, int *minor, CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceComputeCapability, major,
                         minor, dev);
}

CUresult cuDeviceGetProperties(CUdevprop *prop, CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetProperties, prop, dev);
}

CUresult cuEGLInit(void) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLInit);
}

CUresult cuEGLApiInit(void) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLApiInit);
}

CUresult cuEGLStreamConsumerAcquireFrame(CUeglStreamConnection *conn,
                                         CUgraphicsResource *pCudaResource,
                                         CUstream *pStream,
                                         unsigned int timeout) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamConsumerAcquireFrame,
                         conn, pCudaResource, pStream, timeout);
}

CUresult cuEGLStreamConsumerConnect(CUeglStreamConnection *conn,
                                    EGLStreamKHR stream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamConsumerConnect, conn,
                         stream);
}

CUresult cuEGLStreamConsumerConnectWithFlags(CUeglStreamConnection *conn,
                                             EGLStreamKHR stream,
                                             unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuEGLStreamConsumerConnectWithFlags, conn, stream,
                         flags);
}

CUresult cuEGLStreamConsumerDisconnect(CUeglStreamConnection *conn) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamConsumerDisconnect,
                         conn);
}

CUresult cuEGLStreamConsumerReleaseFrame(CUeglStreamConnection *conn,
                                         CUgraphicsResource pCudaResource,
                                         CUstream *pStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamConsumerReleaseFrame,
                         conn, pCudaResource, pStream);
}

CUresult cuEGLStreamProducerConnect(CUeglStreamConnection *conn,
                                    EGLStreamKHR stream, EGLint width,
                                    EGLint height) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamProducerConnect, conn,
                         stream, width, height);
}

CUresult cuEGLStreamProducerDisconnect(CUeglStreamConnection *conn) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamProducerDisconnect,
                         conn);
}

CUresult cuEGLStreamProducerPresentFrame(CUeglStreamConnection *conn,
                                         CUeglFrame eglframe,
                                         CUstream *pStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamProducerPresentFrame,
                         conn, eglframe, pStream);
}

CUresult cuEGLStreamProducerReturnFrame(CUeglStreamConnection *conn,
                                        CUeglFrame *eglframe,
                                        CUstream *pStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamProducerReturnFrame,
                         conn, eglframe, pStream);
}

CUresult cuFuncSetAttribute(CUfunction hfunc, CUfunction_attribute attrib,
                            int value) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetAttribute, hfunc, attrib,
                         value);
}

CUresult cuFuncSetSharedSize(CUfunction hfunc, unsigned int bytes) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetSharedSize, hfunc, bytes);
}

CUresult cuGraphicsEGLRegisterImage(CUgraphicsResource *pCudaResource,
                                    EGLImageKHR image, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsEGLRegisterImage,
                         pCudaResource, image, flags);
}

CUresult cuGraphicsResourceGetMappedEglFrame(CUeglFrame *eglFrame,
                                             CUgraphicsResource resource,
                                             unsigned int index,
                                             unsigned int mipLevel) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsEGLRegisterImage,
                         cuGraphicsResourceGetMappedEglFrame, eglFrame,
                         resource, index, mipLevel);
}

CUresult cuGraphicsResourceGetMappedPointer(CUdeviceptr *pDevPtr, size_t *pSize,
                                            CUgraphicsResource resource) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsResourceGetMappedPointer,
                         pDevPtr, pSize, resource);
}

CUresult cuGraphicsResourceSetMapFlags(CUgraphicsResource resource,
                                       unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsResourceSetMapFlags,
                         resource, flags);
}

CUresult
cuLaunchCooperativeKernelMultiDevice(CUDA_LAUNCH_PARAMS *launchParamsList,
                                     unsigned int numDevices,
                                     unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuLaunchCooperativeKernelMultiDevice, launchParamsList,
                         numDevices, flags);
}

CUresult cuMemAllocHost_v2(void **pp, size_t bytesize) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocHost_v2, pp, bytesize);
}

CUresult cuMemAllocHost(void **pp, size_t bytesize) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocHost, pp, bytesize);
}

CUresult cuMemcpy2D_v2(const CUDA_MEMCPY2D *pCopy) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2D_v2, pCopy);
}

CUresult cuMemcpy2D(const CUDA_MEMCPY2D *pCopy) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2D, pCopy);
}

CUresult cuMemcpyAtoA_v2_ptds(CUarray dstArray, size_t dstOffset,
                              CUarray srcArray, size_t srcOffset,
                              size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoA_v2_ptds, dstArray,
                         dstOffset, srcArray, srcOffset, ByteCount);
}

CUresult cuMemcpyAtoA_v2(CUarray dstArray, size_t dstOffset, CUarray srcArray,
                         size_t srcOffset, size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoA_v2, dstArray,
                         dstOffset, srcArray, srcOffset, ByteCount);
}

CUresult cuMemcpyAtoA(CUarray dstArray, size_t dstOffset, CUarray srcArray,
                      size_t srcOffset, size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoA, dstArray, dstOffset,
                         srcArray, srcOffset, ByteCount);
}

CUresult cuMemcpyAtoD(CUdeviceptr dstDevice, CUarray srcArray, size_t srcOffset,
                      size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoD, dstDevice, srcArray,
                         srcOffset, ByteCount);
}

CUresult cuMemcpyAtoD_v2(CUdeviceptr dstDevice, CUarray srcArray,
                         size_t srcOffset, size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoD_v2, dstDevice,
                         srcArray, srcOffset, ByteCount);
}

CUresult cuMemcpyAtoD_v2_ptds(CUdeviceptr dstDevice, CUarray srcArray,
                              size_t srcOffset, size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoD_v2_ptds, dstDevice,
                         srcArray, srcOffset, ByteCount);
}

CUresult cuMemcpyAtoH_v2_ptds(void *dstHost, CUarray srcArray, size_t srcOffset,
                              size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoH_v2_ptds, dstHost,
                         srcArray, srcOffset, ByteCount);
}

CUresult cuMemcpyAtoH_v2(void *dstHost, CUarray srcArray, size_t srcOffset,
                         size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoH_v2, dstHost, srcArray,
                         srcOffset, ByteCount);
}

CUresult cuMemcpyAtoH(void *dstHost, CUarray srcArray, size_t srcOffset,
                      size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoH, dstHost, srcArray,
                         srcOffset, ByteCount);
}

CUresult cuMemcpyAtoHAsync_v2_ptsz(void *dstHost, CUarray srcArray,
                                   size_t srcOffset, size_t ByteCount,
                                   CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoHAsync_v2_ptsz, dstHost,
                         srcArray, srcOffset, ByteCount, hStream);
}

CUresult cuMemcpyAtoHAsync_v2(void *dstHost, CUarray srcArray, size_t srcOffset,
                              size_t ByteCount, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoHAsync_v2, dstHost,
                         srcArray, srcOffset, ByteCount, hStream);
}

CUresult cuMemcpyAtoHAsync(void *dstHost, CUarray srcArray, size_t srcOffset,
                           size_t ByteCount, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoHAsync, dstHost,
                         srcArray, srcOffset, ByteCount, hStream);
}

CUresult cuMemcpyDtoA_v2_ptds(CUarray dstArray, size_t dstOffset,
                              CUdeviceptr srcDevice, size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoA_v2_ptds, dstArray,
                         dstOffset, srcDevice, ByteCount);
}

CUresult cuMemcpyDtoA_v2(CUarray dstArray, size_t dstOffset,
                         CUdeviceptr srcDevice, size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoA_v2, dstArray,
                         dstOffset, srcDevice, ByteCount);
}

CUresult cuMemcpyDtoA(CUarray dstArray, size_t dstOffset, CUdeviceptr srcDevice,
                      size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoA, dstArray, dstOffset,
                         srcDevice, ByteCount);
}

CUresult cuMemcpyHtoA_v2_ptds(CUarray dstArray, size_t dstOffset,
                              const void *srcHost, size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoA_v2_ptds, dstArray,
                         dstOffset, srcHost, ByteCount);
}

CUresult cuMemcpyHtoA_v2(CUarray dstArray, size_t dstOffset,
                         const void *srcHost, size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoA_v2, dstArray,
                         dstOffset, srcHost, ByteCount);
}

CUresult cuMemcpyHtoA(CUarray dstArray, size_t dstOffset, const void *srcHost,
                      size_t ByteCount) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoA, dstArray, dstOffset,
                         srcHost, ByteCount);
}

CUresult cuMemcpyHtoAAsync_v2_ptsz(CUarray dstArray, size_t dstOffset,
                                   const void *srcHost, size_t ByteCount,
                                   CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoAAsync_v2_ptsz,
                         dstArray, dstOffset, srcHost, ByteCount, hStream);
}

CUresult cuMemcpyHtoAAsync_v2(CUarray dstArray, size_t dstOffset,
                              const void *srcHost, size_t ByteCount,
                              CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoAAsync_v2, dstArray,
                         dstOffset, srcHost, ByteCount, hStream);
}

CUresult cuMemcpyHtoAAsync(CUarray dstArray, size_t dstOffset,
                           const void *srcHost, size_t ByteCount,
                           CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoAAsync, dstArray,
                         dstOffset, srcHost, ByteCount, hStream);
}

CUresult cuMemsetD16_v2_ptds(CUdeviceptr dstDevice, unsigned short us,
                             size_t N) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD16_v2_ptds, dstDevice, us,
                         N);
}

CUresult cuMemsetD16_v2(CUdeviceptr dstDevice, unsigned short us, size_t N) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD16_v2, dstDevice, us, N);
}

CUresult cuMemsetD16(CUdeviceptr dstDevice, unsigned short us, size_t N) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD16, dstDevice, us, N);
}

CUresult cuMemsetD16Async_ptsz(CUdeviceptr dstDevice, unsigned short us,
                               size_t N, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD16Async_ptsz, dstDevice,
                         us, N, hStream);
}

CUresult cuMemsetD16Async(CUdeviceptr dstDevice, unsigned short us, size_t N,
                          CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD16Async, dstDevice, us, N,
                         hStream);
}

CUresult cuMemsetD2D16_v2_ptds(CUdeviceptr dstDevice, size_t dstPitch,
                               unsigned short us, size_t Width, size_t Height) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D16_v2_ptds, dstDevice,
                         dstPitch, us, Width, Height);
}

CUresult cuMemsetD2D16_v2(CUdeviceptr dstDevice, size_t dstPitch,
                          unsigned short us, size_t Width, size_t Height) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D16_v2, dstDevice,
                         dstPitch, us, Width, Height);
}

CUresult cuMemsetD2D16(CUdeviceptr dstDevice, size_t dstPitch,
                       unsigned short us, size_t Width, size_t Height) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D16, dstDevice, dstPitch,
                         us, Width, Height);
}

CUresult cuMemsetD2D16Async_ptsz(CUdeviceptr dstDevice, size_t dstPitch,
                                 unsigned short us, size_t Width, size_t Height,
                                 CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D16Async_ptsz, dstDevice,
                         dstPitch, us, Width, Height, hStream);
}

CUresult cuMemsetD2D16Async(CUdeviceptr dstDevice, size_t dstPitch,
                            unsigned short us, size_t Width, size_t Height,
                            CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D16Async, dstDevice,
                         dstPitch, us, Width, Height, hStream);
}

CUresult cuMemsetD2D32_v2_ptds(CUdeviceptr dstDevice, size_t dstPitch,
                               unsigned int ui, size_t Width, size_t Height) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D32_v2_ptds, dstDevice,
                         dstPitch, ui, Width, Height);
}

CUresult cuMemsetD2D32_v2(CUdeviceptr dstDevice, size_t dstPitch,
                          unsigned int ui, size_t Width, size_t Height) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D32_v2, dstDevice,
                         dstPitch, ui, Width, Height);
}

CUresult cuMemsetD2D32(CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui,
                       size_t Width, size_t Height) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D32, dstDevice, dstPitch,
                         ui, Width, Height);
}

CUresult cuMemsetD2D32Async_ptsz(CUdeviceptr dstDevice, size_t dstPitch,
                                 unsigned int ui, size_t Width, size_t Height,
                                 CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D32Async_ptsz, dstDevice,
                         dstPitch, ui, Width, Height, hStream);
}

CUresult cuMemsetD2D32Async(CUdeviceptr dstDevice, size_t dstPitch,
                            unsigned int ui, size_t Width, size_t Height,
                            CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D32Async, dstDevice,
                         dstPitch, ui, Width, Height, hStream);
}

CUresult cuMemsetD32_v2_ptds(CUdeviceptr dstDevice, unsigned int ui, size_t N) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD32_v2_ptds, dstDevice, ui,
                         N);
}

CUresult cuMemsetD32_v2(CUdeviceptr dstDevice, unsigned int ui, size_t N) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD32_v2, dstDevice, ui, N);
}

CUresult cuMemsetD32(CUdeviceptr dstDevice, unsigned int ui, size_t N) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD32, dstDevice, ui, N);
}

CUresult cuMemsetD32Async_ptsz(CUdeviceptr dstDevice, unsigned int ui, size_t N,
                               CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD32Async_ptsz, dstDevice,
                         ui, N, hStream);
}

CUresult cuMemsetD32Async(CUdeviceptr dstDevice, unsigned int ui, size_t N,
                          CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD32Async, dstDevice, ui, N,
                         hStream);
}

CUresult cuModuleLoadDataEx(CUmodule *module, const void *image,
                            unsigned int numOptions, CUjit_option *options,
                            void **optionValues) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoadDataEx, module, image,
                         numOptions, options, optionValues);
}

CUresult cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(
    int *numBlocks, CUfunction func, int blockSize, size_t dynamicSMemSize,
    unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags,
                         numBlocks, func, blockSize, dynamicSMemSize, flags);
}

CUresult
cuOccupancyMaxPotentialBlockSize(int *minGridSize, int *blockSize,
                                 CUfunction func,
                                 CUoccupancyB2DSize blockSizeToDynamicSMemSize,
                                 size_t dynamicSMemSize, int blockSizeLimit) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyMaxPotentialBlockSize,
                         minGridSize, blockSize, func,
                         blockSizeToDynamicSMemSize, dynamicSMemSize,
                         blockSizeLimit);
}

CUresult cuOccupancyMaxPotentialBlockSizeWithFlags(
    int *minGridSize, int *blockSize, CUfunction func,
    CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize,
    int blockSizeLimit, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuOccupancyMaxPotentialBlockSizeWithFlags, minGridSize,
                         blockSize, func, blockSizeToDynamicSMemSize,
                         dynamicSMemSize, blockSizeLimit, flags);
}

CUresult cuParamSetf(CUfunction hfunc, int offset, float value) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSetf, hfunc, offset, value);
}

CUresult cuParamSeti(CUfunction hfunc, int offset, unsigned int value) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSeti, hfunc, offset, value);
}

CUresult cuParamSetSize(CUfunction hfunc, unsigned int numbytes) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSetSize, hfunc, numbytes);
}

CUresult cuParamSetTexRef(CUfunction hfunc, int texunit, CUtexref hTexRef) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSetTexRef, hfunc, texunit,
                         hTexRef);
}

CUresult cuParamSetv(CUfunction hfunc, int offset, void *ptr,
                     unsigned int numbytes) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSetv, hfunc, offset, ptr,
                         numbytes);
}

CUresult cuPointerSetAttribute(const void *value, CUpointer_attribute attribute,
                               CUdeviceptr ptr) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuPointerSetAttribute, value,
                         attribute, ptr);
}

CUresult cuStreamWaitValue64_ptsz(CUstream stream, CUdeviceptr addr,
                                  cuuint64_t value, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitValue64_ptsz, stream,
                         addr, value, flags);
}

CUresult cuStreamWaitValue64(CUstream stream, CUdeviceptr addr,
                             cuuint64_t value, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitValue64, stream, addr,
                         value, flags);
}

CUresult cuStreamWriteValue64_ptsz(CUstream stream, CUdeviceptr addr,
                                   cuuint64_t value, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWriteValue64_ptsz, stream,
                         addr, value, flags);
}

CUresult cuStreamWriteValue64(CUstream stream, CUdeviceptr addr,
                              cuuint64_t value, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWriteValue64, stream, addr,
                         value, flags);
}

CUresult cuSurfRefGetArray(CUarray *phArray, CUsurfref hSurfRef) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfRefGetArray, phArray,
                         hSurfRef);
}

CUresult cuTexRefGetAddress_v2(CUdeviceptr *pdptr, CUtexref hTexRef) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetAddress_v2, pdptr,
                         hTexRef);
}

CUresult cuTexRefGetAddress(CUdeviceptr *pdptr, CUtexref hTexRef) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetAddress, pdptr,
                         hTexRef);
}

CUresult cuTexRefGetAddressMode(CUaddress_mode *pam, CUtexref hTexRef,
                                int dim) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetAddressMode, pam,
                         hTexRef, dim);
}

CUresult cuTexRefGetArray(CUarray *phArray, CUtexref hTexRef) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetArray, phArray,
                         hTexRef);
}

CUresult cuTexRefGetFilterMode(CUfilter_mode *pfm, CUtexref hTexRef) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetFilterMode, pfm,
                         hTexRef);
}

CUresult cuTexRefGetFlags(unsigned int *pFlags, CUtexref hTexRef) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetFlags, pFlags, hTexRef);
}

CUresult cuTexRefGetFormat(CUarray_format *pFormat, int *pNumChannels,
                           CUtexref hTexRef) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetFormat, pFormat,
                         pNumChannels, hTexRef);
}

CUresult cuTexRefGetMaxAnisotropy(int *pmaxAniso, CUtexref hTexRef) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMaxAnisotropy,
                         pmaxAniso, hTexRef);
}

CUresult cuTexRefGetMipmapFilterMode(CUfilter_mode *pfm, CUtexref hTexRef) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMipmapFilterMode, pfm,
                         hTexRef);
}

CUresult cuTexRefGetMipmapLevelBias(float *pbias, CUtexref hTexRef) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMipmapLevelBias, pbias,
                         hTexRef);
}

CUresult cuTexRefGetMipmapLevelClamp(float *pminMipmapLevelClamp,
                                     float *pmaxMipmapLevelClamp,
                                     CUtexref hTexRef) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMipmapLevelClamp,
                         pminMipmapLevelClamp, pmaxMipmapLevelClamp, hTexRef);
}

CUresult cuTexRefGetMipmappedArray(CUmipmappedArray *phMipmappedArray,
                                   CUtexref hTexRef) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMipmappedArray,
                         phMipmappedArray, hTexRef);
}

CUresult cuTexRefSetAddress(size_t *ByteOffset, CUtexref hTexRef,
                            CUdeviceptr dptr, size_t bytes) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddress, ByteOffset,
                         hTexRef, dptr, bytes);
}

CUresult cuDeviceGetAttribute(int *pi, CUdevice_attribute attrib,
                              CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetAttribute, pi, attrib,
                         dev);
}

CUresult cuDestroyExternalMemory(CUexternalMemory extMem) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDestroyExternalMemory, extMem);
}

CUresult cuDestroyExternalSemaphore(CUexternalSemaphore extSem) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDestroyExternalSemaphore,
                         extSem);
}

CUresult cuDeviceGetUuid_v2(CUuuid *uuid, CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetUuid_v2, uuid, dev);
}

CUresult cuDeviceGetUuid(CUuuid *uuid, CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetUuid, uuid, dev);
}

CUresult cuExternalMemoryGetMappedBuffer(
    CUdeviceptr *devPtr, CUexternalMemory extMem,
    const CUDA_EXTERNAL_MEMORY_BUFFER_DESC *bufferDesc) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuExternalMemoryGetMappedBuffer,
                         devPtr, extMem, bufferDesc);
}

CUresult cuExternalMemoryGetMappedMipmappedArray(
    CUmipmappedArray *mipmap, CUexternalMemory extMem,
    const CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC *mipmapDesc) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuExternalMemoryGetMappedMipmappedArray, mipmap,
                         extMem, mipmapDesc);
}

CUresult cuGraphAddChildGraphNode(CUgraphNode *phGraphNode, CUgraph hGraph,
                                  const CUgraphNode *dependencies,
                                  size_t numDependencies, CUgraph childGraph) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddChildGraphNode,
                         phGraphNode, hGraph, dependencies, numDependencies,
                         childGraph);
}

CUresult cuGraphAddDependencies(CUgraph hGraph, const CUgraphNode *from,
                                const CUgraphNode *to, size_t numDependencies) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddDependencies, hGraph,
                         from, to, numDependencies, numDependencies);
}

CUresult cuGraphAddEmptyNode(CUgraphNode *phGraphNode, CUgraph hGraph,
                             const CUgraphNode *dependencies,
                             size_t numDependencies) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddEmptyNode, phGraphNode,
                         hGraph, dependencies, numDependencies);
}

CUresult cuGraphAddHostNode(CUgraphNode *phGraphNode, CUgraph hGraph,
                            const CUgraphNode *dependencies,
                            size_t numDependencies,
                            const CUDA_HOST_NODE_PARAMS *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddHostNode, phGraphNode,
                         hGraph, dependencies, numDependencies, nodeParams);
}

CUresult cuGraphAddKernelNode(CUgraphNode *phGraphNode, CUgraph hGraph,
                              const CUgraphNode *dependencies,
                              size_t numDependencies,
                              const CUDA_KERNEL_NODE_PARAMS *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddKernelNode, phGraphNode,
                         hGraph, dependencies, numDependencies, nodeParams);
}

CUresult cuGraphAddMemcpyNode(CUgraphNode *phGraphNode, CUgraph hGraph,
                              const CUgraphNode *dependencies,
                              size_t numDependencies,
                              const CUDA_MEMCPY3D *copyParams, CUcontext ctx) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddMemcpyNode, phGraphNode,
                         hGraph, dependencies, numDependencies, copyParams,
                         ctx);
}

CUresult cuGraphAddMemsetNode(CUgraphNode *phGraphNode, CUgraph hGraph,
                              const CUgraphNode *dependencies,
                              size_t numDependencies,
                              const CUDA_MEMSET_NODE_PARAMS *memsetParams,
                              CUcontext ctx) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddMemsetNode, phGraphNode,
                         hGraph, dependencies, numDependencies, memsetParams,
                         ctx);
}

CUresult cuGraphChildGraphNodeGetGraph(CUgraphNode hNode, CUgraph *phGraph) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphChildGraphNodeGetGraph,
                         hNode, phGraph);
}

CUresult cuGraphClone(CUgraph *phGraphClone, CUgraph originalGraph) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphClone, phGraphClone,
                         originalGraph);
}

CUresult cuGraphCreate(CUgraph *phGraph, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphCreate, phGraph, flags);
}

CUresult cuGraphDestroy(CUgraph hGraph) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphDestroy, hGraph);
}

CUresult cuGraphDestroyNode(CUgraphNode hNode) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphDestroyNode, hNode);
}

CUresult cuGraphExecDestroy(CUgraphExec hGraphExec) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecDestroy, hGraphExec);
}

CUresult cuGraphGetEdges(CUgraph hGraph, CUgraphNode *from, CUgraphNode *to,
                         size_t *numEdges) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphGetEdges, hGraph, from, to,
                         numEdges);
}

CUresult cuGraphGetNodes(CUgraph hGraph, CUgraphNode *nodes, size_t *numNodes) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphGetNodes, hGraph, nodes,
                         numNodes);
}

CUresult cuGraphGetRootNodes(CUgraph hGraph, CUgraphNode *rootNodes,
                             size_t *numRootNodes) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphGetRootNodes, hGraph,
                         rootNodes, numRootNodes);
}

CUresult cuGraphHostNodeGetParams(CUgraphNode hNode,
                                  CUDA_HOST_NODE_PARAMS *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphHostNodeGetParams, hNode,
                         nodeParams);
}

CUresult cuGraphHostNodeSetParams(CUgraphNode hNode,
                                  const CUDA_HOST_NODE_PARAMS *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphHostNodeSetParams, hNode,
                         nodeParams);
}

CUresult cuGraphInstantiate(CUgraphExec *phGraphExec, CUgraph hGraph,
                            CUgraphNode *phErrorNode, char *logBuffer,
                            size_t bufferSize) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphInstantiate, phGraphExec,
                         hGraph, phErrorNode, logBuffer, bufferSize);
}

CUresult cuGraphKernelNodeGetParams(CUgraphNode hNode,
                                    CUDA_KERNEL_NODE_PARAMS *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeGetParams, hNode,
                         nodeParams);
}

CUresult cuGraphKernelNodeSetParams(CUgraphNode hNode,
                                    const CUDA_KERNEL_NODE_PARAMS *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeSetParams, hNode,
                         nodeParams);
}

CUresult cuGraphLaunch(CUgraphExec hGraphExec, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphLaunch, hGraphExec,
                         hStream);
}

CUresult cuGraphLaunch_ptsz(CUgraphExec hGraphExec, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphLaunch_ptsz, hGraphExec,
                         hStream);
}

CUresult cuGraphMemcpyNodeGetParams(CUgraphNode hNode,
                                    CUDA_MEMCPY3D *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemcpyNodeGetParams, hNode,
                         nodeParams);
}

CUresult cuGraphMemcpyNodeSetParams(CUgraphNode hNode,
                                    const CUDA_MEMCPY3D *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemcpyNodeSetParams, hNode,
                         nodeParams);
}

CUresult cuGraphMemsetNodeGetParams(CUgraphNode hNode,
                                    CUDA_MEMSET_NODE_PARAMS *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemsetNodeGetParams, hNode,
                         nodeParams);
}

CUresult cuGraphMemsetNodeSetParams(CUgraphNode hNode,
                                    const CUDA_MEMSET_NODE_PARAMS *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemsetNodeSetParams, hNode,
                         nodeParams);
}

CUresult cuGraphNodeFindInClone(CUgraphNode *phNode, CUgraphNode hOriginalNode,
                                CUgraph hClonedGraph) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeFindInClone, phNode,
                         hOriginalNode, hClonedGraph);
}

CUresult cuGraphNodeGetDependencies(CUgraphNode hNode,
                                    CUgraphNode *dependencies,
                                    size_t *numDependencies) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetDependencies, hNode,
                         dependencies, numDependencies);
}

CUresult cuGraphNodeGetDependentNodes(CUgraphNode hNode,
                                      CUgraphNode *dependentNodes,
                                      size_t *numDependentNodes) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetDependentNodes,
                         hNode, dependentNodes, numDependentNodes);
}

CUresult cuGraphNodeGetType(CUgraphNode hNode, CUgraphNodeType *type) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetType, hNode, type);
}

CUresult cuGraphRemoveDependencies(CUgraph hGraph, const CUgraphNode *from,
                                   const CUgraphNode *to,
                                   size_t numDependencies) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphRemoveDependencies, hGraph,
                         from, to, numDependencies);
}

CUresult
cuImportExternalMemory(CUexternalMemory *extMem_out,
                       const CUDA_EXTERNAL_MEMORY_HANDLE_DESC *memHandleDesc) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuImportExternalMemory, extMem_out,
                         memHandleDesc);
}

CUresult cuImportExternalSemaphore(
    CUexternalSemaphore *extSem_out,
    const CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC *semHandleDesc) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuImportExternalSemaphore,
                         extSem_out, semHandleDesc);
}

CUresult cuLaunchHostFunc(CUstream hStream, CUhostFn fn, void *userData) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuLaunchHostFunc, hStream, fn,
                         userData);
}

CUresult cuLaunchHostFunc_ptsz(CUstream hStream, CUhostFn fn, void *userData) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuLaunchHostFunc_ptsz, hStream, fn,
                         userData);
}

CUresult cuSignalExternalSemaphoresAsync(
    const CUexternalSemaphore *extSemArray,
    const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *paramsArray,
    unsigned int numExtSems, CUstream stream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuSignalExternalSemaphoresAsync,
                         extSemArray, paramsArray, numExtSems, stream);
}

CUresult cuSignalExternalSemaphoresAsync_ptsz(
    const CUexternalSemaphore *extSemArray,
    const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *paramsArray,
    unsigned int numExtSems, CUstream stream) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuSignalExternalSemaphoresAsync_ptsz, extSemArray,
                         paramsArray, numExtSems, stream);
}

CUresult cuStreamBeginCapture(CUstream hStream, CUstreamCaptureMode mode) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBeginCapture, hStream,
                         mode);
}

CUresult cuStreamBeginCapture_ptsz(CUstream hStream, CUstreamCaptureMode mode) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBeginCapture_ptsz, hStream,
                         mode);
}

CUresult cuStreamEndCapture(CUstream hStream, CUgraph *phGraph) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamEndCapture, hStream,
                         phGraph);
}

CUresult cuStreamEndCapture_ptsz(CUstream hStream, CUgraph *phGraph) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamEndCapture_ptsz, hStream,
                         phGraph);
}

CUresult cuStreamGetCtx(CUstream hStream, CUcontext *pctx) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCtx, hStream, pctx);
}

CUresult cuStreamGetCtx_ptsz(CUstream hStream, CUcontext *pctx) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCtx_ptsz, hStream,
                         pctx);
}

CUresult cuStreamIsCapturing(CUstream hStream,
                             CUstreamCaptureStatus *captureStatus) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamIsCapturing, hStream,
                         captureStatus);
}

CUresult cuStreamIsCapturing_ptsz(CUstream hStream,
                                  CUstreamCaptureStatus *captureStatus) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamIsCapturing_ptsz, hStream,
                         captureStatus);
}

CUresult cuWaitExternalSemaphoresAsync(
    const CUexternalSemaphore *extSemArray,
    const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *paramsArray,
    unsigned int numExtSems, CUstream stream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuWaitExternalSemaphoresAsync,
                         extSemArray, paramsArray, numExtSems, stream);
}

CUresult cuWaitExternalSemaphoresAsync_ptsz(
    const CUexternalSemaphore *extSemArray,
    const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *paramsArray,
    unsigned int numExtSems, CUstream stream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuWaitExternalSemaphoresAsync_ptsz,
                         extSemArray, paramsArray, numExtSems, stream);
}

CUresult
cuGraphExecKernelNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode,
                               const CUDA_KERNEL_NODE_PARAMS *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecKernelNodeSetParams,
                         hGraphExec, hNode, nodeParams);
}

CUresult cuStreamBeginCapture_v2(CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBeginCapture_v2, hStream);
}

CUresult cuStreamBeginCapture_v2_ptsz(CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBeginCapture_v2_ptsz,
                         hStream);
}

CUresult cuStreamGetCaptureInfo_v2(CUstream hStream,
                                   CUstreamCaptureStatus *captureStatus,
                                   cuuint64_t *id) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCaptureInfo_v2, hStream,
                         captureStatus, id);
}

CUresult cuStreamGetCaptureInfo(CUstream hStream,
                                CUstreamCaptureStatus *captureStatus,
                                cuuint64_t *id) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCaptureInfo, hStream,
                         captureStatus, id);
}

CUresult cuStreamGetCaptureInfo_v2_ptsz(CUstream hStream,
                                        CUstreamCaptureStatus *captureStatus,
                                        cuuint64_t *id) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCaptureInfo_v2_ptsz,
                         hStream, captureStatus, id);
}

CUresult cuStreamGetCaptureInfo_ptsz(CUstream hStream,
                                     CUstreamCaptureStatus *captureStatus,
                                     cuuint64_t *id) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCaptureInfo_ptsz,
                         hStream, captureStatus, id);
}

CUresult cuThreadExchangeStreamCaptureMode(CUstreamCaptureMode *mode) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuThreadExchangeStreamCaptureMode,
                         mode);
}

CUresult cuDeviceGetNvSciSyncAttributes(void *nvSciSyncAttrList, CUdevice dev,
                                        int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetNvSciSyncAttributes,
                         nvSciSyncAttrList, dev, flags);
}

CUresult cuGraphExecHostNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode,
                                      const CUDA_HOST_NODE_PARAMS *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecHostNodeSetParams,
                         hGraphExec, hNode, nodeParams);
}

CUresult cuGraphExecMemcpyNodeSetParams(CUgraphExec hGraphExec,
                                        CUgraphNode hNode,
                                        const CUDA_MEMCPY3D *copyParams,
                                        CUcontext ctx) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecMemcpyNodeSetParams,
                         hGraphExec, hNode, copyParams, ctx);
}

CUresult
cuGraphExecMemsetNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode,
                               const CUDA_MEMSET_NODE_PARAMS *memsetParams,
                               CUcontext ctx) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecMemsetNodeSetParams,
                         hGraphExec, hNode, memsetParams, ctx);
}

CUresult cuGraphExecUpdate(CUgraphExec hGraphExec, CUgraph hGraph,
                           CUgraphNode *hErrorNode_out,
                           CUgraphExecUpdateResult *updateResult_out) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecUpdate, hGraphExec,
                         hGraph, hErrorNode_out, updateResult_out);
}

CUresult cuMemAddressFree(CUdeviceptr ptr, size_t size) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAddressFree, ptr, size);
}

CUresult cuMemAddressReserve(CUdeviceptr *ptr, size_t size, size_t alignment,
                             CUdeviceptr addr, unsigned long long flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAddressReserve, ptr, size,
                         alignment, addr, flags);
}

CUresult cuMemCreate(CUmemGenericAllocationHandle *handle, size_t size,
                     const CUmemAllocationProp *prop,
                     unsigned long long flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemCreate, handle, size, prop,
                         flags);
}

CUresult cuMemExportToShareableHandle(void *shareableHandle,
                                      CUmemGenericAllocationHandle handle,
                                      CUmemAllocationHandleType handleType,
                                      unsigned long long flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemExportToShareableHandle,
                         shareableHandle, handle, handleType, flags);
}

CUresult cuMemGetAccess(unsigned long long *flags,
                        const CUmemLocation *location, CUdeviceptr ptr) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetAccess, flags, location,
                         ptr);
}

CUresult
cuMemGetAllocationGranularity(size_t *granularity,
                              const CUmemAllocationProp *prop,
                              CUmemAllocationGranularity_flags option) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetAllocationGranularity,
                         granularity, prop, option);
}

CUresult
cuMemGetAllocationPropertiesFromHandle(CUmemAllocationProp *prop,
                                       CUmemGenericAllocationHandle handle) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuMemGetAllocationPropertiesFromHandle, prop, handle);
}

CUresult
cuMemImportFromShareableHandle(CUmemGenericAllocationHandle *handle,
                               void *osHandle,
                               CUmemAllocationHandleType shHandleType) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemImportFromShareableHandle,
                         handle, osHandle, shHandleType);
}

CUresult cuMemMap(CUdeviceptr ptr, size_t size, size_t offset,
                  CUmemGenericAllocationHandle handle,
                  unsigned long long flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemMap, ptr, size, offset,
                         handle, flags);
}

CUresult cuMemRelease(CUmemGenericAllocationHandle handle) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemRelease, handle);
}

CUresult cuMemSetAccess(CUdeviceptr ptr, size_t size,
                        const CUmemAccessDesc *desc, size_t count) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemSetAccess, ptr, size, desc,
                         count);
}

CUresult cuMemUnmap(CUdeviceptr ptr, size_t size) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemUnmap, ptr, size);
}

CUresult cuCtxResetPersistingL2Cache(void) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxResetPersistingL2Cache);
}

CUresult cuDevicePrimaryCtxRelease_v2(CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxRelease_v2);
}

CUresult cuDevicePrimaryCtxReset_v2(CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxReset_v2, dev);
}

CUresult cuDevicePrimaryCtxSetFlags_v2(CUdevice dev, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxSetFlags_v2, dev,
                         flags);
}

CUresult cuFuncGetModule(CUmodule *hmod, CUfunction hfunc) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncGetModule);
}

CUresult cuGraphInstantiate_v2(CUgraphExec *phGraphExec, CUgraph hGraph,
                               CUgraphNode *phErrorNode, char *logBuffer,
                               size_t bufferSize) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphInstantiate_v2, phGraphExec,
                         hGraph, phErrorNode, logBuffer, bufferSize);
}

CUresult cuGraphKernelNodeCopyAttributes(CUgraphNode dst, CUgraphNode src) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeCopyAttributes,
                         dst, src);
}

CUresult cuGraphKernelNodeGetAttribute(CUgraphNode hNode,
                                       CUkernelNodeAttrID attr,
                                       CUkernelNodeAttrValue *value_out) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeGetAttribute,
                         hNode, attr, value_out);
}

CUresult cuGraphKernelNodeSetAttribute(CUgraphNode hNode,
                                       CUkernelNodeAttrID attr,
                                       const CUkernelNodeAttrValue *value) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeSetAttribute,
                         hNode, attr, value);
}

CUresult cuMemRetainAllocationHandle(CUmemGenericAllocationHandle *handle,
                                     void *addr) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemRetainAllocationHandle,
                         handle, addr);
}

CUresult cuOccupancyAvailableDynamicSMemPerBlock(size_t *dynamicSmemSize,
                                                 CUfunction func, int numBlocks,
                                                 int blockSize) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuOccupancyAvailableDynamicSMemPerBlock,
                         dynamicSmemSize, func, numBlocks, blockSize);
}

CUresult cuStreamCopyAttributes(CUstream dst, CUstream src) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamCopyAttributes, dst, src);
}

CUresult cuStreamCopyAttributes_ptsz(CUstream dst, CUstream src) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamCopyAttributes_ptsz, dst,
                         src);
}

CUresult cuStreamGetAttribute(CUstream hStream, CUstreamAttrID attr,
                              CUstreamAttrValue *value_out) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetAttribute, hStream,
                         attr, value_out);
}

CUresult cuStreamGetAttribute_ptsz(CUstream hStream, CUstreamAttrID attr,
                                   CUstreamAttrValue *value_out) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetAttribute_ptsz, hStream,
                         attr, value_out);
}

CUresult cuStreamSetAttribute(CUstream hStream, CUstreamAttrID attr,
                              const CUstreamAttrValue *value) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamSetAttribute, hStream,
                         attr, value);
}

CUresult cuStreamSetAttribute_ptsz(CUstream hStream, CUstreamAttrID attr,
                                   const CUstreamAttrValue *value) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamSetAttribute_ptsz, hStream,
                         attr, value);
}

/** 11. 2 */
CUresult cuArrayGetPlane(CUarray *pPlaneArray, CUarray hArray,
                         unsigned int planeIdx) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayGetPlane, pPlaneArray,
                         hArray, planeIdx);
}

CUresult
cuArrayGetSparseProperties(CUDA_ARRAY_SPARSE_PROPERTIES *sparseProperties,
                           CUarray array) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayGetSparseProperties,
                         sparseProperties, array);
}

CUresult cuDeviceGetDefaultMemPool(CUmemoryPool *pool_out, CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetDefaultMemPool,
                         pool_out, dev);
}

CUresult cuDeviceGetLuid(char *luid, unsigned int *deviceNodeMask,
                         CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetLuid, luid,
                         deviceNodeMask, dev);
}

CUresult cuDeviceGetMemPool(CUmemoryPool *pool, CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetMemPool, pool, dev);
}

CUresult cuDeviceGetTexture1DLinearMaxWidth(size_t *maxWidthInElements,
                                            CUarray_format format,
                                            unsigned numChannels,
                                            CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetTexture1DLinearMaxWidth,
                         maxWidthInElements, format, numChannels, dev);
}

CUresult cuDeviceSetMemPool(CUdevice dev, CUmemoryPool pool) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceSetMemPool, dev, pool);
}

CUresult cuEventRecordWithFlags(CUevent hEvent, CUstream hStream,
                                unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEventRecordWithFlags, hEvent,
                         hStream, flags);
}

CUresult cuEventRecordWithFlags_ptsz(CUevent hEvent, CUstream hStream,
                                     unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuEventRecordWithFlags_ptsz,
                         hEvent, hStream, flags);
}
CUresult cuGraphAddEventRecordNode(CUgraphNode *phGraphNode, CUgraph hGraph,
                                   const CUgraphNode *dependencies,
                                   size_t numDependencies, CUevent event) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddEventRecordNode,
                         phGraphNode, hGraph, dependencies, numDependencies,
                         event);
}
CUresult cuGraphAddEventWaitNode(CUgraphNode *phGraphNode, CUgraph hGraph,
                                 const CUgraphNode *dependencies,
                                 size_t numDependencies, CUevent event) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddEventWaitNode,
                         phGraphNode, hGraph, dependencies, numDependencies,
                         event);
}

CUresult cuGraphAddExternalSemaphoresSignalNode(
    CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies,
    size_t numDependencies, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuGraphAddExternalSemaphoresSignalNode, phGraphNode,
                         hGraph, dependencies, numDependencies, nodeParams);
}
CUresult cuGraphAddExternalSemaphoresWaitNode(
    CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies,
    size_t numDependencies, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuGraphAddExternalSemaphoresWaitNode, phGraphNode,
                         hGraph, dependencies, numDependencies, nodeParams);
}

CUresult cuGraphEventRecordNodeGetEvent(CUgraphNode hNode, CUevent *event_out) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventRecordNodeGetEvent,
                         hNode, event_out);
}

CUresult cuGraphEventRecordNodeSetEvent(CUgraphNode hNode, CUevent event) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventRecordNodeSetEvent,
                         hNode, event);
}

CUresult cuGraphEventWaitNodeGetEvent(CUgraphNode hNode, CUevent *event_out) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventWaitNodeGetEvent,
                         hNode, event_out);
}

CUresult cuGraphEventWaitNodeSetEvent(CUgraphNode hNode, CUevent event) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventWaitNodeSetEvent,
                         hNode, event);
}

CUresult cuGraphExecChildGraphNodeSetParams(CUgraphExec hGraphExec,
                                            CUgraphNode hNode,
                                            CUgraph childGraph) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecChildGraphNodeSetParams,
                         hGraphExec, hNode, childGraph);
}

CUresult cuGraphExecEventRecordNodeSetEvent(CUgraphExec hGraphExec,
                                            CUgraphNode hNode, CUevent event) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecEventRecordNodeSetEvent,
                         hGraphExec, hNode, event);
}

CUresult cuGraphExecEventWaitNodeSetEvent(CUgraphExec hGraphExec,
                                          CUgraphNode hNode, CUevent event) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecEventWaitNodeSetEvent,
                         hGraphExec, hNode, event);
}
CUresult cuGraphExecExternalSemaphoresSignalNodeSetParams(
    CUgraphExec hGraphExec, CUgraphNode hNode,
    const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuGraphExecExternalSemaphoresSignalNodeSetParams,
                         hGraphExec, hNode, nodeParams);
}

CUresult cuGraphExecExternalSemaphoresWaitNodeSetParams(
    CUgraphExec hGraphExec, CUgraphNode hNode,
    const CUDA_EXT_SEM_WAIT_NODE_PARAMS *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuGraphExecExternalSemaphoresWaitNodeSetParams,
                         hGraphExec, hNode, nodeParams);
}

CUresult cuGraphExternalSemaphoresSignalNodeGetParams(
    CUgraphNode hNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *params_out) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuGraphExternalSemaphoresSignalNodeGetParams, hNode,
                         params_out);
}

CUresult cuGraphExternalSemaphoresSignalNodeSetParams(
    CUgraphNode hNode, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuGraphExternalSemaphoresSignalNodeSetParams, hNode,
                         nodeParams);
}

CUresult cuGraphExternalSemaphoresWaitNodeGetParams(
    CUgraphNode hNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS *params_out) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuGraphExternalSemaphoresWaitNodeGetParams, hNode,
                         params_out);
}

CUresult cuGraphExternalSemaphoresWaitNodeSetParams(
    CUgraphNode hNode, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuGraphExternalSemaphoresWaitNodeSetParams, hNode,
                         nodeParams);
}

CUresult cuGraphUpload(CUgraphExec hGraphExec, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphUpload, hGraphExec,
                         hStream);
}

CUresult cuGraphUpload_ptsz(CUgraphExec hGraphExec, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphUpload_ptsz, hGraphExec,
                         hStream);
}
CUresult cuIpcOpenMemHandle_v2(CUdeviceptr *pdptr, CUipcMemHandle handle,
                               unsigned int Flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcOpenMemHandle_v2, pdptr,
                         handle, Flags);
}

CUresult cuMemAllocAsync(CUdeviceptr *dptr, size_t bytesize, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocAsync, dptr, bytesize,
                         hStream);
}

CUresult cuMemAllocAsync_ptsz(CUdeviceptr *dptr, size_t bytesize,
                              CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocAsync_ptsz, dptr,
                         bytesize, hStream);
}
CUresult cuMemAllocFromPoolAsync(CUdeviceptr *dptr, size_t bytesize,
                                 CUmemoryPool pool, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocFromPoolAsync, dptr,
                         bytesize, pool, hStream);
}
CUresult cuMemAllocFromPoolAsync_ptsz(CUdeviceptr *dptr, size_t bytesize,
                                      CUmemoryPool pool, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocFromPoolAsync_ptsz, dptr,
                         bytesize, pool, hStream);
}

CUresult cuMemFreeAsync(CUdeviceptr dptr, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemFreeAsync, dptr, hStream);
}

CUresult cuMemFreeAsync_ptsz(CUdeviceptr dptr, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemFreeAsync_ptsz, dptr,
                         hStream);
}

CUresult cuMemMapArrayAsync(CUarrayMapInfo *mapInfoList, unsigned int count,
                            CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemMapArrayAsync, mapInfoList,
                         count, hStream);
}

CUresult cuMemMapArrayAsync_ptsz(CUarrayMapInfo *mapInfoList,
                                 unsigned int count, CUstream hStream) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemMapArrayAsync_ptsz,
                         mapInfoList, count, hStream);
}
CUresult cuMemPoolCreate(CUmemoryPool *pool, const CUmemPoolProps *poolProps) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolCreate, pool, poolProps);
}

CUresult cuMemPoolDestroy(CUmemoryPool pool) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolDestroy, pool);
}

CUresult cuMemPoolExportPointer(CUmemPoolPtrExportData *shareData_out,
                                CUdeviceptr ptr) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolExportPointer,
                         shareData_out, ptr);
}
CUresult cuMemPoolExportToShareableHandle(void *handle_out, CUmemoryPool pool,
                                          CUmemAllocationHandleType handleType,
                                          unsigned long long flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolExportToShareableHandle,
                         handle_out, pool, handleType, flags);
}
CUresult cuMemPoolGetAccess(CUmemAccess_flags *flags, CUmemoryPool memPool,
                            CUmemLocation *location) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolGetAccess, flags, memPool,
                         location);
}
CUresult cuMemPoolGetAttribute(CUmemoryPool pool, CUmemPool_attribute attr,
                               void *value) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolGetAttribute, pool, attr,
                         value);
}

CUresult
cuMemPoolImportFromShareableHandle(CUmemoryPool *pool_out, void *handle,
                                   CUmemAllocationHandleType handleType,
                                   unsigned long long flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolImportFromShareableHandle,
                         pool_out, handle, handleType, flags);
}

CUresult cuMemPoolImportPointer(CUdeviceptr *ptr_out, CUmemoryPool pool,
                                CUmemPoolPtrExportData *shareData) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolImportPointer, ptr_out,
                         pool, shareData);
}
CUresult cuMemPoolSetAccess(CUmemoryPool pool, const CUmemAccessDesc *map,
                            size_t count) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolSetAccess, pool, map,
                         count);
}

CUresult cuMemPoolSetAttribute(CUmemoryPool pool, CUmemPool_attribute attr,
                               void *value) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolSetAttribute, pool, attr,
                         value);
}
CUresult cuMemPoolTrimTo(CUmemoryPool pool, size_t minBytesToKeep) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolTrimTo, pool,
                         minBytesToKeep);
}

CUresult cuMipmappedArrayGetSparseProperties(
    CUDA_ARRAY_SPARSE_PROPERTIES *sparseProperties, CUmipmappedArray mipmap) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuMipmappedArrayGetSparseProperties, sparseProperties,
                         mipmap);
}

CUresult cuCtxGetExecAffinity(CUexecAffinityParam *pExecAffinity,
                              CUexecAffinityType type) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetExecAffinity,
                         pExecAffinity, type);
}

CUresult cuDeviceGetExecAffinitySupport(int *pi, CUexecAffinityType type,
                                        CUdevice dev) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetExecAffinitySupport, pi,
                         type, dev);
}

CUresult cuDeviceGetGraphMemAttribute(CUdevice device,
                                      CUgraphMem_attribute attr, void *value) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetGraphMemAttribute,
                         device, attr, value);
}

CUresult cuDeviceGraphMemTrim(CUdevice device) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGraphMemTrim, device);
}

CUresult cuDeviceSetGraphMemAttribute(CUdevice device,
                                      CUgraphMem_attribute attr, void *value) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceSetGraphMemAttribute,
                         device, attr, value);
}

CUresult cuFlushGPUDirectRDMAWrites(CUflushGPUDirectRDMAWritesTarget target,
                                    CUflushGPUDirectRDMAWritesScope scope) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuFlushGPUDirectRDMAWrites, target,
                         scope);
}

CUresult cuGraphAddMemAllocNode(CUgraphNode *phGraphNode, CUgraph hGraph,
                                const CUgraphNode *dependencies,
                                size_t numDependencies,
                                CUDA_MEM_ALLOC_NODE_PARAMS *nodeParams) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddMemAllocNode,
                         phGraphNode, hGraph, dependencies, numDependencies,
                         nodeParams);
}

CUresult cuGraphAddMemFreeNode(CUgraphNode *phGraphNode, CUgraph hGraph,
                               const CUgraphNode *dependencies,
                               size_t numDependencies, CUdeviceptr dptr) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddMemFreeNode, phGraphNode,
                         hGraph, dependencies, numDependencies, dptr);
}

CUresult cuGraphDebugDotPrint(CUgraph hGraph, const char *path,
                              unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphDebugDotPrint, hGraph, path,
                         flags);
}

CUresult cuGraphInstantiateWithFlags(CUgraphExec *phGraphExec, CUgraph hGraph,
                                     unsigned long long flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphInstantiateWithFlags,
                         phGraphExec, hGraph, flags);
}

CUresult cuGraphMemAllocNodeGetParams(CUgraphNode hNode,
                                      CUDA_MEM_ALLOC_NODE_PARAMS *params_out) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemAllocNodeGetParams,
                         hNode, params_out);
}

CUresult cuGraphMemFreeNodeGetParams(CUgraphNode hNode, CUdeviceptr *dptr_out) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemFreeNodeGetParams, hNode,
                         dptr_out);
}

CUresult cuGraphReleaseUserObject(CUgraph graph, CUuserObject object,
                                  unsigned int count) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphReleaseUserObject, graph,
                         object, count);
}

CUresult cuGraphRetainUserObject(CUgraph graph, CUuserObject object,
                                 unsigned int count, unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphRetainUserObject, graph,
                         object, count, flags);
}

CUresult cuStreamUpdateCaptureDependencies(CUstream hStream,
                                           CUgraphNode *dependencies,
                                           size_t numDependencies,
                                           unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamUpdateCaptureDependencies,
                         hStream, dependencies, numDependencies, flags);
}

CUresult cuStreamUpdateCaptureDependencies_ptsz(CUstream hStream,
                                                CUgraphNode *dependencies,
                                                size_t numDependencies,
                                                unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry,
                         cuStreamUpdateCaptureDependencies_ptsz, hStream,
                         dependencies, numDependencies, flags);
}

CUresult cuUserObjectCreate(CUuserObject *object_out, void *ptr,
                            CUhostFn destroy, unsigned int initialRefcount,
                            unsigned int flags) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuUserObjectCreate, object_out,
                         ptr, destroy, initialRefcount, flags);
}

CUresult cuUserObjectRelease(CUuserObject object, unsigned int count) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuUserObjectRelease, object,
                         count);
}

CUresult cuUserObjectRetain(CUuserObject object, unsigned int count) {
  return CUDA_ENTRY_CALL(cuda_library_entry, cuUserObjectRetain, object, count);
}