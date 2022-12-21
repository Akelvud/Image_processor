#include "Sharpening.h"

Sharpening::Sharpening() {
    matrix_[0][0] = 0;
    matrix_[0][1] = -1;
    matrix_[0][2] = 0;

    matrix_[1][0] = -1;
    matrix_[1][1] = 5;
    matrix_[1][2] = -1;

    matrix_[2][0] = 0;
    matrix_[2][1] = -1;
    matrix_[2][2] = 0;
}

void Sharpening::ApplyFilter(Image &image) const {
    MatrixFilter::ApplyMatrixFilter(image);
}
