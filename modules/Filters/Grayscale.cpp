#include "Grayscale.h"

void Grayscale::ApplyFilter(Image& image) const {
    for (int i = 0; i < image.GetWidth(); i++) {
        for (int j = 0; j < image.GetHeight(); j++) {
            PixelRGB pixel = image.GetPixel(i, j);
            unsigned char r = pixel.GetR();
            unsigned char g = pixel.GetG();
            unsigned char b = pixel.GetB();

            unsigned char gray = 0.299 * r + 0.587 * g + 0.114 * b;
            image.SetPixel(i, j, PixelRGB(gray,gray,gray));
        }
    }
}