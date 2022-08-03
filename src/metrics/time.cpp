#include "time.hpp"
#include <iostream>

namespace zoio {
namespace metrics {

Time::Time(std::string name) {
    _name = name;
    _begin = std::chrono::steady_clock::now();
}

Time::~Time() {
    auto end = std::chrono::steady_clock::now();
    auto delta =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - _begin)
            .count();
    std::cout << _name << " took " << delta << " [ns]" << std::endl;
}

} // namespace metrics
} // namespace zoio