#ifndef __stack_enhanced___
#define __stack_enhanced___

#include "stack.hpp"

template <typename T> class StackEnhanced : public Stack<T>
{
  public:
    // Inherit the Stack<T> constructors as they are
    // https://en.cppreference.com/w/cpp/language/using_declaration
    using Stack<T>::Stack;

    void clear()
    {
        // WRITE YOUR CODE HERE (Q3.1)
        // Using Stack<T>::_head;
        // _head = 0;
        this->_head = 0;
    }
};

template <typename T>
StackEnhanced<T> &operator<<(StackEnhanced<T> &stack, const T &value)
{
    // WRITE YOUR CODE HERE (Q3.1)
}

#endif // __stack_enhanced___