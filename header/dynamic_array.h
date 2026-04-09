//
// Created by anwar on 08/04/2026.
//

#ifndef ALGORITHMS_DYNAMICARRAY_H
#define ALGORITHMS_DYNAMICARRAY_H
#include <iosfwd>
#include <iostream>

template<typename T>
class dynamic_array {
private:
    T *arr=nullptr;
    int last_index;  // index of last element (-1 means empty)
    int capacity;  // number of elements
    [[nodiscard]] bool is_full() const {
        return this->capacity==this->last_index+1;
    }
    [[nodiscard]] bool is_empty() const {
        return this->last_index==-1;
    }

    void resize() {
        if (is_full()) {
            const int new_capacity=this->capacity*2;
            const auto new_arr=new T[new_capacity];
            for (int i=0;i<=this->last_index;i++) {
                new_arr[i]=this->arr[i];
            }
            delete[] this->arr;
            this->arr=new_arr;
            this->capacity=new_capacity;
        }
    }
    [[nodiscard]] T* copy(const dynamic_array &other) const {
        const auto new_arr = new T[other.capacity];
        if (other.arr!=nullptr) {
            for (int i = 0; i <= other.last_index; i++) {
                new_arr[i] = other.arr[i];
                std::cout<<new_arr[i];
            }
        }
        return new_arr;
    }
public:
    explicit dynamic_array(int capacity=4) {
        capacity=capacity==0?1:capacity;
        this->capacity=capacity;
        this->last_index=-1;
        this->arr=new T[capacity];
    }

    explicit dynamic_array(const dynamic_array &other) : last_index(other.last_index), capacity(other.capacity) {
        this->arr = copy(other);
    }
    dynamic_array& operator=(const dynamic_array &other) {
        if (this==&other) {
            return *this;
        }
        delete[] arr;
        this->capacity = other.capacity;
        this->last_index = other.last_index;

        this->arr = copy(other);
        return *this;
    }
    void push_front(const T value) {
        resize();
        //Shift the elements
        for (int i=last_index;i>=0;i--) {
            this->arr[i+1]=this->arr[i];
        }
        this->arr[0]=value;
        this->last_index=this->last_index+1;
    }

    void push_back(const T value) {
        resize();
        arr[++last_index] = value;
    }

    T pop_back() {
        if (is_empty()) {
            throw std::runtime_error("Array is empty");
        }
        const T value=this->arr[this->last_index];
        this->last_index=this->last_index-1;
        return value;
    }
    T pop_front() {
        if (is_empty()) {
            throw std::runtime_error("Array is empty");
        }
        const T value=this->arr[0];
        for (int i=0;i<this->last_index;i++) {
            this->arr[i]=this->arr[i+1];
        }
        this->last_index=this->last_index-1;
        return value;
    }
    ~dynamic_array() {
        delete[] this->arr;
    }
    friend std::ostream& operator<<(std::ostream& os, const dynamic_array& obj) {
        os << "Last index: " << obj.last_index<<std::endl;
        os << "Capacity:" <<obj.capacity<<std::endl;
        os << "Values: ";
        for (int i=0;i<=obj.last_index;i++) {
            os<<obj.arr[i]<< " ";
        }
        return os;
    }
};

#endif //ALGORITHMS_DYNAMICARRAY_H
