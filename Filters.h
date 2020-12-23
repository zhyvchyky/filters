//
// Created by linups on 10/27/20.
//

#ifndef FILTERS_FILTERS_H
#define FILTERS_FILTERS_H


#include "Conveyor.h"
#include "ConveyorManager.h"
#include "command/ICommand.h"
#include "utilities/CustomStack.h"

class Filters {
private:
    std::shared_ptr<ConveyorManager> conveyorManager;
    CustomStack<std::shared_ptr<ICommand>> commandHistory;

public:
    Filters();
    std::shared_ptr<ConveyorManager> getConveyorManager();
    void executeCommand(std::shared_ptr<ICommand> command);
};


#endif //FILTERS_FILTERS_H
