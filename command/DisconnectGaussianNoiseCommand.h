//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_DISCONNECTGAUSSIANNOISECOMMAND_H
#define FILTERS_DISCONNECTGAUSSIANNOISECOMMAND_H

#include "AConnectCommand.h"
#include "nodes/ANode.h"
#include "cards/GaussianNoiseCard.h"
#include "nodes/GaussianNoiseNode.h"

class DisconnectGaussianNoiseCommand: public AConnectCommand<GaussianNoiseCard> {
public:
    explicit DisconnectGaussianNoiseCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<GaussianNoiseCard>);
    bool execute() override;
};


#endif //FILTERS_DISCONNECTGAUSSIANNOISECOMMAND_H
