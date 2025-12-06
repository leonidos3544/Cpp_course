#ifndef QUEUE_H
#define QUEUE_H
#include "stack_.h"
#include <stdexcept>
#include <cstdint>

template<typename simv>
class Queue {
private:
    Stack<simv> stack_in;    
    Stack<simv> stack_out;
    std::int64_t count;
    std::int64_t capacity;

public:
    Queue(std::int64_t capacity) : stack_in(capacity), stack_out(capacity),count(0),capacity(capacity) {
    }

    void enqueue(simv value) {
        if (count >=capacity) {
            throw std::overflow_error("Queue overflow");
        }
        stack_in.push(value);
        ++count;
    }

    simv dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("queue is empty");
        }
        if (stack_out.isEmpty()) {
            while(!stack_in.isEmpty()){
                stack_out.push(stack_in.pop());
            }
        }
        simv value = stack_out.pop();
        --count;
        return value;
    }

    bool isEmpty() {
        return count == 0;
    }

    std::int64_t size() {
        return count;
    }
};
#endif
