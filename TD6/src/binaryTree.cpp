#include "binaryTree.hpp"

void BinaryTree::insert(int value) {
    if (!root) {
        root = std::make_unique<SmartNode>(value);
    } else {
        root->insert(value);
    }
}

bool BinaryTree::remove(int value) {
    if (!root) {
        return false;
    } else if (root->value == value) {
        root = root->remove();
        return true;
    } else {
        return root->remove(value);
    }
}

void BinaryTree::clear() {
    root.reset();
}

bool contains(std::unique_ptr<SmartNode>& node, int value) {
    if (!node) {
        return false;
    } else if (node->value == value) {
        return true;
    } else if (value < node->value) {
        return contains(node->left, value);
    } else {
        return contains(node->right, value);
    }
}
bool BinaryTree::contains(int value) const {
    if (!root) {
        return false;
    } else {
        return contains(root, value);
    }
}

size_t BinaryTree::height() const {
    if (!root) {
        return 0;
    } else {
        return root->height();
    }
}
