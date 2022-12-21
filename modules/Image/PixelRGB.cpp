#include "PixelRGB.h"

PixelRGB::PixelRGB() {
    r_ = g_ = b_ = 0;
}
PixelRGB::PixelRGB(unsigned char r, unsigned char g, unsigned char b) :
    r_(r),
    g_(g),
    b_(b) {}

void PixelRGB::SetRGB(unsigned char r, unsigned char g, unsigned char b) {
    r_ = r;
    g_ = g;
    b_ = b;
}

unsigned char PixelRGB::GetR() const {
    return r_;
}

unsigned char PixelRGB::GetG() const {
    return g_;
}

unsigned char PixelRGB::GetB() const {
    return b_;
}