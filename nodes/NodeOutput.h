//
// Created by noxin on 11/30/20.
//

#ifndef FILTERS_NODEOUTPUT_H
#define FILTERS_NODEOUTPUT_H

#include <fstream>
#include "ANode.h"
#include "Image.h"
#include <cassert>

class NodeOutput : public ANode {
private:
    std::string filePath;

    static void writeImageToFile(std::shared_ptr<Image> image, std::string path);

public:
    void process() override;
    void setFilePath(std::string filepath);

    std::string getFilePath();
};


#endif //FILTERS_NODEOUTPUT_H
