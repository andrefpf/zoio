#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>

class Matrix {

public:
    Matrix(int width, int height);

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