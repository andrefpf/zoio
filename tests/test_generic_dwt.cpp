#include <generic_dwt.hpp>
#include <iostream>
#include <vector>

#include "acutest.h"


void test_encode_dwt() {
    std::vector<int> original{1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> expected{1, 4, 2, 2, 1, 1, 1, 1};

    int levels = 1;
    zoio::dwt::foward(original, levels);

    for (int i = 0; i < expected.size(); i++)
        std::cout << original[i] << " ";
    std::cout << std::endl;

    // for (int i = 0; i < expected.size(); i++)
    //     TEST_CHECK(expected[i] == original[i]);
}

void test_decode_dwt() {
    // std::vector<int> original{1, 5, 2, 2, 1, 1, 1, 1};
    std::vector<int> original{3, 7, 11, 15, 1, 1, 1, 1};
    std::vector<int> expected{1, 2, 3, 4, 5, 6, 7, 8};
    
    int levels = 1;
    zoio::dwt::backward(original, levels);

    for (int i = 0; i < expected.size(); i++)
        std::cout << original[i] << " ";
    std::cout << std::endl;

    // for (int i = 0; i < expected.size(); i++)
    //     TEST_CHECK(expected[i] == original[i]);
}

// void test_long_dwt() {
//     int levels = 23;

//     std::vector<int> original;
    
//     for (int i = 0; i < (1 << levels); i++) {
//         original.push_back(i);
//     }

//     std::vector<int> tmp(original.begin(), original.end());

//     for (int i = 0; i < original.size(); i++)
//         TEST_CHECK(original[i] == tmp[i]);

//     dwt::foward(tmp, levels);
//     dwt::backward(tmp, levels);
    
//     for (int i = 0; i < original.size(); i++)
//         TEST_CHECK(original[i] == tmp[i]);

// }

TEST_LIST = {
    { "Encode DWT 1D",         test_encode_dwt },
    { "Decode DWT 1D",         test_decode_dwt },
    // { "Encode/Decode DWT 1D",  test_long_dwt_1d},
    { NULL, NULL }
};