//
// Created by makstsar on 26.12.2020.
//

#ifndef FILTERS_COLORGENERATORCARD_H
#define FILTERS_COLORGENERATORCARD_H

#include "nodes/ColorGeneratorNode.h"
#include "IObserver.h"

class ColorGeneratorCard: public IObserver<ColorGeneratorNode> {
private:
    int red, green, blue, height, width;
public:
    std::tuple<int, int, int, int, int> getColor();
    void notify(std::shared_ptr<ColorGeneratorNode>) override;
};


#endif //FILTERS_COLORGENERATORCARD_H
