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
#include "processors/CombineProcessor.h"

int main() {
    ImageSourceProcessor input = ImageSourceProcessor();
    ImageOutputProcessor output = ImageOutputProcessor();
    auto image = std::make_shared<Image>(input.getImageFromFile("/home/linups/repos/filters/anon.ppm").value());

    EdgeDetectionProcessor det = EdgeDetectionProcessor();
    auto blur = GaussianBlurProcessor(8);
    CombineProcessor comb = CombineProcessor();
    auto image1 = blur.applyTransform(image);
    auto image2 = det.applyTransform(image);
    auto img3 = comb.combine(image1, image2);
    output.writeImageToFile(img3, "/home/linups/repos/filters/newimg2.ppm");
    return 0;
}
