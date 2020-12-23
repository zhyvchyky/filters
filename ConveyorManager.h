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


class ConveyorManager {
private:
    std::vector<std::shared_ptr<Conveyor>> conveyors;
    IdGenerator idGenerator;

public:
    std::shared_ptr<Conveyor> createConveyor();
    void loadConveyor(const std::string& filepath);
    void saveConveyor(int conveyorId, const std::string& filepath);
    void deleteConveyor(size_t id);
};

#endif //FILTERS_CONVEYORMANAGER_H
