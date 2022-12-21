#pragma once
#include "Filter.h"

class Grayscale : public Filter{
    void ApplyFilter(Image& image) const override;
};
