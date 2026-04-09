#include "./header/dynamic_array.h"
#include <iostream>
int main() {
    auto d_arr=dynamic_array<int>(4);
    d_arr.push_back(10);
    d_arr.push_back(12);
    d_arr.push_front(15);
    std::cout << d_arr;
    return 0;
}
