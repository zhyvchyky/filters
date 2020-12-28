//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_DISCONNECTINPUTCOMMAND_H
#define FILTERS_DISCONNECTINPUTCOMMAND_H

#include "command/attachCommands/AConnectCommand.h"
#include "nodes/ANode.h"
#include "nodes/NodeInput.h"

class DisconnectInputCommand: public AConnectCommand<IObserver<NodeInput>> {
public:
    explicit DisconnectInputCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<NodeInput>>);
    bool execute() override;
};


#endif //FILTERS_DISCONNECTINPUTCOMMAND_H
