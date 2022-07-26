#include <metrics/psnr.hpp>
#include <iostream>
#include <math.h>

namespace zoio {

double psnr(Image image_a, Image image_b) {
    double _mse = mse(image_a, image_b);
    double ratio = (255*255) / _mse;
    return 10 * log10(ratio);
}

} // zoio