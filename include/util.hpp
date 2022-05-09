#ifndef ZOIO_UTIL_H_
#define ZOIO_UTIL_H_

#include <string>
#include <matrix.hpp>

Matrix load_cringe_img(std::string path);

void save_cringe_img(std::string path, Matrix & img);

#endif