//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_DISCONNECTCONVEYORMANAGERCOMMAND_H
#define FILTERS_DISCONNECTCONVEYORMANAGERCOMMAND_H

#include "command/ICommand.h"
#include "ConveyorManager.h"
#include "gui/cards/ConveyorManagerCard.h"

class DisconnectConveyorManagerCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    std::shared_ptr<IObserver<ConveyorManager>> card;
public:
    explicit DisconnectConveyorManagerCommand(std::shared_ptr<ConveyorManager>, std::shared_ptr<IObserver<ConveyorManager>>);
    bool execute() override;
};


#endif //FILTERS_DISCONNECTCONVEYORMANAGERCOMMAND_H
