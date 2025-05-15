#include <iostream>
#include <string>    
#include <stdexcept> 
#include "MyVector.hpp"

// Helper function to print vector stats and content
template <typename T>
void print_vector_details(const MyVector<T>& vec, const std::string& name) {
    std::cout << "---- " << name << " ----" << std::endl;
    std::cout << name << ".size(): " << vec.size()
              << ", " << name << ".capacity(): " << vec.capacity()
              << ", " << name << ".empty(): " << (vec.empty() ? "true" : "false")
              << std::endl;
    std::cout << name << " elements: [ ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i == vec.size() - 1 ? "" : ", "); // Uses const operator[]
    }
    std::cout << " ]" << std::endl;
    std::cout << "--------------------" << std::endl;
}

int main() {
    std::cout << "MyVector Project: Testing Step 4 (operator[]) started." << std::endl;
    std::cout << "=======================================================" << std::endl;

    MyVector<int> v_int;
    v_int.push_back(10);
    v_int.push_back(20);
    v_int.push_back(30);
    print_vector_details(v_int, "v_int");

    std::cout << "\nModifying v_int[1]..." << std::endl;
    v_int[1] = 200; // Uses non-const operator[]
    print_vector_details(v_int, "v_int (after modification)");

    std::cout << "\nAccessing elements of a const MyVector..." << std::endl;
    const MyVector<int>& const_v_int_ref = v_int;
    std::cout << "const_v_int_ref[0]: " << const_v_int_ref[0] << std::endl; // Uses const operator[]
    // const_v_int_ref[0] = 1000; // This line should cause a compile error if uncommented

    print_vector_details(const_v_int_ref, "const_v_int_ref");


    std::cout << "\nTesting out-of-bounds access..." << std::endl;
    try {
        std::cout << "Attempting to access v_int[5] (size is " << v_int.size() << ")..." << std::endl;
        std::cout << v_int[5] << std::endl; // This should throw
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Attempting to access const_v_int_ref[3] (size is " << const_v_int_ref.size() << ")..." << std::endl;
        std::cout << const_v_int_ref[3] << std::endl; // This should throw
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=======================================================" << std::endl;
    std::cout << "MyVector Project: Testing Step 4 finished." << std::endl;
    return 0;
}