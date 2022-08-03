#include "image/image.hpp"
#include "image/pgm.hpp"
#include "metrics/psnr.hpp"
#include "util.hpp"
#include <iomanip>
#include <iostream>

#include "acutest.h"
#define CLOSE_ENOUGH(a, b) (TEST_CHECK((a - b) <= 1e-6))

void deform_image(zoio::Image &image) {
    for (int i = 0; i < image.width(); i++) {
        for (int j = 0; j < image.height(); j++) {
            // Checkered image
            if ((i / 16 + j / 16) % 2 == 0)
                image.at(i, j) /= 2;
        }
    }
}

void test_mse() {
    double mse;
    zoio::Image image_a = zoio::read_pgm("data/lena.pgm");
    zoio::Image image_b = zoio::read_pgm("data/lena.pgm");

    mse = zoio::mse(image_a, image_b);
    CLOSE_ENOUGH(mse, 0);

    deform_image(image_b);
    mse = zoio::mse(image_a, image_b);
    CLOSE_ENOUGH(mse, 1052.953281);
}

void test_psnr() {
    double psnr;

    zoio::Image image_a = zoio::read_pgm("data/lena.pgm");
    zoio::Image image_b = zoio::read_pgm("data/lena.pgm");

    psnr = zoio::psnr(image_a, image_b);
    TEST_CHECK(psnr == inf);

    deform_image(image_b);
    psnr = zoio::psnr(image_a, image_b);
    CLOSE_ENOUGH(psnr, 17.906713);
}

TEST_LIST = {{"MSE", test_mse}, {"PSNR", test_psnr}, {NULL, NULL}};