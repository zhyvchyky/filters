//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_DEATTACHCONVEYORCOMMAND_H
#define FILTERS_DEATTACHCONVEYORCOMMAND_H

#include "command/ICommand.h"
#include "ConveyorManager.h"
#include "gui/cards/ConveyorCard.h"

class DeattachConveyorCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    size_t conveyorId;
    std::shared_ptr<IObserver<Conveyor>> card;
public:
    explicit DeattachConveyorCommand(std::shared_ptr<ConveyorManager>, size_t, std::shared_ptr<IObserver<Conveyor>>);
    bool execute() override;
};


#endif //FILTERS_DEATTACHCONVEYORCOMMAND_H
