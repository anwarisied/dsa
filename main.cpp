#include "./header/dynamic_array.h"
#include <iostream>
int main() {
    auto d_arr=dynamic_array(4);
    d_arr.push_back(10);
    d_arr.push_back(12);
    d_arr.push_front(15);
    d_arr.pop_front();
    d_arr.pop_front();
    std::cout << d_arr;
    return 0;
}
