//
// Created by makstsar on 26.12.2020.
//

#ifndef FILTERS_CONNECTCOLORGENERATORCOMMAND_H
#define FILTERS_CONNECTCOLORGENERATORCOMMAND_H

#include "command/attachCommands/AConnectCommand.h"
#include "nodes/ANode.h"
#include "nodes/ColorGeneratorNode.h"

class ConnectColorGeneratorCommand: public AConnectCommand<IObserver<ColorGeneratorNode>> {
public:
    explicit ConnectColorGeneratorCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<ColorGeneratorNode>>);
    bool execute() override;
};



#endif //FILTERS_CONNECTCOLORGENERATORCOMMAND_H
