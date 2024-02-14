#ifndef __stack_rpn__
#define __stack_rpn__

#include "stack.hpp"
#include <cassert>
#include <functional>

// WRITE YOUR CODE HERE

// template <typename T1, typename T2>

template <typename T1, typename T2>
void apply_operation(Stack<T1> &stack, T2 operation)
{
    auto L = stack.top();
    stack.pop();
    auto R = stack.top();
    stack.pop();
    stack.push(operation(L, R));
}

template <typename T> void plus(Stack<T> &stack)
{
    apply_operation(stack, std::plus<T>{});
}

template <typename T> void minus(Stack<T> &stack)
{
    apply_operation(stack, std::minus<T>{});
}

template <typename T> void multiplies(Stack<T> &stack)
{
    apply_operation(stack, std::multiplies<T>{});
}

template <typename T> void divides(Stack<T> &stack)
{
    apply_operation(stack, std::divides<T>{});
}

template <typename T> void negate(Stack<T> &stack)
{
    auto temp = stack.top();
    stack.pop();
    stack.push(std::negate<T>(temp));
}

// operator<< on types Stack<int> and int
template <typename T> Stack<T> &operator<<(Stack<T> &stack, const T &val)
{
    stack.push(val);
    return stack;
}

template <typename T>
Stack<T> &operator<<(Stack<T> &stack, void (*fn)(Stack<T> &))
{
    fn(stack);
    return stack;
}

// operator<< on types Stack<int> and fn
#endif // __stack_rpn__