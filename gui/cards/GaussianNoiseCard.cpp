//
// Created by makstsar on 26.12.2020.
//

#include "GaussianNoiseCard.h"

std::tuple<int, int, int> GaussianNoiseCard::getNoise() {
    return std::make_tuple(this->noise, this->height, this->width);
}

void GaussianNoiseCard::notify(std::shared_ptr<GaussianNoiseNode> node) {
    std::tie(this->noise, this->height, this->width) = node->getNoise();
}
