# MyVector - A Custom Dynamic Array Implementation in C++

## Description

This project is a custom implementation of a dynamic array class template, `MyVector<T>`, similar to C++'s `std::vector`. It serves as a learning exercise to deeply understand fundamental C++ concepts such as manual memory management, templates, operator overloading, the Rule of Five (copy/move semantics), and performance considerations related to data structures.

The `MyVector` class manages a contiguous block of memory on the heap to store elements of a generic type `T`, automatically resizing its internal storage as needed when elements are added.

## Features Implemented

* **Template Class:** `MyVector<T>` can store elements of any type `T`.
* **Dynamic Memory Management:** Uses `new[]` and `delete[]` to manage the underlying array.
* **Dynamic Resizing:** Automatically grows its capacity when `push_back()` is called on a full vector (current strategy: doubles capacity or initializes to 1 if empty).
* **Element Access:**
    * `operator[](size_t index)`: Provides direct access to elements (both `const` and non-`const` versions).
    * Includes bounds checking (throws `std::out_of_range` for invalid indices).
* **Core Lifecycle Management (Rule of Five):**
    * **Default Constructor:** `MyVector()` - Creates an empty vector.
    * **Destructor:** `~MyVector()` - Frees dynamically allocated memory.
    * **Copy Constructor:** `MyVector(const MyVector& other)` - Performs a deep copy.
    * **Copy Assignment Operator:** `MyVector& operator=(const MyVector& other)` - Performs a deep copy with self-assignment protection.
    * **Move Constructor:** `MyVector(MyVector&& other) noexcept` - Efficiently transfers resources from an rvalue.
    * **Move Assignment Operator:** `MyVector& operator=(MyVector&& other) noexcept` - Efficiently transfers resources from an rvalue on assignment.
* **Basic Utility Functions:**
    * `size() const`: Returns the number of elements currently in the vector.
    * `capacity() const`: Returns the current allocated storage capacity.
    * `empty() const`: Checks if the vector contains any elements.
* **Element Insertion:**
    * `push_back(const T& value)`: Adds an element to the end of the vector.

## Learning Goals

This project aims to provide practical experience with:
* Manual memory management in C++ (`new[]`, `delete[]`).
* The Resource Acquisition Is Initialization (RAII) principle.
* Writing generic code using C++ templates (class templates).
* Overloading C++ operators for intuitive class usage.
* The importance and implementation of the "Rule of Five" (Destructor, Copy Constructor, Copy Assignment, Move Constructor, Move Assignment) for resource-owning classes.
* Understanding the performance implications of copy vs. move semantics.
* Fundamentals of data structure implementation.

This knowledge is critical for advanced C++ programming and is particularly relevant for understanding memory management in performance-sensitive contexts like CUDA programming.

## How to Compile and Run

### Prerequisites
* A C++ compiler that supports C++11 or later (C++17 is used in the examples).
    * Examples: g++, Clang, MSVC.

### Compilation
Navigate to the project's root directory (`MyVectorProject`) in your terminal and use a command similar to the following (example using g++):

```bash
g++ -std=c++17 -Wall main.cpp -o MyVectorTest