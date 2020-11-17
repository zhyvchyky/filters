//                mode = word[1] - '0'S;

// Created by noxin on 10/27/20.
//

#include <iostream>
#include <optional>
#include "processors/ImageSourceProcessor.h"
int main(){
    ImageSourceProcessor inputProcessor = ImageSourceProcessor();
    Image image = inputProcessor.getImageFromFile("image.ppm").value();
    Pixel pixel = image.getPixel(1, 0).value();
    std::cout << pixel.red << " " << pixel.green << " " << pixel.blue;
    return 0;
}