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
#include "processors/BlackAndWhiteProcessor.h"
#include "processors/EdgeDetectionProcessor.h"
#include "processors/GaussianNoiseProcessor.h"
#include "processors/NegativeProcessor.h"

int main() {
    ImageSourceProcessor input = ImageSourceProcessor();
    ImageOutputProcessor output = ImageOutputProcessor();
    auto image = std::make_shared<Image>(input.getImageFromFile("/home/linups/repos/filters/112.ppm").value());

    NegativeProcessor neg = NegativeProcessor();
    image = neg.applyTransform(image);
    output.writeImageToFile(image, "/home/linups/repos/filters/newimg.ppm");
    return 0;
}
