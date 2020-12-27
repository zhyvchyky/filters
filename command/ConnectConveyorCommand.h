//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_CONNECTCONVEYORCOMMAND_H
#define FILTERS_CONNECTCONVEYORCOMMAND_H

#include "ICommand.h"
#include "ConveyorManager.h"
#include "cards/ConveyorCard.h"

class ConnectConveyorCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    size_t conveyorId;
    std::shared_ptr<ConveyorCard> card;
public:
    explicit ConnectConveyorCommand(std::shared_ptr<ConveyorManager>, size_t, std::shared_ptr<ConveyorCard>);
    bool execute() override;
};


#endif //FILTERS_CONNECTCONVEYORCOMMAND_H
