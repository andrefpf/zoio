#include <dwt.hpp>
#include <iostream>
#include <vector>

#include "acutest.h"


void test_encode_dwt_1d() {
    std::vector<int> original{1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> expected{1, 4, 2, 2, 1, 1, 1, 1};

    int levels = 3;
    DWT::foward(original, levels);

    for (int i = 0; i < expected.size(); i++)
        TEST_CHECK(expected[i] == original[i]);
}

void test_decode_dwt_1d() {
    std::vector<int> original{1, 5, 2, 2, 1, 1, 1, 1};
    std::vector<int> expected{1, 2, 3, 4, 5, 6, 7, 8};
    
    int levels = 2;
    DWT::backward(original, levels);

    for (int i = 0; i < expected.size(); i++)
        TEST_CHECK(expected[i] == original[i]);
}

void test_long_dwt_1d() {
    int levels = 23;

    std::vector<int> original;
    
    for (int i = 0; i < (1 << levels); i++) {
        original.push_back(i);
    }

    std::vector<int> tmp(original.begin(), original.end());

    for (int i = 0; i < original.size(); i++)
        TEST_CHECK(original[i] == tmp[i]);

    DWT::foward(tmp, levels);
    DWT::backward(tmp, levels);
    
    for (int i = 0; i < original.size(); i++)
        TEST_CHECK(original[i] == tmp[i]);

}

TEST_LIST = {
    { "Encode DWT 1D",         test_encode_dwt_1d },
    { "Decode DWT 1D",        test_decode_dwt_1d },
    { "Encode/Decode DWT 1D",    test_long_dwt_1d},
    { NULL, NULL }
};