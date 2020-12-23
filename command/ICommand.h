//
// Created by noxin on 12/23/20.
//

#ifndef FILTERS_ICOMMAND_H
#define FILTERS_ICOMMAND_H

class ICommand{
    //virtual void undo()=0;

public:
    virtual bool execute()=0;
};

#endif //FILTERS_ICOMMAND_H
