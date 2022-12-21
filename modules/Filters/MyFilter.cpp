#include "MyFilter.h"

void MyFilter::ApplyFilter(Image &image) const {
    for (int i = 0; i < image.GetWidth(); i++) {
        for (int j = 0; j < image.GetHeight(); j++) {
            unsigned char r = image.GetPixel(i, j).GetR();

            image.SetPixel(i, j, PixelRGB(r, 0, 255));
        }
    }
}
