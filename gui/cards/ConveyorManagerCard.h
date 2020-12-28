//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_CONVEYORMANAGERCARD_H
#define FILTERS_CONVEYORMANAGERCARD_H

#include "ConveyorManager.h"
#include "IObserver.h"

class ConveyorManagerCard: public IObserver<ConveyorManager> {
private:
    std::vector<std::shared_ptr<Conveyor>> conveyors;
public:
    std::vector<std::shared_ptr<Conveyor>> getConveyors();
    void notify(std::shared_ptr<ConveyorManager>) override;
};


#endif //FILTERS_CONVEYORMANAGERCARD_H
