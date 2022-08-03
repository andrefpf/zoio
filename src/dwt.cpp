#include "dwt.hpp"
#include <iostream>

void DWT::foward(std::vector<int> &input, int levels) {
    int even, odd;
    int half = input.size() / 2;
    std::vector<int> tmp(input.size());

    for (int level = 0; level < levels; level++) {
        for (int i = 0; i < half; i++) {
            even = input[i * 2];
            odd = input[i * 2 + 1];

            tmp[i] = even;
            tmp[i + half] = odd - even;
        }

        for (int i = 0; i < half * 2; i++) {
            input[i] = tmp[i];
        }

        half /= 2;
    }
}

void DWT::backward(std::vector<int> &input, int levels) {
    int even, odd;
    int half = input.size() >> levels;
    std::vector<int> tmp(input.size());

    for (int level = levels; level > 0; level--) {
        for (int i = 0; i < half; i++) {
            even = input[i];
            odd = input[i + half] + even;

            tmp[i * 2] = even;
            tmp[i * 2 + 1] = odd;
        }

        for (int i = 0; i < half * 2; i++) {
            input[i] = tmp[i];
        }

        half *= 2;
    }
}