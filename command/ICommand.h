//
// Created by noxin on 12/23/20.
//

#ifndef FILTERS_ICOMMAND_H
#define FILTERS_ICOMMAND_H

class ICommand{
    virtual void execute()=0;
    //virtual void undo()=0;
};

#endif //FILTERS_ICOMMAND_H
