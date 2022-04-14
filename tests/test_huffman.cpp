#include <huffman.hpp>
#include <iostream>
#include <vector>

#include "acutest.h"


void test_create_table() {
    std::unordered_map<int, int> dict;
    std::vector<int> input {
        1,
        2,2,
        3,3,3,
        4,4,4,4,
        5,5,5,5,5
    };

    dict = Huffman::create_table(input);

    TEST_CHECK(dict.size() == 5);
    
    for (auto it: input) {
        TEST_CHECK(dict.at(it) == it);
    }
}

void test_create_nodes() {
    std::unordered_map<int, int> dict {
        {1, 2},
        {2, 4},
        {3, 6},
        {4, 8}
    };

    std::vector<HuffmanNode*> nodes = Huffman::create_nodes(dict);

    TEST_CHECK(nodes.size() == dict.size());

    for (auto it: nodes) {
        TEST_CHECK(it->data * 2 == it->freq);
    }

}

void test_tree_order() {
    /*
           Create a tree structure like this:
        
                       (0, 6)
                           |
                   _____|_____
                   |           |
               (0, 3)       (3, 3)
                   |
               _____|_____
               |           |
           (1, 1)       (2, 2)
        
    */

    std::vector<HuffmanNode> nodes {
        HuffmanNode(0, 6),
        HuffmanNode(0, 3),
        HuffmanNode(3, 3),
        HuffmanNode(1, 1),
        HuffmanNode(2, 2)
    };

    nodes[0].left(nodes[1]);
    nodes[0].right(nodes[2]);

    nodes[1].left(nodes[3]);
    nodes[1].right(nodes[4]);


    TEST_CHECK(!nodes[0].is_leaf());
    TEST_CHECK(!nodes[1].is_leaf());

    TEST_CHECK(nodes[2].is_leaf());
    TEST_CHECK(nodes[3].is_leaf());
    TEST_CHECK(nodes[4].is_leaf());

    TEST_CHECK(HuffmanNode::level(nodes[0], nodes[0]) == 0);
    TEST_CHECK(HuffmanNode::level(nodes[0], nodes[1]) == 1);
    TEST_CHECK(HuffmanNode::level(nodes[0], nodes[2]) == 1);
    TEST_CHECK(HuffmanNode::level(nodes[0], nodes[3]) == 2);
    TEST_CHECK(HuffmanNode::level(nodes[0], nodes[4]) == 2);

    std::vector<int> expected;
    std::vector<HuffmanNode *> tmp;

    tmp.clear();
    nodes[0].inorder(tmp);
    expected = {1, 3, 2, 6, 3};

    for (int i = 0; i < expected.size(); i++) {
        TEST_CHECK(tmp[i]->freq == expected[i]);
    }

    tmp.clear();
    nodes[0].inorder_leafs(tmp);
    expected = {1, 2, 3};

    for (int i = 0; i < expected.size(); i++) {
        TEST_CHECK(tmp[i]->freq == expected[i]);
    }

}

void test_create_tree() {
    HuffmanNode tree;
    std::unordered_map<int, int> dict;
    std::vector<HuffmanNode *> nodes;
    std::vector<int> expected;
    
    dict = {
        {1, 1},
        {2, 2},
        {3, 3},
        {4, 4}
    };

    nodes = Huffman::create_nodes(dict);
    tree = Huffman::create_tree(nodes);

    nodes.clear();
    tree.inorder(nodes);
    expected = {1, 3, 2, 6, 3, 10, 4};

    for (int i = 0; i < expected.size(); i++) {
        TEST_CHECK(nodes[i]->freq == expected[i]);
    }

    nodes.clear();
    expected.clear();
    tree.inorder_leafs(nodes);
    expected = {1, 2, 3, 4};

    for (int i = 0; i < expected.size(); i++) {
        TEST_CHECK(nodes[i]->data == expected[i]);
    }
}   


void test_huffman_encode() {
    std::vector<int> original = {4,0,0,2,8,9,2,2};
    std::vector<bool> expected;
    std::vector<bool> output;

    Huffman huff(original);
    output = huff.encode(original);

}

void test_huffman_decode() {
}

void test_huffman_encode_decode() {

}


TEST_LIST = {
    { "Create table",               test_create_table },
    { "Create nodes",               test_create_nodes },
    { "Tree order",                 test_tree_order },
    { "Create tree",                test_create_tree },
    { "Encode Huffman",             test_huffman_encode},
    { "Decode Huffman",             test_huffman_decode},
    { "Encode/Decode Huffman",      test_huffman_encode_decode},
    { NULL, NULL }
};