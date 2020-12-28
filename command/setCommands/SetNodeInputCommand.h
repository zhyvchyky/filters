//
// Created by linups on 12/25/20.
//

#ifndef FILTERS_SETNODEINPUTCOMMAND_H
#define FILTERS_SETNODEINPUTCOMMAND_H

#include "command/ICommand.h"
#include "ConveyorManager.h"

class SetNodeInputCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    size_t conveyorId, nodeId;
    std::string filepath;
public:
    SetNodeInputCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId, size_t nodeId, std::string filepath);
    bool execute() override;
};


#endif //FILTERS_SETNODEINPUTCOMMAND_H
