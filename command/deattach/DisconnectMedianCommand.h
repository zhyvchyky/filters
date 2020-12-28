//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_DISCONNECTMEDIANCOMMAND_H
#define FILTERS_DISCONNECTMEDIANCOMMAND_H

#include "command/attachCommands/AConnectCommand.h"
#include "nodes/ANode.h"
#include "nodes/MedianNode.h"

class DisconnectMedianCommand: public AConnectCommand<IObserver<MedianNode>> {
public:
    explicit DisconnectMedianCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<MedianNode>>);
    bool execute() override;
};


#endif //FILTERS_DISCONNECTMEDIANCOMMAND_H
