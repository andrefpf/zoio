#include <rle.hpp>
#include <iostream>
#include <vector>

#include "acutest.h"


void test_foward_rle() {
    std::vector<int> original = {0,0,0,0,0,2,0,0,0,4,0,0,0,0,0,0,6,0,0,2,0,1,0,0,0,0,0,0,0,6,0,0,0};
    std::vector<int> expected = {0,5,2,0,3,4,0,6,6,0,2,2,0,1,1,0,7,6,0,3};

    RLE::foward(original);

    for (int i = 0; i < expected.size(); i++)
        TEST_CHECK(original[i] == expected[i]);

}

void test_backward_rle() {
    std::vector<int> original = {0,5,2,0,3,4,0,6,6,0,2,2,0,1,1,0,7,6,0,3};
    std::vector<int> expected = {0,0,0,0,0,2,0,0,0,4,0,0,0,0,0,0,6,0,0,2,0,1,0,0,0,0,0,0,0,6,0,0,0};

    RLE::backward(original);

    for (int i = 0; i < expected.size(); i++)
        TEST_CHECK(original[i] == expected[i]);

}

void test_long_rle() {
    std::vector<int> original;

    srand(time(NULL));

    for (int i = 0; i < (1 << 23); i++) {
        if (rand() % 100 < 70) {
            original.push_back(0);
        }
        else {
            original.push_back(rand());
        }
    }

    std::vector<int> tmp(original.begin(), original.end());

    RLE::foward(tmp);
    RLE::backward(tmp);

    for (int i = 0; i < original.size(); i++)
        TEST_CHECK(original[i] == tmp[i]);
}

TEST_LIST = {
    { "Foward RLE", test_foward_rle },
    { "Backward RLE", test_backward_rle },
    { "Long RLE", test_long_rle },
    { NULL, NULL }
};