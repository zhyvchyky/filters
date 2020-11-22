//
// Created by noxin on 10/27/20.
//

#include "Image.h"

Image::Image(int height, int width, int maxColorNumber, Pixel *matrix) {
    this->height = height;
    this->width = width;
    this->matrix = matrix;
}

std::optional<Pixel> Image::getPixel(int row, int col) {
    if (row >= height || col >= width)
        return {};
    return this->matrix[row * width + col];
}

void Image::setPixel(int row, int col, int red, int green, int blue) {
    if(row < height && col < width){
        this->matrix[row * width + col].setColors(red, green, blue);
    }
}

int Image::getHeight() const {
    return height;
}

int Image::getWidth() const{
    return width;
}

Pixel::Pixel(int red, int green, int blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

Pixel::Pixel() {
    this->red = 0;
    this->green = 0;
    this->blue = 0;
}

void Pixel::setColors(int red, int green, int blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

Pixel Pixel::operator+(const Pixel &pixel1) const {
    Pixel temp;
    temp.red = red + pixel1.red;
    temp.green = green + pixel1.green;
    temp.blue = blue + pixel1.blue;
    return temp;
}

Pixel Pixel::operator*(double num) const {
    Pixel temp;
    temp.red = red * num;
    temp.green = green * num;
    temp.blue = blue * num;
    return temp;
}
