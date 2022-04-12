#include <matrix.hpp>
#include <vector>

Matrix::Matrix(int width, int height)
: _width(width), _height(height) 
{
    _data = new int[width * height];
}

int Matrix::width() {
    return _width;
}

int Matrix::height() {
    return _height;
}

int & Matrix::at(int n_row, int n_col) {
    return _data[n_col + n_row * _width];
}

void Matrix::insert(int n_row, int n_col, int val) {
     _data[n_col + n_row * _width] = val;
}

std::vector<int> Matrix::row(int n_row) {
    std::vector<int> out(_width);

    for (int i = 0; i < _width; i++) {
        out[i] = at(n_row, i);
    }

    return out;
}

std::vector<int> Matrix::col(int n_col) {
    std::vector<int> out(_height);
    
    for (int i = 0; i < _height; i++) {
        out[i] = at(i, n_col);
    }

    return out;
}

void Matrix::row(int n_row, std::vector<int> & v_row) {
    for (int i = 0; i < _width; i++) {
        at(n_row, i) = v_row[i];
    }
}

void Matrix::col(int n_col, std::vector<int> & v_col) {
    for (int i = 0; i < _height; i++) {
        at(i, n_col) = v_col[i];
    }
}

