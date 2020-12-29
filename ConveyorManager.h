//
// Created by makstar on 27.10.2020.
//

#ifndef FILTERS_CONVEYORMANAGER_H
#define FILTERS_CONVEYORMANAGER_H

#include <vector>
#include <string>
#include <fstream>
#include <map>

#include "Conveyor.h"
#include "utilities/IdGenerator.h"


class ConveyorManager: public ISubject<ConveyorManager> {
private:
    size_t curId = 0;
    std::vector<std::shared_ptr<Conveyor>> conveyors;
    size_t createConveyor();
    void deleteConveyor(size_t id);
public:
    std::shared_ptr<Conveyor> getConveyorByID(size_t);
    std::vector<std::shared_ptr<Conveyor>> getConveyors();
    friend class CreateConveyorCommand;
    friend class DeleteConveyorCommand;
};

#endif //FILTERS_CONVEYORMANAGER_H
