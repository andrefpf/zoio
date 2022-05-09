#include <util.hpp>
#include <iostream>
#include <fstream>


Matrix load_cringe_img(std::string path) {
    return Matrix(0,0);
}

void save_cringe_img(std::string path, Matrix & img) {
    std::ofstream file;
    file.open(path);

    file << img.width() << " " << img.height() << std::endl;
}
