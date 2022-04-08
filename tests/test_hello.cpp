#include <hello.hpp>
#include <iostream>
#include <string>

#include "acutest.h"


void test_hello() {
    TEST_CHECK(hello().compare("Hello!") != 0);
}

void test_hello_world() {
    TEST_CHECK(hello().compare("Hello World!") == 0);
}

TEST_LIST = {
    { "hello", test_hello },
    { "hello world", test_hello_world },
    { NULL, NULL }
};
