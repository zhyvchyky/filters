//
// Created by makstar on 26.12.2020.
//

#ifndef FILTERS_ATTACHOUTPUTCOMMAND_H
#define FILTERS_ATTACHOUTPUTCOMMAND_H


#include "command/attachCommands/AAttachCommand.h"
#include "nodes/ANode.h"
#include "nodes/NodeOutput.h"

class AttachOutputCommand: public AAttachCommand<IObserver<NodeOutput>> {
public:
    explicit AttachOutputCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<NodeOutput>>);
    bool execute() override;
};


#endif //FILTERS_ATTACHOUTPUTCOMMAND_H
