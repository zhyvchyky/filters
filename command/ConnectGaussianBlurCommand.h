//
// Created by makstar on 26.12.2020.
//

#ifndef FILTERS_CONNECTGAUSSIANBLURCOMMAND_H
#define FILTERS_CONNECTGAUSSIANBLURCOMMAND_H

#include "AConnectCommand.h"
#include "nodes/ANode.h"
#include "cards/GaussianBlurCard.h"
#include "nodes/GaussianBlurNode.h"

class ConnectGaussianBlurCommand: public AConnectCommand<GaussianBlurCard> {
public:
    explicit ConnectGaussianBlurCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<GaussianBlurCard>);
    bool execute() override;
};


#endif //FILTERS_CONNECTGAUSSIANBLURCOMMAND_H
