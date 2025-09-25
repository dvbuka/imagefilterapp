#ifndef IMAGE_FILTERING_HPP
#define IMAGE_FILTERING_HPP

#include "../Common/Image.hpp"
#include <string>

// Function to filter an image using a specified filter type and parameters
void filter_image(string file_loc, string filter_type, float sigma, string out_loc = "out.png");

#endif // IMAGE_FILTERING_HPP