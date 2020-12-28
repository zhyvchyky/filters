//
// Created by linups on 12/25/20.
//

#ifndef FILTERS_SETGAUSSIANBLURCOMMAND_H
#define FILTERS_SETGAUSSIANBLURCOMMAND_H

#include "command/ICommand.h"
#include "ConveyorManager.h"

class SetGaussianBlurCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    size_t conveyorId, nodeId;
    int blurRadius;
public:
    SetGaussianBlurCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId, size_t nodeId, int blurRadius);
    bool execute() override;
};


#endif //FILTERS_SETGAUSSIANBLURCOMMAND_H
