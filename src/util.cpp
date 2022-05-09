#include <util.hpp>
#include <matrix.hpp>
#include <iostream>
#include <fstream>


Matrix load_cringe_img(std::string path) {
    std::ifstream file;
    file.open(path);

    int w;
    int h;

    if (!file.is_open()) {
        std::cerr << "Could not open the file" << std::endl;
    }

    file >> w;
    file >> h;

    Matrix matrix(w, h);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            file >> matrix.at(i,j);
        }
    }

    return matrix;
}

void save_cringe_img(std::string path, Matrix & img) {
    std::ofstream file;
    file.open(path);

    file << img.width() << " " << img.height() << std::endl;

    for (int i = 0; i < img.height(); i++) {
        for (int j = 0; j < img.width(); j++) {
            file << img.at(i,j) << " ";
        }
        file << std::endl;
    }
}
