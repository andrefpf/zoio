#include "dwt2d.hpp"
#include "image/image.hpp"
#include "image/pgm.hpp"
#include "matrix.hpp"
#include "metrics/psnr.hpp"
#include "util.hpp"
#include <string>

#include "acutest.h"
#define CLOSE_ENOUGH(a, b) (TEST_CHECK((a - b) <= 1e-6))

void read_write_pgm() {
    zoio::Image image_a = zoio::read_pgm("data/shell.pgm");
    zoio::write_pgm(image_a, "/tmp/shell.pgm");
    zoio::Image image_b = zoio::read_pgm("/tmp/shell.pgm");

    double psnr = zoio::metrics::psnr(image_a, image_b);
    TEST_CHECK(psnr == inf);
}

TEST_LIST = {{"PGM", read_write_pgm}, {NULL, NULL}};