//
// Created by anwar on 08/04/2026.
//

#include "../header/search_algorithms.h"

int search_algorithms::binary_search(const std::vector<int> &list_of_numbers, const int guess) {
    int low=0;
    int high=static_cast<int>(list_of_numbers.size()-1);
    while (low<=high) {
        const int mid=low + (high-low)/2;
        if (guess==list_of_numbers[mid]) {
            return mid;
        }
        if (guess>list_of_numbers[mid]) {
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    return -1;
}
