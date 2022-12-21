#include "Crop.h"

Crop::Crop(const int &width, const int &height) : width_(width), height_(height) {}

void Crop::ApplyFilter(Image &image) const {
    int last_width = image.GetWidth();
    int last_height = image.GetHeight();
    int new_width = std::min(width_, image.GetWidth());
    int new_height = std::min(height_, image.GetHeight());

    std::vector<std::vector<PixelRGB>> new_pixels(new_width,
                                                  std::vector<PixelRGB>(new_height));

    for (int i = 0; i < last_width; i++) {
        if (i >= new_width) {
            continue;
        }
        for (int j = last_height - new_height, j_n = 0; j < last_height; j++, j_n++) {
            new_pixels[i][j_n] = image.GetPixel(i, j);
        }
    }

    image.ChangeImage(new_pixels);
}