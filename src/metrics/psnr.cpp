#include "psnr.hpp"
#include <iostream>
#include <math.h>

namespace zoio {
namespace metrics {

double psnr(Image image_a, Image image_b) {
    double _mse = mse(image_a, image_b);
    double ratio = (255 * 255) / _mse;
    return 10 * log10(ratio);
}

} // namespace metrics
} // namespace zoio