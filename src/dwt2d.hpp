#ifndef DWT_2D_H_
#define DWT_2D_H_

#include <matrix.hpp>

class DWT2D {
    
public:
    static void foward(Matrix & m, int levels);
    static void backward(Matrix & m, int levels);
};

#endif