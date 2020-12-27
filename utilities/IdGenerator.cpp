//
// Created by noxin on 12/22/20.
//

#include "IdGenerator.h"

size_t IdGenerator::getNewId() {
    if(this->freedIds.size() == 0){
        return currentId++;
    } else {
        size_t retValue = this->freedIds.front();
        freedIds.pop();
        return retValue;
    }
}

void IdGenerator::freeId(size_t id) {
    this->freedIds.push(id);
}
