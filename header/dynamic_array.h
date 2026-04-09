//
// Created by anwar on 08/04/2026.
//

#ifndef ALGORITHMS_DYNAMICARRAY_H
#define ALGORITHMS_DYNAMICARRAY_H
#include <iosfwd>
#include <iostream>

class dynamic_array {
private:
    int *arr=nullptr;
    int last_index;  // index of last element (-1 means empty)
    int capacity;  // number of elements
    [[nodiscard]] bool is_full() const;
    [[nodiscard]] bool is_empty() const;
    void resize();
    [[nodiscard]] int* copy(const dynamic_array &other) const;
public:
    explicit dynamic_array(int capacity=4);
    dynamic_array(const dynamic_array& other);
    dynamic_array& operator=(const dynamic_array& other);
    void push_back(int value);
    void push_front(int value);
    int pop_back();
    int pop_front();
    ~dynamic_array();
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
