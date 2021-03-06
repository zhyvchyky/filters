//
// Created by noxin on 11/30/20.
//

#ifndef FILTERS_NODEINPUT_H
#define FILTERS_NODEINPUT_H

#include "ANode.h"
#include "Image.h"
#include "ISubject.h"
#include <iostream>
#include <fstream>
#include <cassert>


class NodeInput : public ANode, public ISubject<NodeInput> {

private:
    std::string filePath;

    void setFilePath(std::string filepath);
    static std::shared_ptr<Image> getImageFromFile(const std::string &path);
    static std::tuple<int, int, int, int> getHeader(std::ifstream &input);
    void process() override;

public:
    friend class SetNodeInputCommand;

    std::string getFilePath();

    NodeType getNodeType() override;
};


#endif //FILTERS_NODEINPUT_H
