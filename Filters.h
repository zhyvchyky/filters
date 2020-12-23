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
    ConveyorManager conveyorManager;
    CustomStack<ICommand> commandHistory;

public:
    Filters();
    ~Filters();

};


#endif //FILTERS_FILTERS_H
