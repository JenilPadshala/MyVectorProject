#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <cstddef>
#include <iostream> //for testing purpose only
#include <algorithm>
#include <stdexcept>
#include <utility>



template <typename T>
class MyVector {
private:
    T* m_data;              // Pointer to the array of elements
    size_t m_size;          // Number of elements in the vector
    size_t m_capacity;      // Current allocated storage capacity

    // Private helper function to handle reallocation.
    void _reallocate_and_copy(size_t new_capacity) {
        std::cout << "MyVector<T> Reallocating from capacity " << m_capacity 
                  << " to " << new_capacity << std::endl;
        
        // allocate new memory  block
        T* new_data = new T[new_capacity];

        // copy existing elements to new block
        if (m_data != nullptr) {
            for (size_t i=0; i< m_size; ++i) {
                new_data[i] = m_data[i];
            }
        }

        // deallocate the old memory block
        delete[] m_data;
        
        // update members to point to the new memory block
        m_data = new_data;
        m_capacity = new_capacity;
    }

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

    // Copy Constructor
    MyVector(const MyVector& other) : m_data(nullptr), m_size(other.m_size), m_capacity(other.m_capacity) {
        if (m_capacity == 0){
            return;
        }
        m_data = new T[m_capacity];

        for (size_t i=0; i<m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }

    // copy assignment operator
    MyVector& operator=(const MyVector& other) {
        if (this == &other) {
            return *this;
        }

        delete[] m_data;
        m_data = nullptr;
        m_size = 0;
        m_capacity = 0;

        m_size = other.m_size;
        m_capacity = other.m_capacity;

        if (m_capacity == 0){
            return *this;
        }

        m_data = new T[m_capacity];

        for (size_t i=0; i<m_size; ++i){
            m_data[i] = other.m_data[i];
        }

        return *this;
    }
    

    // Move Constructor
    MyVector(MyVector&& other) noexcept : m_data(other.m_data), m_size(other.m_size), m_capacity(other.m_capacity) {
        other.m_data = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }

    // Move assignment operator
    MyVector& operator=(MyVector&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        delete[] m_data;
        m_data = other.m_data;
        m_size = other.m_size;
        m_capacity = other.m_capacity;

        other.m_data = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;

        return *this;
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


    // Modifiers

    void push_back(const T& value) {
        std::cout << "MyVector<T> push_back(" << value << ") called. "
                  << "Current size: " << m_size << ", capacity: " << m_capacity << std::endl;
        
        //check if we need to reallocate
        if (m_size >= m_capacity) {
            size_t new_capacity = (m_capacity == 0) ? 1 : m_capacity * 2; // Growth factor of 2
            _reallocate_and_copy(new_capacity); 
        }

        // add the new element at the end
        m_data[m_size] = value;
        m_size++;
        std::cout << "After push_back. New size: " << m_size << ", new capacity: " << m_capacity << std::endl;
    }

    // Element Access

    // Non-const version: allows modification of the element
    T& operator[](size_t index) {
        if (index >= m_size) {
            throw std::out_of_range("MyVector::operator[] - Index out of bounds");
        }
        return m_data[index];
    }

    // Const version: for read-only access on const Myvector objects
    const T& operator[](size_t index) const {
        if (index >= m_size) {
            throw std::out_of_range("MyVector::operator[] - Index out of bounds");
        }
        return m_data[index];
    }
};

#endif