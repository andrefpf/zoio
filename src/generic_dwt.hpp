#ifndef GENERIC_DWT_H_
#define GENERIC_DWT_H_

#include <vector>

namespace zoio {
namespace dwt {

void foward(std::vector<int> &input, int levels);
void backward(std::vector<int> &input, int levels);

} // namespace dwt
} // namespace zoio

#endif