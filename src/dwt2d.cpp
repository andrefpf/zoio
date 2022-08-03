#include "dwt2d.hpp"
#include "dwt.hpp"
#include <iostream>
#include <vector>

void DWT2D::foward(Matrix &m, int levels) {
    std::vector<int> tmp;
    int w = m.width();
    int h = m.height();

    for (int level = 0; level < levels; level++) {
        for (int i = 0; i < h; i++) {
            tmp = m.row(i);
            tmp.resize(w);
            DWT::foward(tmp, 1);
            m.row(i, tmp);
        }

        for (int i = 0; i < w; i++) {
            tmp = m.col(i);
            tmp.resize(h);
            DWT::foward(tmp, 1);
            m.col(i, tmp);
        }

        w /= 2;
        h /= 2;
    }
}

void DWT2D::backward(Matrix &m, int levels) {
    std::vector<int> tmp;
    int w = m.width() >> levels;
    int h = m.height() >> levels;

    for (int level = levels; level > 0; level--) {
        w *= 2;
        h *= 2;

        for (int i = 0; i < h; i++) {
            tmp = m.row(i);
            tmp.resize(w);
            DWT::backward(tmp, 1);
            m.row(i, tmp);
        }

        for (int i = 0; i < w; i++) {
            tmp = m.col(i);
            tmp.resize(h);
            DWT::backward(tmp, 1);
            m.col(i, tmp);
        }
    }
}