#ifndef __binary_saerch_tree_enhanced__
#define __binary_saerch_tree_enhanced__

#include "binary_search_tree.hpp"

template <typename T> T bst_min(const T &tree)
{
    // WRITE YOUR CODE HERE (Q6.2)

    if (!tree || !left(tree)) {
        return tree;
    } else {
        return bst_min(left(tree));
    }
}

template <typename T> T bst_max(const T &tree)
{
    // WRITE YOUR CODE HERE (Q6.2)

    if (!tree || !right(tree)) {
        return tree;
    } else {
        return bst_max(right(tree));
    }
}

#endif // __binary_saerch_tree_enhanced__