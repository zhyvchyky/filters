//
// Created by noxin on 12/23/20.
//

#include "CustomStack.h"

template<class T>
void CustomStack<T>::push(T element) {
    if (this->stack.size() >= max_size){
        stack.pop_front();
    }
    stack.push_back(element);
}

template<class T>
void CustomStack<T>::pop() {
    stack.pop_back();
}

template<class T>
CustomStack<T>::CustomStack(size_t max_size) {
    this->max_size = max_size;
}

template<class T>
T CustomStack<T>::back() {
    return stack.back();
}
