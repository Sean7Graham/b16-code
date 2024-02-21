#include <iostream>
#include <memory>

#include "binary_search_tree.hpp"
#include "binary_search_tree_enhanced.hpp"
#include "binary_search_tree_traversal.hpp"

int main(int argc, char **argv)
{
    std::unique_ptr<BinaryTree<int>> bt;

    for (int x : {38, 46, 21, 40, 85, 86, 53, 11, 84}) {
        bt = bst_insert(std::move(bt), x);
    }

    auto function = [](const auto &tree) { std::cout << value(tree) << " "; };

    std::cout << "Forward Traversal: ";

    bst_in_order_traversal(bt.get(), function);
    std::cout << "\n";

    std::cout << "Backwards Traversal: ";

    bst_in_order_traversal_backwards(bt.get(), function);
    std::cout << "\n";
    return 0;
};