#ifndef __queue_enhanced__
#define __queue_enhanced__

#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>

#include "queue.hpp"

template <typename T> class Dequeue : public Queue<T>
{
  public:
    // Inherit the constructors of Queue<T>
    using Queue<T>::Queue;

    // Access the element at the back of the queue
    T &back()
    {
        // WRITE YOUR CODE HERE (Q4)

        assert(!this->empty());
        return this->_storage[this->_tail()];
    }

    // Const-access the element at the back of the queue
    const T &back() const
    {
        // WRITE YOUR CODE HERE (Q4)
        assert(!this->empty());
        return this->_storage[this->_tail()];
    }

    // Add a new element to the front of the queue by copying
    // void enqueue_front(const T &value)
    // {
    //     // WRITE YOUR CODE HERE (Q4)
    //     assert(!this->full());
    //     this->_storage[this->_head()] = value;
    //     this->_size++;
    //     if (this->_position == this->_storage.size() - 1) {
    //         this->_position = 0;
    //     } else {
    //         this->_position++;
    //     }
    // }

    void enqueue_front(const T &value)
    {
        assert(!this->full());
        size_t i;
        if (this->empty()) {
            index = 0;
            this->_position = this->_storage.size() - 1;
        } else {
            index = this->_head() + 1;
        }
        if (i > this->_storage.size()) { i -= this->_storage.size(); }
        this->_size++;
        this->_storage[index] = value;
    }

    // Remove the element at the back of the queue
    void dequeue_back()
    {
        // WRITE YOUR CODE HERE (Q4)

        assert(!this->empty());
        this->_size--;
        // Call the _tail function given the updated size of the queue
        this->_position = _tail();
    }

    // Remove all elements from the queue
    void clear()
    {
        this->_size = 0;
        this->_position = 0;
    }

  protected:
    // Return the index of the element to the front of the queue
    size_t _tail() const
    {
        // WRITE YOUR CODE HERE (Q4)

        assert(this->_size >= 0);
        if (this->_position + 1 == this->_storage.size()) { return 0; }
        return this->_position + 1;
    }
};

#endif // __queue_enhanced__