#pragma once
#include <vector>
#include "PixelRGB.h"

class Image
{
public:
    Image();
    ~Image();

    int GetWidth() const;
    int GetHeight() const;
    PixelRGB GetPixel(int x, int y) const;

    void SetPixel(const int& x, const int& y, PixelRGB pixel);

    void ChangeImage(std::vector<std::vector<PixelRGB>>& pixels);

    bool ReadImage(const char *file_name);
    bool WriteImage(const char *file_name);
private:
    std::vector<std::vector<PixelRGB>> pixels_;
    int width_ = 0;
    int height_ = 0;
};

