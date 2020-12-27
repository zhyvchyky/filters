//
// Created by linups on 12/25/20.
//

#ifndef FILTERS_SETCOLORGENERATORCOMMAND_H
#define FILTERS_SETCOLORGENERATORCOMMAND_H

#include "ICommand.h"
#include "ConveyorManager.h"

class SetColorGeneratorCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    int red, green, blue, width, height;
    size_t conveyorId, nodeId;
public:
    SetColorGeneratorCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId, size_t nodeId, int red, int green, int blue, int width, int height);
    bool execute() override;
};


#endif //FILTERS_SETCOLORGENERATORCOMMAND_H
