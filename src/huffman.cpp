#include <huffman.hpp>
#include <iostream>
#include <algorithm>

// HuffmanNode

bool MostFrequent::operator() (HuffmanNode * a, HuffmanNode * b) {
    return a->freq > b->freq;
}

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

int HuffmanNode::distance(HuffmanNode & node) {
    int tmp;

    if (this == &node)
        return 0;

    if (_left) {
        tmp = left().distance(node);
        if (tmp >= 0) 
            return tmp + 1;
    }

    if (_right) {
        tmp = right().distance(node);
        if (tmp >= 0) 
            return tmp + 1;
    }

    return -1;
}

HuffmanNode & HuffmanNode::find(int val) {
    // TODO: It is possible to optimize this by knowing the 
    // preffered way the tree is going to grow

    HuffmanNode * tmp;

    if (data == val)
        return *this;

    if (_left) {
        tmp = &left().find(val);
        if (tmp)
            return *tmp;
    }

    if (_right) {
        return right().find(val);
    }    

    tmp = 0;
    return *tmp;
}

std::vector<bool> HuffmanNode::path(HuffmanNode & node) {
    HuffmanNode * n = &node;
    std::vector<bool> path;
    bool direction;

    // Generate the path from node to root
    while (n != this) {
        if ((n == 0) || (&n->father() == 0)) {
            path.clear();
            break;
        }

        direction = (n == &n->father().right());
        path.push_back(direction);
        n = &n->father();
    }

    // Path from root to node
    reverse(path.begin(), path.end());

    return path;
}



// Huffman

Huffman::Huffman(const std::vector<int> & data) {
    std::unordered_map<int, int> table;
    std::vector<HuffmanNode *> nodes;

    table = create_table(data);
    nodes = create_nodes(table);
    _tree = &create_tree(nodes);
}

Huffman::Huffman(const std::unordered_map<int, int> & table) {
    std::vector<HuffmanNode *> nodes;
    nodes = create_nodes(table);
    _tree = &create_tree(nodes);
}

Huffman::Huffman(HuffmanNode & tree) {
    _tree = &tree;
}

std::unordered_map<int, int> Huffman::create_table(const std::vector<int> & data) {
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
        // TODO: change this to shared_ptr to prevent memory leaks
        node = new HuffmanNode(pair.first, pair.second);
        nodes.push_back(node);
    }

    return nodes;
}

HuffmanNode & Huffman::create_tree(const std::vector<HuffmanNode *> & nodes) {
    HuffmanNode *node, *left, *right;
    HuffmanPqueue pqueue(nodes.begin(), nodes.end());

    while (pqueue.size() > 1) {
        left = pqueue.top();
        pqueue.pop();

        right = pqueue.top();
        pqueue.pop();

        // std::cout << left->freq << " " << left->data << std::endl; 
        // std::cout << right->freq << " " << right->data << std::endl; 

        node = new HuffmanNode(-1, (left->freq + right->freq));
        node->left(*left);
        node->right(*right);

        pqueue.emplace(node);
    }

    node = pqueue.top();
    pqueue.pop();

    return *node;
}

HuffmanNode & Huffman::root() {
    return *_tree;
}

std::vector<bool> Huffman::encode(const std::vector<int> & input) {
    std::vector<bool> output;
    HuffmanNode * node;

    for (auto it: input) {
        node = &_tree->find(it);

        for (auto dir: _tree->path(*node)) {
            output.push_back(dir);
        }
    }

    return output;
}

// std::vector<int> & Huffman::decode(std::vector<bool> & input) {

// }




