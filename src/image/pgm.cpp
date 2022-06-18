#include <image/pgm.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>

namespace zoio {

Image read_pgm(std::string path) {
    int width;
    int height;
    int max;
    std::string line;
    std::ifstream file;
    std::stringstream ss;
    
    file.open(path);

    if (!file.is_open()) {
        std::cerr << "Could not open the file." << std::endl;
    }

    file >> line; 
    if (line != "P5") {
        std::cerr << "This is not a valid pgm file." << std::endl;
    }

    do {
        getline(file, line);
    } while (line.empty() | line[0] == '#');
    
    ss << line;
    ss >> width;
    ss >> height;

    do {
        getline(file, line);
    } while (line.empty() | line[0] == '#');

    ss.clear();
    ss << line;
    ss >> max;

    if (max > 256) {
        std::cerr << "Zoio still do not support pgm files with 16 bits." << std::endl;
    }

    Image image(width, height);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            file >> std::noskipws >> image.at(i, j);
        }
    }

    return image;
}


void write_pgm(Image image, std::string path) {
    std::ofstream file;
    file.open(path);

    if (!file.is_open()) {
        std::cerr << "Could not open the file." << std::endl;
    }

    int width = image.width();
    int height = image.height();

    file << "P5" << std::endl;
    file << "# CREATOR: ZOIO developer version" << std::endl;
    file << width << " " << height << std::endl;
    file << 255 << std::endl;
    
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            file << image.at(i, j);
        }
    }
}

} // zoio