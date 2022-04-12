#include <dwt.hpp>
#include <iostream>
#include <vector>

#include "acutest.h"


void test_dwt_1d() {
    std::vector<int> original{1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> expected{1, 4, 2, 2, 1, 1, 1, 1};
    std::vector<int> tmp(original.begin(), original.end());

    int levels = 3;

    for (int i = 0; i < original.size(); i++)
        TEST_CHECK(original[i] == tmp[i]);

    DWT::foward(tmp, levels);

    for (int i = 0; i < expected.size(); i++)
        TEST_CHECK(expected[i] == tmp[i]);

    DWT::backward(tmp, levels);
    
    for (int i = 0; i < original.size(); i++)
        TEST_CHECK(original[i] == tmp[i]);
}

TEST_LIST = {
    {"DWT 1D", test_dwt_1d},
    {NULL, NULL}
};