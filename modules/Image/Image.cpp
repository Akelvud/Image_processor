#include <iostream>
#include <algorithm>
#include "Image.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#pragma pack(push, 1)
typedef struct {
    __int16   bf_type;
    int    bf_size;
    int    bf_reserved;
    int    bf_off_bits;
    int    bi_size;
    int    bi_width;
    int    bi_height;
    __int16   bi_planes;
    __int16   bi_bit_count;
    int    bi_compression;
    int    bi_size_image;
    int    bi_x_pels_per_meter;
    int    bi_y_pels_per_meter;
    int    bi_clr_used;
    int    bi_clr_important;
} BMPheader;
#pragma pack(pop)


Image::Image() {

    width_ = 0;
    height_ = 0;
}

Image::~Image() {
    pixels_.clear();
}



int Image::GetWidth() const {
    return width_;
}

int Image::GetHeight() const {
    return height_;
}

bool Image::ReadImage(const char *file_name) {
    width_ = -1;
    height_ = -1;
    FILE *file = fopen(file_name, "rb");
    if (!file) {
        std::cout << "Error : The file did not open\n";
        return false;
    }
    BMPheader bmp_header;
    size_t result;

    result = fread(&bmp_header, 1, sizeof(BMPheader), file);
    if (result != sizeof(BMPheader)) {
        fclose(file);
        std::cout << "Error : The file is invalid\n";
        return false;
    }

    if (bmp_header.bf_type != 0x4d42 && bmp_header.bf_type != 0x4349 && bmp_header.bf_type != 0x5450) {
        fclose(file);
        std::cout << "Error : The file is invalid\n";
        return false;
    }

    fseek(file, 0, SEEK_END);
    int filesize = ftell(file);
    fseek(file, sizeof(BMPheader), SEEK_SET);

    if (bmp_header.bf_size != filesize ||
        bmp_header.bf_reserved != 0 ||
        bmp_header.bi_planes != 1 ||
        (bmp_header.bi_size != 40 && bmp_header.bi_size != 108 && bmp_header.bi_size != 124) ||
        bmp_header.bf_off_bits != 14 + bmp_header.bi_size ||

        bmp_header.bi_width < 1 || bmp_header.bi_width > 10000 ||
        bmp_header.bi_height < 1 || bmp_header.bi_height > 10000 ||
        bmp_header.bi_bit_count != 24 ||
        bmp_header.bi_compression != 0
            ) {
        fclose(file);
        std::cout << "Error : The file is invalid\n";
        return false;
    }

    width_ = bmp_header.bi_width;
    height_ = bmp_header.bi_height;
    int width3 = (3 * width_ + 3) & (-4);
    auto *tmp_buf = new unsigned char[width3 * height_];
    result = fread(tmp_buf, 1, width3 * height_, file);
    if ((int) result != width3 * height_) {
        delete[]tmp_buf;
        fclose(file);
        std::cout << "Error : The file is invalid\n";
        return false;
    }
    fclose(file);

    pixels_ = std::vector<std::vector<PixelRGB>>(width_,
            std::vector<PixelRGB>(height_));


    for (int y = height_ - 1; y >= 0; y--) {
        unsigned char *p_row = tmp_buf + width3 * y;
        for (int x = 0; x < width_; x++) {
            unsigned char r = *(p_row + 2);
            unsigned char g = *(p_row + 1);
            unsigned char b = *p_row;
            p_row += 3;
            pixels_[x][y].SetRGB(r, g, b);
        }
    }
    delete[]tmp_buf;

    return true;
}

bool Image::WriteImage(const char *file_name) {
    BMPheader bmp_header;
    memset(&bmp_header, 0, sizeof(bmp_header));
    bmp_header.bf_type = 0x4d42;    // 'BM'

    int width3 = (3 * width_ + 3) & (-4);
    int filesize = 54 + height_ * width3;
    bmp_header.bf_size = filesize;
    bmp_header.bf_reserved = 0;
    bmp_header.bi_planes = 1;
    bmp_header.bi_size = 40;
    bmp_header.bf_off_bits = 14 + bmp_header.bi_size;
    bmp_header.bi_width = width_;
    bmp_header.bi_height = height_;
    bmp_header.bi_bit_count = 24;
    bmp_header.bi_compression = 0;

    FILE *file = fopen(file_name, "wb");
    if (!file) {
        std::cout << "Error : The file did not open\n";
        return false;
    }
    size_t result;

    result = fwrite(&bmp_header, 1, sizeof(BMPheader), file);
    if (result != sizeof(BMPheader)) {
        fclose(file);
        std::cout << "Error : The file is invalid\n";
        return false;
    }

    auto *tmp_buf = new unsigned char[width3 * height_];
    for (int y = height_ - 1; y >= 0; y--) {
        unsigned char *pRow = tmp_buf + width3 * y;
        for (int x = 0; x < width_; x++) {
            *(pRow + 2) = pixels_[x][y].GetR();
            *(pRow + 1) = pixels_[x][y].GetG();
            *pRow = pixels_[x][y].GetB();
            pRow += 3;

        }
    }

    fwrite( tmp_buf, 1, width3*height_, file );
    fclose(file);
    delete[]tmp_buf;

    return true;
}

PixelRGB Image::GetPixel(int x, int y) const {
    x = std::min(std::max(x, 0), width_ - 1);
    y = std::min(std::max(y, 0), height_ - 1);
    return pixels_[x][y];
}

void Image::SetPixel(const int &x, const int& y, PixelRGB pixel) {
    pixels_[x][y] = pixel;
}

void Image::ChangeImage(std::vector<std::vector<PixelRGB>>& pixels) {
    pixels_.clear();
    pixels_ = std::move(pixels);

    width_ = static_cast<int>(pixels_.size());
    height_ = static_cast<int>(pixels_[0].size());
}

#pragma clang diagnostic pop