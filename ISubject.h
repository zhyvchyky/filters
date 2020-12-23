//
// Created by noxin on 12/23/20.
//

#ifndef FILTERS_ISUBJECT_H
#define FILTERS_ISUBJECT_H

#include <vector>
#include "IObserver.h"
#include <memory>
#include <iterator>

template<class T>
class ISubject {
private:
    std::vector<std::weak_ptr<IObserver<T>>> observers;

public:
    virtual ~ISubject() {}

    inline void subscribe(const std::shared_ptr<IObserver<T>> &observer) {
        observers.push_back(observer);
    }
    inline void notify() {
        for (auto wptr : observers) {
            if (!wptr.expired()) {
                auto observer = wptr.lock();
                observer->notify(std::make_shared<T>(this));
            }
        }
    }
    inline void unsubscribe(const std::shared_ptr<IObserver<T>> &observer){
        std::erase(
                std::remove_if(
                        this->observers.begin(),
                        this->observers.end(),
                        [&](const std::weak_ptr<IObserver<T>>& wptr)
                        {
                            return wptr.expired() || wptr.lock() == observer;
                        }
                ),
                this->observers.end()
        );
    }
};


#endif //FILTERS_ISUBJECT_H
