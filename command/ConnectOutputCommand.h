//
// Created by makstar on 26.12.2020.
//

#ifndef FILTERS_CONNECTOUTPUTCOMMAND_H
#define FILTERS_CONNECTOUTPUTCOMMAND_H


#include "AConnectCommand.h"
#include "nodes/ANode.h"
#include "cards/NodeOutputCard.h"
#include "nodes/NodeOutput.h"

class ConnectOutputCommand: public AConnectCommand<NodeOutputCard> {
public:
    explicit ConnectOutputCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<NodeOutputCard>);
    bool execute() override;
};


#endif //FILTERS_CONNECTOUTPUTCOMMAND_H
