//
// Created by makstar on 26.12.2020.
//

#ifndef FILTERS_CONNECTINPUTCOMMAND_H
#define FILTERS_CONNECTINPUTCOMMAND_H

#include "command/attachCommands/AConnectCommand.h"
#include "nodes/ANode.h"
#include "nodes/NodeInput.h"

class ConnectInputCommand: public AConnectCommand<IObserver<NodeInput>> {
public:
explicit ConnectInputCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<NodeInput>>);
bool execute() override;
};


#endif //FILTERS_CONNECTINPUTCOMMAND_H
