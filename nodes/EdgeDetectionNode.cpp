//
// Created by linups on 12/19/20.
//

#include "EdgeDetectionNode.h"

void EdgeDetectionNode::process() {
    this->outputPtr = applyTransform(this->inputs[0]->getOutputPtr());
}

std::shared_ptr<Image> EdgeDetectionNode::preProcess(std::shared_ptr<Image> img1) {
    auto nodeBW = std::make_shared<BlackAndWhiteNode>();
    auto nodeBlur = std::make_shared<GaussianBlurNode>();
    nodeBlur->setRadius(2);
    nodeBW->setInput(0, this->inputs[0]);
    nodeBlur->setInput(0, nodeBW);
    nodeBW->process();
    nodeBlur->process();
    return nodeBlur->getOutputPtr();
}

std::tuple<std::shared_ptr<Image>, int*> EdgeDetectionNode::calcGradient(const std::shared_ptr<Image>& img1) {
    int width = img1->getWidth();
    int height = img1->getHeight();
    auto midXVal = std::make_shared<Image>(height, width, 3, new Pixel[height*width]);
    auto midYVal = std::make_shared<Image>(height, width, 3, new Pixel[height*width]);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel1 = applyVectorTransform(img1, i, j, Horizontal, 1, kernelX1);
            Pixel pixel2 = applyVectorTransform(img1, i, j, Horizontal, 1, kernelX2);
            midXVal->setPixel(i, j, pixel1.red, pixel1.green, pixel1.blue);
            midYVal->setPixel(i, j, pixel2.red, pixel2.green, pixel2.blue);
        }
    }
    auto imgX = std::make_shared<Image>(height, width, 3, new Pixel[height*width]);
    auto imgY = std::make_shared<Image>(height, width, 3, new Pixel[height*width]);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel1 = applyVectorTransform(midXVal, i, j, Vertical, 1, kernelX2);
            Pixel pixel2 = applyVectorTransform(midYVal, i, j, Vertical, 1, kernelX1);
            imgX->setPixel(i, j, pixel1.red, pixel1.green, pixel1.blue);
            imgY->setPixel(i, j, pixel2.red, pixel2.green, pixel2.blue);
        }
    }
    midXVal.reset();
    midYVal.reset();
    std::shared_ptr<Image> gradient = calcHypotenuse(imgX, imgY);
    int* angle = calcAtan2(imgX, imgY);
    imgX.reset();
    imgY.reset();
    return std::make_tuple(gradient, angle);
}

std::shared_ptr<Image> EdgeDetectionNode::calcHypotenuse(const std::shared_ptr<Image>& imgX, const std::shared_ptr<Image>& imgY) {
    int width = imgX->getWidth();
    int height = imgY->getHeight();
    auto result = std::make_shared<Image>(height, width, 3, new Pixel[height*width]);
    int max = 0;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel1 = imgX->getPixel(i, j);
            Pixel pixel2 = imgY->getPixel(i, j);

            int xVal = pixel1.red;
            int yVal = pixel2.red;

            int resultVal = ceil(sqrt(pow(xVal, 2) + pow(yVal, 2)));
            if(max < resultVal){
                max = resultVal;
            }
            result->setPixel(i, j, resultVal, resultVal, resultVal);
        }
    }
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel1 = result->getPixel(i, j);
            pixel1 = pixel1 * (255./double(max));
            result->setPixel(i, j, pixel1.red, pixel1.green, pixel1.blue);
        }
    }
    return result;
}

int* EdgeDetectionNode::calcAtan2(const std::shared_ptr<Image> &imgX, const std::shared_ptr<Image> &imgY) {
    int width = imgX->getWidth();
    int height = imgY->getHeight();
    int* result = new int[height*width];
    const double pi = 3.1428;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel1 = imgX->getPixel(i, j);
            Pixel pixel2 = imgY->getPixel(i, j);

            double xVal = pixel1.red;
            double yVal = pixel2.red;

            double degreeVal = atan(yVal/xVal) * 180./pi;

            if(degreeVal < 0){
                degreeVal += 180;
            }

            if((0 <= degreeVal && degreeVal < 22.5) || (157.5 <= degreeVal && degreeVal <= 180)){
                result[i*width + j] = 0;
            }
            else if(22.5 <= degreeVal && degreeVal < 67.5){
                result[i*width + j] = 45;
            }
            else if(67.5 <= degreeVal && degreeVal < 112.5){
                result[i*width + j] = 90;
            }
            else if(112.5 <= degreeVal && degreeVal < 157.5){
                result[i*width + j] = 135;
            }
        }
    }
    return result;
}

std::shared_ptr<Image> EdgeDetectionNode::nonMaxSupression(const std::shared_ptr<Image>& gradient, const int *angle) {
    int height = gradient->getHeight();
    int width = gradient->getWidth();
    auto result = std::make_shared<Image>(height, width, 3, new Pixel[height*width]);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int l = 255;
            int r = 255;

            if(angle[i*width+j] == 0){
                l = gradient->getPixel(i,j-1).red;
                r = gradient->getPixel(i,j+1).red;
            }
            else if(angle[i*width+j] == 45){
                l = gradient->getPixel(i-1, j+1).red;
                r = gradient->getPixel(i+1, j-1).red;
            }
            else if(angle[i*width+j] == 90){
                l = gradient->getPixel(i-1,j).red;
                r = gradient->getPixel(i+1,j).red;
            }
            else if(angle[i*width+j] == 135){
                l = gradient->getPixel(i+1,j+1).red;
                r = gradient->getPixel(i-1,j-1).red;
            }
            int current = gradient->getPixel(i, j).red;
            if((current >= l) && (current >= r)){
                result->setPixel(i, j, current, current, current);
            }
            else{
                result->setPixel(i, j, 0, 0, 0);
            }
        }
    }
    return result;
}

std::shared_ptr<Image> EdgeDetectionNode::dThresholdEdgeDetector(const std::shared_ptr<Image>& supressedImg) {
    int height = supressedImg->getHeight();
    int width = supressedImg->getWidth();

    int highThreshold = ceil(255. * 0.09);
    int lowThreshold = ceil(highThreshold * 0.1);
    auto result = std::make_shared<Image>(height, width, 3, new Pixel[height*width]);

    int weak = 25;
    int strong = 255;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int current = supressedImg->getPixel(i, j).red;
            if(current >= highThreshold){
                result->setPixel(i, j, strong, strong, strong);
            }
            else if((lowThreshold <= current) && (current < highThreshold)){
                result->setPixel(i, j, weak, weak, weak);
            }
        }
    }
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(result->getPixel(i, j).red == weak){
                if((result->getPixel(i+1, j-1).red == strong) || (result->getPixel(i+1, j).red == strong) || (result->getPixel(i+1, j+1).red == strong) || (result->getPixel(i, j-1).red == strong) || (result->getPixel(i, j+1).red == strong) || (result->getPixel(i-1, j-1).red == strong) || (result->getPixel(i-1, j).red == strong) || (result->getPixel(i-1, j+1).red == strong)){
                    result->setPixel(i, j, strong, strong, strong);
                }
                else{
                    result->setPixel(i, j, 0, 0, 0);
                }
            }
        }
    }
    return result;
}

std::shared_ptr<Image> EdgeDetectionNode::applyTransform(std::shared_ptr<Image> image) {
    image = preProcess(image);
    auto tuple = calcGradient(image);
    image = nonMaxSupression(std::get<0>(tuple), std::get<1>(tuple));
    image = dThresholdEdgeDetector(image);
    return image;
}

std::shared_ptr<Image> EdgeDetectionNode::getOutputPtr() {
    return this->outputPtr;
}

void EdgeDetectionNode::setOutput(int index, std::shared_ptr<INode> node) {
    if(this->outputs.size() <= index)
        this->outputs.push_back(node);
    else
        this->outputs[index] = node;
}

void EdgeDetectionNode::setInput(int index, std::shared_ptr<INode> node) {
    if(this->inputs.size() <= index)
        this->inputs.push_back(node);
    else
        this->inputs[index] = node;
}

std::vector<std::shared_ptr<INode>> EdgeDetectionNode::getInputs() {
    return this->inputs;
}