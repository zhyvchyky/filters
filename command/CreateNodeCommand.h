//
// Created by noxin on 12/23/20.
//

#ifndef FILTERS_CREATENODECOMMAND_H
#define FILTERS_CREATENODECOMMAND_H

#include "ICommand.h"
#include "NodeType.h"

class CreateNodeCommand: public ICommand{
private:
    NodeType nodeType;
    size_t conveyorId;
public:
    CreateNodeCommand(size_t conveyorId, NodeType nodeType);
    bool execute() override;
};


#endif //FILTERS_CREATENODECOMMAND_H
