//
// Created by noxin on 10/27/20.
//

#ifndef FILTERS_IMAGE_H
#define FILTERS_IMAGE_H

#include <optional>

class Pixel {
public:
    int red;
    int green;
    int blue;

    Pixel();

    Pixel(int red, int green, int blue);

    void setColors(int red, int green, int blue);
};

class Image {
private:
    int height;
    int width;
    Pixel *matrix;
public:
    Image(int height, int width, int maxColorNumber, Pixel *matrix);

    std::optional<Pixel> getPixel(int row, int col);
    void setPixel(int row, int col, int red, int green, int blue);
};

#endif //FILTERS_IMAGE_H
