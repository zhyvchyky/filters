//
// Created by noxin on 12/23/20.
//

#ifndef FILTERS_CUSTOMSTACK_H
#define FILTERS_CUSTOMSTACK_H

#include <list>

template<class T>

class CustomStack {
private:
    std::list<T> stack;
    size_t max_size{};
public:
    CustomStack(size_t max_size);
    void push(T element);
    void pop();
    T back();
};

#endif //FILTERS_CUSTOMSTACK_H
