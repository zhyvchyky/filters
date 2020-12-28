//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_CONNECTCONVEYORMANAGERCOMMAND_H
#define FILTERS_CONNECTCONVEYORMANAGERCOMMAND_H

#include "command/ICommand.h"
#include "Filters.h"

class ConnectConveyorManagerCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    std::shared_ptr<IObserver<ConveyorManager>> card;
public:
    explicit ConnectConveyorManagerCommand(std::shared_ptr<ConveyorManager>, std::shared_ptr<IObserver<ConveyorManager>>);
    bool execute() override;
};


#endif //FILTERS_CONNECTCONVEYORMANAGERCOMMAND_H
