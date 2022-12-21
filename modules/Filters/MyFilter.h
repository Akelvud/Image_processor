#pragma once
#include "Filter.h"

class MyFilter : public Filter{
    void ApplyFilter(Image& image) const override;
};

