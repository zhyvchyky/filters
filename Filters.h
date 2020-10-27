//
// Created by linups on 10/27/20.
//

#ifndef FILTERS_FILTERS_H
#define FILTERS_FILTERS_H


#include <vector>
#include <string>

#include "Conveyor.h"
#include "ConveyorManager.h"

class Filters {
private:
    ConveyorManager conveyorManager;
public:
    Filters();
    ~Filters();

    void createConveyor();
    void deleteConveyor(int id);
    void loadConveyor(std::string filePath);
    void saveConveyor(int id, std::string filePath);
    std::vector<int> getConveyorIds();
    Conveyor& getConveyor(int conveyorId);
};


#endif //FILTERS_FILTERS_H
