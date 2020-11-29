//
// Created by linups on 11/28/20.
//

#ifndef FILTERS_APPLYVECTORTRANSFORM_H
#define FILTERS_APPLYVECTORTRANSFORM_H
#include "Image.h"
#include <memory>

enum Mode {Horizontal, Vertical};
Pixel applyVectorTransform(const std::shared_ptr<Image>& img1, int row, int col, Mode mode, int centre, double* transformVector);

#endif //FILTERS_APPLYVECTORTRANSFORM_H
