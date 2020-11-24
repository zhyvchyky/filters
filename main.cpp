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
#include "processors/ImageOutputProcessor.h"
#include "processors/GaussianBlurProcessor.h"

int main(){
    ImageSourceProcessor inputProcessor = ImageSourceProcessor();
    Image image = inputProcessor.getImageFromFile("copy.ppm").value();
    auto imagePtr = std::make_shared<Image>(image);
    ImageOutputProcessor outputProcessor = ImageOutputProcessor();
    outputProcessor.writeImageToFile(imagePtr, "copy2.ppm");

    return 0;
}
