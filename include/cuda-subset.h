/*
 * Copyright 1993-2018 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO LICENSEE:
 *
 * This source code and/or documentation ("Licensed Deliverables") are
 * subject to NVIDIA intellectual property rights under U.S. and
 * international Copyright laws.
 *
 * These Licensed Deliverables contained herein is PROPRIETARY and
 * CONFIDENTIAL to NVIDIA and is being provided under the terms and
 * conditions of a form of NVIDIA software license agreement by and
 * between NVIDIA and Licensee ("License Agreement") or electronically
 * accepted by Licensee.  Notwithstanding any terms or conditions to
 * the contrary in the License Agreement, reproduction or disclosure
 * of the Licensed Deliverables to any third party without the express
 * written consent of NVIDIA is prohibited.
 *
 * NOTWITHSTANDING ANY TERMS OR CONDITIONS TO THE CONTRARY IN THE
 * LICENSE AGREEMENT, NVIDIA MAKES NO REPRESENTATION ABOUT THE
 * SUITABILITY OF THESE LICENSED DELIVERABLES FOR ANY PURPOSE.  IT IS
 * PROVIDED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY OF ANY KIND.
 * NVIDIA DISCLAIMS ALL WARRANTIES WITH REGARD TO THESE LICENSED
 * DELIVERABLES, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY,
 * NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
 * NOTWITHSTANDING ANY TERMS OR CONDITIONS TO THE CONTRARY IN THE
 * LICENSE AGREEMENT, IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY
 * SPECIAL, INDIRECT, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, OR ANY
 * DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THESE LICENSED DELIVERABLES.
 *
 * U.S. Government End Users.  These Licensed Deliverables are a
 * "commercial item" as that term is defined at 48 C.F.R. 2.101 (OCT
 * 1995), consisting of "commercial computer software" and "commercial
 * computer software documentation" as such terms are used in 48
 * C.F.R. 12.212 (SEPT 1995) and is provided to the U.S. Government
 * only as a commercial end item.  Consistent with 48 C.F.R.12.212 and
 * 48 C.F.R. 227.7202-1 through 227.7202-4 (JUNE 1995), all
 * U.S. Government End Users acquire the Licensed Deliverables with
 * only those rights set forth herein.
 *
 * Any use of the Licensed Deliverables in individual and commercial
 * software must include, in the user documentation and internal
 * comments to the code, the above Disclaimer and U.S. Government End
 * Users Notice.
 */
#ifndef HIJACK_CUDA_SUBSET_H
#define HIJACK_CUDA_SUBSET_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>
#include <vdpau/vdpau.h>

typedef uint32_t cuuint32_t;
typedef uint64_t cuuint64_t;

typedef unsigned long long CUdeviceptr;
typedef unsigned int GLuint; /* 4-byte unsigned */
typedef unsigned int GLenum;

typedef struct CUuuid_st { /**< CUDA definition of UUID */
  char bytes[16];
} CUuuid;

typedef int CUdevice;                 /**< CUDA device */
typedef struct CUctx_st *CUcontext;   /**< CUDA context */
typedef struct CUmod_st *CUmodule;    /**< CUDA module */
typedef struct CUfunc_st *CUfunction; /**< CUDA function */
typedef struct CUarray_st *CUarray;   /**< CUDA array */
typedef struct CUmipmappedArray_st
    *CUmipmappedArray;                  /**< CUDA mipmapped array */
typedef struct CUtexref_st *CUtexref;   /**< CUDA texture reference */
typedef struct CUsurfref_st *CUsurfref; /**< CUDA surface reference */
typedef struct CUevent_st *CUevent;     /**< CUDA event */
typedef struct CUstream_st *CUstream;   /**< CUDA stream */
typedef struct CUgraphicsResource_st
    *CUgraphicsResource; /**< CUDA graphics interop resource */
typedef unsigned long long
    CUtexObject; /**< An opaque value that represents a CUDA texture object */
typedef unsigned long long
    CUsurfObject; /**< An opaque value that represents a CUDA surface object */

typedef struct CUlinkState_st *CUlinkState;
typedef struct CUextMemory_st *CUexternalMemory; /**< CUDA external memory */
typedef struct CUextSemaphore_st
    *CUexternalSemaphore;                   /**< CUDA external semaphore */
typedef struct CUgraph_st *CUgraph;         /**< CUDA graph */
typedef struct CUgraphNode_st *CUgraphNode; /**< CUDA graph node */
typedef struct CUgraphExec_st *CUgraphExec; /**< CUDA executable graph */

/**
 * Error codes
 */
typedef enum cudaError_enum {
  /**
   * The API call returned with no errors. In the case of query calls, this
   * can also mean that the operation being queried is complete (see
   * ::cuEventQuery() and ::cuStreamQuery()).
   */
  CUDA_SUCCESS = 0,

  /**
   * This indicates that one or more of the parameters passed to the API call
   * is not within an acceptable range of values.
   */
  CUDA_ERROR_INVALID_VALUE = 1,

  /**
   * The API call failed because it was unable to allocate enough memory to
   * perform the requested operation.
   */
  CUDA_ERROR_OUT_OF_MEMORY = 2,

  /**
   * This indicates that the CUDA driver has not been initialized with
   * ::cuInit() or that initialization has failed.
   */
  CUDA_ERROR_NOT_INITIALIZED = 3,

  /**
   * This indicates that the CUDA driver is in the process of shutting down.
   */
  CUDA_ERROR_DEINITIALIZED = 4,

  /**
   * This indicates profiler is not initialized for this run. This can
   * happen when the application is running with external profiling tools
   * like visual profiler.
   */
  CUDA_ERROR_PROFILER_DISABLED = 5,

  /**
   * \deprecated
   * This error return is deprecated as of CUDA 5.0. It is no longer an error
   * to attempt to enable/disable the profiling via ::cuProfilerStart or
   * ::cuProfilerStop without initialization.
   */
  CUDA_ERROR_PROFILER_NOT_INITIALIZED = 6,

  /**
   * \deprecated
   * This error return is deprecated as of CUDA 5.0. It is no longer an error
   * to call cuProfilerStart() when profiling is already enabled.
   */
  CUDA_ERROR_PROFILER_ALREADY_STARTED = 7,

  /**
   * \deprecated
   * This error return is deprecated as of CUDA 5.0. It is no longer an error
   * to call cuProfilerStop() when profiling is already disabled.
   */
  CUDA_ERROR_PROFILER_ALREADY_STOPPED = 8,

  /**
   * This indicates that no CUDA-capable devices were detected by the installed
   * CUDA driver.
   */
  CUDA_ERROR_NO_DEVICE = 100,

  /**
   * This indicates that the device ordinal supplied by the user does not
   * correspond to a valid CUDA device.
   */
  CUDA_ERROR_INVALID_DEVICE = 101,

  /**
   * This indicates that the device kernel image is invalid. This can also
   * indicate an invalid CUDA module.
   */
  CUDA_ERROR_INVALID_IMAGE = 200,

  /**
   * This most frequently indicates that there is no context bound to the
   * current thread. This can also be returned if the context passed to an
   * API call is not a valid handle (such as a context that has had
   * ::cuCtxDestroy() invoked on it). This can also be returned if a user
   * mixes different API versions (i.e. 3010 context with 3020 API calls).
   * See ::cuCtxGetApiVersion() for more details.
   */
  CUDA_ERROR_INVALID_CONTEXT = 201,

  /**
   * This indicated that the context being supplied as a parameter to the
   * API call was already the active context.
   * \deprecated
   * This error return is deprecated as of CUDA 3.2. It is no longer an
   * error to attempt to push the active context via ::cuCtxPushCurrent().
   */
  CUDA_ERROR_CONTEXT_ALREADY_CURRENT = 202,

  /**
   * This indicates that a map or register operation has failed.
   */
  CUDA_ERROR_MAP_FAILED = 205,

  /**
   * This indicates that an unmap or unregister operation has failed.
   */
  CUDA_ERROR_UNMAP_FAILED = 206,

  /**
   * This indicates that the specified array is currently mapped and thus
   * cannot be destroyed.
   */
  CUDA_ERROR_ARRAY_IS_MAPPED = 207,

  /**
   * This indicates that the resource is already mapped.
   */
  CUDA_ERROR_ALREADY_MAPPED = 208,

  /**
   * This indicates that there is no kernel image available that is suitable
   * for the device. This can occur when a user specifies code generation
   * options for a particular CUDA source file that do not include the
   * corresponding device configuration.
   */
  CUDA_ERROR_NO_BINARY_FOR_GPU = 209,

  /**
   * This indicates that a resource has already been acquired.
   */
  CUDA_ERROR_ALREADY_ACQUIRED = 210,

  /**
   * This indicates that a resource is not mapped.
   */
  CUDA_ERROR_NOT_MAPPED = 211,

  /**
   * This indicates that a mapped resource is not available for access as an
   * array.
   */
  CUDA_ERROR_NOT_MAPPED_AS_ARRAY = 212,

  /**
   * This indicates that a mapped resource is not available for access as a
   * pointer.
   */
  CUDA_ERROR_NOT_MAPPED_AS_POINTER = 213,

  /**
   * This indicates that an uncorrectable ECC error was detected during
   * execution.
   */
  CUDA_ERROR_ECC_UNCORRECTABLE = 214,

  /**
   * This indicates that the ::CUlimit passed to the API call is not
   * supported by the active device.
   */
  CUDA_ERROR_UNSUPPORTED_LIMIT = 215,

  /**
   * This indicates that the ::CUcontext passed to the API call can
   * only be bound to a single CPU thread at a time but is already
   * bound to a CPU thread.
   */
  CUDA_ERROR_CONTEXT_ALREADY_IN_USE = 216,

  /**
   * This indicates that peer access is not supported across the given
   * devices.
   */
  CUDA_ERROR_PEER_ACCESS_UNSUPPORTED = 217,

  /**
   * This indicates that a PTX JIT compilation failed.
   */
  CUDA_ERROR_INVALID_PTX = 218,

  /**
   * This indicates an error with OpenGL or DirectX context.
   */
  CUDA_ERROR_INVALID_GRAPHICS_CONTEXT = 219,

  /**
   * This indicates that an uncorrectable NVLink error was detected during the
   * execution.
   */
  CUDA_ERROR_NVLINK_UNCORRECTABLE = 220,

  /**
   * This indicates that the device kernel source is invalid.
   */
  CUDA_ERROR_INVALID_SOURCE = 300,

  /**
   * This indicates that the file specified was not found.
   */
  CUDA_ERROR_FILE_NOT_FOUND = 301,

  /**
   * This indicates that a link to a shared object failed to resolve.
   */
  CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND = 302,

  /**
   * This indicates that initialization of a shared object failed.
   */
  CUDA_ERROR_SHARED_OBJECT_INIT_FAILED = 303,

  /**
   * This indicates that an OS call failed.
   */
  CUDA_ERROR_OPERATING_SYSTEM = 304,

  /**
   * This indicates that a resource handle passed to the API call was not
   * valid. Resource handles are opaque types like ::CUstream and ::CUevent.
   */
  CUDA_ERROR_INVALID_HANDLE = 400,

  /**
   * This indicates that a named symbol was not found. Examples of symbols
   * are global/constant variable names, texture names, and surface names.
   */
  CUDA_ERROR_NOT_FOUND = 500,

  /**
   * This indicates that asynchronous operations issued previously have not
   * completed yet. This result is not actually an error, but must be indicated
   * differently than ::CUDA_SUCCESS (which indicates completion). Calls that
   * may return this value include ::cuEventQuery() and ::cuStreamQuery().
   */
  CUDA_ERROR_NOT_READY = 600,

  /**
   * While executing a kernel, the device encountered a
   * load or store instruction on an invalid memory address.
   * This leaves the process in an inconsistent state and any further CUDA work
   * will return the same error. To continue using CUDA, the process must be
   * terminated
   * and relaunched.
   */
  CUDA_ERROR_ILLEGAL_ADDRESS = 700,

  /**
   * This indicates that a launch did not occur because it did not have
   * appropriate resources. This error usually indicates that the user has
   * attempted to pass too many arguments to the device kernel, or the
   * kernel launch specifies too many threads for the kernel's register
   * count. Passing arguments of the wrong size (i.e. a 64-bit pointer
   * when a 32-bit int is expected) is equivalent to passing too many
   * arguments and can also result in this error.
   */
  CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES = 701,

  /**
   * This indicates that the device kernel took too long to execute. This can
   * only occur if timeouts are enabled - see the device attribute
   * ::CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT for more information.
   * This leaves the process in an inconsistent state and any further CUDA work
   * will return the same error. To continue using CUDA, the process must be
   * terminated
   * and relaunched.
   */
  CUDA_ERROR_LAUNCH_TIMEOUT = 702,

  /**
   * This error indicates a kernel launch that uses an incompatible texturing
   * mode.
   */
  CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING = 703,

  /**
   * This error indicates that a call to ::cuCtxEnablePeerAccess() is
   * trying to re-enable peer access to a context which has already
   * had peer access to it enabled.
   */
  CUDA_ERROR_PEER_ACCESS_ALREADY_ENABLED = 704,

  /**
   * This error indicates that ::cuCtxDisablePeerAccess() is
   * trying to disable peer access which has not been enabled yet
   * via ::cuCtxEnablePeerAccess().
   */
  CUDA_ERROR_PEER_ACCESS_NOT_ENABLED = 705,

  /**
   * This error indicates that the primary context for the specified device
   * has already been initialized.
   */
  CUDA_ERROR_PRIMARY_CONTEXT_ACTIVE = 708,

  /**
   * This error indicates that the context current to the calling thread
   * has been destroyed using ::cuCtxDestroy, or is a primary context which
   * has not yet been initialized.
   */
  CUDA_ERROR_CONTEXT_IS_DESTROYED = 709,

  /**
   * A device-side assert triggered during kernel execution. The context
   * cannot be used anymore, and must be destroyed. All existing device
   * memory allocations from this context are invalid and must be
   * reconstructed if the program is to continue using CUDA.
   */
  CUDA_ERROR_ASSERT = 710,

  /**
   * This error indicates that the hardware resources required to enable
   * peer access have been exhausted for one or more of the devices
   * passed to ::cuCtxEnablePeerAccess().
   */
  CUDA_ERROR_TOO_MANY_PEERS = 711,

  /**
   * This error indicates that the memory range passed to ::cuMemHostRegister()
   * has already been registered.
   */
  CUDA_ERROR_HOST_MEMORY_ALREADY_REGISTERED = 712,

  /**
   * This error indicates that the pointer passed to ::cuMemHostUnregister()
   * does not correspond to any currently registered memory region.
   */
  CUDA_ERROR_HOST_MEMORY_NOT_REGISTERED = 713,

  /**
   * While executing a kernel, the device encountered a stack error.
   * This can be due to stack corruption or exceeding the stack size limit.
   * This leaves the process in an inconsistent state and any further CUDA work
   * will return the same error. To continue using CUDA, the process must be
   * terminated
   * and relaunched.
   */
  CUDA_ERROR_HARDWARE_STACK_ERROR = 714,

  /**
   * While executing a kernel, the device encountered an illegal instruction.
   * This leaves the process in an inconsistent state and any further CUDA work
   * will return the same error. To continue using CUDA, the process must be
   * terminated
   * and relaunched.
   */
  CUDA_ERROR_ILLEGAL_INSTRUCTION = 715,

  /**
   * While executing a kernel, the device encountered a load or store
   * instruction
   * on a memory address which is not aligned.
   * This leaves the process in an inconsistent state and any further CUDA work
   * will return the same error. To continue using CUDA, the process must be
   * terminated
   * and relaunched.
   */
  CUDA_ERROR_MISALIGNED_ADDRESS = 716,

  /**
   * While executing a kernel, the device encountered an instruction
   * which can only operate on memory locations in certain address spaces
   * (global, shared, or local), but was supplied a memory address not
   * belonging to an allowed address space.
   * This leaves the process in an inconsistent state and any further CUDA work
   * will return the same error. To continue using CUDA, the process must be
   * terminated
   * and relaunched.
   */
  CUDA_ERROR_INVALID_ADDRESS_SPACE = 717,

  /**
   * While executing a kernel, the device program counter wrapped its address
   * space.
   * This leaves the process in an inconsistent state and any further CUDA work
   * will return the same error. To continue using CUDA, the process must be
   * terminated
   * and relaunched.
   */
  CUDA_ERROR_INVALID_PC = 718,

  /**
   * An exception occurred on the device while executing a kernel. Common
   * causes include dereferencing an invalid device pointer and accessing
   * out of bounds shared memory.
   * This leaves the process in an inconsistent state and any further CUDA work
   * will return the same error. To continue using CUDA, the process must be
   * terminated
   * and relaunched.
   */
  CUDA_ERROR_LAUNCH_FAILED = 719,

  /**
   * This error indicates that the attempted operation is not permitted.
   */
  CUDA_ERROR_NOT_PERMITTED = 800,

  /**
   * This error indicates that the attempted operation is not supported
   * on the current system or device.
   */
  CUDA_ERROR_NOT_SUPPORTED = 801,

  /**
   * This indicates that an unknown internal error has occurred.
   */
  CUDA_ERROR_UNKNOWN = 999
} CUresult;

/**
 * Device properties
 */
typedef enum CUdevice_attribute_enum {
  CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK =
      1, /**< Maximum number of threads per block */
  CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X = 2, /**< Maximum block dimension X */
  CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y = 3, /**< Maximum block dimension Y */
  CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z = 4, /**< Maximum block dimension Z */
  CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X = 5,  /**< Maximum grid dimension X */
  CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y = 6,  /**< Maximum grid dimension Y */
  CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z = 7,  /**< Maximum grid dimension Z */
  CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK =
      8, /**< Maximum shared memory available per block in bytes */
  CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK =
      8, /**< Deprecated, use CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK */
  CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY =
      9, /**< Memory available on device for __constant__ variables in a CUDA C
                    kernel in bytes */
  CU_DEVICE_ATTRIBUTE_WARP_SIZE = 10, /**< Warp size in threads */
  CU_DEVICE_ATTRIBUTE_MAX_PITCH =
      11, /**< Maximum pitch in bytes allowed by memory copies */
  CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK =
      12, /**< Maximum number of 32-bit registers available per block */
  CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK =
      12, /**< Deprecated, use CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK */
  CU_DEVICE_ATTRIBUTE_CLOCK_RATE =
      13, /**< Typical clock frequency in kilohertz */
  CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT =
      14, /**< Alignment requirement for textures */
  CU_DEVICE_ATTRIBUTE_GPU_OVERLAP =
      15, /**< Device can possibly copy memory and execute a kernel
                     concurrently. Deprecated. Use instead
                     CU_DEVICE_ATTRIBUTE_ASYNC_ENGINE_COUNT. */
  CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT =
      16, /**< Number of multiprocessors on device */
  CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT =
      17, /**< Specifies whether there is a run time limit on kernels */
  CU_DEVICE_ATTRIBUTE_INTEGRATED =
      18, /**< Device is integrated with host memory */
  CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY =
      19, /**< Device can map host memory into CUDA address space */
  CU_DEVICE_ATTRIBUTE_COMPUTE_MODE =
      20, /**< Compute mode (See ::CUcomputemode for details) */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH =
      21, /**< Maximum 1D texture width */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH =
      22, /**< Maximum 2D texture width */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT =
      23, /**< Maximum 2D texture height */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH =
      24, /**< Maximum 3D texture width */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT =
      25, /**< Maximum 3D texture height */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH =
      26, /**< Maximum 3D texture depth */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_WIDTH =
      27, /**< Maximum 2D layered texture width */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_HEIGHT =
      28, /**< Maximum 2D layered texture height */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_LAYERS =
      29, /**< Maximum layers in a 2D layered texture */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_WIDTH =
      27, /**< Deprecated, use
                     CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_WIDTH */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_HEIGHT =
      28, /**< Deprecated, use
                     CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_HEIGHT */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_NUMSLICES =
      29, /**< Deprecated, use
                     CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_LAYERS */
  CU_DEVICE_ATTRIBUTE_SURFACE_ALIGNMENT =
      30, /**< Alignment requirement for surfaces */
  CU_DEVICE_ATTRIBUTE_CONCURRENT_KERNELS =
      31, /**< Device can possibly execute multiple kernels concurrently */
  CU_DEVICE_ATTRIBUTE_ECC_ENABLED = 32,   /**< Device has ECC support enabled */
  CU_DEVICE_ATTRIBUTE_PCI_BUS_ID = 33,    /**< PCI bus ID of the device */
  CU_DEVICE_ATTRIBUTE_PCI_DEVICE_ID = 34, /**< PCI device ID of the device */
  CU_DEVICE_ATTRIBUTE_TCC_DRIVER = 35, /**< Device is using TCC driver model */
  CU_DEVICE_ATTRIBUTE_MEMORY_CLOCK_RATE =
      36, /**< Peak memory clock frequency in kilohertz */
  CU_DEVICE_ATTRIBUTE_GLOBAL_MEMORY_BUS_WIDTH =
      37, /**< Global memory bus width in bits */
  CU_DEVICE_ATTRIBUTE_L2_CACHE_SIZE = 38, /**< Size of L2 cache in bytes */
  CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_MULTIPROCESSOR =
      39, /**< Maximum resident threads per multiprocessor */
  CU_DEVICE_ATTRIBUTE_ASYNC_ENGINE_COUNT =
      40, /**< Number of asynchronous engines */
  CU_DEVICE_ATTRIBUTE_UNIFIED_ADDRESSING =
      41, /**< Device shares a unified address space with the host */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_WIDTH =
      42, /**< Maximum 1D layered texture width */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_LAYERS =
      43, /**< Maximum layers in a 1D layered texture */
  CU_DEVICE_ATTRIBUTE_CAN_TEX2D_GATHER = 44, /**< Deprecated, do not use. */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_GATHER_WIDTH =
      45, /**< Maximum 2D texture width if CUDA_ARRAY3D_TEXTURE_GATHER is set */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_GATHER_HEIGHT =
      46, /**< Maximum 2D texture height if CUDA_ARRAY3D_TEXTURE_GATHER is set
           */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH_ALTERNATE =
      47, /**< Alternate maximum 3D texture width */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT_ALTERNATE =
      48, /**< Alternate maximum 3D texture height */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH_ALTERNATE =
      49, /**< Alternate maximum 3D texture depth */
  CU_DEVICE_ATTRIBUTE_PCI_DOMAIN_ID = 50, /**< PCI domain ID of the device */
  CU_DEVICE_ATTRIBUTE_TEXTURE_PITCH_ALIGNMENT =
      51, /**< Pitch alignment requirement for textures */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_WIDTH =
      52, /**< Maximum cubemap texture width/height */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_LAYERED_WIDTH =
      53, /**< Maximum cubemap layered texture width/height */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_LAYERED_LAYERS =
      54, /**< Maximum layers in a cubemap layered texture */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_WIDTH =
      55, /**< Maximum 1D surface width */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_WIDTH =
      56, /**< Maximum 2D surface width */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_HEIGHT =
      57, /**< Maximum 2D surface height */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_WIDTH =
      58, /**< Maximum 3D surface width */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_HEIGHT =
      59, /**< Maximum 3D surface height */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_DEPTH =
      60, /**< Maximum 3D surface depth */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_LAYERED_WIDTH =
      61, /**< Maximum 1D layered surface width */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_LAYERED_LAYERS =
      62, /**< Maximum layers in a 1D layered surface */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_WIDTH =
      63, /**< Maximum 2D layered surface width */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_HEIGHT =
      64, /**< Maximum 2D layered surface height */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_LAYERS =
      65, /**< Maximum layers in a 2D layered surface */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_WIDTH =
      66, /**< Maximum cubemap surface width */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_LAYERED_WIDTH =
      67, /**< Maximum cubemap layered surface width */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_LAYERED_LAYERS =
      68, /**< Maximum layers in a cubemap layered surface */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LINEAR_WIDTH =
      69, /**< Maximum 1D linear texture width */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_WIDTH =
      70, /**< Maximum 2D linear texture width */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_HEIGHT =
      71, /**< Maximum 2D linear texture height */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_PITCH =
      72, /**< Maximum 2D linear texture pitch in bytes */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_MIPMAPPED_WIDTH =
      73, /**< Maximum mipmapped 2D texture width */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_MIPMAPPED_HEIGHT =
      74, /**< Maximum mipmapped 2D texture height */
  CU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MAJOR =
      75, /**< Major compute capability version number */
  CU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MINOR =
      76, /**< Minor compute capability version number */
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_MIPMAPPED_WIDTH =
      77, /**< Maximum mipmapped 1D texture width */
  CU_DEVICE_ATTRIBUTE_STREAM_PRIORITIES_SUPPORTED =
      78, /**< Device supports stream priorities */
  CU_DEVICE_ATTRIBUTE_GLOBAL_L1_CACHE_SUPPORTED =
      79, /**< Device supports caching globals in L1 */
  CU_DEVICE_ATTRIBUTE_LOCAL_L1_CACHE_SUPPORTED =
      80, /**< Device supports caching locals in L1 */
  CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_MULTIPROCESSOR =
      81, /**< Maximum shared memory available per multiprocessor in bytes */
  CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_MULTIPROCESSOR =
      82, /**< Maximum number of 32-bit registers available per multiprocessor
           */
  CU_DEVICE_ATTRIBUTE_MANAGED_MEMORY =
      83, /**< Device can allocate managed memory on this system */
  CU_DEVICE_ATTRIBUTE_MULTI_GPU_BOARD =
      84, /**< Device is on a multi-GPU board */
  CU_DEVICE_ATTRIBUTE_MULTI_GPU_BOARD_GROUP_ID =
      85, /**< Unique id for a group of devices on the same multi-GPU board */
  CU_DEVICE_ATTRIBUTE_HOST_NATIVE_ATOMIC_SUPPORTED =
      86, /**< Link between the device and the host supports native atomic
                     operations (this is a placeholder attribute, and is not
                 supported on any current hardware)*/
  CU_DEVICE_ATTRIBUTE_SINGLE_TO_DOUBLE_PRECISION_PERF_RATIO =
      87, /**< Ratio of single precision performance (in floating-point
                     operations per second) to double precision performance */
  CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS =
      88, /**< Device supports coherently accessing pageable memory without
                     calling cudaHostRegister on it */
  CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS =
      89, /**< Device can coherently access managed memory concurrently with the
                     CPU */
  CU_DEVICE_ATTRIBUTE_COMPUTE_PREEMPTION_SUPPORTED =
      90, /**< Device supports compute preemption. */
  CU_DEVICE_ATTRIBUTE_CAN_USE_HOST_POINTER_FOR_REGISTERED_MEM =
      91, /**< Device can access host registered memory at the same virtual
                     address as the CPU */
  CU_DEVICE_ATTRIBUTE_CAN_USE_STREAM_MEM_OPS =
      92, /**< ::cuStreamBatchMemOp and related APIs are supported. */
  CU_DEVICE_ATTRIBUTE_CAN_USE_64_BIT_STREAM_MEM_OPS =
      93, /**< 64-bit operations are supported in ::cuStreamBatchMemOp and
                     related APIs. */
  CU_DEVICE_ATTRIBUTE_CAN_USE_STREAM_WAIT_VALUE_NOR =
      94, /**< ::CU_STREAM_WAIT_VALUE_NOR is supported. */
  CU_DEVICE_ATTRIBUTE_COOPERATIVE_LAUNCH = 95, /**< Device supports launching
                                                  cooperative kernels via
                                                  ::cuLaunchCooperativeKernel */
  CU_DEVICE_ATTRIBUTE_COOPERATIVE_MULTI_DEVICE_LAUNCH =
      96, /**< Device can participate in cooperative kernels launched via
                     ::cuLaunchCooperativeKernelMultiDevice */
  CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK_OPTIN =
      97, /**< Maximum optin shared memory per block */
  CU_DEVICE_ATTRIBUTE_MAX
} CUdevice_attribute;

/**
 * P2P Attributes
 */
typedef enum CUdevice_P2PAttribute_enum {
  CU_DEVICE_P2P_ATTRIBUTE_PERFORMANCE_RANK =
      0x01, /**< A relative value indicating the performance of the link between
                               two devices */
  CU_DEVICE_P2P_ATTRIBUTE_ACCESS_SUPPORTED = 0x02, /**< P2P Access is enable */
  CU_DEVICE_P2P_ATTRIBUTE_NATIVE_ATOMIC_SUPPORTED =
      0x03 /**< Atomic operation over the link supported */
} CUdevice_P2PAttribute;

/**
 * Limits
 */
typedef enum CUlimit_enum {
  CU_LIMIT_STACK_SIZE = 0x00,       /**< GPU thread stack size */
  CU_LIMIT_PRINTF_FIFO_SIZE = 0x01, /**< GPU printf FIFO size */
  CU_LIMIT_MALLOC_HEAP_SIZE = 0x02, /**< GPU malloc heap size */
  CU_LIMIT_DEV_RUNTIME_SYNC_DEPTH =
      0x03, /**< GPU device runtime launch synchronize depth */
  CU_LIMIT_DEV_RUNTIME_PENDING_LAUNCH_COUNT =
      0x04, /**< GPU device runtime pending launch count */
  CU_LIMIT_MAX
} CUlimit;

/**
 * Function cache configurations
 */
typedef enum CUfunc_cache_enum {
  CU_FUNC_CACHE_PREFER_NONE =
      0x00, /**< no preference for shared memory or L1 (default) */
  CU_FUNC_CACHE_PREFER_SHARED =
      0x01, /**< prefer larger shared memory and smaller L1 cache */
  CU_FUNC_CACHE_PREFER_L1 =
      0x02, /**< prefer larger L1 cache and smaller shared memory */
  CU_FUNC_CACHE_PREFER_EQUAL =
      0x03 /**< prefer equal sized L1 cache and shared memory */
} CUfunc_cache;

/**
 * Shared memory configurations
 */
typedef enum CUsharedconfig_enum {
  CU_SHARED_MEM_CONFIG_DEFAULT_BANK_SIZE =
      0x00, /**< set default shared memory bank size */
  CU_SHARED_MEM_CONFIG_FOUR_BYTE_BANK_SIZE =
      0x01, /**< set shared memory bank width to four bytes */
  CU_SHARED_MEM_CONFIG_EIGHT_BYTE_BANK_SIZE =
      0x02 /**< set shared memory bank width to eight bytes */
} CUsharedconfig;

/**
 * Online compiler and linker options
 */
typedef enum CUjit_option_enum {
  /**
   * Max number of registers that a thread may use.\n
   * Option type: unsigned int\n
   * Applies to: compiler only
   */
  CU_JIT_MAX_REGISTERS = 0,

  /**
   * IN: Specifies minimum number of threads per block to target compilation
   * for\n
   * OUT: Returns the number of threads the compiler actually targeted.
   * This restricts the resource utilization fo the compiler (e.g. max
   * registers) such that a block with the given number of threads should be
   * able to launch based on register limitations. Note, this option does not
   * currently take into account any other resource limitations, such as
   * shared memory utilization.\n
   * Cannot be combined with ::CU_JIT_TARGET.\n
   * Option type: unsigned int\n
   * Applies to: compiler only
   */
  CU_JIT_THREADS_PER_BLOCK,

  /**
   * Overwrites the option value with the total wall clock time, in
   * milliseconds, spent in the compiler and linker\n
   * Option type: float\n
   * Applies to: compiler and linker
   */
  CU_JIT_WALL_TIME,

  /**
   * Pointer to a buffer in which to print any log messages
   * that are informational in nature (the buffer size is specified via
   * option ::CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES)\n
   * Option type: char *\n
   * Applies to: compiler and linker
   */
  CU_JIT_INFO_LOG_BUFFER,

  /**
   * IN: Log buffer size in bytes.  Log messages will be capped at this size
   * (including null terminator)\n
   * OUT: Amount of log buffer filled with messages\n
   * Option type: unsigned int\n
   * Applies to: compiler and linker
   */
  CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES,

  /**
   * Pointer to a buffer in which to print any log messages that
   * reflect errors (the buffer size is specified via option
   * ::CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES)\n
   * Option type: char *\n
   * Applies to: compiler and linker
   */
  CU_JIT_ERROR_LOG_BUFFER,

  /**
   * IN: Log buffer size in bytes.  Log messages will be capped at this size
   * (including null terminator)\n
   * OUT: Amount of log buffer filled with messages\n
   * Option type: unsigned int\n
   * Applies to: compiler and linker
   */
  CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES,

  /**
   * Level of optimizations to apply to generated code (0 - 4), with 4
   * being the default and highest level of optimizations.\n
   * Option type: unsigned int\n
   * Applies to: compiler only
   */
  CU_JIT_OPTIMIZATION_LEVEL,

  /**
   * No option value required. Determines the target based on the current
   * attached context (default)\n
   * Option type: No option value needed\n
   * Applies to: compiler and linker
   */
  CU_JIT_TARGET_FROM_CUCONTEXT,

  /**
   * Target is chosen based on supplied ::CUjit_target.  Cannot be
   * combined with ::CU_JIT_THREADS_PER_BLOCK.\n
   * Option type: unsigned int for enumerated type ::CUjit_target\n
   * Applies to: compiler and linker
   */
  CU_JIT_TARGET,

  /**
   * Specifies choice of fallback strategy if matching cubin is not found.
   * Choice is based on supplied ::CUjit_fallback.  This option cannot be
   * used with cuLink* APIs as the linker requires exact matches.\n
   * Option type: unsigned int for enumerated type ::CUjit_fallback\n
   * Applies to: compiler only
   */
  CU_JIT_FALLBACK_STRATEGY,

  /**
   * Specifies whether to create debug information in output (-g)
   * (0: false, default)\n
   * Option type: int\n
   * Applies to: compiler and linker
   */
  CU_JIT_GENERATE_DEBUG_INFO,

  /**
   * Generate verbose log messages (0: false, default)\n
   * Option type: int\n
   * Applies to: compiler and linker
   */
  CU_JIT_LOG_VERBOSE,

  /**
   * Generate line number information (-lineinfo) (0: false, default)\n
   * Option type: int\n
   * Applies to: compiler only
   */
  CU_JIT_GENERATE_LINE_INFO,

  /**
   * Specifies whether to enable caching explicitly (-dlcm) \n
   * Choice is based on supplied ::CUjit_cacheMode_enum.\n
   * Option type: unsigned int for enumerated type ::CUjit_cacheMode_enum\n
   * Applies to: compiler only
   */
  CU_JIT_CACHE_MODE,

  /**
   * The below jit options are used for internal purposes only, in this version
   * of CUDA
   */
  CU_JIT_NEW_SM3X_OPT,
  CU_JIT_FAST_COMPILE,

  CU_JIT_NUM_OPTIONS

} CUjit_option;

/**
 * Device code formats
 */
typedef enum CUjitInputType_enum {
  /**
   * Compiled device-class-specific device code\n
   * Applicable options: none
   */
  CU_JIT_INPUT_CUBIN = 0,

  /**
   * PTX source code\n
   * Applicable options: PTX compiler options
   */
  CU_JIT_INPUT_PTX,

  /**
   * Bundle of multiple cubins and/or PTX of some device code\n
   * Applicable options: PTX compiler options, ::CU_JIT_FALLBACK_STRATEGY
   */
  CU_JIT_INPUT_FATBINARY,

  /**
   * Host object with embedded device code\n
   * Applicable options: PTX compiler options, ::CU_JIT_FALLBACK_STRATEGY
   */
  CU_JIT_INPUT_OBJECT,

  /**
   * Archive of host objects with embedded device code\n
   * Applicable options: PTX compiler options, ::CU_JIT_FALLBACK_STRATEGY
   */
  CU_JIT_INPUT_LIBRARY,

  CU_JIT_NUM_INPUT_TYPES
} CUjitInputType;

/**
 * Pointer information
 */
typedef enum CUpointer_attribute_enum {
  CU_POINTER_ATTRIBUTE_CONTEXT =
      1, /**< The ::CUcontext on which a pointer was allocated or registered */
  CU_POINTER_ATTRIBUTE_MEMORY_TYPE = 2, /**< The ::CUmemorytype describing the
                                           physical location of a pointer */
  CU_POINTER_ATTRIBUTE_DEVICE_POINTER =
      3, /**< The address at which a pointer's memory may be accessed on the
                            device */
  CU_POINTER_ATTRIBUTE_HOST_POINTER = 4, /**< The address at which a pointer's
                                            memory may be accessed on the host
                                            */
  CU_POINTER_ATTRIBUTE_P2P_TOKENS = 5,   /**< A pair of tokens for use with the
                                            nv-p2p.h Linux kernel interface */
  CU_POINTER_ATTRIBUTE_SYNC_MEMOPS = 6,  /**< Synchronize every synchronous
                                            memory operation initiated on this
                                            region */
  CU_POINTER_ATTRIBUTE_BUFFER_ID =
      7, /**< A process-wide unique ID for an allocated memory region*/
  CU_POINTER_ATTRIBUTE_IS_MANAGED =
      8 /**< Indicates if the pointer points to managed memory */
} CUpointer_attribute;

/**
 * Memory types
 */
typedef enum CUmemorytype_enum {
  CU_MEMORYTYPE_HOST = 0x01,   /**< Host memory */
  CU_MEMORYTYPE_DEVICE = 0x02, /**< Device memory */
  CU_MEMORYTYPE_ARRAY = 0x03,  /**< Array memory */
  CU_MEMORYTYPE_UNIFIED = 0x04 /**< Unified device or host memory */
} CUmemorytype;

/**
 * 2D memory copy parameters
 */
typedef struct CUDA_MEMCPY2D_st {
  size_t srcXInBytes; /**< Source X in bytes */
  size_t srcY;        /**< Source Y */

  CUmemorytype srcMemoryType; /**< Source memory type (host, device, array) */
  const void *srcHost;        /**< Source host pointer */
  CUdeviceptr srcDevice;      /**< Source device pointer */
  CUarray srcArray;           /**< Source array reference */
  size_t srcPitch;            /**< Source pitch (ignored when src is array) */

  size_t dstXInBytes; /**< Destination X in bytes */
  size_t dstY;        /**< Destination Y */

  CUmemorytype
      dstMemoryType;     /**< Destination memory type (host, device, array) */
  void *dstHost;         /**< Destination host pointer */
  CUdeviceptr dstDevice; /**< Destination device pointer */
  CUarray dstArray;      /**< Destination array reference */
  size_t dstPitch;       /**< Destination pitch (ignored when dst is array) */

  size_t WidthInBytes; /**< Width of 2D memory copy in bytes */
  size_t Height;       /**< Height of 2D memory copy */
} CUDA_MEMCPY2D;

/**
 * 3D memory copy parameters
 */
typedef struct CUDA_MEMCPY3D_st {
  size_t srcXInBytes;         /**< Source X in bytes */
  size_t srcY;                /**< Source Y */
  size_t srcZ;                /**< Source Z */
  size_t srcLOD;              /**< Source LOD */
  CUmemorytype srcMemoryType; /**< Source memory type (host, device, array) */
  const void *srcHost;        /**< Source host pointer */
  CUdeviceptr srcDevice;      /**< Source device pointer */
  CUarray srcArray;           /**< Source array reference */
  void *reserved0;            /**< Must be NULL */
  size_t srcPitch;            /**< Source pitch (ignored when src is array) */
  size_t srcHeight; /**< Source height (ignored when src is array; may be 0 if
                       Depth==1) */

  size_t dstXInBytes; /**< Destination X in bytes */
  size_t dstY;        /**< Destination Y */
  size_t dstZ;        /**< Destination Z */
  size_t dstLOD;      /**< Destination LOD */
  CUmemorytype
      dstMemoryType;     /**< Destination memory type (host, device, array) */
  void *dstHost;         /**< Destination host pointer */
  CUdeviceptr dstDevice; /**< Destination device pointer */
  CUarray dstArray;      /**< Destination array reference */
  void *reserved1;       /**< Must be NULL */
  size_t dstPitch;       /**< Destination pitch (ignored when dst is array) */
  size_t dstHeight; /**< Destination height (ignored when dst is array; may be 0
                       if Depth==1) */

  size_t WidthInBytes; /**< Width of 3D memory copy in bytes */
  size_t Height;       /**< Height of 3D memory copy */
  size_t Depth;        /**< Depth of 3D memory copy */
} CUDA_MEMCPY3D;

/**
 * 3D memory cross-context copy parameters
 */
typedef struct CUDA_MEMCPY3D_PEER_st {
  size_t srcXInBytes;         /**< Source X in bytes */
  size_t srcY;                /**< Source Y */
  size_t srcZ;                /**< Source Z */
  size_t srcLOD;              /**< Source LOD */
  CUmemorytype srcMemoryType; /**< Source memory type (host, device, array) */
  const void *srcHost;        /**< Source host pointer */
  CUdeviceptr srcDevice;      /**< Source device pointer */
  CUarray srcArray;           /**< Source array reference */
  CUcontext srcContext;       /**< Source context (ignored with srcMemoryType is
                                 ::CU_MEMORYTYPE_ARRAY) */
  size_t srcPitch;            /**< Source pitch (ignored when src is array) */
  size_t srcHeight; /**< Source height (ignored when src is array; may be 0 if
                       Depth==1) */

  size_t dstXInBytes; /**< Destination X in bytes */
  size_t dstY;        /**< Destination Y */
  size_t dstZ;        /**< Destination Z */
  size_t dstLOD;      /**< Destination LOD */
  CUmemorytype
      dstMemoryType;     /**< Destination memory type (host, device, array) */
  void *dstHost;         /**< Destination host pointer */
  CUdeviceptr dstDevice; /**< Destination device pointer */
  CUarray dstArray;      /**< Destination array reference */
  CUcontext dstContext;  /**< Destination context (ignored with dstMemoryType is
                            ::CU_MEMORYTYPE_ARRAY) */
  size_t dstPitch;       /**< Destination pitch (ignored when dst is array) */
  size_t dstHeight; /**< Destination height (ignored when dst is array; may be 0
                       if Depth==1) */

  size_t WidthInBytes; /**< Width of 3D memory copy in bytes */
  size_t Height;       /**< Height of 3D memory copy */
  size_t Depth;        /**< Depth of 3D memory copy */
} CUDA_MEMCPY3D_PEER;

/**
 * Function properties
 */
typedef enum CUfunction_attribute_enum {
  /**
   * The maximum number of threads per block, beyond which a launch of the
   * function would fail. This number depends on both the function and the
   * device on which the function is currently loaded.
   */
  CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 0,

  /**
   * The size in bytes of statically-allocated shared memory required by
   * this function. This does not include dynamically-allocated shared
   * memory requested by the user at runtime.
   */
  CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES = 1,

  /**
   * The size in bytes of user-allocated constant memory required by this
   * function.
   */
  CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES = 2,

  /**
   * The size in bytes of local memory used by each thread of this function.
   */
  CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES = 3,

  /**
   * The number of registers used by each thread of this function.
   */
  CU_FUNC_ATTRIBUTE_NUM_REGS = 4,

  /**
   * The PTX virtual architecture version for which the function was
   * compiled. This value is the major PTX version * 10 + the minor PTX
   * version, so a PTX version 1.3 function would return the value 13.
   * Note that this may return the undefined value of 0 for cubins
   * compiled prior to CUDA 3.0.
   */
  CU_FUNC_ATTRIBUTE_PTX_VERSION = 5,

  /**
   * The binary architecture version for which the function was compiled.
   * This value is the major binary version * 10 + the minor binary version,
   * so a binary version 1.3 function would return the value 13. Note that
   * this will return a value of 10 for legacy cubins that do not have a
   * properly-encoded binary architecture version.
   */
  CU_FUNC_ATTRIBUTE_BINARY_VERSION = 6,

  /**
   * The attribute to indicate whether the function has been compiled with
   * user specified option "-Xptxas --dlcm=ca" set .
   */
  CU_FUNC_ATTRIBUTE_CACHE_MODE_CA = 7,

  CU_FUNC_ATTRIBUTE_MAX
} CUfunction_attribute;

/**
 * Array formats
 */
typedef enum CUarray_format_enum {
  CU_AD_FORMAT_UNSIGNED_INT8 = 0x01,  /**< Unsigned 8-bit integers */
  CU_AD_FORMAT_UNSIGNED_INT16 = 0x02, /**< Unsigned 16-bit integers */
  CU_AD_FORMAT_UNSIGNED_INT32 = 0x03, /**< Unsigned 32-bit integers */
  CU_AD_FORMAT_SIGNED_INT8 = 0x08,    /**< Signed 8-bit integers */
  CU_AD_FORMAT_SIGNED_INT16 = 0x09,   /**< Signed 16-bit integers */
  CU_AD_FORMAT_SIGNED_INT32 = 0x0a,   /**< Signed 32-bit integers */
  CU_AD_FORMAT_HALF = 0x10,           /**< 16-bit floating point */
  CU_AD_FORMAT_FLOAT = 0x20           /**< 32-bit floating point */
} CUarray_format;

/**
 * Array descriptor
 */
typedef struct CUDA_ARRAY_DESCRIPTOR_st {
  size_t Width;  /**< Width of array */
  size_t Height; /**< Height of array */

  CUarray_format Format;    /**< Array format */
  unsigned int NumChannels; /**< Channels per array element */
} CUDA_ARRAY_DESCRIPTOR;

/**
 * 3D array descriptor
 */
typedef struct CUDA_ARRAY3D_DESCRIPTOR_st {
  size_t Width;  /**< Width of 3D array */
  size_t Height; /**< Height of 3D array */
  size_t Depth;  /**< Depth of 3D array */

  CUarray_format Format;    /**< Array format */
  unsigned int NumChannels; /**< Channels per array element */
  unsigned int Flags;       /**< Flags */
} CUDA_ARRAY3D_DESCRIPTOR;

/**
 * Texture reference addressing modes
 */
typedef enum CUaddress_mode_enum {
  CU_TR_ADDRESS_MODE_WRAP = 0,   /**< Wrapping address mode */
  CU_TR_ADDRESS_MODE_CLAMP = 1,  /**< Clamp to edge address mode */
  CU_TR_ADDRESS_MODE_MIRROR = 2, /**< Mirror address mode */
  CU_TR_ADDRESS_MODE_BORDER = 3  /**< Border address mode */
} CUaddress_mode;

/**
 * Texture reference filtering modes
 */
typedef enum CUfilter_mode_enum {
  CU_TR_FILTER_MODE_POINT = 0, /**< Point filter mode */
  CU_TR_FILTER_MODE_LINEAR = 1 /**< Linear filter mode */
} CUfilter_mode;

/**
 * Resource types
 */
typedef enum CUresourcetype_enum {
  CU_RESOURCE_TYPE_ARRAY = 0x00,           /**< Array resoure */
  CU_RESOURCE_TYPE_MIPMAPPED_ARRAY = 0x01, /**< Mipmapped array resource */
  CU_RESOURCE_TYPE_LINEAR = 0x02,          /**< Linear resource */
  CU_RESOURCE_TYPE_PITCH2D = 0x03          /**< Pitch 2D resource */
} CUresourcetype;

/**
 * CUDA Resource descriptor
 */
typedef struct CUDA_RESOURCE_DESC_st {
  CUresourcetype resType; /**< Resource type */

  union {
    struct {
      CUarray hArray; /**< CUDA array */
    } array;
    struct {
      CUmipmappedArray hMipmappedArray; /**< CUDA mipmapped array */
    } mipmap;
    struct {
      CUdeviceptr devPtr;       /**< Device pointer */
      CUarray_format format;    /**< Array format */
      unsigned int numChannels; /**< Channels per array element */
      size_t sizeInBytes;       /**< Size in bytes */
    } linear;
    struct {
      CUdeviceptr devPtr;       /**< Device pointer */
      CUarray_format format;    /**< Array format */
      unsigned int numChannels; /**< Channels per array element */
      size_t width;             /**< Width of the array in elements */
      size_t height;            /**< Height of the array in elements */
      size_t pitchInBytes;      /**< Pitch between two rows in bytes */
    } pitch2D;
    struct {
      int reserved[32];
    } reserved;
  } res;

  unsigned int flags; /**< Flags (must be zero) */
} CUDA_RESOURCE_DESC;

/**
 * Texture descriptor
 */
typedef struct CUDA_TEXTURE_DESC_st {
  CUaddress_mode addressMode[3];  /**< Address modes */
  CUfilter_mode filterMode;       /**< Filter mode */
  unsigned int flags;             /**< Flags */
  unsigned int maxAnisotropy;     /**< Maximum anisotropy ratio */
  CUfilter_mode mipmapFilterMode; /**< Mipmap filter mode */
  float mipmapLevelBias;          /**< Mipmap level bias */
  float minMipmapLevelClamp;      /**< Mipmap minimum level clamp */
  float maxMipmapLevelClamp;      /**< Mipmap maximum level clamp */
  float borderColor[4];           /**< Border Color */
  int reserved[12];
} CUDA_TEXTURE_DESC;

/**
 * Resource view format
 */
typedef enum CUresourceViewFormat_enum {
  CU_RES_VIEW_FORMAT_NONE =
      0x00, /**< No resource view format (use underlying resource format) */
  CU_RES_VIEW_FORMAT_UINT_1X8 = 0x01, /**< 1 channel unsigned 8-bit integers */
  CU_RES_VIEW_FORMAT_UINT_2X8 = 0x02, /**< 2 channel unsigned 8-bit integers */
  CU_RES_VIEW_FORMAT_UINT_4X8 = 0x03, /**< 4 channel unsigned 8-bit integers */
  CU_RES_VIEW_FORMAT_SINT_1X8 = 0x04, /**< 1 channel signed 8-bit integers */
  CU_RES_VIEW_FORMAT_SINT_2X8 = 0x05, /**< 2 channel signed 8-bit integers */
  CU_RES_VIEW_FORMAT_SINT_4X8 = 0x06, /**< 4 channel signed 8-bit integers */
  CU_RES_VIEW_FORMAT_UINT_1X16 =
      0x07, /**< 1 channel unsigned 16-bit integers */
  CU_RES_VIEW_FORMAT_UINT_2X16 =
      0x08, /**< 2 channel unsigned 16-bit integers */
  CU_RES_VIEW_FORMAT_UINT_4X16 =
      0x09, /**< 4 channel unsigned 16-bit integers */
  CU_RES_VIEW_FORMAT_SINT_1X16 = 0x0a, /**< 1 channel signed 16-bit integers */
  CU_RES_VIEW_FORMAT_SINT_2X16 = 0x0b, /**< 2 channel signed 16-bit integers */
  CU_RES_VIEW_FORMAT_SINT_4X16 = 0x0c, /**< 4 channel signed 16-bit integers */
  CU_RES_VIEW_FORMAT_UINT_1X32 =
      0x0d, /**< 1 channel unsigned 32-bit integers */
  CU_RES_VIEW_FORMAT_UINT_2X32 =
      0x0e, /**< 2 channel unsigned 32-bit integers */
  CU_RES_VIEW_FORMAT_UINT_4X32 =
      0x0f, /**< 4 channel unsigned 32-bit integers */
  CU_RES_VIEW_FORMAT_SINT_1X32 = 0x10,  /**< 1 channel signed 32-bit integers */
  CU_RES_VIEW_FORMAT_SINT_2X32 = 0x11,  /**< 2 channel signed 32-bit integers */
  CU_RES_VIEW_FORMAT_SINT_4X32 = 0x12,  /**< 4 channel signed 32-bit integers */
  CU_RES_VIEW_FORMAT_FLOAT_1X16 = 0x13, /**< 1 channel 16-bit floating point */
  CU_RES_VIEW_FORMAT_FLOAT_2X16 = 0x14, /**< 2 channel 16-bit floating point */
  CU_RES_VIEW_FORMAT_FLOAT_4X16 = 0x15, /**< 4 channel 16-bit floating point */
  CU_RES_VIEW_FORMAT_FLOAT_1X32 = 0x16, /**< 1 channel 32-bit floating point */
  CU_RES_VIEW_FORMAT_FLOAT_2X32 = 0x17, /**< 2 channel 32-bit floating point */
  CU_RES_VIEW_FORMAT_FLOAT_4X32 = 0x18, /**< 4 channel 32-bit floating point */
  CU_RES_VIEW_FORMAT_UNSIGNED_BC1 = 0x19, /**< Block compressed 1 */
  CU_RES_VIEW_FORMAT_UNSIGNED_BC2 = 0x1a, /**< Block compressed 2 */
  CU_RES_VIEW_FORMAT_UNSIGNED_BC3 = 0x1b, /**< Block compressed 3 */
  CU_RES_VIEW_FORMAT_UNSIGNED_BC4 = 0x1c, /**< Block compressed 4 unsigned */
  CU_RES_VIEW_FORMAT_SIGNED_BC4 = 0x1d,   /**< Block compressed 4 signed */
  CU_RES_VIEW_FORMAT_UNSIGNED_BC5 = 0x1e, /**< Block compressed 5 unsigned */
  CU_RES_VIEW_FORMAT_SIGNED_BC5 = 0x1f,   /**< Block compressed 5 signed */
  CU_RES_VIEW_FORMAT_UNSIGNED_BC6H =
      0x20, /**< Block compressed 6 unsigned half-float */
  CU_RES_VIEW_FORMAT_SIGNED_BC6H =
      0x21, /**< Block compressed 6 signed half-float */
  CU_RES_VIEW_FORMAT_UNSIGNED_BC7 = 0x22 /**< Block compressed 7 */
} CUresourceViewFormat;

/**
 * Resource view descriptor
 */
typedef struct CUDA_RESOURCE_VIEW_DESC_st {
  CUresourceViewFormat format;   /**< Resource view format */
  size_t width;                  /**< Width of the resource view */
  size_t height;                 /**< Height of the resource view */
  size_t depth;                  /**< Depth of the resource view */
  unsigned int firstMipmapLevel; /**< First defined mipmap level */
  unsigned int lastMipmapLevel;  /**< Last defined mipmap level */
  unsigned int firstLayer;       /**< First layer index */
  unsigned int lastLayer;        /**< Last layer index */
  unsigned int reserved[16];
} CUDA_RESOURCE_VIEW_DESC;

/**
 * Operations for ::cuStreamBatchMemOp
 */
typedef enum CUstreamBatchMemOpType_enum {
  CU_STREAM_MEM_OP_WAIT_VALUE_32 =
      1, /**< Represents a ::cuStreamWaitValue32 operation */
  CU_STREAM_MEM_OP_WRITE_VALUE_32 =
      2, /**< Represents a ::cuStreamWriteValue32 operation */
  CU_STREAM_MEM_OP_FLUSH_REMOTE_WRITES =
      3 /**< This has the same effect as ::CU_STREAM_WAIT_VALUE_FLUSH, but as a
                               standalone operation. */
} CUstreamBatchMemOpType;

/**
 * Per-operation parameters for ::cuStreamBatchMemOp
 */
typedef union CUstreamBatchMemOpParams_union {
  CUstreamBatchMemOpType operation;
  struct CUstreamMemOpWaitValueParams_st {
    CUstreamBatchMemOpType operation;
    CUdeviceptr address;
    union {
      cuuint32_t value;
      cuuint64_t pad;
    };
    unsigned int flags;
    CUdeviceptr
        alias; /**< For driver internal use. Initial value is unimportant. */
  } waitValue;
  struct CUstreamMemOpWriteValueParams_st {
    CUstreamBatchMemOpType operation;
    CUdeviceptr address;
    union {
      cuuint32_t value;
      cuuint64_t pad;
    };
    unsigned int flags;
    CUdeviceptr
        alias; /**< For driver internal use. Initial value is unimportant. */
  } writeValue;
  struct CUstreamMemOpFlushRemoteWritesParams_st {
    CUstreamBatchMemOpType operation;
    unsigned int flags;
  } flushRemoteWrites;
  cuuint64_t pad[6];
} CUstreamBatchMemOpParams;

typedef void (*CUstreamCallback)(CUstream hStream, CUresult status,
                                 void *userData);

/**
 * CUDA IPC handle size
 */
#define CU_IPC_HANDLE_SIZE 64

/**
 * CUDA IPC event handle
 */
typedef struct CUipcEventHandle_st {
  char reserved[CU_IPC_HANDLE_SIZE];
} CUipcEventHandle;

/**
 * CUDA IPC mem handle
 */
typedef struct CUipcMemHandle_st {
  char reserved[CU_IPC_HANDLE_SIZE];
} CUipcMemHandle;

/**
 * CUDA devices corresponding to an OpenGL device
 */
typedef enum CUGLDeviceList_enum {
  CU_GL_DEVICE_LIST_ALL = 0x01, /**< The CUDA devices for all GPUs used by the
                                   current OpenGL context */
  CU_GL_DEVICE_LIST_CURRENT_FRAME =
      0x02, /**< The CUDA devices for the GPUs used by the current OpenGL
                               context in its currently rendering frame */
  CU_GL_DEVICE_LIST_NEXT_FRAME =
      0x03, /**< The CUDA devices for the GPUs to be used by the current OpenGL
                               context in the next frame */
} CUGLDeviceList;

/**
 * Profiler Output Modes
 */
/*DEVICE_BUILTIN*/
typedef enum CUoutput_mode_enum {
  CU_OUT_KEY_VALUE_PAIR = 0x00, /**< Output mode Key-Value pair format. */
  CU_OUT_CSV = 0x01 /**< Output mode Comma separated values format. */
} CUoutput_mode;

/**
 * Memory advise values
 */
typedef enum CUmem_advise_enum {
  CU_MEM_ADVISE_SET_READ_MOSTLY =
      1, /**< Data will mostly be read and only occassionally be written to */
  CU_MEM_ADVISE_UNSET_READ_MOSTLY =
      2, /**< Undo the effect of ::CU_MEM_ADVISE_SET_READ_MOSTLY */
  CU_MEM_ADVISE_SET_PREFERRED_LOCATION =
      3, /**< Set the preferred location for the data as the specified device */
  CU_MEM_ADVISE_UNSET_PREFERRED_LOCATION =
      4, /**< Clear the preferred location for the data */
  CU_MEM_ADVISE_SET_ACCESSED_BY =
      5, /**< Data will be accessed by the specified device, so prevent page
                            faults as much as possible */
  CU_MEM_ADVISE_UNSET_ACCESSED_BY = 6 /**< Let the Unified Memory subsystem
                                         decide on the page faulting policy for
                                         the specified device */
} CUmem_advise;

typedef enum CUmem_range_attribute_enum {
  CU_MEM_RANGE_ATTRIBUTE_READ_MOSTLY =
      1, /**< Whether the range will mostly be read and only occassionally be
                            written to */
  CU_MEM_RANGE_ATTRIBUTE_PREFERRED_LOCATION =
      2, /**< The preferred location of the range */
  CU_MEM_RANGE_ATTRIBUTE_ACCESSED_BY = 3, /**< Memory range has
                                             ::CU_MEM_ADVISE_SET_ACCESSED_BY set
                                             for specified device */
  CU_MEM_RANGE_ATTRIBUTE_LAST_PREFETCH_LOCATION =
      4 /**< The last location to which the range was prefetched */
} CUmem_range_attribute;

typedef const struct CUDBGAPI_st *CUDBGAPI;

typedef enum {
  CUDBG_SUCCESS = 0x0000,       /* Successful execution */
  CUDBG_ERROR_UNKNOWN = 0x0001, /* Error type not listed below */
  CUDBG_ERROR_BUFFER_TOO_SMALL =
      0x0002, /* Cannot copy all the queried data into the buffer argument */
  CUDBG_ERROR_UNKNOWN_FUNCTION =
      0x0003, /* Function cannot be found in the CUDA kernel */
  CUDBG_ERROR_INVALID_ARGS =
      0x0004, /* Wrong use of arguments (NULL pointer, illegal value,...) */
  CUDBG_ERROR_UNINITIALIZED =
      0x0005, /* Debugger API has not yet been properly initialized */
  CUDBG_ERROR_INVALID_COORDINATES =
      0x0006, /* Invalid block or thread coordinates were provided */
  CUDBG_ERROR_INVALID_MEMORY_SEGMENT =
      0x0007, /* Invalid memory segment requested (read/write) */
  CUDBG_ERROR_INVALID_MEMORY_ACCESS = 0x0008, /* Requested address (+size) is
                                                 not within proper segment
                                                 boundaries */
  CUDBG_ERROR_MEMORY_MAPPING_FAILED =
      0x0009,                    /* Memory is not mapped and cannot be mapped */
  CUDBG_ERROR_INTERNAL = 0x000a, /* A debugger internal error occurred */
  CUDBG_ERROR_INVALID_DEVICE = 0x000b,   /* Specified device cannot be found */
  CUDBG_ERROR_INVALID_SM = 0x000c,       /* Specified sm cannot be found */
  CUDBG_ERROR_INVALID_WARP = 0x000d,     /* Specified warp cannot be found */
  CUDBG_ERROR_INVALID_LANE = 0x000e,     /* Specified lane cannot be found */
  CUDBG_ERROR_SUSPENDED_DEVICE = 0x000f, /* device is suspended */
  CUDBG_ERROR_RUNNING_DEVICE = 0x0010, /* device is running and not suspended */
  CUDBG_ERROR_RESERVED_0 = 0x0011,     /* Reserved error code */
  CUDBG_ERROR_INVALID_ADDRESS = 0x0012,  /* address is out-of-range */
  CUDBG_ERROR_INCOMPATIBLE_API = 0x0013, /* API version does not match */
  CUDBG_ERROR_INITIALIZATION_FAILURE =
      0x0014,                        /* The CUDA Driver failed to initialize */
  CUDBG_ERROR_INVALID_GRID = 0x0015, /* Specified grid cannot be found */
  CUDBG_ERROR_NO_EVENT_AVAILABLE = 0x0016, /* No event left to be processed */
  CUDBG_ERROR_SOME_DEVICES_WATCHDOGGED =
      0x0017, /* One or more devices have an associated watchdog (eg. X) */
  CUDBG_ERROR_ALL_DEVICES_WATCHDOGGED =
      0x0018, /* All devices have an associated watchdog (eg. X) */
  CUDBG_ERROR_INVALID_ATTRIBUTE =
      0x0019, /* Specified attribute does not exist or is incorrect */
  CUDBG_ERROR_ZERO_CALL_DEPTH =
      0x001a, /* No function calls have been made on the device */
  CUDBG_ERROR_INVALID_CALL_LEVEL = 0x001b, /* Specified call level is invalid */
  CUDBG_ERROR_COMMUNICATION_FAILURE =
      0x001c, /* Communication error between the debugger and the application.
               */
  CUDBG_ERROR_INVALID_CONTEXT = 0x001d, /* Specified context cannot be found */
  CUDBG_ERROR_ADDRESS_NOT_IN_DEVICE_MEM =
      0x001e, /* Requested address was not originally allocated from device
                                 memory (most likely visible in system memory)
               */
  CUDBG_ERROR_MEMORY_UNMAPPING_FAILED =
      0x001f, /* Memory is not unmapped and cannot be unmapped */
  CUDBG_ERROR_INCOMPATIBLE_DISPLAY_DRIVER =
      0x0020, /* The display driver is incompatible with the API */
  CUDBG_ERROR_INVALID_MODULE = 0x0021, /* The specified module is not valid */
  CUDBG_ERROR_LANE_NOT_IN_SYSCALL =
      0x0022, /* The specified lane is not inside a device syscall */
  CUDBG_ERROR_MEMCHECK_NOT_ENABLED = 0x0023, /* Memcheck has not been enabled */
  CUDBG_ERROR_INVALID_ENVVAR_ARGS =
      0x0024, /* Some environment variable's value is invalid */
  CUDBG_ERROR_OS_RESOURCES =
      0x0025, /* Error while allocating resources from the OS */
  CUDBG_ERROR_FORK_FAILED =
      0x0026, /* Error while forking the debugger process */
  CUDBG_ERROR_NO_DEVICE_AVAILABLE =
      0x0027, /* No CUDA capable device was found */
  CUDBG_ERROR_ATTACH_NOT_POSSIBLE =
      0x0028, /* Attaching to the CUDA program is not possible */
  CUDBG_ERROR_WARP_RESUME_NOT_POSSIBLE =
      0x0029, /* The resumeWarpsUntilPC() API is not possible, use
                                 resumeDevice() or singleStepWarp() instead */
  CUDBG_ERROR_INVALID_WARP_MASK =
      0x002a, /* Specified warp mask is zero, or contains invalid warps */
  CUDBG_ERROR_AMBIGUOUS_MEMORY_ADDRESS =
      0x002b, /* Address cannot be resolved to a GPU unambiguously */
  CUDBG_ERROR_RECURSIVE_API_CALL =
      0x002c, /* Debug API entry point called from within a debug API callback
               */
} CUDBGResult;

/**
 * Legacy device properties
 */
typedef struct CUdevprop_st {
  int maxThreadsPerBlock;  /**< Maximum number of threads per block */
  int maxThreadsDim[3];    /**< Maximum size of each dimension of a block */
  int maxGridSize[3];      /**< Maximum size of each dimension of a grid */
  int sharedMemPerBlock;   /**< Shared memory available per block in bytes */
  int totalConstantMemory; /**< Constant memory available on device in bytes */
  int SIMDWidth;           /**< Warp size in threads */
  int memPitch;     /**< Maximum pitch in bytes allowed by memory copies */
  int regsPerBlock; /**< 32-bit registers available per block */
  int clockRate;    /**< Clock frequency in kilohertz */
  int textureAlign; /**< Alignment requirement for textures */
} CUdevprop;

typedef struct CUeglStreamConnection_st *CUeglStreamConnection;

#define MAX_PLANES 3

typedef enum CUeglFrameType_enum {
  CU_EGL_FRAME_TYPE_ARRAY = 0,
  CU_EGL_FRAME_TYPE_PITCH = 1,
} CUeglFrameType;

typedef enum CueglColorFormat_enum {
  CU_EGL_COLOR_FORMAT_YUV420_PLANAR = 0x00,
  CU_EGL_COLOR_FORMAT_YUV420_SEMIPLANAR = 0x01,
  CU_EGL_COLOR_FORMAT_YUV422_PLANAR = 0x02,
  CU_EGL_COLOR_FORMAT_YUV422_SEMIPLANAR = 0x03,
  CU_EGL_COLOR_FORMAT_RGB = 0x04,
  CU_EGL_COLOR_FORMAT_BGR = 0x05,
  CU_EGL_COLOR_FORMAT_ARGB = 0x06,
  CU_EGL_COLOR_FORMAT_RGBA = 0x07,
  CU_EGL_COLOR_FORMAT_L = 0x08,
  CU_EGL_COLOR_FORMAT_R = 0x09
} CUeglColorFormat;

typedef struct CUeglFrame_st {
  union {
    CUarray pArray[MAX_PLANES];
    void *pPitch[MAX_PLANES];
  } frame;
  unsigned int width;
  unsigned int height;
  unsigned int depth;
  unsigned int pitch;
  unsigned int planeCount;
  unsigned int numChannels;
  CUeglFrameType frameType;
  CUeglColorFormat eglColorFormat;
  CUarray_format cuFormat;
} CUeglFrame;

typedef struct CUDA_LAUNCH_PARAMS_st {
  unsigned int blockDimX;
  unsigned int blockDimY;
  unsigned int blockDimZ;
  CUfunction function;
  unsigned int gridDimX;
  unsigned int gridDimY;
  unsigned int gridDimZ;
  CUstream hStream;
  void **kernelParams;
  unsigned int sharedMemBytes;
} CUDA_LAUNCH_PARAMS;

typedef size_t (*CUoccupancyB2DSize)(int blockSize);

/** EGL */
typedef void *EGLStreamKHR;
typedef int32_t EGLint;
typedef void *EGLImageKHR;

/**
 * External memory buffer descriptor
 */
typedef struct CUDA_EXTERNAL_MEMORY_BUFFER_DESC_st {
  /**
   * Offset into the memory object where the buffer's base is
   */
  unsigned long long offset;
  /**
   * Size of the buffer
   */
  unsigned long long size;
  /**
   * Flags reserved for future use. Must be zero.
   */
  unsigned int flags;
  unsigned int reserved[16];
} CUDA_EXTERNAL_MEMORY_BUFFER_DESC;

/**
 * External memory mipmap descriptor
 */
typedef struct CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC_st {
  /**
   * Offset into the memory object where the base level of the
   * mipmap chain is.
   */
  unsigned long long offset;
  /**
   * Format, dimension and type of base level of the mipmap chain
   */
  CUDA_ARRAY3D_DESCRIPTOR arrayDesc;
  /**
   * Total number of levels in the mipmap chain
   */
  unsigned int numLevels;
  unsigned int reserved[16];
} CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC;

/**
 * CUDA host function
 * \param userData Argument value passed to the function
 */
typedef void (*CUhostFn)(void *userData);

/**
 * Host node parameters
 */
typedef struct CUDA_HOST_NODE_PARAMS_st {
  CUhostFn fn;    /**< The function to call when the node executes */
  void *userData; /**< Argument to pass to the function */
} CUDA_HOST_NODE_PARAMS;

/**
 * Graph node types
 */
typedef enum CUgraphNodeType_enum {
  CU_GRAPH_NODE_TYPE_KERNEL = 0, /**< GPU kernel node */
  CU_GRAPH_NODE_TYPE_MEMCPY = 1, /**< Memcpy node */
  CU_GRAPH_NODE_TYPE_MEMSET = 2, /**< Memset node */
  CU_GRAPH_NODE_TYPE_HOST = 3,   /**< Host (executable) node */
  CU_GRAPH_NODE_TYPE_GRAPH = 4,  /**< Node which executes an embedded graph */
  CU_GRAPH_NODE_TYPE_EMPTY = 5,  /**< Empty (no-op) node */
  CU_GRAPH_NODE_TYPE_COUNT
} CUgraphNodeType;

/**
 * GPU kernel node parameters
 */
typedef struct CUDA_KERNEL_NODE_PARAMS_st {
  CUfunction func;             /**< Kernel to launch */
  unsigned int gridDimX;       /**< Width of grid in blocks */
  unsigned int gridDimY;       /**< Height of grid in blocks */
  unsigned int gridDimZ;       /**< Depth of grid in blocks */
  unsigned int blockDimX;      /**< X dimension of each thread block */
  unsigned int blockDimY;      /**< Y dimension of each thread block */
  unsigned int blockDimZ;      /**< Z dimension of each thread block */
  unsigned int sharedMemBytes; /**< Dynamic shared-memory size per thread block
                                  in bytes */
  void **kernelParams;         /**< Array of pointers to kernel parameters */
  void **extra;                /**< Extra options */
} CUDA_KERNEL_NODE_PARAMS;

/**
 * Memset node parameters
 */
typedef struct CUDA_MEMSET_NODE_PARAMS_st {
  CUdeviceptr dst; /**< Destination device pointer */
  size_t
      pitch; /**< Pitch of destination device pointer. Unused if height is 1 */
  unsigned int value; /**< Value to be set */
  unsigned int
      elementSize; /**< Size of each element in bytes. Must be 1, 2, or 4. */
  size_t width;    /**< Width in bytes, of the row */
  size_t height;   /**< Number of rows */
} CUDA_MEMSET_NODE_PARAMS;

/**
 * External memory handle types
 */
typedef enum CUexternalMemoryHandleType_enum {
  /**
   * Handle is an opaque file descriptor
   */
  CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD = 1,
  /**
   * Handle is an opaque shared NT handle
   */
  CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32 = 2,
  /**
   * Handle is an opaque, globally shared handle
   */
  CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT = 3,
  /**
   * Handle is a D3D12 heap object
   */
  CU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP = 4,
  /**
   * Handle is a D3D12 committed resource
   */
  CU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE = 5
} CUexternalMemoryHandleType;

/**
 * External memory handle descriptor
 */
typedef struct CUDA_EXTERNAL_MEMORY_HANDLE_DESC_st {
  /**
   * Type of the handle
   */
  CUexternalMemoryHandleType type;
  union {
    /**
     * File descriptor referencing the memory object. Valid
     * when type is
     * ::CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD
     */
    int fd;
    /**
     * Win32 handle referencing the semaphore object. Valid when
     * type is one of the following:
     * - ::CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32
     * - ::CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT
     * - ::CU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP
     * - ::CU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE
     * Exactly one of 'handle' and 'name' must be non-NULL. If
     * type is
     * ::CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT
     * then 'name' must be NULL.
     */
    struct {
      /**
       * Valid NT handle. Must be NULL if 'name' is non-NULL
       */
      void *handle;
      /**
       * Name of a valid memory object.
       * Must be NULL if 'handle' is non-NULL.
       */
      const void *name;
    } win32;
  } handle;
  /**
   * Size of the memory allocation
   */
  unsigned long long size;
  /**
   * Flags must either be zero or ::CUDA_EXTERNAL_MEMORY_DEDICATED
   */
  unsigned int flags;
  unsigned int reserved[16];
} CUDA_EXTERNAL_MEMORY_HANDLE_DESC;

/**
 * External semaphore handle types
 */
typedef enum CUexternalSemaphoreHandleType_enum {
  /**
   * Handle is an opaque file descriptor
   */
  CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD = 1,
  /**
   * Handle is an opaque shared NT handle
   */
  CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32 = 2,
  /**
   * Handle is an opaque, globally shared handle
   */
  CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT = 3,
  /**
   * Handle is a shared NT handle referencing a D3D12 fence object
   */
  CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE = 4
} CUexternalSemaphoreHandleType;

/**
 * External semaphore handle descriptor
 */
typedef struct CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC_st {
  /**
   * Type of the handle
   */
  CUexternalSemaphoreHandleType type;
  union {
    /**
     * File descriptor referencing the semaphore object. Valid
     * when type is
     * ::CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD
     */
    int fd;
    /**
     * Win32 handle referencing the semaphore object. Valid when
     * type is one of the following:
     * - ::CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32
     * - ::CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT
     * - ::CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE
     * Exactly one of 'handle' and 'name' must be non-NULL. If
     * type is
     * ::CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT
     * then 'name' must be NULL.
     */
    struct {
      /**
       * Valid NT handle. Must be NULL if 'name' is non-NULL
       */
      void *handle;
      /**
       * Name of a valid synchronization primitive.
       * Must be NULL if 'handle' is non-NULL.
       */
      const void *name;
    } win32;
  } handle;
  /**
   * Flags reserved for the future. Must be zero.
   */
  unsigned int flags;
  unsigned int reserved[16];
} CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC;

/**
 * External semaphore signal parameters
 */
typedef struct CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS_st {
  struct {
    /**
     * Parameters for fence objects
     */
    struct {
      /**
       * Value of fence to be signaled
       */
      unsigned long long value;
    } fence;
    unsigned int reserved[16];
  } params;
  /**
   * Flags reserved for the future. Must be zero.
   */
  unsigned int flags;
  unsigned int reserved[16];
} CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS;

/**
 * Possible modes for stream capture thread interactions. For more details see
 * ::cuStreamBeginCapture and ::cuThreadExchangeStreamCaptureMode
 */
typedef enum CUstreamCaptureMode_enum {
  CU_STREAM_CAPTURE_MODE_GLOBAL = 0,
  CU_STREAM_CAPTURE_MODE_THREAD_LOCAL = 1,
  CU_STREAM_CAPTURE_MODE_RELAXED = 2
} CUstreamCaptureMode;

/**
 * Possible stream capture statuses returned by ::cuStreamIsCapturing
 */
typedef enum CUstreamCaptureStatus_enum {
  CU_STREAM_CAPTURE_STATUS_NONE = 0,   /**< Stream is not capturing */
  CU_STREAM_CAPTURE_STATUS_ACTIVE = 1, /**< Stream is actively capturing */
  CU_STREAM_CAPTURE_STATUS_INVALIDATED =
      2 /**< Stream is part of a capture sequence that
                   has been invalidated, but not terminated */
} CUstreamCaptureStatus;

/**
 * External semaphore wait parameters
 */
typedef struct CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS_st {
  struct {
    /**
     * Parameters for fence objects
     */
    struct {
      /**
       * Value of fence to be waited on
       */
      unsigned long long value;
    } fence;
    unsigned int reserved[16];
  } params;
  /**
   * Flags reserved for the future. Must be zero.
   */
  unsigned int flags;
  unsigned int reserved[16];
} CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS;

typedef unsigned long long CUmemGenericAllocationHandle;

typedef enum CUgraphExecUpdateResult_enum {
  CU_GRAPH_EXEC_UPDATE_SUCCESS = 0x0, /**< The update succeeded */
  CU_GRAPH_EXEC_UPDATE_ERROR =
      0x1, /**< The update failed for an unexpected reason which is described in
                  the return value of the function */
  CU_GRAPH_EXEC_UPDATE_ERROR_TOPOLOGY_CHANGED =
      0x2, /**< The update failed because the topology changed */
  CU_GRAPH_EXEC_UPDATE_ERROR_NODE_TYPE_CHANGED =
      0x3, /**< The update failed because a node type changed */
  CU_GRAPH_EXEC_UPDATE_ERROR_FUNCTION_CHANGED =
      0x4, /**< The update failed because the function of a kernel node changed
            */
  CU_GRAPH_EXEC_UPDATE_ERROR_PARAMETERS_CHANGED =
      0x5, /**< The update failed because the parameters changed in a way that
                  is not supported */
  CU_GRAPH_EXEC_UPDATE_ERROR_NOT_SUPPORTED =
      0x6 /**< The update failed because something about the node is not
                 supported */
} CUgraphExecUpdateResult;

/**
 * Defines the allocation types available
 */
typedef enum CUmemAllocationType_enum {
  CU_MEM_ALLOCATION_TYPE_INVALID = 0x0,

  /** This allocation type is 'pinned', i.e. cannot migrate from its current
   * location while the application is actively using it
   */
  CU_MEM_ALLOCATION_TYPE_PINNED = 0x1,
  CU_MEM_ALLOCATION_TYPE_MAX = 0xFFFFFFFF
} CUmemAllocationType;

/**
 * Flags for specifying particular handle types
 */
typedef enum CUmemAllocationHandleType_enum {
  CU_MEM_HANDLE_TYPE_POSIX_FILE_DESCRIPTOR =
      0x1, /**< Allows a file descriptor to be used for exporting. Permitted
                  only on POSIX systems. (int) */
  CU_MEM_HANDLE_TYPE_WIN32 =
      0x2, /**< Allows a Win32 NT handle to be used for exporting. (HANDLE) */
  CU_MEM_HANDLE_TYPE_WIN32_KMT = 0x4, /**< Allows a Win32 KMT handle to be used
                                         for exporting. (D3DKMT_HANDLE) */
  CU_MEM_HANDLE_TYPE_MAX = 0xFFFFFFFF
} CUmemAllocationHandleType;

/**
 * Specifies the type of location
 */
typedef enum CUmemLocationType_enum {
  CU_MEM_LOCATION_TYPE_INVALID = 0x0,
  CU_MEM_LOCATION_TYPE_DEVICE =
      0x1, /**< Location is a device location, thus id is a device ordinal */
  CU_MEM_LOCATION_TYPE_MAX = 0xFFFFFFFF
} CUmemLocationType;

/**
 * Specifies a location for an allocation.
 */
typedef struct CUmemLocation_st {
  CUmemLocationType type; /**< Specifies the location type, which modifies the
                             meaning of id. */
  int id; /**< identifier for a given this location's ::CUmemLocationType. */
} CUmemLocation;

/**
 * Specifies the allocation properties for a allocation.
 */
typedef struct CUmemAllocationProp_st {
  /** Allocation type */
  CUmemAllocationType type;
  /** requested ::CUmemAllocationHandleType */
  CUmemAllocationHandleType requestedHandleTypes;
  /** Location of allocation */
  CUmemLocation location;
  /**
   * Windows-specific LPSECURITYATTRIBUTES required when
   * ::CU_MEM_HANDLE_TYPE_WIN32 is specified.  This security attribute defines
   * the scope of which exported allocations may be tranferred to other
   * processes.  In all other cases, this field is required to be zero.
   */
  void *win32HandleMetaData;
  /** Reserved for future use, must be zero */
  unsigned long long reserved;
} CUmemAllocationProp;

/**
 * Flag for requesting different optimal and required granularities for an
 * allocation.
 */
typedef enum CUmemAllocationGranularity_flags_enum {
  CU_MEM_ALLOC_GRANULARITY_MINIMUM =
      0x0, /**< Minimum required granularity for allocation */
  CU_MEM_ALLOC_GRANULARITY_RECOMMENDED =
      0x1 /**< Recommended granularity for allocation for best performance */
} CUmemAllocationGranularity_flags;

/**
 * Specifies the memory protection flags for mapping.
 */
typedef enum CUmemAccess_flags_enum {
  CU_MEM_ACCESS_FLAGS_PROT_NONE =
      0x0, /**< Default, make the address range not accessible */
  CU_MEM_ACCESS_FLAGS_PROT_READ =
      0x1, /**< Make the address range read accessible */
  CU_MEM_ACCESS_FLAGS_PROT_READWRITE =
      0x3, /**< Make the address range read-write accessible */
  CU_MEM_ACCESS_FLAGS_PROT_MAX = 0xFFFFFFFF
} CUmemAccess_flags;

/**
 * Memory access descriptor
 */
typedef struct CUmemAccessDesc_st {
  CUmemLocation location; /**< Location on which the request is to change it's
                             accessibility */
  CUmemAccess_flags
      flags; /**< ::CUmemProt accessibility flags to set on the request */
} CUmemAccessDesc;

/**
 * Graph kernel node Attributes
 */
typedef enum CUkernelNodeAttrID_enum {
  CU_KERNEL_NODE_ATTRIBUTE_ACCESS_POLICY_WINDOW =
      1, /**< Identifier for ::CUkernelNodeAttrValue::accessPolicyWindow. */
  CU_KERNEL_NODE_ATTRIBUTE_COOPERATIVE =
      2 /**< Allows a kernel node to be cooperative (see
           ::cuLaunchCooperativeKernel). */
} CUkernelNodeAttrID;

/**
 * Specifies performance hint with ::CUaccessPolicyWindow for hitProp and
 * missProp members
 */
typedef enum CUaccessProperty_enum {
  CU_ACCESS_PROPERTY_NORMAL = 0, /**< Normal cache persistence. */
  CU_ACCESS_PROPERTY_STREAMING =
      1, /**< Streaming access is less likely to persit from cache. */
  CU_ACCESS_PROPERTY_PERSISTING =
      2 /**< Persisting access is more likely to persist in cache.*/
} CUaccessProperty;

/**
 * Specifies an access policy for a window, a contiguous extent of memory
 * beginning at base_ptr and ending at base_ptr + num_bytes.
 * num_bytes is limited by CU_DEVICE_ATTRIBUTE_MAX_ACCESS_POLICY_WINDOW_SIZE.
 * Partition into many segments and assign segments such that:
 * sum of "hit segments" / window == approx. ratio.
 * sum of "miss segments" / window == approx 1-ratio.
 * Segments and ratio specifications are fitted to the capabilities of
 * the architecture.
 * Accesses in a hit segment apply the hitProp access policy.
 * Accesses in a miss segment apply the missProp access policy.
 */
typedef struct CUaccessPolicyWindow_st {
  void *base_ptr; /**< Starting address of the access policy window. CUDA driver
                     may align it. */
  size_t num_bytes; /**< Size in bytes of the window policy. CUDA driver may
                       restrict the maximum size and alignment. */
  float hitRatio; /**< hitRatio specifies percentage of lines assigned hitProp,
                     rest are assigned missProp. */
  CUaccessProperty hitProp;  /**< ::CUaccessProperty set for hit. */
  CUaccessProperty missProp; /**< ::CUaccessProperty set for miss. Must be
                                either NORMAL or STREAMING */
} CUaccessPolicyWindow;

/**
 * Graph attributes union, used with
 * ::cuKernelNodeSetAttribute/::cuKernelNodeGetAttribute
 */
typedef union CUkernelNodeAttrValue_union {
  CUaccessPolicyWindow
      accessPolicyWindow; /**< Attribute ::CUaccessPolicyWindow. */
  int cooperative;        /**< Nonzero indicates a cooperative kernel (see
                             ::cuLaunchCooperativeKernel). */
} CUkernelNodeAttrValue;

/**
 * Stream Attributes
 */
typedef enum CUstreamAttrID_enum {
  CU_STREAM_ATTRIBUTE_ACCESS_POLICY_WINDOW =
      1, /**< Identifier for ::CUstreamAttrValue::accessPolicyWindow. */
  CU_STREAM_ATTRIBUTE_SYNCHRONIZATION_POLICY =
      3 /**< ::CUsynchronizationPolicy for work queued up in this stream */
} CUstreamAttrID;

typedef enum CUsynchronizationPolicy_enum {
  CU_SYNC_POLICY_AUTO = 1,
  CU_SYNC_POLICY_SPIN = 2,
  CU_SYNC_POLICY_YIELD = 3,
  CU_SYNC_POLICY_BLOCKING_SYNC = 4
} CUsynchronizationPolicy;

/**
 * Stream attributes union, used with
 * ::cuStreamSetAttribute/::cuStreamGetAttribute
 */
typedef union CUstreamAttrValue_union {
  CUaccessPolicyWindow
      accessPolicyWindow; /**< Attribute ::CUaccessPolicyWindow. */
  CUsynchronizationPolicy
      syncPolicy; /**< Value for ::CU_STREAM_ATTRIBUTE_SYNCHRONIZATION_POLICY.
                   */
} CUstreamAttrValue;

/**
 * CUDA array sparse properties
 */
typedef struct CUDA_ARRAY_SPARSE_PROPERTIES_st {
  struct {
    unsigned int width;  /**< Width of sparse tile in elements */
    unsigned int height; /**< Height of sparse tile in elements */
    unsigned int depth;  /**< Depth of sparse tile in elements */
  } tileExtent;

  /**
   * First mip level at which the mip tail begins.
   */
  unsigned int miptailFirstLevel;
  /**
   * Total size of the mip tail.
   */
  unsigned long long miptailSize;
  /**
   * Flags will either be zero or ::CU_ARRAY_SPARSE_PROPERTIES_SINGLE_MIPTAIL
   */
  unsigned int flags;
  unsigned int reserved[4];
} CUDA_ARRAY_SPARSE_PROPERTIES;

typedef struct CUmemPoolHandle_st *CUmemoryPool; /**< CUDA memory pool */

/**
 * Semaphore signal node parameters
 */
typedef struct CUDA_EXT_SEM_SIGNAL_NODE_PARAMS_st {
  CUexternalSemaphore *extSemArray;
  const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *paramsArray;
  unsigned int numExtSems;
} CUDA_EXT_SEM_SIGNAL_NODE_PARAMS;

/**
 * Semaphore wait node parameters
 */
typedef struct CUDA_EXT_SEM_WAIT_NODE_PARAMS_st {
  CUexternalSemaphore *extSemArray;
  const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *paramsArray;
  unsigned int numExtSems;
} CUDA_EXT_SEM_WAIT_NODE_PARAMS;

/**
 * Sparse subresource types
 */
typedef enum CUarraySparseSubresourceType_enum {
  CU_ARRAY_SPARSE_SUBRESOURCE_TYPE_SPARSE_LEVEL = 0,
  CU_ARRAY_SPARSE_SUBRESOURCE_TYPE_MIPTAIL = 1
} CUarraySparseSubresourceType;

/**
 * Memory operation types
 */
typedef enum CUmemOperationType_enum {
  CU_MEM_OPERATION_TYPE_MAP = 1,
  CU_MEM_OPERATION_TYPE_UNMAP = 2
} CUmemOperationType;

/**
 * Memory handle types
 */
typedef enum CUmemHandleType_enum {
  CU_MEM_HANDLE_TYPE_GENERIC = 0
} CUmemHandleType;

/**
 * Specifies the CUDA array or CUDA mipmapped array memory mapping information
 */
typedef struct CUarrayMapInfo_st {
  CUresourcetype resourceType; /**< Resource type */

  union {
    CUmipmappedArray mipmap;
    CUarray array;
  } resource;

  CUarraySparseSubresourceType subresourceType; /**< Sparse subresource type */

  union {
    struct {
      unsigned int level;   /**< For CUDA mipmapped arrays must a valid mipmap
                               level. For CUDA arrays must be zero */
      unsigned int layer;   /**< For CUDA layered arrays must be a valid layer
                               index. Otherwise, must be zero */
      unsigned int offsetX; /**< Starting X offset in elements */
      unsigned int offsetY; /**< Starting Y offset in elements */
      unsigned int offsetZ; /**< Starting Z offset in elements */
      unsigned int extentWidth;  /**< Width in elements */
      unsigned int extentHeight; /**< Height in elements */
      unsigned int extentDepth;  /**< Depth in elements */
    } sparseLevel;
    struct {
      unsigned int layer; /**< For CUDA layered arrays must be a valid layer
                             index. Otherwise, must be zero */
      unsigned long long offset; /**< Offset within mip tail */
      unsigned long long size;   /**< Extent in bytes */
    } miptail;
  } subresource;

  CUmemOperationType memOperationType; /**< Memory operation type */
  CUmemHandleType memHandleType;       /**< Memory handle type */

  union {
    CUmemGenericAllocationHandle memHandle;
  } memHandle;

  unsigned long long offset;  /**< Offset within the memory */
  unsigned int deviceBitMask; /**< Device ordinal bit mask */
  unsigned int flags;         /**< flags for future use, must be zero now. */
  unsigned int reserved[2];   /**< Reserved for future use, must be zero now. */
} CUarrayMapInfo;

typedef struct CUmemPoolProps_st {
  CUmemAllocationType allocType;
  CUmemAllocationHandleType handleTypes;
  CUmemLocation location;
  void *win32SecurityAttributes;
  unsigned char reserved[64];
} CUmemPoolProps;

typedef struct CUmemPoolPtrExportData_st {
  unsigned char reserved[64];
} CUmemPoolPtrExportData;

typedef enum CUmemPool_attribute_enum {
  CU_MEMPOOL_ATTR_REUSE_FOLLOW_EVENT_DEPENDENCIES = 1,
  CU_MEMPOOL_ATTR_REUSE_ALLOW_OPPORTUNISTIC,
  CU_MEMPOOL_ATTR_REUSE_ALLOW_INTERNAL_DEPENDENCIES,
  CU_MEMPOOL_ATTR_RELEASE_THRESHOLD
} CUmemPool_attribute;

/**
 * Execution Affinity Types
 */
typedef enum CUexecAffinityType_enum {
  CU_EXEC_AFFINITY_TYPE_SM_COUNT = 0, /**< Create a context with limited SMs. */
  CU_EXEC_AFFINITY_TYPE_MAX
} CUexecAffinityType;

/**
 * Value for ::CU_EXEC_AFFINITY_TYPE_SM_COUNT
 */
typedef struct CUexecAffinitySmCount_st {
  unsigned int val; /**< The number of SMs the context is limited to use. */
} CUexecAffinitySmCount_v1;
typedef CUexecAffinitySmCount_v1 CUexecAffinitySmCount;

/**
 * Execution Affinity Parameters
 */
typedef struct CUexecAffinityParam_st {
  CUexecAffinityType type;
  union {
    CUexecAffinitySmCount
        smCount; /** Value for ::CU_EXEC_AFFINITY_TYPE_SM_COUNT */
  } param;
} CUexecAffinityParam_v1;
typedef CUexecAffinityParam_v1 CUexecAffinityParam;

typedef enum CUgraphMem_attribute_enum {
  /**
   * (value type = cuuint64_t)
   * Amount of memory, in bytes, currently associated with graphs
   */
  CU_GRAPH_MEM_ATTR_USED_MEM_CURRENT,

  /**
   * (value type = cuuint64_t)
   * High watermark of memory, in bytes, associated with graphs since the
   * last time it was reset.  High watermark can only be reset to zero.
   */
  CU_GRAPH_MEM_ATTR_USED_MEM_HIGH,

  /**
   * (value type = cuuint64_t)
   * Amount of memory, in bytes, currently allocated for use by
   * the CUDA graphs asynchronous allocator.
   */
  CU_GRAPH_MEM_ATTR_RESERVED_MEM_CURRENT,

  /**
   * (value type = cuuint64_t)
   * High watermark of memory, in bytes, currently allocated for use by
   * the CUDA graphs asynchronous allocator.
   */
  CU_GRAPH_MEM_ATTR_RESERVED_MEM_HIGH
} CUgraphMem_attribute;

/**
 * Memory allocation node parameters
 */
typedef struct CUDA_MEM_ALLOC_NODE_PARAMS_st {
  /**
   * in: location where the allocation should reside (specified in ::location).
   * ::handleTypes must be ::CU_MEM_HANDLE_TYPE_NONE. IPC is not supported.
   */
  CUmemPoolProps poolProps;
  const CUmemAccessDesc
      *accessDescs;       /**< in: array of memory access descriptors. Used to
                             describe peer GPU access */
  size_t accessDescCount; /**< in: number of memory access descriptors.  Must
                             not exceed the number of GPUs. */
  size_t bytesize;        /**< in: size in bytes of the requested allocation */
  CUdeviceptr dptr; /**< out: address of the allocation returned by CUDA */
} CUDA_MEM_ALLOC_NODE_PARAMS;

typedef struct CUuserObject_st
    *CUuserObject; /**< CUDA user object for graphs */

/**
 * The targets for ::cuFlushGPUDirectRDMAWrites
 */
typedef enum CUflushGPUDirectRDMAWritesTarget_enum {
  CU_FLUSH_GPU_DIRECT_RDMA_WRITES_TARGET_CURRENT_CTX =
      0 /**< Sets the target for ::cuFlushGPUDirectRDMAWrites() to the currently
           active CUDA device context. */
} CUflushGPUDirectRDMAWritesTarget;

/**
 * The scopes for ::cuFlushGPUDirectRDMAWrites
 */
typedef enum CUflushGPUDirectRDMAWritesScope_enum {
  CU_FLUSH_GPU_DIRECT_RDMA_WRITES_TO_OWNER =
      100, /**< Blocks until remote writes are visible to the CUDA device
              context owning the data. */
  CU_FLUSH_GPU_DIRECT_RDMA_WRITES_TO_ALL_DEVICES =
      200 /**< Blocks until remote writes are visible to all CUDA device
             contexts. */
} CUflushGPUDirectRDMAWritesScope;

#ifdef __cplusplus
}
#endif

#endif // HIJACK_CUDA_SUBSET_H
