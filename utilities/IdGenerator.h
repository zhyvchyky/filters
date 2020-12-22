//
// Created by noxin on 12/22/20.
//

#ifndef FILTERS_IDGENERATOR_H
#define FILTERS_IDGENERATOR_H

#include <queue>

class IdGenerator {
    std::queue<size_t> freedIds;
    size_t currentId = 1;
public:
    size_t getNewId();
    void freeId(size_t id);

};


#endif //FILTERS_IDGENERATOR_H
