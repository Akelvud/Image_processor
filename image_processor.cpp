#include <iostream>
#include "modules/FilterManager/FilterManager.h"

int main(int argc, char **argv) {
    Image image;

    if (argc < 2) {
        return  0;
    }

    if (!image.ReadImage(argv[1])) {
        return 0;
    }

    std::cout << "The picture is read\n";

    FilterManager filter_manager;
    if (!filter_manager.CreateFilters(argc, argv)) {
        std::cout << "Error : incorrect filters";
        return 0;
    }
    filter_manager.Start(image);

    std::cout << "Filters applied\n";
    if (!image.WriteImage(argv[2])) {
        return 0;
    }

    std::cout << "The picture is recorded\n";
}



