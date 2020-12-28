//
// Created by linups on 12/25/20.
//

#ifndef FILTERS_SETNODEOUTPUTCOMMAND_H
#define FILTERS_SETNODEOUTPUTCOMMAND_H

#include "command/ICommand.h"
#include "ConveyorManager.h"

class SetNodeOutputCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    size_t conveyorId;
    std::string filepath;
public:
    SetNodeOutputCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId, std::string filepath);
    bool execute() override;
};


#endif //FILTERS_SETNODEOUTPUTCOMMAND_H
