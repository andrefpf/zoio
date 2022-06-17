#include <dwt2d.hpp>
#include <matrix.hpp>
#include <util.hpp>
#include <image/image.hpp>
#include <image/pgm.hpp>
#include <string>

using namespace zoio;

int main() {
    Image img = read_pgm("data/lena.pgm");
    write_pgm(img, "data/new_lena.pgm");
    return 0;
}