//
// Created by noxin on 10/27/20.
//

#include "Image.h"

Image::Image(int height, int width, int maxColorNumber, Pixel *matrix) {
    this->height = height;
    this->width = width;
    this->matrix = matrix;
}

Pixel Image::getPixel(int row, int col) {
    if ((0 <= row && row < height) && (0 <= col && col < width)){
        return this->matrix[row * width + col];
    }
    return Pixel();
}

void Image::setPixel(int row, int col, int red, int green, int blue) {
    if(row < height && col < width){
        this->matrix[row * width + col].setColors(red, green, blue);
    }
}

Image::~Image() {
    delete [] this->matrix;
}

int Image::getHeight() const {
    return this->height;
}

int Image::getWidth() const{
    return this->width;
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
    int colorRed = this->red + pixel1.red;;
    int colorGreen = this->green + pixel1.green;
    int colorBlue = this->blue + pixel1.blue;

    temp.red = colorRed;
    temp.green = colorGreen;
    temp.blue = colorBlue;
    return temp;
}

Pixel Pixel::operator*(double num) const {
    Pixel temp;
    int colorRed = ceil(double(this->red) * num);
    int colorGreen = ceil(double(this->green) * num);
    int colorBlue = ceil(double(this->blue) * num);

    temp.red = colorRed;
    temp.green = colorGreen;
    temp.blue = colorBlue;
    return temp;
}

std::ostream &operator<<(std::ostream &os, const Pixel &obj) {
    os << obj.red << ' ' << obj.green << ' ' << obj.blue;
    return os;
}
