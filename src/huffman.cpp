#include <huffman.hpp>
#include <iostream>

// HuffmanNode

bool HuffmanNode::is_leaf() {
    return (_left == 0) && (_right == 0);
}

void HuffmanNode::father(HuffmanNode & node) {
    _father = &node;
}

void HuffmanNode::left(HuffmanNode & node) {
    _left = &node;
    node._father = this;
}

void HuffmanNode::right(HuffmanNode & node) {
    _right = &node;
    node._father = this;
}

void HuffmanNode::inorder(std::vector<HuffmanNode *> & nodes) {
    if (_left) {
        left().inorder(nodes);
    }

    nodes.push_back(this);

    if (_right) {
        right().inorder(nodes);
    }
}

void HuffmanNode::inorder_leafs(std::vector<HuffmanNode *> & nodes) {
    if (_left) {
        left().inorder_leafs(nodes);
    }

    if (is_leaf()) {
        nodes.push_back(this);
    }

    if (_right) {
        right().inorder_leafs(nodes);
    }
}

// Huffman

// Huffman::Huffman(const std::vector<int> & data) {

// }

// Huffman::Huffman(const std::unordered_map<int, int> & table) {
    
// }

// Huffman::Huffman(const HuffmanNode & tree) {

// }

// std::vector<bool> & Huffman::encode(std::vector<int> & input) {

// }

// std::vector<int> & Huffman::decode(std::vector<bool> & input) {

// }

std::unordered_map<int, int> Huffman::create_table(std::vector<int> & data) {
    std::unordered_map<int, int> dict;
    bool key_exists;

    for (auto it: data) {
        key_exists = dict.count(it);

        if (key_exists) {
            dict.at(it) += 1;
        }
        else {
            dict.emplace(it, 1);
        }
    }
    
    return dict;
}

std::vector<HuffmanNode *> Huffman::create_nodes(const std::unordered_map<int, int> & table) {
    std::vector<HuffmanNode *> nodes;
    HuffmanNode * node;

    for (auto pair: table) {
        // TODO: fix this to prevent memory leaks
        node = new HuffmanNode(pair.first, pair.second);
        nodes.push_back(node);
    }

    return nodes;
}


HuffmanNode & Huffman::create_tree(const std::vector<HuffmanNode *> & nodes) {
    HuffmanNode *node, *left, *right;
    std::priority_queue<HuffmanNode*> pqueue(nodes.begin(), nodes.end());

    while (pqueue.size() > 1) {
        left = pqueue.top();
        pqueue.pop();

        right = pqueue.top();
        pqueue.pop();

        node = new HuffmanNode(0, (left->freq + right->freq));
        node->left(*left);
        node->right(*right);

        pqueue.emplace(node);
    }

    node = pqueue.top();
    pqueue.pop();

    return *node;
}




