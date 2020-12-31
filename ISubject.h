//
// Created by noxin on 12/23/20.
//

#ifndef FILTERS_ISUBJECT_H
#define FILTERS_ISUBJECT_H

#include <vector>
#include "IObserver.h"
#include <memory>
#include <iterator>
#include <algorithm>

template<class T>
class ISubject : public std::enable_shared_from_this<T> {
public:
    std::vector<std::weak_ptr<IObserver<T>>> observers;

public:
    inline virtual ~ISubject() {
        observers.clear();
    };

    virtual inline void subscribe(const std::shared_ptr<IObserver<T>> &observer) {
        observers.push_back(observer);
    }

    virtual inline void notify() {
        for (auto wptr : observers) {
            if (!wptr.expired()) {
                auto observer = wptr.lock();
                observer->notify(std::dynamic_pointer_cast<T>(this->shared_from_this()));
            }
        }
    }

    virtual inline void unsubscribe(const std::shared_ptr<IObserver<T>> &observer) {
        auto it = std::find_if(observers.begin(), observers.end(), [observer](std::weak_ptr<IObserver<T>> &p) {
            return p.expired() || p.lock() == observer;
        });

        if (it == observers.end()) {
            return;
        }
        observers.erase(it);
    }
};


#endif //FILTERS_ISUBJECT_H
