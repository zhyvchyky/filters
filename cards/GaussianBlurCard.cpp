//
// Created by linups on 12/23/20.
//

#include "GaussianBlurCard.h"

int GaussianBlurCard::getRadius() {
    return this->radius;
}

void GaussianBlurCard::notify(std::shared_ptr<GaussianBlurNode> node) {
    this->radius = node->getRadius();
}
