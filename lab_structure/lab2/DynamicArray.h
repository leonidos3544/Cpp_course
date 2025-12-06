#ifndef DYN_ARR_H
#define DYN_ARR_H
//предотвращает повторное подкл. файла
#include <cstdint>
#include <stdexcept>

template<typename simv>
class DynamicArray {
private:
    simv* data;
    std::int64_t size;
    std::int64_t capacity;

    bool isEmpty() {
        return size ==-1;
    }

public:
    DynamicArray(std::int64_t initial_capacity) {
        if (initial_capacity<1) {
            throw std::invalid_argument("Capacity < 1");
        }
        this->capacity =initial_capacity;
        this->data =new simv[this->capacity];
        this->size =-1;
    }

  

    ~DynamicArray() {
        if (this->data) {
            delete[] this->data;
        }
    }

    void push_back(simv value) {
        if (size+1>=capacity) {
            std::int64_t new_capacity = capacity*2;
            simv* new_data = new simv[new_capacity];
            
            for (std::int64_t i=0;i<=size;++i) {
                new_data[i] = data[i];
            }
            
            delete[] data;
            data=new_data;
            capacity =new_capacity;
        }
        data[++size]=value;
    }

    void push_front(simv value) {
        if (size+1>=capacity) {
            std::int64_t new_capacity=capacity*2;
            simv* new_data=new simv[new_capacity];
            
            for (std::int64_t i=0;i<=size;++i) {
                new_data[i]=data[i];
            }
            
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
        
        for (std::int64_t i=size;i>=0;--i) {
            data[i +1]=data[i];
        }
        data[0]=value;
        size++;
    }

    simv front() {
        if (isEmpty()) {
            throw std::invalid_argument("Empty array");
        }
        return data[0];
    }
    simv  back(){
         if (isEmpty()) {
            throw std::invalid_argument("Empty array");
    
        }
        return data[size];

    }

    void insert(std::int64_t idx, simv val){
        if (idx<0 || idx > size + 1){  //size=len(data)-1(индексы)
            throw std::invalid_argument("index out of range");
        }
        if (size + 1 >= capacity) {
            std::int64_t newCapacity = capacity * 2;
            simv* tempArray = new simv[newCapacity];
            for (int i = 0; i < capacity; ++i) {
                tempArray[i] = data[i];
            }
            delete[] data;
            data = tempArray;
            capacity = newCapacity;
        }
        for (int i=size;i>idx-1;--i){
             data[i+1]=data[i];
        }
        data[idx]=val;
        size++;
    }


    void dele_te(std::int64_t idx) {
        if (idx<0||idx>size) {
            throw std::invalid_argument("ind out of range");
        }
        for (std::int64_t i=idx;i<size;++i) {
            data[i]=data[i+1];
        }
        size--;
    }
    void erase_after(std::int64_t idx){
        if (idx<0 || idx>size){
            throw std::invalid_argument("idx out of range");
        }
        size=idx;
    } 

    void  increase_capacity(std::int64_t newCapacity){
        if (newCapacity<=capacity){
            throw std::invalid_argument("newCapasity <= old capacity");
        }
        simv* tempArray = new simv[newCapacity];
        for (int i = 0; i < capacity; ++i) {
            tempArray[i] = data[i];
        }
        delete[] data;
        data = tempArray;
        capacity = newCapacity;
    }

    void decrease_capacity(std::int64_t newCapacity){
        if (newCapacity>=capacity){
            throw std::invalid_argument("newCapasity >= old capacity");
        }
        
        simv* tempArray = new simv[newCapacity];
        if (newCapacity<=size){
            for (int i=0;i<=size;++i) {
                tempArray[i] = data[i];
            }
        }
         
        else{
            
            for (int i=0;i<newCapacity; ++i) {
                tempArray[i]=data[i];
            }

        }
        delete[] data;
        data=tempArray;
        capacity=newCapacity;
}
    
};

#endif
