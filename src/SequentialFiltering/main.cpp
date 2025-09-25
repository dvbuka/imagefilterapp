#include <iostream>
#include <string>
#include <cctype>
#include <chrono>
#include "../Common/Image.hpp"
#include "../Common/utils.hpp"

using namespace std;

Image sobel_filter(struct Image image);
Image gaussian_filter(struct Image image, double sigma);
Image box_blur(struct Image image);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cout << "Please enter argument for file and filtering type" << endl;
        return 0;
    }
    string file_loc = argv[1];
    string filtering_type = tolower(argv[2]);
    struct Image image = read_image(file_loc);
    // Types: Sobel, Gaussian, and Box
    // https://stackoverflow.com/questions/61153680/how-to-use-stbi-write-png-to-write-image-pixel-data-to-a-png-file
    auto start = std::chrono::high_resolution_clock::now();
    if (filtering_type == "sobel")
    {
        start = std::chrono::high_resolution_clock::now();
        sobel_filter(image);
    }
    else if (filtering_type == "gaussian")
    {
        if (argc > 3 && !isnumber(argv[3]))
        {
            cout << "If passing optional arguments, must specify sigma value as a number" << endl;
            return 0;
        }
        double sigma = argc > 3 ? stod(argv[3]) : 2;
        start = std::chrono::high_resolution_clock::now();
        gaussian_filter(image, sigma);
    }
    else if (filtering_type == "box")
    {
        start = std::chrono::high_resolution_clock::now();
        box_blur(image);
    }
    else
    {
        cout << "Invalid filtering type. Options: sobel, gaussian, and box" << endl;
    }

    string out_loc = argc > 3 ? argv[3] : "out.png";
    if (filtering_type == "gaussian")
    {
        out_loc = argc > 4 ? argv[4] : "out.png";
    }
    write_image(image, out_loc);
    auto stop = std::chrono::high_resolution_clock::now();
    cout << "Execution time in microseconds: " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << endl;
}

Image sobel_filter(struct Image image)
{
    int sobel_operator[3][3] = {{1, 0, -1},
                                {2, 0, -2},
                                {1, 0, -1}};
    unsigned char *new_pixels = image.pixels;
    for (int w = 1; w < image.width - 1; ++w)
    {
        for (int h = 1; h < image.height - 1; ++h)
        {
            for (int c = 0; c < 3; ++c)
            {
                double sum = 0;
                for (int i = 0; i < 3; ++i)
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        sum += image.pixels[3 * (image.width * (h + i) + (w + j)) + c] * sobel_operator[i][j];
                    }
                }
                new_pixels[3 * (image.width * h + w) + c] = (unsigned char)(u_int8_t)sum;
            }
        }
    }
    image.pixels = new_pixels;
    return image;
}

Image gaussian_filter(struct Image image, double sigma)
{
    double kernel[3][3];
    double guass_coeff = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int x = i - 1;
            int y = j - 1;
            kernel[i][j] = 1 / (2 * 3.14 * sigma * sigma) * exp(-(x * x + y * y) / (2 * sigma * sigma));
            guass_coeff += kernel[i][j];
        }
    }
    unsigned char *new_pixels = image.pixels;
    for (int w = 1; w < image.width - 1; ++w)
    {
        for (int h = 1; h < image.height - 1; ++h)
        {
            for (int c = 0; c < 3; ++c)
            {
                double sum = 0;
                for (int i = 0; i < 3; ++i)
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        sum += image.pixels[3 * (image.width * (h + i) + (w + j)) + c] * kernel[i][j] / guass_coeff;
                    }
                }
                new_pixels[3 * (image.width * h + w) + c] = (unsigned char)(u_int8_t)sum;
            }
        }
    }
    image.pixels = new_pixels;
    return image;
}

Image box_blur(struct Image image)
{
    int weights[3][3] = {{1, 1, 1},
                         {1, 1, 1},
                         {1, 1, 1}};
    unsigned char *new_pixels = image.pixels;
    for (int w = 1; w < image.width - 1; ++w)
    {
        for (int h = 1; h < image.height - 1; ++h)
        {
            for (int c = 0; c < 3; ++c)
            {
                double sum = 0;
                for (int i = 0; i < 3; ++i)
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        sum += image.pixels[3 * (image.width * (h + i) + (w + j)) + c] * weights[i][j];
                    }
                }
                new_pixels[3 * (image.width * h + w) + c] = (unsigned char)(u_int8_t)(sum / 9);
            }
        }
    }
    image.pixels = new_pixels;
    return image;
}
