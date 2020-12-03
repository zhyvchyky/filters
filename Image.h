//
// Created by noxin on 10/27/20.
//

#ifndef FILTERS_IMAGE_H
#define FILTERS_IMAGE_H

#include <optional>
#include <cmath>
#include <ostream>

class Pixel {
public:
    int red;
    int green;
    int blue;

    Pixel();

    Pixel(int red, int green, int blue);

    int getMaxPixel() const;
    int getMinPixel() const;
    void setColors(int red, int green, int blue);
    Pixel operator + (const Pixel& pixel1) const;
    Pixel operator * (double num) const;
    Pixel operator + (double num) const;
    friend std::ostream& operator << (std::ostream& os, const Pixel& obj);
};

class Image {
private:
    int height;
    int width;
    Pixel *matrix;
public:
    Image(int height, int width, int maxColorNumber, Pixel *matrix);

    Pixel getPixel(int row, int col);
    void setPixel(int row, int col, int red, int green, int blue);
    int getHeight() const;
    int getWidth() const;
};

#endif //FILTERS_IMAGE_H
