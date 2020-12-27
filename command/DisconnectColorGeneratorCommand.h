//
// Created by makst on 26.12.2020.
//

#ifndef FILTERS_DISCONNECTCOLORGENERATORCOMMAND_H
#define FILTERS_DISCONNECTCOLORGENERATORCOMMAND_H

#include "AConnectCommand.h"
#include "nodes/ANode.h"
#include "cards/ColorGeneratorCard.h"
#include "nodes/ColorGeneratorNode.h"

class DisconnectColorGeneratorCommand: public AConnectCommand<ColorGeneratorCard> {
public:
    explicit DisconnectColorGeneratorCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<ColorGeneratorCard>);
    bool execute() override;
};


#endif //FILTERS_DISCONNECTCOLORGENERATORCOMMAND_H
