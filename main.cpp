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

int main() {
    ImageSourceProcessor input = ImageSourceProcessor();
    auto image = std::make_shared<Image>(input.getImageFromFile("/home/linups/repos/filters/112.ppm").value());
    auto blur = GaussianBlurProcessor(14);
    blur.applyTransform(image);
    ImageOutputProcessor output = ImageOutputProcessor();
    output.writeImageToFile(image, "/home/linups/repos/filters/new.ppm");
    return 0;
}
