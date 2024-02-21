#ifndef __binary_search_tree_traversal__
#define __binary_search_tree_traversal__

#include "binary_search_tree.hpp"
#include <functional>

template <class T, typename F>
void bst_in_order_traversal(const T &tree, F function)
{
    if (!tree) return;

    bst_in_order_traversal(left(tree), function);

    function(tree);

    bst_in_order_traversal(right(tree), function);
}

template <class T, typename F>
void bst_in_order_traversal_backwards(const T &tree, F function)
{
    if (!tree) return;

    bst_in_order_traversal_backwards(right(tree), function);

    function(tree);

    bst_in_order_traversal_backwards(left(tree), function);
}

#endif // __binary_search_tree_traversal__
