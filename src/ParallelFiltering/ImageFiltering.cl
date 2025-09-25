__kernel void image_kernel(__global const uchar* input, // input image, 3 channels assumed
                           __global uchar* output, // output image, 3 channels assumed
                           const int width, // width of the image
                           const int height, // height of the image
                           __global const float* kernel_filter) // assume 3x3 by kernel
{
    int w = get_global_id(0); // cur h index
    int h = get_global_id(1); // cur w index
    
    // check out of bounding
    if (w > width - 1 || w == 0 || h > height - 1 || h == 0)  {
        output[3 * (width * h + w)] = input[3 * (width * h + w)];
        output[3 * (width * h + w) + 1] = input[3 * (width * h + w) + 1];
        output[3 * (width * h + w) + 2] = input[3 * (width * h + w) + 2];
        return;
    }
    
    for(int c = 0; c < 3; c++) { // c = channel
        float sum = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                float k_val = kernel_filter[3 * i + j];
                sum += input[3 * (width * (h + i - 1) + (w + j - 1)) + c] * k_val;
            }
        }
        output[3 * (width * h + w) + c] = (uchar) (sum);
    }
}
