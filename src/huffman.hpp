#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>


class HuffmanNode {

public:
    HuffmanNode() {}
    HuffmanNode(int data_, int freq_): data(data_), freq(freq_) {}

    bool is_leaf();
    void father(HuffmanNode & node);
    void left(HuffmanNode & node);
    void right(HuffmanNode & node);

    HuffmanNode & left() { return *_left; }
    HuffmanNode & right() { return *_right; }
    HuffmanNode & father() { return *_father; }

    HuffmanNode & find(int val);
    std::vector<bool> path(HuffmanNode & node);  
    int distance(HuffmanNode & node);
    
    void inorder(std::vector<HuffmanNode *> & nodes);
    void inorder_leafs(std::vector<HuffmanNode *> & nodes);

public:
    int data;
    int freq;

public:
    HuffmanNode * _left = 0;
    HuffmanNode * _right = 0;
    HuffmanNode * _father = 0;
    
}; // HuffmanNode


class MostFrequent {
public:
    bool operator() (HuffmanNode * a, HuffmanNode * b);
};


class Huffman {

public:
    Huffman(const std::vector<int> & data);
    Huffman(const std::unordered_map<int, int> & table);
    Huffman(HuffmanNode & tree);

    std::vector<bool> encode(const std::vector<int> & input);
    std::vector<int> decode(std::vector<bool> & input);

    HuffmanNode & root();

    static std::unordered_map<int, int> 
    create_table(const std::vector<int> & data);

    static std::vector<HuffmanNode *> 
    create_nodes(const std::unordered_map<int, int> & table);

    static HuffmanNode &
    create_tree(const std::vector<HuffmanNode *> & nodes);

private:
    std::unordered_map<int, int> _table;
    HuffmanNode * _tree;

}; // Huffman

using HuffmanPqueue = std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, MostFrequent>;

#endif