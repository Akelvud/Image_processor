#pragma once
#include "Filter.h"

class GaussianBlur : public Filter{
public:
    explicit GaussianBlur(double sigma);
    void ApplyFilter(Image& image) const override;

private:
    double sigma_;
};
