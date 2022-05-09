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
        {1, 3, 1, 1},
        {3, 5, 1, 1},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
    };

    DWT2D::foward(original, 1);

    for (int i = 0; i < original.height(); i++) {
        for (int j = 0; j < original.width(); j++) {
            TEST_CHECK(original.at(i,j) == expected.at(i,j));
        }
    }
}

void test_decode_dwt_2d() {
    Matrix original = {
        {1, 3, 1, 1},
        {3, 5, 1, 1},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
    };

    Matrix expected = {
        {1, 2, 3, 4},
        {2, 3, 4, 5},
        {3, 4, 5, 6},
        {4, 5, 6, 7},
    };

    DWT2D::backward(original, 1);

    for (int i = 0; i < expected.height(); i++) {
        for (int j = 0; j < expected.width(); j++) {
            TEST_CHECK(expected.at(i,j) == original.at(i,j));
        }
    }
}

void test_long_dwt_2d() {
    int r;
    int w = 1 << 12;
    int h = 1 << 11;

    srand(time(NULL));

    Matrix original(w, h);
    Matrix tmp(w, h);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            r = rand() % 255;
            original.at(i,j) = r;
            tmp.at(i,j) = r;
        }
    }

    DWT2D::foward(tmp, 5);
    DWT2D::backward(tmp, 5);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            TEST_CHECK(original.at(i,j) == tmp.at(i,j));
        }
    }
}

TEST_LIST = {
    { "Encode DWT 2D",          test_encode_dwt_2d },
    { "Decode DWT 2D",          test_decode_dwt_2d },
    { "Encode/Decode DWT 2D",   test_long_dwt_2d},
    { NULL, NULL }
};
