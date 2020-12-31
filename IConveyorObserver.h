//
// Created by noxin on 12/31/20.
//

#ifndef FILTERS_ICONVEYOROBSERVER_H
#define FILTERS_ICONVEYOROBSERVER_H

#include "IObserver.h"
#include "Conveyor.h"

class Conveyor;
class IConveyorObserver: public IObserver<Conveyor> {

public:
    virtual void processNotify(std::shared_ptr<Conveyor>) = 0;

    void notify(std::shared_ptr<Conveyor>) override = 0;
};


#endif //FILTERS_ICONVEYOROBSERVER_H
