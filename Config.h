//
// Created by noxin on 11/26/20.
//

#ifndef FILTERS_CONFIG_H
#define FILTERS_CONFIG_H

#include <vector>
#include <variant>
#include <string>
class Node;

typedef std::variant<std::string, int> ConfigField;

using Inputs = std::vector<std::shared_ptr<Node>>;
using Outputs = std::vector<std::shared_ptr<Node>>;



class Config {
    //temporary public
public:
    std::vector<ConfigField> fields;
    Inputs inputs;
    Outputs outputs;

};


#endif //FILTERS_CONFIG_H
