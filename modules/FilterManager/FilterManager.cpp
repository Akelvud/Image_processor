#include "FilterManager.h"
#include <iostream>
#include "../Filters/Grayscale.h"
#include "../Filters/Negative.h"
#include "../Filters/Sharpening.h"
#include "../Filters/MyFilter.h"
#include "../Filters/GaussianBlur.h"
#include "../Filters/EdgeDetection.h"
#include "../Filters/Crop.h"

bool FilterManager::CreateFilters(int argc, char **argv) {

    int k = 3;
    while(k < argc) {
        std::string s = argv[k];
        if (s == "-gs") {
            filters_.push_back(new Grayscale());
        } else
        if (s == "-neg") {
            filters_.push_back(new Negative());
        } else
        if (s == "-sharp") {
            filters_.push_back(new Sharpening());
        } else
        if (s == "-mf") {
            filters_.push_back(new Grayscale());
            filters_.push_back(new MyFilter());
        } else
        if (s == "-blur") {
            ++k;
            if (k == argc) {
                return false;
            }
            double sigma = 0;
            if (!GetDouble(argv[k], sigma)) {
                return false;
            }
            filters_.push_back(new GaussianBlur(sigma));

        } else
        if (s == "-edge") {
            ++k;
            if (k == argc) {
                return false;
            }
            double threshold = 0;
            if (!GetDouble(argv[k], threshold)) {
                return false;
            }
            filters_.push_back(new Grayscale());
            filters_.push_back(new EdgeDetection(threshold));
        } else
        if (s == "-crop") {
            ++k;
            if (k == argc) {
                return false;
            }
            int width  = 0;
            if (!GetInt(argv[k], width)) {
                return false;
            }
            if (k == argc) {
                return false;
            }
            k++;
            int height = 0;
            if (!GetInt(argv[k], height)) {
                return false;
            }
            filters_.push_back(new Crop(width, height));
        } else {
            return false;
        }
        k++;
    }
    return true;
}

void FilterManager::Start(Image &image) {
    for (auto filter: filters_) {
        filter->ApplyFilter(image);
    }
}

bool FilterManager::GetInt(char *str, int &a) {
    std::stringstream ss;
    std::string s = str;
    ss << s;
    ss >> a;

    if (a == 0) return false;
    return true;
}

bool FilterManager::GetDouble(char *str, double &a) {
    std::stringstream ss;
    std::string s = str;
    ss << s;
    ss >> a;

    if (a == 0) return false;
    return true;
}
