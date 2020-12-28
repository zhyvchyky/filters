//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_DEATTACHGAUSSIANNOISECOMMAND_H
#define FILTERS_DEATTACHGAUSSIANNOISECOMMAND_H

#include "command/attachCommands/AAttachCommand.h"
#include "nodes/ANode.h"
#include "nodes/GaussianNoiseNode.h"

class DeattachGaussianNoiseCommand: public AAttachCommand<IObserver<GaussianNoiseNode>> {
public:
    explicit DeattachGaussianNoiseCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<GaussianNoiseNode>>);
    bool execute() override;
};


#endif //FILTERS_DEATTACHGAUSSIANNOISECOMMAND_H
