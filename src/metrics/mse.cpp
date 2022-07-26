#include <metrics/mse.hpp>
#include <iostream>
#include <math.h>

namespace zoio {

double mse(Image image_a, Image image_b) {
    double tmp = 0;
    double sum = 0;

    if (image_a.height() != image_b.height())
        std::cerr << "MSE expects images of the same size" << std::endl;

    if (image_a.width() != image_b.width())
        std::cerr << "MSE expects images of the same size" << std::endl;

    for (int i = 0; i < image_a.width(); i++) {
        for (int j = 0; j < image_a.height(); j++) {
            tmp = image_a.at(i,j) - image_b.at(i,j);
            sum += tmp * tmp;
        }
    }

    return sum / (image_a.width() * image_a.height());
}

} // zoio
