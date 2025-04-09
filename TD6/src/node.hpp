#pragma once
#include <vector>

struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    bool is_leaf() const;
    void insert(int value);
    int height() const;
    void delete_children();
    void display_infix() const;
    std::vector<Node const*> prefix() const;
    std::vector<Node const*> postfix() const;
    Node*& most_left(Node*& node);
    int min() const;
    int max() const;
};

Node* create_node(int value);
bool remove(Node*& node, int value);
void delete_tree(Node*& node);