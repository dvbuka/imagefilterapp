#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include "stb_image_write.h"
#include "stb_image.h"

class Image
{
public:
    int width;
    int height;
    int num_original_channels;
    int num_desired_channels;
    unsigned char *pixels;
};

Image read_image(std::string file_loc);
void write_image(Image image, std::string file_loc);

#endif
