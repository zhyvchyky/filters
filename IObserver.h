//
// Created by noxin on 12/23/20.
//

#ifndef FILTERS_IOBSERVER_H
#define FILTERS_IOBSERVER_H

#include <memory>

template<class T>
class IObserver{
public:
    inline virtual ~IObserver() {};
    virtual void notify(std::shared_ptr<T>) = 0;
};

#endif //FILTERS_IOBSERVER_H

