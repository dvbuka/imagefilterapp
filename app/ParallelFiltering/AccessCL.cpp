#include "AccessCL.hpp"
#include "ErrorLogging.h"
#include <string>

std::string Get_Kernel_String(std::string cl_file)
{
    std::ifstream in_file;
    std::string shader_string;
    in_file.open(cl_file);
    if (!in_file.is_open())
    {
        std::cout << "ERROR Loading Shader file!!" << std::endl;
        exit(2);
    }
    std::string line;
    while (getline(in_file, line))
    {
        if (!line.empty())
        {
            shader_string.append(line + "\n");
        }
    }
    return shader_string;
}

static cl_platform_id Get_Platform()
{
    // 1: Get the number of cl_platforms.
    cl_uint num = 0;
    CL_Check_Error(clGetPlatformIDs(10, NULL, &num));
    // 2: build an array of platforms
    cl_platform_id *platforms = (cl_platform_id *)malloc(num * sizeof(cl_platform_id));
    CL_Check_Error(clGetPlatformIDs(num, platforms, NULL));

    if (num == 1)
    {
        return platforms[0];
    }

    // 3: Print the name of each platform
    for (int i = 0; i < num; i++)
    {
        char plat_info[300];
        int test = clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, sizeof(plat_info), plat_info, NULL);
        printf("PLATFORM INFO: Name = %s\n", plat_info);
    }
    int idx;
    printf("Enter the number of the platform that identifies your GPU.\n: ");
    scanf("%d", &idx);

    return platforms[idx];
}

static cl_device_id Get_Device()
{
    cl_platform_id platform_id = Get_Platform();
    cl_device_id device_id;
    CL_Check_Error(clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_ALL, 1, &device_id, NULL));
    return device_id;
}

// Takes an image and 3x3 kernel filter, runs filter on image using OpenCL, and returns filtered image.
Image AccessCL(Image image, const float kernel_filter[3][3])
{
    if (image.num_desired_channels != 3)
        return image;
    const int width = image.width;
    const int height = image.height;
    const int tot = width * height * 3;
    const size_t image_dat_size = tot * sizeof(cl_uchar);
    cl_uchar *input = (cl_uchar *)malloc(image_dat_size);
    cl_uchar *output = (cl_uchar *)malloc(image_dat_size);

    // Fill input and output buffers.
    for (int i = 0; i < tot; i++)
    {
        input[i] = image.pixels[i];
        output[i] = image.pixels[i];
    }

    int err; // error code returned from api calls

    cl_device_id device_id = Get_Device(); // Get the device id for the GPU.

    // Open up a line of communication with the GPU
    cl_context context;
    context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &err);
    CL_Check_Error(err);

    // Create a program to be executed on the GPU using your kernel source code
    // read in a source file.
    std::string KS = Get_Kernel_String("./app/ParallelFiltering/ImageFiltering.cl");
    const char *source = KS.c_str();

    cl_program program;
    program = clCreateProgramWithSource(context, 1, (const char **)&source, NULL, &err);
    CL_Check_Error(err);
    err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
    CL_Check_Error(err);

    // Create a link to a specific kernel, "function", in the program
    cl_kernel kernel;
    kernel = clCreateKernel(program, "image_kernel", &err);
    CL_Check_Error(err);

    // Allocate the needed memory on the GPU
    cl_mem img_mem = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(cl_uchar) * tot, NULL, &err);
    CL_Check_Error(err);
    cl_mem out_mem = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(cl_uchar) * tot, NULL, &err);
    CL_Check_Error(err);
    cl_mem filter_mem = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(cl_float) * 9, NULL, &err);
    CL_Check_Error(err);

    // Set the pointers to the memory to specific arguments in the kernel
    err = 0;
    err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &img_mem);     // in
    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &out_mem);    // out
    err |= clSetKernelArg(kernel, 2, sizeof(cl_int), &width);      // image width
    err |= clSetKernelArg(kernel, 3, sizeof(cl_int), &height);     // image height
    err |= clSetKernelArg(kernel, 4, sizeof(cl_mem), &filter_mem); // kernel
    CL_Check_Error(err);

    // Create a queue to store the list of commands to be issued
    cl_command_queue commands; // command queue
    commands = clCreateCommandQueue(context, device_id, 0, &err);
    CL_Check_Error(err);

    // Transfer the input data
    CL_Check_Error(clEnqueueWriteBuffer(commands, img_mem, CL_TRUE, 0, sizeof(cl_uchar) * tot, input, 0, NULL, NULL));
    CL_Check_Error(clEnqueueWriteBuffer(commands, filter_mem, CL_TRUE, 0, sizeof(cl_float) * 9, kernel_filter, 0, NULL, NULL));

    // Run the kernel
    size_t global[2] = {(size_t)width, (size_t)height};
    err = clEnqueueNDRangeKernel(commands, kernel, 2, NULL, global, NULL, 0, NULL, NULL);
    clFinish(commands);
    err = clEnqueueReadBuffer(commands, out_mem, CL_TRUE, 0, sizeof(cl_uchar) * tot, output, 0, NULL, NULL);
    CL_Check_Error(err);

    // Release OpenCL resources
    clReleaseProgram(program);
    clReleaseCommandQueue(commands);
    clReleaseContext(context);
    clReleaseKernel(kernel);
    clReleaseMemObject(img_mem);
    clReleaseMemObject(out_mem);
    clReleaseMemObject(filter_mem);

    for (int i = 0; i < tot; ++i)
    {
        image.pixels[i] = output[i];
    }

    free(input);
    free(output);

    return image;
}
