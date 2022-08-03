#ifndef ZOIO_PGM_IO_H_
#define ZOIO_PGM_IO_H_

#include <string>
#include "image.hpp"

namespace zoio {

Image read_pgm(std::string path);
void write_pgm(Image image, std::string path);

} // zoio

#endif 