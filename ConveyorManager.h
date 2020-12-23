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
#include "command/CreateConveyorCommand.h"

class CreateConveyorCommand;

class ConveyorManager {
    friend class CreateConveyorCommand;
private:
    std::vector<std::shared_ptr<Conveyor>> conveyors;
    IdGenerator idGenerator;
    std::shared_ptr<Conveyor> createConveyor();


public:
    void loadConveyor(const std::string& filepath);
    void saveConveyor(int conveyorId, const std::string& filepath);
    void deleteConveyor(size_t id);
    std::shared_ptr<Conveyor> getConveyorByID(size_t);
};

#endif //FILTERS_CONVEYORMANAGER_H
