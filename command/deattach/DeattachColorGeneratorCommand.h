//
// Created by makst on 26.12.2020.
//

#ifndef FILTERS_DEATTACHCOLORGENERATORCOMMAND_H
#define FILTERS_DEATTACHCOLORGENERATORCOMMAND_H

#include "command/attachCommands/AAttachCommand.h"
#include "nodes/ANode.h"
#include "gui/cards/ColorGeneratorCard.h"
#include "nodes/ColorGeneratorNode.h"

class DeattachColorGeneratorCommand: public AAttachCommand<IObserver<ColorGeneratorNode>> {
public:
    explicit DeattachColorGeneratorCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<ColorGeneratorNode>>);
    bool execute() override;
};


#endif //FILTERS_DEATTACHCOLORGENERATORCOMMAND_H
