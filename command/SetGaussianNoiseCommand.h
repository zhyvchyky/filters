//
// Created by linups on 12/25/20.
//

#ifndef FILTERS_SETGAUSSIANNOISECOMMAND_H
#define FILTERS_SETGAUSSIANNOISECOMMAND_H

#include "ICommand.h"
#include "ConveyorManager.h"

class SetGaussianNoiseCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    size_t conveyorId, nodeId;
    int noise, height, width;
public:
    SetGaussianNoiseCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId, size_t nodeId, int noise, int height, int width);
    bool execute() override;
};


#endif //FILTERS_SETGAUSSIANNOISECOMMAND_H
