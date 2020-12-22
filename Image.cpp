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
    if (row >= height || col >= width)
        return Pixel();
    return this->matrix[row * width + col];
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

    temp.red = colorRed > 255 ? colorRed % 255 : colorRed;
    temp.green = colorGreen > 255 ? colorGreen % 255 : colorGreen;
    temp.blue = colorBlue > 255 ? colorBlue % 255 : colorBlue;
    return temp;
}

Pixel Pixel::operator*(int num) const {
    Pixel temp;
    int colorRed = this->red * num;
    int colorGreen = this->green * num;
    int colorBlue = this->blue * num;

    temp.red = colorRed > 255 ? colorRed - 255 : colorRed;
    temp.green = colorGreen > 255 ? colorGreen - 255 : colorGreen;
    temp.blue = colorBlue > 255 ? colorBlue - 255 : colorBlue;
    return temp;
}

std::ostream &operator<<(std::ostream &os, const Pixel &obj) {
    os << obj.red << ' ' << obj.green << ' ' << obj.blue;
    return os;
}

int Pixel::getMaxPixel() const {
    if(this->blue >= this->green && this->blue >= this->red) return this->blue;
    else if (this->red >= this->green && this->red >= this->blue) return this->red;
    else return this->green;
}

int Pixel::getMinPixel() const {
    if(this->blue <= this->green && this->blue <= this->red) return this->blue;
    else if (this->red <= this->green && this->red <= this->blue) return this->red;
    else return this->green;
}
