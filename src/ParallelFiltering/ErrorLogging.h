// Credit: Andrew Diggs, PHY 250, UCD

#ifndef ErrorLogging_h
#define ErrorLogging_h
#include <stdio.h>

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/opencl.h>
#endif

inline void CL_Check_Error(int error)
{
    switch (error)
    {
    case 0:
        return; // printf("OpenCl Error CL_SUCCESS\n"); exit(3);
    case -1:
        printf("OpenCl Error CL_DEVICE_NOT_FOUND\n");
        exit(3);
    case -2:
        printf("OpenCl Error CL_DEVICE_NOT_AVAILABLE\n");
        exit(3);
    case -3:
        printf("OpenCl Error CL_COMPILER_NOT_AVAILABLE\n");
        exit(3);
    case -4:
        printf("OpenCl Error CL_MEM_OBJECT_ALLOCATION_FAILURE\n");
        exit(3);
    case -5:
        printf("OpenCl Error CL_OUT_OF_RESOURCES\n");
        exit(3);
    case -6:
        printf("OpenCl Error CL_OUT_OF_HOST_MEMORY\n");
        exit(3);
    case -7:
        printf("OpenCl Error CL_PROFILING_INFO_NOT_AVAILABLE\n");
        exit(3);
    case -8:
        printf("OpenCl Error CL_MEM_COPY_OVERLAP\n");
        exit(3);
    case -9:
        printf("OpenCl Error CL_IMAGE_FORMAT_MISMATCH\n");
        exit(3);
    case -10:
        printf("OpenCl Error CL_IMAGE_FORMAT_NOT_SUPPORTED\n");
        exit(3);
    case -11:
        printf("OpenCl Error CL_BUILD_PROGRAM_FAILURE\n");
        exit(3);
    case -12:
        printf("OpenCl Error CL_MAP_FAILURE\n");
        exit(3);
    case -13:
        printf("OpenCl Error CL_MISALIGNED_SUB_BUFFER_OFFSET\n");
        exit(3);
    case -14:
        printf("OpenCl Error CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST\n");
        exit(3);
    case -15:
        printf("OpenCl Error CL_COMPILE_PROGRAM_FAILURE\n");
        exit(3);
    case -16:
        printf("OpenCl Error CL_LINKER_NOT_AVAILABLE\n");
        exit(3);
    case -17:
        printf("OpenCl Error CL_LINK_PROGRAM_FAILURE\n");
        exit(3);
    case -18:
        printf("OpenCl Error CL_DEVICE_PARTITION_FAILED\n");
        exit(3);
    case -19:
        printf("OpenCl Error CL_KERNEL_ARG_INFO_NOT_AVAILABLE\n");
        exit(3);
    case -30:
        printf("OpenCl Error CL_INVALID_VALUE\n");
        exit(3);
    case -31:
        printf("OpenCl Error CL_INVALID_DEVICE_TYPE\n");
        exit(3);
    case -32:
        printf("OpenCl Error CL_INVALID_PLATFORM\n");
        exit(3);
    case -33:
        printf("OpenCl Error CL_INVALID_DEVICE\n");
        exit(3);
    case -34:
        printf("OpenCl Error CL_INVALID_CONTEXT\n");
        exit(3);
    case -35:
        printf("OpenCl Error CL_INVALID_QUEUE_PROPERTIES\n");
        exit(3);
    case -36:
        printf("OpenCl Error CL_INVALID_COMMAND_QUEUE\n");
        exit(3);
    case -37:
        printf("OpenCl Error CL_INVALID_HOST_PTR\n");
        exit(3);
    case -38:
        printf("OpenCl Error CL_INVALID_MEM_OBJECT\n");
        exit(3);
    case -39:
        printf("OpenCl Error CL_INVALID_IMAGE_FORMAT_DESCRIPTOR\n");
        exit(3);
    case -40:
        printf("OpenCl Error CL_INVALID_IMAGE_SIZE\n");
        exit(3);
    case -41:
        printf("OpenCl Error CL_INVALID_SAMPLER\n");
        exit(3);
    case -42:
        printf("OpenCl Error CL_INVALID_BINARY\n");
        exit(3);
    case -43:
        printf("OpenCl Error CL_INVALID_BUILD_OPTIONS\n");
        exit(3);
    case -44:
        printf("OpenCl Error CL_INVALID_PROGRAM\n");
        exit(3);
    case -45:
        printf("OpenCl Error CL_INVALID_PROGRAM_EXECUTABLE\n");
        exit(3);
    case -46:
        printf("OpenCl Error CL_INVALID_KERNEL_NAME\n");
        exit(3);
    case -47:
        printf("OpenCl Error CL_INVALID_KERNEL_DEFINITION\n");
        exit(3);
    case -48:
        printf("OpenCl Error CL_INVALID_KERNEL\n");
        exit(3);
    case -49:
        printf("OpenCl Error CL_INVALID_ARG_INDEX\n");
        exit(3);
    case -50:
        printf("OpenCl Error CL_INVALID_ARG_VALUE\n");
        exit(3);
    case -51:
        printf("OpenCl Error CL_INVALID_ARG_SIZE\n");
        exit(3);
    case -52:
        printf("OpenCl Error CL_INVALID_KERNEL_ARGS\n");
        exit(3);
    case -53:
        printf("OpenCl Error CL_INVALID_WORK_DIMENSION\n");
        exit(3);
    case -54:
        printf("OpenCl Error CL_INVALID_WORK_GROUP_SIZE\n");
        exit(3);
    case -55:
        printf("OpenCl Error CL_INVALID_WORK_ITEM_SIZE\n");
        exit(3);
    case -56:
        printf("OpenCl Error CL_INVALID_GLOBAL_OFFSET\n");
        exit(3);
    case -57:
        printf("OpenCl Error CL_INVALID_EVENT_WAIT_LIST\n");
        exit(3);
    case -58:
        printf("OpenCl Error CL_INVALID_EVENT\n");
        exit(3);
    case -59:
        printf("OpenCl Error CL_INVALID_OPERATION\n");
        exit(3);
    case -60:
        printf("OpenCl Error CL_INVALID_GL_OBJECT\n");
        exit(3);
    case -61:
        printf("OpenCl Error CL_INVALID_BUFFER_SIZE\n");
        exit(3);
    case -62:
        printf("OpenCl Error CL_INVALID_MIP_LEVEL\n");
        exit(3);
    case -63:
        printf("OpenCl Error CL_INVALID_GLOBAL_WORK_SIZE\n");
        exit(3);
    case -64:
        printf("OpenCl Error CL_INVALID_PROPERTY\n");
        exit(3);
    case -65:
        printf("OpenCl Error CL_INVALID_IMAGE_DESCRIPTOR\n");
        exit(3);
    case -66:
        printf("OpenCl Error CL_INVALID_COMPILER_OPTIONS\n");
        exit(3);
    case -67:
        printf("OpenCl Error CL_INVALID_LINKER_OPTIONS\n");
        exit(3);
    case -68:
        printf("OpenCl Error CL_INVALID_DEVICE_PARTITION_COUNT\n");
        exit(3);
    }
}

inline void Print_Image_Format(cl_image_format fmt)
{
    switch (fmt.image_channel_order)
    {
    case CL_R:
        printf("Order = R ");
        break;
    case CL_A:
        printf("Order = A ");
        break;
    case CL_DEPTH:
        printf("Order = depth ");
        break;
    case CL_LUMINANCE:
        printf("Order = Luminance ");
        break;
    case CL_INTENSITY:
        printf("Order = Intensity ");
        break;
    case CL_RG:
        printf("Order = RG ");
        break;
    case CL_RA:
        printf("Order = RA ");
        break;
    case CL_Rx:
        printf("Order = Rx ");
        break;
    case CL_RGx:
        printf("Order = RGx ");
        break;
    case CL_RGB:
        printf("Order = RGB ");
        break;
    case CL_RGBx:
        printf("Order = RGBx ");
        break;
    case CL_RGBA:
        printf("Order = RGBA ");
        break;
    case CL_ARGB:
        printf("Order = ARGB ");
        break;
    case CL_BGRA:
        printf("Order = BGRA ");
        break;
    default:
        printf("Order = - ");
        break;
    }

    switch (fmt.image_channel_data_type)
    {
    case CL_SNORM_INT8:
        printf("Data Type = Snorm int8\n");
        break;
    case CL_SNORM_INT16:
        printf("Data Type = Snorm int16\n");
        break;
    case CL_UNORM_INT8:
        printf("Data Type = Unorm int8\n");
        break;
    case CL_UNORM_INT16:
        printf("Data Type = Unorm int16\n");
        break;
    case CL_UNSIGNED_INT8:
        printf("Data Type = unsigned int8\n");
        break;
    case CL_UNSIGNED_INT16:
        printf("Data Type = unsigned int16\n");
        break;
    case CL_UNSIGNED_INT32:
        printf("Data Type = unsigned int32\n");
        break;
    case CL_UNORM_SHORT_555:
        printf("Data Type = unorm short 555\n");
        break;
    case CL_UNORM_SHORT_565:
        printf("Data Type = unorm short 565\n");
        break;
    case CL_UNORM_INT_101010:
        printf("Data Type = unorm int 101010\n");
        break;
    case CL_UNORM_INT24:
        printf("Data Type = unorm int 24\n");
        break;
    case CL_SIGNED_INT8:
        printf("Data Type = signed int8\n");
        break;
    case CL_SIGNED_INT16:
        printf("Data Type = signed int16\n");
        break;
    case CL_SIGNED_INT32:
        printf("Data Type = signed int32\n");
        break;
    case CL_HALF_FLOAT:
        printf("Data Type = half\n");
        break;
    case CL_FLOAT:
        printf("Data Type = float\n");
        break;
    default:
        printf("Data Type = -\n");
        break;
    }
}
template <typename T>
inline T Safe_Get(T func, int *err)
{
    CL_Check_Error(*err);
    return func;
}

inline void Print_Device_Info(cl_device_id device_id)
{
    unsigned int info;
    size_t size;
    size_t sizes[3];
    char version[500];
    cl_bool i_supp;
    clGetDeviceInfo(device_id, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(info), &info, NULL);
    printf("GPU INFO: compute units = %u\n", info);

    clGetDeviceInfo(device_id, CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(size), &size, NULL);
    printf("GPU INFO: max work group size = %lu\n", size);

    clGetDeviceInfo(device_id, CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, sizeof(info), &info, NULL);
    printf("GPU INFO: work item demsions = %u\n", info);

    clGetDeviceInfo(device_id, CL_DEVICE_MAX_WORK_ITEM_SIZES, sizeof(sizes), sizes, NULL);
    printf("GPU INFO: work item sizes = %lux %lu x %lu\n", sizes[0], sizes[1], sizes[2]);

    clGetDeviceInfo(device_id, CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(size), &size, NULL);
    printf("GPU INFO: Global mem size = %lu MB\n", size / 1000000);

    clGetDeviceInfo(device_id, CL_DEVICE_GLOBAL_MEM_CACHE_SIZE, sizeof(size), &size, NULL);
    printf("GPU INFO: Global mem cache size = %lu\n", size);

    clGetDeviceInfo(device_id, CL_DEVICE_LOCAL_MEM_SIZE, sizeof(size), &size, NULL);
    printf("GPU INFO: local mem size = %lu B\n", size);

    clGetDeviceInfo(device_id, CL_DEVICE_IMAGE_SUPPORT, sizeof(i_supp), &i_supp, NULL);
    printf("GPU INFO: Image Support = %s\n", i_supp ? "True" : "False");

    clGetDeviceInfo(device_id, CL_DEVICE_IMAGE_MAX_ARRAY_SIZE, sizeof(size), &size, NULL);
    printf("GPU INFO: Max image array = %lu\n", size);

    clGetDeviceInfo(device_id, CL_DRIVER_VERSION, sizeof(version), &version, NULL);
    printf("GPU INFO: %s\n", version);

    clGetDeviceInfo(device_id, CL_DEVICE_EXTENSIONS, sizeof(version), &version, NULL);
    printf("GPU INFO: %s\n", version);
}

inline void Print_Kernel_Info(cl_kernel kernel, cl_device_id device)
{
    unsigned long priv;
    size_t size;
    size_t sizes[3];

    clGetKernelWorkGroupInfo(kernel, device, CL_KERNEL_GLOBAL_WORK_SIZE, sizeof(sizes), sizes, NULL);
    printf("Kernel Info: Global work group sizes = %lu X %lu X %lu\n", sizes[0], sizes[1], sizes[2]);

    clGetKernelWorkGroupInfo(kernel, device, CL_KERNEL_WORK_GROUP_SIZE, sizeof(size), &size, NULL);
    printf("Kernel Info: Kernel work group size = %lu\n", size);

    clGetKernelWorkGroupInfo(kernel, device, CL_KERNEL_COMPILE_WORK_GROUP_SIZE, sizeof(sizes), sizes, NULL);
    printf("Kernel Info: Compile work group sizes = %lu X %lu X %lu\n", sizes[0], sizes[1], sizes[2]);

    clGetKernelWorkGroupInfo(kernel, device, CL_KERNEL_PREFERRED_WORK_GROUP_SIZE_MULTIPLE, sizeof(size), &size, NULL);
    printf("Kernel Info: Kernel perfered multiple = %lu\n", size);

    clGetKernelWorkGroupInfo(kernel, device, CL_KERNEL_LOCAL_MEM_SIZE, sizeof(priv), &priv, NULL);
    printf("Kernel Info: Local mem size = %lu\n", priv);

    clGetKernelWorkGroupInfo(kernel, device, CL_KERNEL_PRIVATE_MEM_SIZE, sizeof(priv), &priv, NULL);
    printf("Kernel Info: Private mem size = %lu\n", priv);
}

#endif
