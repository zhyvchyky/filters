//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_DEATTACHGAUSSIANBLURCOMMAND_H
#define FILTERS_DEATTACHGAUSSIANBLURCOMMAND_H

#include "command/attachCommands/AAttachCommand.h"
#include "nodes/ANode.h"
#include "nodes/GaussianBlurNode.h"

class DeattachGaussianBlurCommand: public AAttachCommand<IObserver<GaussianBlurNode>> {
public:
    explicit DeattachGaussianBlurCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<GaussianBlurNode>>);
    bool execute() override;
};

#endif //FILTERS_DEATTACHGAUSSIANBLURCOMMAND_H
