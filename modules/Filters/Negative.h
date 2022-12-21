#pragma once
#include "Filter.h"

class Negative : public Filter{
    void ApplyFilter(Image& image) const override;
};
