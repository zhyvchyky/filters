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

int main() {
    ImageSourceProcessor input = ImageSourceProcessor();
    auto image = std::make_shared<Image>(input.getImageFromFile("/home/linups/repos/filters/111.ppm").value());

    EdgeDetectionProcessor det = EdgeDetectionProcessor();
    image = det.applyTransform(image);
    ImageOutputProcessor output = ImageOutputProcessor();
    output.writeImageToFile(image, "/home/linups/repos/filters/1111.ppm");
    return 0;
}
