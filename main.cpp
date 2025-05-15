#include <iostream>
#include <string>
#include <stdexcept>
#include "MyVector.hpp"

template <typename T>
void print_vector_details(const MyVector<T>& vec, const std::string& name) {
    std::cout << "---- " << name << " ----" << std::endl;
    std::cout << name << ".size(): " << vec.size()
              << ", " << name << ".capacity(): " << vec.capacity()
              << ", " << name << ".empty(): " << (vec.empty() ? "true" : "false")
              << std::endl;
    if (!vec.empty()) { // Only print elements if not empty
        std::cout << name << " elements: [ ";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
        }
        std::cout << " ]" << std::endl;
    } else {
        std::cout << name << " is empty." << std::endl;
    }
    std::cout << "--------------------" << std::endl;
}

int main() {
    std::cout << "MyVector Project: Testing Step 5A (Copy Constructor) started." << std::endl;
    std::cout << "=============================================================" << std::endl;

    MyVector<int> original_v;
    original_v.push_back(10);
    original_v.push_back(20);
    original_v.push_back(30);
    print_vector_details(original_v, "original_v");

    std::cout << "\nCreating copied_v from original_v using Copy Constructor..." << std::endl;
    MyVector<int> copied_v = original_v; // Calls Copy Constructor
    print_vector_details(copied_v, "copied_v (after copy construction)");
    print_vector_details(original_v, "original_v (should be unchanged)");

    std::cout << "\nModifying original_v to test deep copy..." << std::endl;
    original_v.push_back(40);
    if (original_v.size() > 0) { // Check if there are elements to modify
        original_v[0] = 100;
    }
    print_vector_details(original_v, "original_v (after modification)");
    print_vector_details(copied_v, "copied_v (should be unaffected by original_v changes)");

    std::cout << "\nTesting copy of an empty vector..." << std::endl;
    MyVector<int> empty_original;
    print_vector_details(empty_original, "empty_original");
    MyVector<int> copied_empty = empty_original; // Calls Copy Constructor
    print_vector_details(copied_empty, "copied_empty");
    copied_empty.push_back(5); // Modify copy to ensure it's independent
    print_vector_details(copied_empty, "copied_empty (after push_back)");
    print_vector_details(empty_original, "empty_original (should still be empty)");

    std::cout << "\n=============================================================" << std::endl;
    std::cout << "MyVector Project: Testing Step 5A finished." << std::endl;
    return 0;
}