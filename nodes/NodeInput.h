//
// Created by noxin on 11/30/20.
//

#ifndef FILTERS_NODEINPUT_H
#define FILTERS_NODEINPUT_H

#include "INode.h"
#include "Image.h"
#include <iostream>
#include <fstream>
#include <cassert>

class NodeInput : public INode {
private:
    std::string filePath;
    std::vector<std::shared_ptr<INode>> inputs;
    std::vector<std::shared_ptr<INode>> outputs;

    static std::shared_ptr<Image> getImageFromFile(const std::string &path);

    static std::tuple<int, int, int, int> getHeader(std::ifstream &input);

public:
    std::shared_ptr<Image> outputPtr;

    void process() override;

    void setOutput(int index, std::shared_ptr<INode>) override;

    void setInput(int index, std::shared_ptr<INode>) override;

    void setFields(std::vector<std::variant<int, std::string>>) override;

    std::shared_ptr<Image> getOutputPtr() override;

    std::vector<std::variant<int, std::string>> getFields() override;

};


#endif //FILTERS_NODEINPUT_H
