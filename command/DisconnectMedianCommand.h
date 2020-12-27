//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_DISCONNECTMEDIANCOMMAND_H
#define FILTERS_DISCONNECTMEDIANCOMMAND_H

#include "AConnectCommand.h"
#include "nodes/ANode.h"
#include "cards/MedianCard.h"
#include "nodes/MedianNode.h"

class DisconnectMedianCommand: public AConnectCommand<MedianCard> {
public:
    explicit DisconnectMedianCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<MedianCard>);
    bool execute() override;
};


#endif //FILTERS_DISCONNECTMEDIANCOMMAND_H
