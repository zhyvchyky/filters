//                mode = word[1] - '0'S;

// Created by noxin on 10/27/20.
//

#include <iostream>
#include "Filters.h"
#include "Conveyor.h"
#include "Node.h"
#include "NodeType.h"
#include <optional>
#include "processors/ImageSourceProcessor.h"
#include "processors/GaussianBlurProcessor.h"

int main(){
    ImageSourceProcessor inputProcessor = ImageSourceProcessor();
    Image image = inputProcessor.getImageFromFile("/home/linups/repos/filters1/filters/processors/112.ppm").value();
    GaussianBlurProcessor blur = GaussianBlurProcessor(4);
    blur.process();
    blur.applyTransform(image);
    return 0;
}
