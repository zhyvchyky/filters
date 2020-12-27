//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_DISCONNECTGAUSSIANBLURCOMMAND_H
#define FILTERS_DISCONNECTGAUSSIANBLURCOMMAND_H

#include "AConnectCommand.h"
#include "nodes/ANode.h"
#include "cards/GaussianBlurCard.h"
#include "nodes/GaussianBlurNode.h"

class DisconnectGaussianBlurCommand: public AConnectCommand<GaussianBlurCard> {
public:
    explicit DisconnectGaussianBlurCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<GaussianBlurCard>);
    bool execute() override;
};

#endif //FILTERS_DISCONNECTGAUSSIANBLURCOMMAND_H
