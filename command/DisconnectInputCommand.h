//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_DISCONNECTINPUTCOMMAND_H
#define FILTERS_DISCONNECTINPUTCOMMAND_H

#include "AConnectCommand.h"
#include "nodes/ANode.h"
#include "cards/NodeInputCard.h"
#include "nodes/NodeInput.h"

class DisconnectInputCommand: public AConnectCommand<NodeInputCard> {
public:
    explicit DisconnectInputCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<NodeInputCard>);
    bool execute() override;
};


#endif //FILTERS_DISCONNECTINPUTCOMMAND_H
