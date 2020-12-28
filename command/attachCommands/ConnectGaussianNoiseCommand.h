//
// Created by makstar on 26.12.2020.
//

#ifndef FILTERS_CONNECTGAUSSIANNOISECOMMAND_H
#define FILTERS_CONNECTGAUSSIANNOISECOMMAND_H

#include "command/attachCommands/AConnectCommand.h"
#include "nodes/ANode.h"
#include "nodes/GaussianNoiseNode.h"

class ConnectGaussianNoiseCommand: public AConnectCommand<IObserver<GaussianNoiseNode>> {
public:
    explicit ConnectGaussianNoiseCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<GaussianNoiseNode>>);
    bool execute() override;
};


#endif //FILTERS_CONNECTGAUSSIANNOISECOMMAND_H
