#include "AccessCL.hpp"
#include "ErrorLogging.h"
#include "ImageFiltering.hpp"

using namespace std;

void filter_image(string file_loc, string filter_type, float sigma, string out_loc)
{
    Image image = read_image(file_loc);
    double *output;
    if (filter_type == "sobel")
    {
        AccessCL(image, (float[3][3]){{1, 0, -1},
                                      {2, 0, -2},
                                      {1, 0, -1}});
    }
    else if (filter_type == "gaussian")
    {
        float kernel[3][3];
        float guass_coeff = 0;
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
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                kernel[i][j] /= guass_coeff;
            }
        }
        AccessCL(image, kernel);
    }
    else if (filter_type == "box")
    {
        AccessCL(image, (float[3][3]){{1 / 9, 1 / 9, 1 / 9},
                                      {1 / 9, 1 / 9, 1},
                                      {1 / 9, 1 / 9, 1 / 9}});
    }
    else
    {
        cout << "Invalid filtering type. Options: sobel, gaussian, and box" << endl;
    }

    write_image(image, out_loc);
}