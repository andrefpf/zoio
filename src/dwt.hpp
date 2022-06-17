#ifndef DWT_H_
#define DWT_H_

#include <vector>

class DWT {
    
public:
    static void foward(std::vector<int> & input, int levels);
    static void backward(std::vector<int> & input, int levels);
};

#endif