#ifndef ZOIO_PGM_IO_
#define ZOIO_PGM_IO_

#include <string>
#include <image/image.hpp>

namespace zoio {

Image read_pgm(std::string path);
void write_pgm(Image image, std::string path);

} // zoio

#endif 