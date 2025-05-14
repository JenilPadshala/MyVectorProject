#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <cstddef>
#include <iostream> //for testing purpose only

template <typename T>
class MyVector {
private:
    T* m_data;              // Pointer to the array of elements
    size_t m_size;          // Number of elements in the vector
    size_t m_capacity;      // Current allocated storage capacity

public:
    //Default constructor
    MyVector() : m_data(nullptr), m_size(0), m_capacity(0){
        std::cout << "MyVector<T> Default Constructor called. Address: " << this << std::endl;
    }

    // Destructor
    ~MyVector(){
        std::cout << "MyVector<T> Destructor called. Address: " << this 
                  << ", Size: " << m_size
                  << ", Capacity: " << m_capacity << std::endl;
        delete[] m_data;
    }
    
    // Basic Accessor Methods
    size_t size() const {
        return m_size;
    }

    size_t capacity() const {
        return m_capacity;
    }

    bool empty() const {
        return m_size == 0;
    }

};

#endif