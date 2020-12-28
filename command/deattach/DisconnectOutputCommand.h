//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_DISCONNECTOUTPUTCOMMAND_H
#define FILTERS_DISCONNECTOUTPUTCOMMAND_H

#include "command/attachCommands/AConnectCommand.h"
#include "nodes/ANode.h"
#include "nodes/NodeOutput.h"

class DisconnectOutputCommand: public AConnectCommand<IObserver<NodeOutput>> {
public:
    explicit DisconnectOutputCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<NodeOutput>>);
    bool execute() override;
};


#endif //FILTERS_DISCONNECTOUTPUTCOMMAND_H
