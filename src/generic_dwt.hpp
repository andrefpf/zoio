#ifndef GENERIC_DWT_H_
#define GENERIC_DWT_H_

#include <vector>

namespace zoio {
namespace dwt {

void foward(std::vector<float> &input, int levels, std::vector<float> high_pass,
            std::vector<float> low_pass);

void backward(std::vector<float> &input, int levels,
              std::vector<float> high_pass, std::vector<float> low_pass);

} // namespace dwt
} // namespace zoio

#endif