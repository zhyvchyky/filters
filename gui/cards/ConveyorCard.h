//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_CONVEYORCARD_H
#define FILTERS_CONVEYORCARD_H

#include "Conveyor.h"
#include "IObserver.h"

class ConveyorCard: public IObserver<Conveyor> {
private:
    std::set<size_t> nodes;
    std::map<size_t, size_t> connections;
public:
    std::set<size_t> getNodes();
    void notify(std::shared_ptr<Conveyor>) override;
};


#endif //FILTERS_CONVEYORCARD_H
