#include <dwt2d.hpp>
#include <iostream>

#include "acutest.h"


void test_encode_dwt_2d() {
    Matrix original = {
        {1, 2, 3, 4},
        {2, 3, 4, 5},
        {3, 4, 5, 6},
        {4, 5, 6, 7},
    };

    Matrix expected = {
        {1, 2, 1, 1},
        {2, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
    };

    DWT2D::foward(original, 2);

    for (int i = 0; i < expected.height(); i++) {
        for (int j = 0; j < expected.width(); j++) {
            TEST_CHECK(expected.at(i,j) == original.at(i,j));
        }
    }

}

void test_decode_dwt_2d() {

}

void test_long_dwt_2d() {

}

TEST_LIST = {
    { "Encode DWT 2D",         test_encode_dwt_2d },
    { "Dencode DWT 2D",        test_decode_dwt_2d },
    { "Encode/Decode DWT 2D",    test_long_dwt_2d},
    { NULL, NULL }
};

// {
//     {1, 2, 3, 4},
//     {2, 3, 4, 5},
//     {3, 4, 5, 6},
//     {4, 5, 6, 7},
// }

// {
//     {1, 2, 1, 1},
//     {2, 2, 1, 1},
//     {1, 1, 1, 1},
//     {1, 1, 1, 1},
// }