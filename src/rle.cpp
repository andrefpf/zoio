#include "rle.hpp"
#include <iostream>
#include <vector>

void RLE::foward(std::vector<int> &input) {
    std::vector<int> tmp{input.begin(), input.end()};
    int num_zeros = 0;

    input.clear();
    for (auto it : tmp) {
        if (it == 0) {
            num_zeros++;
        } else if (num_zeros >= 1) {
            input.push_back(0);
            input.push_back(num_zeros);
            input.push_back(it);
            num_zeros = 0;
        } else {
            input.push_back(it);
        }
    }

    if (num_zeros >= 1) {
        input.push_back(0);
        input.push_back(num_zeros);
    }
}

void RLE::backward(std::vector<int> &input) {
    std::vector<int> tmp{input.begin(), input.end()};
    bool last_was_zero = false;

    input.clear();
    for (auto it : tmp) {
        if (it == 0) {
            last_was_zero = true;
        } else if (last_was_zero) {
            for (int i = 0; i < it; i++)
                input.push_back(0);
            last_was_zero = false;
        } else {
            input.push_back(it);
        }
    }
}