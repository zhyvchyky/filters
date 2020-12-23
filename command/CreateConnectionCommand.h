//
// Created by makstar on 23.12.2020.
//

#ifndef FILTERS_CREATECONNECTIONCOMMAND_H
#define FILTERS_CREATECONNECTIONCOMMAND_H

#include "ICommand.h"
#include <memory>
#include "ConveyorManager.h"

class CreateConnectionCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    size_t conveyorId;
    std::shared_ptr<ANode> inputNode;
    std::shared_ptr<ANode> outputNode;
public:
    explicit CreateConnectionCommand(std::shared_ptr<ConveyorManager>, size_t, std::shared_ptr<ANode>, std::shared_ptr<ANode>);
    bool execute() override;
};


#endif //FILTERS_CREATECONNECTIONCOMMAND_H
