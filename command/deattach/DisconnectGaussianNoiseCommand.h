//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_DISCONNECTGAUSSIANNOISECOMMAND_H
#define FILTERS_DISCONNECTGAUSSIANNOISECOMMAND_H

#include "command/attachCommands/AConnectCommand.h"
#include "nodes/ANode.h"
#include "nodes/GaussianNoiseNode.h"

class DisconnectGaussianNoiseCommand: public AConnectCommand<IObserver<GaussianNoiseNode>> {
public:
    explicit DisconnectGaussianNoiseCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<GaussianNoiseNode>>);
    bool execute() override;
};


#endif //FILTERS_DISCONNECTGAUSSIANNOISECOMMAND_H
