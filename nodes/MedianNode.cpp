//
// Created by makstar on 06.12.2020.
//

#include "MedianNode.h"


void MedianNode::process() {
    this->outputPtr=applyTransform(this->inputs[0]->getOutputPtr());
}

std::shared_ptr<Image> MedianNode::applyTransform(const std::shared_ptr<Image> &img) {

    int width = img->getWidth();
    int height = img->getHeight();

    auto new_img = std::make_shared<Image>(height, width, 3, new Pixel[height * width]);
    std::vector<double> g, b, r;
    int i,j,h,w;

    Pixel pix;

    for(h = 0; h < height; h++)
        for(w = 0; w < width; w++){
            if (h < this->N || h > (height - this->N - 1) || w < this->N || w > (width - this->N - 1)) {
                pix = img->getPixel(h, w);
                new_img->setPixel(h, w, pix.red, pix.green, pix.blue);
            }
        }


    for(h = this->N; h < (height - this->N); h++)
        for(w = this->N; w < (width - this->N); w++){
            for(i = (h - this->N); i <= (h + this->N); i++)
                for(j = (w - this->N); j <= (w + this->N); j++) {
                    pix = img->getPixel(i, j);
                    r.push_back(pix.red);
                    g.push_back(pix.green);
                    b.push_back(pix.blue);
                }

            pix = img->getPixel(h,w);
            new_img->setPixel(h, w, r[getPositionMedian(r)], g[getPositionMedian(g)], b[getPositionMedian(b)]);

            g.clear();
            r.clear();
            b.clear();
        }

    return new_img;
}

int MedianNode::getPositionMedian(std::vector<double> vec){
    auto const len = vec.size();
    auto const mid = (len-1)/2;
    std::vector<int> indices;
    auto value = 0;
    std::generate_n(std::back_inserter(indices), len, [&](){return value++;});

    std::nth_element(indices.begin(), indices.begin() + mid, indices.end(), [&](int lhs, int rhs){return vec[lhs] < vec[rhs];});

    return indices[mid];
}

void MedianNode::setMedian(int mdn) {
    this->N = mdn;
}

int MedianNode::getMedian() const {
    return this->N;
}
