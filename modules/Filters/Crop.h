#pragma once
#include "Filter.h"



class Crop : public Filter{
public:
    Crop(const int& width,const int& height);
    void ApplyFilter(Image& image) const override;

private:
    int width_;
    int height_;
};
