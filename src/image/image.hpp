#ifndef ZOIO_IMAGE_
#define ZOIO_IMAGE_

#include <util.hpp>
#include <vector>

namespace zoio {

class Image {

public:
    Image(int width, int height);
    bytes_t & at(int i);
    bytes_t & at(int x, int y);
    int width();
    int height();
    
private:
    int _width;
    int _height;
    std::vector<bytes_t> _data;
    
}; // Image

} // zoio

#endif