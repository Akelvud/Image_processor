class PixelRGB {
public:
    PixelRGB();
    PixelRGB(unsigned char r, unsigned char g, unsigned char b);
    void SetRGB(unsigned char r, unsigned char g, unsigned char b);

    unsigned char GetR() const;
    unsigned char GetG() const;
    unsigned char GetB() const;
private:
    unsigned char r_ = 0;
    unsigned char g_ = 0;
    unsigned char b_ = 0;
};
