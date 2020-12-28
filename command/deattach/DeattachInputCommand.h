//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_DEATTACHINPUTCOMMAND_H
#define FILTERS_DEATTACHINPUTCOMMAND_H

#include "command/attachCommands/AAttachCommand.h"
#include "nodes/ANode.h"
#include "nodes/NodeInput.h"

class DeattachInputCommand: public AAttachCommand<IObserver<NodeInput>> {
public:
    explicit DeattachInputCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<NodeInput>>);
    bool execute() override;
};


#endif //FILTERS_DEATTACHINPUTCOMMAND_H
