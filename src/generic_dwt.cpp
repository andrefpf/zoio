#include "generic_dwt.hpp"
#include <iostream>
#include <math.h>

namespace zoio {
namespace dwt {

/*
Essa implementação com certeza está errada. Preciso entender a forma como os
filtros devem ser utilizados. Provávelmente não deveria estar dividindo pelo
filter_size.
*/

void foward(std::vector<float> &input, int levels, std::vector<float> high_pass,
            std::vector<float> low_pass) {

    std::vector<float> tmp(input.size());
    int half = input.size() / 2;
    int filter_size = high_pass.size();

    float low;
    float high;

    for (int level = 0; level < levels; level++) {
        for (int i = 0; i < half; i++) {
            high = 0;
            low = 0;

            for (int j = 0; j < filter_size; j++) {
                high += input[2 * i + j] * high_pass[j];
                low += input[2 * i + j] * low_pass[j];
            }

            tmp[i] = low;
            tmp[i + half] = high;
        }

        for (int i = 0; i < half * 2; i++) {
            input[i] = tmp[i];
        }

        half /= 2;
    }
}

void backward(std::vector<float> &input, int levels,
              std::vector<float> high_pass, std::vector<float> low_pass) {

    std::vector<float> tmp(input.size());
    int half = input.size() >> levels;
    int filter_size = high_pass.size();

    float low;
    float high;

    for (int level = 0; level < levels; level++) {
        for (int i = 0; i < half; i++) {
            low = input[i];
            high = input[i + half];

            for (int j = 0; j < filter_size; j++) {
                tmp[2 * i + j] += high * high_pass[j];
                tmp[2 * i + j] += low * low_pass[j];
            }
        }

        for (int i = 0; i < half * 2; i++) {
            input[i] = tmp[i];
            tmp[i] = 0;
        }

        half *= 2;
    }
}

} // namespace dwt
} // namespace zoio