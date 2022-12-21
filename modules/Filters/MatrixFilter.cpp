#include "MatrixFilter.h"

void MatrixFilter::ApplyMatrixFilter(Image& image) const {

    std::vector<std::vector<PixelRGB>> new_pixels(image.GetWidth(),
                                                  std::vector<PixelRGB>(image.GetHeight()));

    for (int i = 0; i < image.GetWidth(); i++) {
        for (int j = 0; j < image.GetHeight(); j++) {
            new_pixels[i][j] = MatrixCalc(i, j, image);
        }
    }

    image.ChangeImage(new_pixels);
}

PixelRGB MatrixFilter::MatrixCalc(int x, int y, Image& image) const {
    int r = 0;
    int g = 0;
    int b = 0;

    for (int i_m = 0, i_i =-1; i_m < 3; i_m++, i_i++) {
        for (int j_m = 0, j_i = -1; j_m < 3; j_m++, j_i++) {
            PixelRGB pixel = image.GetPixel(x + i_i, y + j_i);
            r += matrix_[i_m][j_m] * pixel.GetR();
            g += matrix_[i_m][j_m] * pixel.GetG();
            b += matrix_[i_m][j_m] * pixel.GetB();
        }
    }
    r = std::min(std::max(0, r), 255);
    g = std::min(std::max(0, g), 255);
    b = std::min(std::max(0, b), 255);
    PixelRGB res_pixel(r, g, b);
    return res_pixel;
}
