//
// Created by makstar on 26.12.2020.
//

#ifndef FILTERS_CONNECTINPUTCOMMAND_H
#define FILTERS_CONNECTINPUTCOMMAND_H

#include "AConnectCommand.h"
#include "nodes/ANode.h"
#include "cards/NodeInputCard.h"
#include "nodes/NodeInput.h"

class ConnectInputCommand: public AConnectCommand<NodeInputCard> {
public:
explicit ConnectInputCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<NodeInputCard>);
bool execute() override;
};


#endif //FILTERS_CONNECTINPUTCOMMAND_H
