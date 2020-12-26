//
// Created by makstsar on 26.12.2020.
//

#ifndef FILTERS_CONNECTCOLORGENERATORCOMMAND_H
#define FILTERS_CONNECTCOLORGENERATORCOMMAND_H

#include "AConnectCommand.h"
#include "nodes/ANode.h"
#include "cards/ColorGeneratorCard.h"
#include "nodes/ColorGeneratorNode.h"

class ConnectColorGeneratorCommand: public AConnectCommand<ColorGeneratorCard> {
public:
    explicit ConnectColorGeneratorCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<ColorGeneratorCard>);
    bool execute() override;
};



#endif //FILTERS_CONNECTCOLORGENERATORCOMMAND_H
