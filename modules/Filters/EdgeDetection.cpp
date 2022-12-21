#include "EdgeDetection.h"

EdgeDetection::EdgeDetection(double threshold) : threshold_(threshold * 255) {
    matrix_[0][0] = 0;
    matrix_[0][1] = -1;
    matrix_[0][2] = 0;

    matrix_[1][0] = -1;
    matrix_[1][1] = 4;
    matrix_[1][2] = -1;

    matrix_[2][0] = 0;
    matrix_[2][1] = -1;
    matrix_[2][2] = 0;
}

void EdgeDetection::ApplyFilter(Image &image) const {
    MatrixFilter::ApplyMatrixFilter(image);

    for (int i = 0; i < image.GetHeight(); i++) {
        for (int j = 0; j < image.GetWidth(); j++) {
            if (image.GetPixel(i, j).GetR() > threshold_) {
                image.SetPixel(i, j, PixelRGB(255, 255,255));
            } else {
                image.SetPixel(i, j, PixelRGB(0, 0,0));
            }
        }
    }
}


