//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_DISCONNECTCONVEYORMANAGERCOMMAND_H
#define FILTERS_DISCONNECTCONVEYORMANAGERCOMMAND_H

#include "ICommand.h"
#include "ConveyorManager.h"
#include "cards/ConveyorManagerCard.h"

class DisconnectConveyorManagerCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    std::shared_ptr<ConveyorManagerCard> card;
public:
    explicit DisconnectConveyorManagerCommand(std::shared_ptr<ConveyorManager>, std::shared_ptr<ConveyorManagerCard>);
    bool execute() override;
};


#endif //FILTERS_DISCONNECTCONVEYORMANAGERCOMMAND_H
