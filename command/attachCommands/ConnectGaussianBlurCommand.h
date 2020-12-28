//
// Created by makstar on 26.12.2020.
//

#ifndef FILTERS_CONNECTGAUSSIANBLURCOMMAND_H
#define FILTERS_CONNECTGAUSSIANBLURCOMMAND_H

#include "command/attachCommands/AConnectCommand.h"
#include "nodes/ANode.h"
#include "nodes/GaussianBlurNode.h"

class ConnectGaussianBlurCommand: public AConnectCommand<IObserver<GaussianBlurNode> > {
public:
    explicit ConnectGaussianBlurCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<GaussianBlurNode> >);
    bool execute() override;
};


#endif //FILTERS_CONNECTGAUSSIANBLURCOMMAND_H
