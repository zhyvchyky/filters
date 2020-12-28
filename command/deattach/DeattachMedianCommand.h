//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_DEATTACHMEDIANCOMMAND_H
#define FILTERS_DEATTACHMEDIANCOMMAND_H

#include "command/attachCommands/AAttachCommand.h"
#include "nodes/ANode.h"
#include "nodes/MedianNode.h"

class DeattachMedianCommand: public AAttachCommand<IObserver<MedianNode>> {
public:
    explicit DeattachMedianCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<MedianNode>>);
    bool execute() override;
};


#endif //FILTERS_DEATTACHMEDIANCOMMAND_H
