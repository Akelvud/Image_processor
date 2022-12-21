cmake_minimum_required(VERSION 3.21)
project(image_processor)

set(CMAKE_CXX_STANDARD 14)

add_executable(image_processor image_processor.cpp
        modules/Image/Image.cpp
        modules/Image/Image.h
        modules/Filters/Filter.h
        modules/Filters/Crop.cpp
        modules/Filters/Crop.h
        modules/Filters/Grayscale.cpp
        modules/Filters/Grayscale.h
        modules/Filters/Negative.cpp
        modules/Filters/Negative.h
        modules/Filters/GaussianBlur.cpp
        modules/Filters/GaussianBlur.h
        modules/Filters/MatrixFilter.cpp
        modules/Filters/MatrixFilter.h
        modules/Filters/Sharpening.cpp
        modules/Filters/Sharpening.h
        modules/Filters/EdgeDetection.cpp
        modules/Filters/EdgeDetection.h
        modules/Filters/MyFilter.cpp
        modules/Filters/MyFilter.h
        modules/Image/PixelRGB.cpp
        modules/Image/PixelRGB.h modules/FilterManager/FilterManager.cpp modules/FilterManager/FilterManager.h)
