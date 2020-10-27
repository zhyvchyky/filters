//
// Created by makstar on 27.10.2020.
//

#ifndef FILTERS_CONVEYORMANAGER_H
#define FILTERS_CONVEYORMANAGER_H

#include <map>
#include <string>

#include "Conveyor.h"


class ConveyorManager {

private:
    std::map<int, Conveyor> conveyors;
    int getNewId();

public:
    ConveyorManager();
    ~ConveyorManager();

    void createConveyor();
    void loadConveyor(std::string filepath);
    void saveConveyor(int conveyorId, std::string filepath);
    void deleteConveyor(int id);
};

#endif //FILTERS_CONVEYORMANAGER_H
