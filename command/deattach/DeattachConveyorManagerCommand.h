//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_DEATTACHCONVEYORMANAGERCOMMAND_H
#define FILTERS_DEATTACHCONVEYORMANAGERCOMMAND_H

#include "command/ICommand.h"
#include "ConveyorManager.h"
#include "gui/cards/ConveyorManagerCard.h"

class DeattachConveyorManagerCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    std::shared_ptr<IObserver<ConveyorManager>> card;
public:
    explicit DeattachConveyorManagerCommand(std::shared_ptr<ConveyorManager>, std::shared_ptr<IObserver<ConveyorManager>>);
    bool execute() override;
};


#endif //FILTERS_DEATTACHCONVEYORMANAGERCOMMAND_H
