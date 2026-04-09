//
// Created by anwar on 08/04/2026.
//
#include "../header/dynamic_array.h"

#include <cstddef>

dynamic_array::dynamic_array(int capacity) {
    capacity=capacity==0?1:capacity;
    this->capacity=capacity;
    this->last_index=-1;
    this->arr=new int[capacity];
}

int* dynamic_array::copy(const dynamic_array &other) const {
    const auto new_arr = new int[capacity];
    if (other.arr!=nullptr) {
        for (int i = 0; i <= last_index; i++) {
            new_arr[i] = other.arr[i];
            std::cout<<new_arr[i];
        }
    }
    return new_arr;
}

dynamic_array::dynamic_array(const dynamic_array &other) : last_index(other.last_index), capacity(other.capacity) {
    this->arr = copy(other);
}

dynamic_array &dynamic_array::operator=(const dynamic_array &other) {
    if (this==&other) {
        return *this;
    }
    delete[] arr;
    this->capacity = other.capacity;
    this->last_index = other.last_index;

    this->arr = copy(other);
    return *this;
}


dynamic_array::~dynamic_array() {
    delete[] this->arr;
}

bool dynamic_array::is_full() const {
    return this->capacity==this->last_index+1;
}

bool dynamic_array::is_empty() const {
    return this->last_index==-1;
}

void dynamic_array::resize() {
    if (is_full()) {
        const int new_capacity=this->capacity*2;
        const auto new_arr=new int[new_capacity];
        for (int i=0;i<=this->last_index;i++) {
            new_arr[i]=this->arr[i];
        }
        delete[] this->arr;
        this->arr=new_arr;
        this->capacity=new_capacity;
    }
}

void dynamic_array::push_back(const int value) {
    resize();
    this->arr[++last_index]=value;
}

void dynamic_array::push_front(const int value) {
    resize();
    //Shift the elements
    for (int i=last_index;i>=0;i--) {
        this->arr[i+1]=this->arr[i];
    }
    this->arr[0]=value;
    this->last_index=this->last_index+1;
}

int dynamic_array::pop_back() {
    if (is_empty()) {
        throw std::runtime_error("Array is empty");
    }
    const int value=this->arr[this->last_index];
    this->arr[this->last_index]=0;
    this->last_index=this->last_index-1;
    return value;
}

int dynamic_array::pop_front() {
    if (is_empty()) {
        throw std::runtime_error("Array is empty");
    }
    const int value=this->arr[0];
    for (int i=0;i<this->last_index;i++) {
        this->arr[i]=this->arr[i+1];
    }
    this->last_index=this->last_index-1;
    return value;
}
