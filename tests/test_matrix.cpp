#include "matrix.hpp"
#include "util.hpp"
#include <iostream>
#include <vector>

#include "acutest.h"

void test_constructor() {
    Matrix m = {
        {1, 3, 5},
        {2, 4, 6},
    };

    TEST_CHECK(m.width() == 3);
    TEST_CHECK(m.height() == 2);

    TEST_CHECK(m.at(0, 0) == 1);
    TEST_CHECK(m.at(1, 0) == 2);
    TEST_CHECK(m.at(0, 1) == 3);
    TEST_CHECK(m.at(1, 1) == 4);
    TEST_CHECK(m.at(0, 2) == 5);
    TEST_CHECK(m.at(1, 2) == 6);
}

void test_insert_at() {
    Matrix m(16, 9);

    TEST_CHECK(m.width() == 16);
    TEST_CHECK(m.height() == 9);

    for (int i = 0; i < m.height(); i++) {
        for (int j = 0; j < m.width(); j++) {
            m.insert(i, j, (i + j));
        }
    }

    for (int i = 0; i < m.height(); i++) {
        for (int j = 0; j < m.width(); j++) {
            TEST_CHECK(m.at(i, j) == (i + j));
        }
    }

    for (int i = 0; i < m.height(); i++) {
        m.insert(i, 0, 1234);
    }

    for (int i = 0; i < m.height(); i++) {
        TEST_CHECK(m.at(i, 0) == 1234);
    }

    for (int i = 0; i < m.width(); i++) {
        m.insert(0, i, 4321);
    }

    for (int i = 0; i < m.width(); i++) {
        TEST_CHECK(m.at(0, i) == 4321);
    }
}

void test_get_rows_cols() {
    Matrix m(32, 64);

    TEST_CHECK(m.width() == 32);
    TEST_CHECK(m.height() == 64);

    for (int i = 0; i < m.height(); i++) {
        for (int j = 0; j < m.width(); j++) {
            m.insert(i, j, (i + j));
        }
    }

    std::vector<int> v;

    for (int i = 0; i < m.height(); i++) {
        v = m.row(i);

        for (int j = 0; j < m.width(); j++) {
            TEST_CHECK(v[j] == m.at(i, j));
        }
    }

    for (int i = 0; i < m.width(); i++) {
        v = m.col(i);
        for (int j = 0; j < m.height(); j++) {
            TEST_CHECK(v[j] == m.at(j, i));
        }
    }
}

void test_set_rows_cols() {
    Matrix m(5, 4);

    TEST_CHECK(m.width() == 5);
    TEST_CHECK(m.height() == 4);

    for (int i = 0; i < m.height(); i++) {
        for (int j = 0; j < m.width(); j++) {
            m.insert(i, j, 0);
        }
    }

    std::vector<int> expected;
    std::vector<int> actual;

    expected = {1, 2, 3, 4, 5};
    m.row(3, expected);
    actual = m.row(3);

    TEST_CHECK(actual.size() == m.width());

    for (int i = 0; i < m.width(); i++) {
        TEST_CHECK(actual[i] == expected[i]);
    }

    expected = {1, 2, 3, 4};
    m.col(1, expected);
    actual = m.col(1);

    TEST_CHECK(actual.size() == m.height());

    for (int i = 0; i < m.height(); i++) {
        TEST_CHECK(actual[i] == expected[i]);
    }
}

TEST_LIST = {{"constructor", test_constructor},
             {"insert/at", test_insert_at},
             {"get rows/cols", test_get_rows_cols},
             {"set rows/cols", test_set_rows_cols},
             {NULL, NULL}};
