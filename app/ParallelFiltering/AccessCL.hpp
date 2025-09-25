#ifndef AccessCL_hpp
#define AccessCL_hpp

#define CL_TARGET_OPENCL_VERSION 120

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>
#include <string>
#include "../Common/Image.hpp"

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/opencl.h>
#endif

using namespace std;
Image AccessCL(Image image, const float kernel_filter[3][3]);

#endif
