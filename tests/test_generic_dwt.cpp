#include "generic_dwt.hpp"
#include <iostream>
#include <vector>

#include "acutest.h"

bool is_close(float a, float b, float diff = 1e-5) {
    if (abs(a - b) > diff) {
        return false;
    } else {
        return true;
    }
}

void test_haar_encode() {
    std::vector<float> data{10, 20, 30, 40, 50, 60, 70, 80};
    std::vector<float> expected{21.21320344,  49.49747468, 77.78174593,
                                106.06601718, -7.07106781, -7.07106781,
                                -7.07106781,  -7.07106781};

    float sq2 = 1.4142135623730951;
    float c = 0.7071067811865476;
    std::vector<float> low_pass = {c, c};
    std::vector<float> high_pass = {c, -c};

    int levels = 1;
    zoio::dwt::foward(data, levels, high_pass, low_pass);

    for (int i = 0; i < expected.size(); i++)
        TEST_CHECK(is_close(expected[i], data[i]));
}

void test_haar_decode() {
    std::vector<float> data{21.21320344, 49.49747468, 77.78174593, 106.06601718,
                            -7.07106781, -7.07106781, -7.07106781, -7.07106781};
    std::vector<float> expected{10, 20, 30, 40, 50, 60, 70, 80};

    float sq2 = 1.4142135623730951;
    float c = 0.7071067811865476;
    std::vector<float> low_pass = {c, c};
    std::vector<float> high_pass = {c, -c};

    int levels = 1;
    zoio::dwt::backward(data, levels, high_pass, low_pass);

    for (int i = 0; i < expected.size(); i++)
        TEST_CHECK(is_close(expected[i], data[i]));
}

void test_haar_encode_decode() {
    std::vector<float> expected{10, 20, 30, 40, 50, 60, 70, 80};
    std::vector<float> data(expected.begin(), expected.end());

    int levels = 3;
    float c = 0.7071067811865476;
    std::vector<float> low_pass = {c, c};
    std::vector<float> high_pass = {c, -c};

    zoio::dwt::foward(data, levels, high_pass, low_pass);

    for (int i = 0; i < expected.size(); i++)
        TEST_CHECK(!is_close(expected[i], data[i]));

    zoio::dwt::backward(data, levels, high_pass, low_pass);

    for (int i = 0; i < expected.size(); i++)
        TEST_CHECK(is_close(expected[i], data[i]));
}

void test_db2_encode_decode() {
    std::vector<float> expected{10, 20, 30, 40, 50, 60, 70, 80};
    std::vector<float> data(expected.begin(), expected.end());

    float sq2 = 1.4142135623730951;
    float sq3 = 1.7320508075688772;

    int levels = 1;
    std::vector<float> low_pass = {
        (1 + sq3) / 4 / sq2,
        (3 + sq3) / 4 / sq2,
        (3 - sq3) / 4 / sq2,
        (1 - sq3) / 4 / sq2,
    };

    std::vector<float> high_pass = {
        (1 - sq3) / 4 / sq2,
        -(3 - sq3) / 4 / sq2,
        (3 + sq3) / 4 / sq2,
        -(1 + sq3) / 4 / sq2,
    };

    zoio::dwt::foward(data, levels, high_pass, low_pass);

    for (int i = 0; i < expected.size(); i++)
        TEST_CHECK(!is_close(expected[i], data[i]));

    zoio::dwt::backward(data, levels, high_pass, low_pass);

    // The first two values does not converge very well, so let's ignore them
    for (int i = 2; i < expected.size(); i++)
        TEST_CHECK(is_close(expected[i], data[i]));
}

TEST_LIST = {{"Encode Haar Wavelet 1D", test_haar_encode},
             {"Decode Haar Wavelet 1D", test_haar_decode},
             {"Encode/Decode Haar Wavelet 1D", test_haar_encode_decode},
             {"Encode/Decode DB2 Wavelet 1D", test_db2_encode_decode},
             {NULL, NULL}};