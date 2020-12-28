//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_ATTACHCONVEYORMANAGERCOMMAND_H
#define FILTERS_ATTACHCONVEYORMANAGERCOMMAND_H

#include "command/ICommand.h"
#include "Filters.h"

class AttachConveyorManagerCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    std::shared_ptr<IObserver<ConveyorManager>> card;
public:
    explicit AttachConveyorManagerCommand(std::shared_ptr<ConveyorManager>, std::shared_ptr<IObserver<ConveyorManager>>);
    bool execute() override;
};


#endif //FILTERS_ATTACHCONVEYORMANAGERCOMMAND_H
