//
// Created by makstar on 26.12.2020.
//

#ifndef FILTERS_ATTACHGAUSSIANNOISECOMMAND_H
#define FILTERS_ATTACHGAUSSIANNOISECOMMAND_H

#include "command/attachCommands/AAttachCommand.h"
#include "nodes/ANode.h"
#include "nodes/GaussianNoiseNode.h"

class AttachGaussianNoiseCommand: public AAttachCommand<IObserver<GaussianNoiseNode>> {
public:
    explicit AttachGaussianNoiseCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<GaussianNoiseNode>>);
    bool execute() override;
};


#endif //FILTERS_ATTACHGAUSSIANNOISECOMMAND_H
