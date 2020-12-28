//
// Created by makstar on 26.12.2020.
//

#ifndef FILTERS_ATTACHINPUTCOMMAND_H
#define FILTERS_ATTACHINPUTCOMMAND_H

#include "command/attachCommands/AAttachCommand.h"
#include "nodes/ANode.h"
#include "nodes/NodeInput.h"

class AttachInputCommand: public AAttachCommand<IObserver<NodeInput>> {
public:
explicit AttachInputCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<NodeInput>>);
bool execute() override;
};


#endif //FILTERS_ATTACHINPUTCOMMAND_H
