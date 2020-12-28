//
// Created by makstar on 26.12.2020.
//

#ifndef FILTERS_ATTACHGAUSSIANBLURCOMMAND_H
#define FILTERS_ATTACHGAUSSIANBLURCOMMAND_H

#include "command/attachCommands/AAttachCommand.h"
#include "nodes/ANode.h"
#include "nodes/GaussianBlurNode.h"

class AttachGaussianBlurCommand: public AAttachCommand<IObserver<GaussianBlurNode> > {
public:
    explicit AttachGaussianBlurCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<GaussianBlurNode> >);
    bool execute() override;
};


#endif //FILTERS_ATTACHGAUSSIANBLURCOMMAND_H
