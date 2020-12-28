//
// Created by makstsar on 26.12.2020.
//

#include "ColorGeneratorCard.h"

std::tuple<int, int, int, int, int> ColorGeneratorCard::getColor() {
    return std::make_tuple(this->red, this->green, this->blue, this->height, this->width);
}

void ColorGeneratorCard::notify(std::shared_ptr<ColorGeneratorNode> node) {
    std::tie(this->red, this->green, this->blue, this->height, this->width) = node->getColorValues();
}
