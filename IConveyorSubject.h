//
// Created by noxin on 12/31/20.
//

#ifndef FILTERS_ICONVEYORSUBJECT_H
#define FILTERS_ICONVEYORSUBJECT_H

#include "ISubject.h"
#include "Conveyor.h"
#include "IConveyorObserver.h"

class IConveyorSubject : public ISubject<Conveyor> {
public:
    std::vector<std::weak_ptr<IConveyorObserver>> observers;
    inline void processNotify() {
        for (auto wptr : observers) {
            if (!wptr.expired()) {
                auto observer = wptr.lock();
                observer->processNotify(std::dynamic_pointer_cast<Conveyor>(this->shared_from_this()));
            }
        }
    }
    inline virtual ~IConveyorSubject() {
        observers.clear();
    };

    inline void subscribe(const std::shared_ptr<IConveyorObserver> &observer) {
        observers.push_back(observer);
    }

    inline void notify() {
        for (auto wptr : observers) {
            if (!wptr.expired()) {
                auto observer = wptr.lock();
                observer->notify(std::dynamic_pointer_cast<Conveyor>(this->shared_from_this()));
            }
        }
    }

    inline void unsubscribe(const std::shared_ptr<IObserver<Conveyor>> &observer) {
        auto it = std::find_if(observers.begin(), observers.end(), [observer](std::weak_ptr<IConveyorObserver> &p) {
            return p.expired() || p.lock() == observer;
        });

        if (it == observers.end()) {
            return;
        }
        observers.erase(it);
    }
};


#endif //FILTERS_ICONVEYORSUBJECT_H
