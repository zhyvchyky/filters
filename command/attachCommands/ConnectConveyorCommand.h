//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_CONNECTCONVEYORCOMMAND_H
#define FILTERS_CONNECTCONVEYORCOMMAND_H

#include "command/ICommand.h"
#include "ConveyorManager.h"

class ConnectConveyorCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    size_t conveyorId;
    std::shared_ptr<IObserver<Conveyor>> card;
public:
    explicit ConnectConveyorCommand(std::shared_ptr<ConveyorManager>, size_t, std::shared_ptr<IObserver<Conveyor>>);
    bool execute() override;
};


#endif //FILTERS_CONNECTCONVEYORCOMMAND_H
