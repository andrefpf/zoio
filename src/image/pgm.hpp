#ifndef ZOIO_PGM_IO
#define ZOIO_PGM_IO

#include <string>
#include <image/image.hpp>

namespace zoio {

Image read_pgm(std::string path);
void write_pgm(Image image, std::string path);

} // zoio

#endif 