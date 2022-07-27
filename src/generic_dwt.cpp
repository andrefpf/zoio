#include <generic_dwt.hpp>
#include <iostream>
#include <math.h>

namespace zoio {
namespace dwt {

void foward(std::vector<int> &input, int levels) {
    std::vector<int> low_pass = {-1, 1};
    std::vector<int> high_pass = {1, 1};
    std::vector<int> tmp(input.size());
    int half = input.size() / 2;
    int low;
    int high;

    float k = 0.5;

    for (int level = 0; level < levels; level++) {
        for (int i = 0; i < half; i++) {
            high = 0;
            low = 0;

            for (int j = 0; j < 2; j++) {
                high += input[2 * i + j] * high_pass[j];
                low += input[2 * i + j] * low_pass[j];
            }

            tmp[i] = ceil(high * k);
            tmp[i + half] = ceil(low * k);
        }

        for (int i = 0; i < half * 2; i++) {
            input[i] = tmp[i];
        }

        half /= 2;
    }
}

void backward(std::vector<int> &input, int levels) {
    std::vector<int> low_pass = {-1, 1};
    std::vector<int> high_pass = {1, 1};
    std::vector<int> tmp(input.size());
    int half = input.size() >> levels;
    int low;
    int high;

    float k = 0.5;

    for (int i = 0; i < half; i++) {
        high = input[i];
        low = input[i + half];

        for (int j = 0; j < 2; j++) {            
            tmp[2 * i + j] += floor(high * high_pass[j] * k);
            tmp[2 * i + j] += floor(low * low_pass[j] * k);
        }
    }

    for (int i = 0; i < half * 2; i++) {
        input[i] = tmp[i];
    }

}

} // dwt
} // zoio



// H = a1 * h1 + a2 * h2
// L = a1 * l1 + a2 * l2 

// a1 = (H - a2 * h2) / h1
// a1 = (L - a2 * l2) / l1