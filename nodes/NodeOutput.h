//
// Created by noxin on 11/30/20.
//

#ifndef FILTERS_NODEOUTPUT_H
#define FILTERS_NODEOUTPUT_H

#include <fstream>
#include "ANode.h"
#include "Image.h"
#include "ISubject.h"
#include <cassert>

class NodeOutput : public ANode, public ISubject<NodeOutput> {
private:
    std::string filePath = "default.ppm";

    void setFilePath(std::string filepath);
    static void writeImageToFile(std::shared_ptr<Image> image, std::string path);
    void process() override;

public:
    friend class SetNodeOutputCommand;

    std::string getFilePath();
    NodeType getNodeType() override;
};


#endif //FILTERS_NODEOUTPUT_H
