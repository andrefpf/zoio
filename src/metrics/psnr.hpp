#ifndef ZOIO_PSNR_
#define ZOIO_PSNR_

#include <image/image.hpp>

namespace zoio {

double mse(Image image_a, Image image_b); 
double psnr(Image image_a, Image image_b);

} // zoio

#endif 
