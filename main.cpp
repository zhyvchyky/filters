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
    ImageSourceProcessor inputProcessor = ImageSourceProcessor();
    ImageOutputProcessor outputProcessor = ImageOutputProcessor();

    Config config1 = Config();
    Config config2 = Config();

    config1.fields.emplace_back("image.ppm");
    config2.fields.emplace_back("copy3.ppm");

    std::shared_ptr<Image> imagePtr = inputProcessor.process(config1);
    config2.inputs.emplace_back(std::make_shared<Node>());
    config2.inputs[0]->outputPointer = inputProcessor.process(config1);
    outputProcessor.process(config2);

    return 0;
}
