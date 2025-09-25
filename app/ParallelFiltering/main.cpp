#include <iostream>
#include <string>
#include "AccessCL.hpp"
#include "ImageFiltering.hpp"
#include <chrono>
#include "../Common/utils.hpp"

using namespace std;

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
    if (filtering_type == "gaussian" && argc > 3 && !isnumber(argv[3]))
    {
        cout << "If passing optional arguments, must specify sigma value as a number" << endl;
        return 0;
    }
    if (filtering_type != "sobel" && filtering_type != "gaussian" && filtering_type != "box")
    {
        cout << "Invalid filtering type. Options: sobel, gaussian, and box" << endl;
    }

    // Types: Sobel, Gaussian, and Box
    float sigma = 0;
    string out_loc = argc > 3 ? argv[3] : "out.png";
    if (filtering_type == "gaussian")
    {
        sigma = argc > 3 ? stof(argv[3]) : 0;
        out_loc = argc > 4 ? argv[4] : "out.png";
    }
    auto start = std::chrono::high_resolution_clock::now();
    filter_image(file_loc, filtering_type, sigma, out_loc);
    auto stop = std::chrono::high_resolution_clock::now();
    cout << "Execution time in microseconds: " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << endl;
}
