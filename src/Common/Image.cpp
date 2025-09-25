#include "Image.hpp"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;

Image read_image(string file_loc)
{
    Image image = {};
    int width, height, original_no_channels;
    image.num_desired_channels = 3;
    image.pixels = stbi_load(file_loc.c_str(), &image.width, &image.height, &image.num_original_channels, image.num_desired_channels);
    return image;
}

void write_image(Image image, string file_loc)
{
    stbi_write_png(file_loc.c_str(), image.width, image.height, image.num_desired_channels, image.pixels, image.width * image.num_desired_channels);
}
