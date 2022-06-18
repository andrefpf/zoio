#ifndef ZOIO_PSNR_H_
#define ZOIO_PSNR_H_

#include <image/image.hpp>

namespace zoio {

double mse(Image image_a, Image image_b); 
double psnr(Image image_a, Image image_b);

} // zoio

#endif 
