#include "Negative.h"

void Negative::ApplyFilter(Image& image) const {
    for (int i = 0; i < image.GetWidth(); i++) {
        for (int j = 0; j < image.GetHeight(); j++) {
            PixelRGB pixel = image.GetPixel(i, j);
            unsigned char r = pixel.GetR();
            unsigned char g = pixel.GetG();
            unsigned char b = pixel.GetB();

            image.SetPixel(i, j, PixelRGB(255 - r, 255- g,255 -b));
        }
    }
}