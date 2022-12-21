#pragma once
#include <algorithm>
#include "../Image/Image.h"

class Filter {
public:
    Filter() = default;
    virtual void ApplyFilter(Image &image) const {};
};
