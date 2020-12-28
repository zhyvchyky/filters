//
// Created by makstar on 26.12.2020.
//

#ifndef FILTERS_ATTACHMEDIANCOMMAND_H
#define FILTERS_ATTACHMEDIANCOMMAND_H

#include "command/attachCommands/AAttachCommand.h"
#include "nodes/ANode.h"
#include "nodes/MedianNode.h"

class AttachMedianCommand: public AAttachCommand<IObserver<MedianNode>> {
public:
    explicit AttachMedianCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<MedianNode>>);
    bool execute() override;
};


#endif //FILTERS_ATTACHMEDIANCOMMAND_H
