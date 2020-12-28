//
// Created by makstsar on 26.12.2020.
//

#ifndef FILTERS_ATTACHCOLORGENERATORCOMMAND_H
#define FILTERS_ATTACHCOLORGENERATORCOMMAND_H

#include "command/attachCommands/AAttachCommand.h"
#include "nodes/ANode.h"
#include "nodes/ColorGeneratorNode.h"

class AttachColorGeneratorCommand: public AAttachCommand<IObserver<ColorGeneratorNode>> {
public:
    explicit AttachColorGeneratorCommand(std::shared_ptr<ConveyorManager>, size_t, size_t, std::shared_ptr<IObserver<ColorGeneratorNode>>);
    bool execute() override;
};



#endif //FILTERS_ATTACHCOLORGENERATORCOMMAND_H
