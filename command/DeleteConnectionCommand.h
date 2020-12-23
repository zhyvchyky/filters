//
// Created by makstar on 23.12.2020.
//

#ifndef FILTERS_DELETECONNECTIONCOMMAND_H
#define FILTERS_DELETECONNECTIONCOMMAND_H

#include "ICommand.h"
#include <memory>
#include "ConveyorManager.h"

class DeleteConnectionCommand : public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    size_t conveyorId;
    std::shared_ptr<ANode> inputNode;
    std::shared_ptr<ANode> outputNode;
public:
    explicit DeleteConnectionCommand(std::shared_ptr<ConveyorManager>, size_t, std::shared_ptr<ANode>, std::shared_ptr<ANode>);
    bool execute() override;
};


#endif //FILTERS_DELETECONNECTIONCOMMAND_H
