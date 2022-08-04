#include "generic_dwt.hpp"
#include <iostream>
#include <vector>

#include "acutest.h"

void test_haar_encode() {
    std::vector<float> original{10, 20, 30, 40, 50, 60, 70, 80};
    std::vector<float> expected{25, 65, 10, 10, 5, 5, 5, 5};

    std::vector<float> low_pass = {-1, 1};
    std::vector<float> high_pass = {1, 1};

    int levels = 2;
    zoio::dwt::foward(original, levels, high_pass, low_pass);

    // for (int i = 0; i < expected.size(); i++)
    //     std::cout << original[i] << " ";
    // std::cout << std::endl;

    for (int i = 0; i < expected.size(); i++)
        TEST_CHECK(expected[i] == original[i]);
}

void test_haar_decode() {
    std::vector<float> original{25, 65, 10, 10, 5, 5, 5, 5};
    std::vector<float> expected{10, 20, 30, 40, 50, 60, 70, 80};

    std::vector<float> low_pass = {-1, 1};
    std::vector<float> high_pass = {1, 1};

    int levels = 2;
    zoio::dwt::backward(original, levels, high_pass, low_pass);

    // for (int i = 0; i < expected.size(); i++)
    //     std::cout << original[i] << " ";
    // std::cout << std::endl;

    for (int i = 0; i < expected.size(); i++)
        TEST_CHECK(expected[i] == original[i]);
}

void test_haar_encode_decode() {
    std::vector<float> expected{10, 20, 30, 40, 50, 60, 70, 80};
    std::vector<float> data(expected.begin(), expected.end());

    int levels = 3;
    std::vector<float> low_pass = {-1, 1};
    std::vector<float> high_pass = {1, 1};

    zoio::dwt::foward(data, levels, high_pass, low_pass);

    // std::cout << std::endl;
    // for (int i = 0; i < expected.size(); i++)
    //     std::cout << data[i] << " ";
    // std::cout << std::endl;

    zoio::dwt::backward(data, levels, high_pass, low_pass);

    std::cout << std::endl;
    for (int i = 0; i < expected.size(); i++)
        TEST_CHECK(expected[i] == data[i]);
    // std::cout << data[i] << " == " << expected[i] << std::endl;
}

TEST_LIST = {{"Encode Haar Wavelet 1D", test_haar_encode},
             {"Decode Haar Wavelet 1D", test_haar_decode},
             {"Encode/Decode Haar Wavelet 1D", test_haar_encode_decode},
             {NULL, NULL}};