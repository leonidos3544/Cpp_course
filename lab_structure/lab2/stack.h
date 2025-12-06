#ifndef STACK_H
#define STACK_H

#include "dyn__arr.h"
#include <stdexcept>
#include <cstdint>

template<typename simv>
class Stack {
private:
    DynamicArray<simv> data;
    std::int64_t capacity;
    std::int64_t count;
    
public:
    Stack(std::int64_t capacity):data(capacity),capacity(capacity), count(0) {
        if (capacity <=0) {
            throw std::invalid_argument("Capacity < 1");
        }
    }

    void push(simv value) {
        if (count >=capacity) {
            throw std::overflow_error("Stack overflow");
        }
        
        if (count ==0) {
            data.push_back(value);
        } else {
            data.push_front(value);
        }
        count++;
    }

    simv top() {
        if (isEmpty()) {
            throw std::underflow_error("stack is empty");
        }
        return data.front();
    }

    simv pop() {
        if (isEmpty()) {
            throw std::underflow_error("stack is empty");
        }
        simv value =data.front();
        data.dele_te(0);
        --count;
        return value;
    }

    bool isEmpty() {
        return count ==0;
    }
};
#endif
