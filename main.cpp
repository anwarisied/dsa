#include "./header/search_algorithms.h"
#include <iostream>
int main() {
    const std::vector<int> list_of_numbers={3,4,5,6,7,8,10,23};
    std::cout<<search_algorithms::binary_search(list_of_numbers,4);
    return 0;
}
