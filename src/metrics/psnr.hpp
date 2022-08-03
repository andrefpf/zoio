#ifndef ZOIO_PSNR_H_
#define ZOIO_PSNR_H_

#include "../image/image.hpp"
#include "mse.hpp"

namespace zoio {
namespace metrics {

double psnr(Image image_a, Image image_b);

}
} // zoio

#endif 
