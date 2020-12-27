//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_CONNECTCONVEYORMANAGERCOMMAND_H
#define FILTERS_CONNECTCONVEYORMANAGERCOMMAND_H

#include "ICommand.h"
#include "Filters.h"
#include "cards/ConveyorManagerCard.h"

class ConnectConveyorManagerCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    std::shared_ptr<ConveyorManagerCard> card;
public:
    explicit ConnectConveyorManagerCommand(std::shared_ptr<ConveyorManager>, std::shared_ptr<ConveyorManagerCard>);
    bool execute() override;
};


#endif //FILTERS_CONNECTCONVEYORMANAGERCOMMAND_H
