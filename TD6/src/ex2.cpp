#include "node.hpp"
#include <iostream>

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}

int main() {
    Node* root = create_node(10);
    root->insert(5);
    root->insert(3);
    root->insert(7);
    root->insert(2);
    root->insert(4);
    root->insert(6);
    root->insert(8);
    root->insert(1);
    root->insert(9);
    root->insert(0);

    pretty_print_left_right(*root);
    
    std::cout << "\nInfix: ";
    root->display_infix();
    std::cout << "\n\n";

    std::cout << "Min: " << root->min() << std::endl;
    std::cout << "Max: " << root->max() << "\n\n";

    std::cout << "Sum:";
    auto prefix_nodes = root->prefix();
    int sum = 0;
    for (const auto& node : prefix_nodes) {
        sum += node->value;
    }
    std::cout << sum << "\n\n";

    std::cout << "Height: " << root->height() << "\n\n";

    return 0;
}