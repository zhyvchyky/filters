//
// Created by makst on 26.12.2020.
//

#ifndef FILTERS_DISCONNECTCOLORGENERATORCOMMAND_H
#define FILTERS_DISCONNECTCOLORGENERATORCOMMAND_H

#include "command/attachCommands/AConnectCommand.h"
#include "nodes/ANode.h"
#include "gui/cards/ColorGeneratorCard.h"
#include "nodes/ColorGeneratorNode.h"

class DisconnectColorGeneratorCommand: public AConnectCommand<IObserver<ColorGeneratorNode>> {
public:
    explicit DisconnectColorGeneratorCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<ColorGeneratorNode>>);
    bool execute() override;
};


#endif //FILTERS_DISCONNECTCOLORGENERATORCOMMAND_H
