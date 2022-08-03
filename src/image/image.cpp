#include "image.hpp"

using namespace zoio;

Image::Image(int width, int height)
    : _width(width), _height(height), _data(width * height, 0) {}

int Image::width() { return _width; }

int Image::height() { return _height; }

bytes_t &Image::at(int i) { return _data[i]; }

bytes_t &Image::at(int x, int y) { return _data[x + y * width()]; }
