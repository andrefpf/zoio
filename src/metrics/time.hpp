#ifndef ZOIO_TIME_H_
#define ZOIO_TIME_H_

#include <chrono>
#include <string>

namespace zoio {

class Time {

public:
    Time(std::string name = "Execution");
    ~Time();

private:
    std::string _name;
    std::chrono::steady_clock::time_point _begin;
    
};

} // zoio

#endif 