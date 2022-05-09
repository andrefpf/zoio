#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>

using initializer_matrix = std::initializer_list<std::initializer_list<int>>;


class Matrix {

public:
    Matrix() {};
    Matrix(int width, int height);
    Matrix(initializer_matrix m);
    ~Matrix();

    int width();
    int height();

    int & at(int n_row, int n_col);
    void insert(int n_row, int n_col, int val);

    std::vector<int> row(int n_row);
    std::vector<int> col(int n_col);

    void row(int n_row, std::vector<int> & v_row);
    void col(int n_col, std::vector<int> & v_col);

private:
    int _width;
    int _height;
    int * _data;
};


#endif