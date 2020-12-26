//
// Created by makstsar on 26.12.2020.
//

#include "MedianCard.h"

int MedianCard::getMedian() {
    return this->median;
}

void MedianCard::notify(std::shared_ptr<MedianNode> node) {
    this->median = node->getMedian();
}
