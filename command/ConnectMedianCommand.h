//
// Created by makstar on 26.12.2020.
//

#ifndef FILTERS_CONNECTMEDIANCOMMAND_H
#define FILTERS_CONNECTMEDIANCOMMAND_H

#include "AConnectCommand.h"
#include "nodes/ANode.h"
#include "cards/MedianCard.h"
#include "nodes/MedianNode.h"

class ConnectMedianCommand: public AConnectCommand<MedianCard> {
public:
    explicit ConnectMedianCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<MedianCard>);
    bool execute() override;
};


#endif //FILTERS_CONNECTMEDIANCOMMAND_H
