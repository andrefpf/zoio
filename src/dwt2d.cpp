#include <dwt2d.hpp>
#include <dwt.hpp>
#include <iostream>
#include <vector>


void DWT2D::foward(Matrix & m, int levels) {
    std::vector<int> tmp;

    for (int i; i < m.height(); i++) {
        tmp = m.row(i);
        DWT::foward(tmp, levels);
        m.row(i, tmp);
    }

    for (int i; i < m.width(); i++) {
        tmp = m.col(i);
        DWT::foward(tmp, levels);
        m.col(i, tmp);
    }
}

void DWT2D::backward(Matrix & m, int levels) {
    std::vector<int> tmp;

    for (int i; i < m.height(); i++) {
        tmp = m.row(i);
        DWT::backward(tmp, levels);
        m.row(i, tmp);
    }

    for (int i; i < m.width(); i++) {
        tmp = m.col(i);
        DWT::backward(tmp, levels);
        m.col(i, tmp);
    }
}