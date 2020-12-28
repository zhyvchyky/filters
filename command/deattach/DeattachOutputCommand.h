//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_DEATTACHOUTPUTCOMMAND_H
#define FILTERS_DEATTACHOUTPUTCOMMAND_H

#include "command/attachCommands/AAttachCommand.h"
#include "nodes/ANode.h"
#include "nodes/NodeOutput.h"

class DeattachOutputCommand: public AAttachCommand<IObserver<NodeOutput>> {
public:
    explicit DeattachOutputCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<NodeOutput>>);
    bool execute() override;
};


#endif //FILTERS_DEATTACHOUTPUTCOMMAND_H
