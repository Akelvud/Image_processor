#include <cmath>
#include "GaussianBlur.h"

GaussianBlur::GaussianBlur(double sigma) : sigma_(sigma) {}

void GaussianBlur::ApplyFilter(Image& image) const {
    double pi = 3.1415926535897932384626433832795;
    double  f = 1/(2 * pi * sigma_ * sigma_);

    std::vector<std::vector<PixelRGB>> new_pixels(image.GetWidth(),
                                                  std::vector<PixelRGB>(image.GetHeight()));


    for (int i_0 = 0; i_0 < image.GetWidth(); i_0++) {
        for (int  j_0 = 0; j_0 < image.GetHeight(); j_0++) {
            double r = 0;
            double g = 0;
            double b = 0;

            for (int i = 0; i < image.GetWidth(); i++) {
                for (int j = 0; j < image.GetHeight(); j++) {
                    double rast = abs(i_0-i) * abs(i_0-i) +
                                  abs(j_0-j) * abs(j_0-j);
                    rast /= 2 * sigma_*sigma_;
                    double e = std::exp(-rast);

                    PixelRGB pixel = image.GetPixel(i, j);
                    r += pixel.GetR() * e;
                    g += pixel.GetG() * e;
                    b += pixel.GetB() * e;
                }
            }

            r *= f;
            g *= f;
            b *= f;

            new_pixels[i_0][j_0] = PixelRGB(static_cast<unsigned char>(r),
                                            static_cast<unsigned char>(g),
                                            static_cast<unsigned char>(b));
        }
    }
    image.ChangeImage(new_pixels);
}

