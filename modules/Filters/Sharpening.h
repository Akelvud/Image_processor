#pragma once
#include "MatrixFilter.h"

class Sharpening : public MatrixFilter{
public:
    Sharpening();
    void ApplyFilter(Image& image) const override;
};



