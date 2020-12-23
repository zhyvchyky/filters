//
// Created by makstar on 07.12.2020.
//

#ifndef FILTERS_COLORGENERATORNODE_H
#define FILTERS_COLORGENERATORNODE_H


#include "ANode.h"
#include <cassert>

class ColorGeneratorNode: public ANode {
private:
    int red,green,blue, height, width;

    std::shared_ptr<Image> genColor();
public:
    void process() override;

    void setColorValues(int colorRed, int colorGreen, int colorBlue, int h, int w);

    std::tuple<int, int, int, int ,int> getColorValues();
};


#endif //FILTERS_COLORGENERATORNODE_H
