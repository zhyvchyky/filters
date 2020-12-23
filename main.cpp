// Created by noxin on 10/27/20.
//

#include <iostream>

#include "command/CreateConveyorCommand.h"
#include "Filters.h"



int main() {
    Filters filters;
    auto createConveyorCommand = std::make_shared<CreateConveyorCommand>(filters.getConveyorManager());
    //filters.getConveyorManager()->com = createConveyorCommand;
    filters.executeCommand(createConveyorCommand);

    return 0;
}
