#pragma once
#include "Filter.h"

class MatrixFilter : public Filter {
private:
    PixelRGB MatrixCalc(int y, int x, Image& image) const;
protected:
    void ApplyMatrixFilter(Image& image) const;
    int matrix_[3][3]{};
};
