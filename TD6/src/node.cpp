#include "node.hpp"
#include <iostream>
#include <algorithm>
#include <stack>

Node* create_node(int value) {
    Node* node = new Node;
    node->value = value;
    return node;
}

bool Node::is_leaf() const {
    return left == nullptr && right == nullptr;
}

void Node::insert(int value) {
    if (value < this->value) {
        if (left == nullptr) {
            left = create_node(value);
        } else {
            left->insert(value);
        }
    } else if (value > this->value) {
        if (right == nullptr) {
            right = create_node(value);
        } else {
            right->insert(value);
        }
    }
}

int Node::height() const {
    if (is_leaf()) {
        return 1;
    } else {
        int left_height = left ? left->height() : 0;
        int right_height = right ? right->height() : 0;
        return 1 + std::max(left_height, right_height);
    }
}

void Node::delete_children() {
    if (left) {
        left->delete_children();
        delete left;
        left = nullptr;
    }
    if (right) {
        right->delete_children();
        delete right;
        right = nullptr;
    }
}

void Node::display_infix() const {
    if (left) {
        left->display_infix();
    }
    std::cout << value << " ";
    if (right) {
        right->display_infix();
    }
}

std::vector<Node const*> Node::prefix() const {
    std::vector<Node const*> result;
    result.push_back(this);
    if (left) {
        auto left_prefix = left->prefix();
        result.insert(result.end(), left_prefix.begin(), left_prefix.end());
    }
    if (right) {
        auto right_prefix = right->prefix();
        result.insert(result.end(), right_prefix.begin(), right_prefix.end());
    }
    return result;
}


std::vector<Node const*> Node::postfix() const {
    std::vector<Node const*> nodes {};
    std::stack<Node const*> to_process {};
    Node const* previous {nullptr};
    to_process.push(this);

    while (!to_process.empty()) {
        Node const* current { to_process.top() };

        // Si on est en train de descendre dans l'arbre
        if (previous == nullptr || (previous->left == current || previous->right == current)) {
            if(current->left != nullptr) {
                to_process.push(current->left);
            }
            else if(current->right != nullptr) {
                to_process.push(current->right);
            } else {
                // on traite le nœud (ajouter au vecteur) et on le retire de la pile
                nodes.push_back(current);
                to_process.pop();
            }

        // Si l'on remonte dans l'arbre en venant de la gauche
        }else if (previous == current->left) {
            if(current->right != nullptr) {
                to_process.push(current->right);
            } else {
                nodes.push_back(current);
                to_process.pop();
            }

        // Si l'on remonte dans l'arbre en venant de la droite
        } else if (previous == current->right) {
            nodes.push_back(current);
            to_process.pop();
        }

        previous = current;
    }

    return nodes;
}

Node*& Node::most_left(Node*& node) {
    if (node->left) {
        return most_left(node->left);
    } else {
        return node;
    }
}

bool remove(Node*& node, int value) {
    if (node == nullptr) {
        return false;
    }

    if (value < node->value) {
        return remove(node->left, value);
    } else if (value > node->value) {
        return remove(node->right, value);
    } else {
        // Node found
        if (node->is_leaf()) {
            delete node;
            node = nullptr;
        } else if (node->left && node->right) {
            Node*& most_left_node = node->most_left(node->right);
            node->value = most_left_node->value;
            remove(node->right, most_left_node->value);
        } else {
            Node* child = (node->left) ? node->left : node->right;
            delete node;
            node = child;
        }
        return true;
    }    
}

void delete_tree(Node*& node) {
    if (node) {
        node->delete_children();
        delete node;
        node = nullptr;
    }
}

int Node::min() const {
    if (left) {
        return left->min();
    } else {
        return value;
    }
}
int Node::max() const {
    if (right) {
        return right->max();
    } else {
        return value;
    }
}