//
// Created by makstar on 26.12.2020.
//

#ifndef FILTERS_CONNECTMEDIANCOMMAND_H
#define FILTERS_CONNECTMEDIANCOMMAND_H

#include "command/attachCommands/AConnectCommand.h"
#include "nodes/ANode.h"
#include "nodes/MedianNode.h"

class ConnectMedianCommand: public AConnectCommand<IObserver<MedianNode>> {
public:
    explicit ConnectMedianCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<MedianNode>>);
    bool execute() override;
};


#endif //FILTERS_CONNECTMEDIANCOMMAND_H
