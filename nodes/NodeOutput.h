//
// Created by noxin on 11/30/20.
//

#ifndef FILTERS_NODEOUTPUT_H
#define FILTERS_NODEOUTPUT_H

#include <fstream>
#include "INode.h"
#include "Image.h"
#include <cassert>

class NodeOutput : public INode {
private:
    std::string filePath;
    std::vector<std::shared_ptr<INode>> inputs;
    std::vector<std::shared_ptr<INode>> outputs;
    std::shared_ptr<Image> outputPtr;

    static void writeImageToFile(std::shared_ptr<Image> image, std::string path);

public:
    void process() override;

    void setOutput(int index, std::shared_ptr<INode>) override;

    void setInput(int index, std::shared_ptr<INode>) override;

    std::shared_ptr<Image> getOutputPtr() override;

    void setFilePath(std::string filepath);

    std::string getFilePath();
};


#endif //FILTERS_NODEOUTPUT_H
