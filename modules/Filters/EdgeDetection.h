#pragma once
#include "MatrixFilter.h"

class EdgeDetection: public MatrixFilter{
public:
    explicit EdgeDetection(double threshold);
    void ApplyFilter(Image& image) const override;
private:
    double threshold_;
};
