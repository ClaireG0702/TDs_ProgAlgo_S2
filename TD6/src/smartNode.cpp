#include "smartNode.hpp"
#include <iostream>
#include <algorithm>
#include <stack>

std::unique_ptr<SmartNode> create_smart_node(int value) {
    return std::make_unique<SmartNode>(SmartNode{value, nullptr, nullptr});
}

bool SmartNode::is_leaf() const {
    return !left && !right;
}

void SmartNode::insert(int value) {
    if (value < this->value) {
        if (left) {
            left->insert(value);
        } else {
            left = create_smart_node(value);
        }
    } else if (value > this->value) {
        if (right) {
            right->insert(value);
        } else {
            right = create_smart_node(value);
        }
    }
}

size_t SmartNode::height() const {
    size_t left_height = left ? left->height() : 0;
    size_t right_height = right ? right->height() : 0;
    return std::max(left_height, right_height) + 1;
}

std::unique_ptr<SmartNode>& SmartNode::most_left(std::unique_ptr<SmartNode>& node) {
    if (node->left) {
        return most_left(node->left);
    } else {
        return node;
    }
}

bool remove(std::unique_ptr<SmartNode>& node, int value) {
    if (!node) {
        return false;
    }

    if (value < node->value) {
        return remove(node->left, value);
    } else if (value > node->value) {
        return remove(node->right, value);
    } else {
        // Node found
        if (node->is_leaf()) {
            node.reset();
        } else if (node->left && node->right) {
            auto& most_left_node = node->most_left(node->right);
            node->value = most_left_node->value;
            remove(most_left_node, most_left_node->value);
        } else {
            node = std::move(node->left ? node->left : node->right);
        }
        return true;
    }
}

int SmartNode::min() const {
    if (left) {
        return left->min();
    } else {
        return value;
    }
}
int SmartNode::max() const {
    if (right) {
        return right->max();
    } else {
        return value;
    }
}