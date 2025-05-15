#include <iostream>
#include <string>
#include <stdexcept>
#include <utility> // For std::move
#include "MyVector.hpp"

template <typename T>
void print_vector_details(const MyVector<T>& vec, const std::string& name) {
    // ... (previous implementation of print_vector_details)
    std::cout << "---- " << name << " ----" << std::endl;
    std::cout << name << ".size(): " << vec.size()
              << ", " << name << ".capacity(): " << vec.capacity()
              << ", " << name << ".empty(): " << (vec.empty() ? "true" : "false")
              << std::endl;
    if (!vec.empty()) {
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

MyVector<int> create_source_vector(int start_val, int count) {
    // ... (previous implementation of create_source_vector)
    MyVector<int> temp_v;
    // std::cout << "Inside create_source_vector, creating temp_v (" << &temp_v << ")" << std::endl;
    for (int i = 0; i < count; ++i) {
        temp_v.push_back(start_val + i);
    }
    // print_vector_details(temp_v, "temp_v (before return from create_source_vector)");
    return temp_v;
}


int main() {
    std::cout << "MyVector Project: Testing Step 6B (Move Assignment) started." << std::endl;
    std::cout << "===============================================================" << std::endl;

    std::cout << "\n--- Test 1: Move assignment from function return ---" << std::endl;
    MyVector<int> assigned_v1;
    assigned_v1.push_back(55);
    assigned_v1.push_back(66);
    print_vector_details(assigned_v1, "assigned_v1 (before move assignment from func)");
    std::cout << "Assigning from create_source_vector(200, 2)..." << std::endl;
    assigned_v1 = create_source_vector(200, 2); // Expect Move Assignment Operator
    print_vector_details(assigned_v1, "assigned_v1 (after move assignment from func)");


    std::cout << "\n--- Test 2: Move assignment using std::move ---" << std::endl;
    MyVector<int> assigned_v2;
    assigned_v2.push_back(111); // Initial content for assigned_v2
    assigned_v2.push_back(222);
    print_vector_details(assigned_v2, "assigned_v2 (before std::move assignment)");

    MyVector<int> source_for_assign;
    source_for_assign.push_back(888);
    source_for_assign.push_back(999);
    source_for_assign.push_back(777);
    print_vector_details(source_for_assign, "source_for_assign (before std::move)");

    std::cout << "Performing assigned_v2 = std::move(source_for_assign);" << std::endl;
    assigned_v2 = std::move(source_for_assign); // Explicitly invoke move assignment
    print_vector_details(assigned_v2, "assigned_v2 (after std::move assignment)");
    print_vector_details(source_for_assign, "source_for_assign (after being moved from)");


    std::cout << "\n--- Test 3: Self-move assignment ---" << std::endl;
    MyVector<int> self_move_v;
    self_move_v.push_back(123);
    self_move_v.push_back(456);
    print_vector_details(self_move_v, "self_move_v (before self-move)");
    std::cout << "Performing self_move_v = std::move(self_move_v);" << std::endl;
    self_move_v = std::move(self_move_v); // Test self-assignment check
    print_vector_details(self_move_v, "self_move_v (after self-move)"); // Should be unchanged due to self-assignment check
    
    // Note: If self_move_v = std::move(self_move_v) *didn't* hit the (this == &other) check
    // (which it should, as std::move returns a reference to the same object),
    // it would delete its own data, then try to move from its now-invalidated self.
    // The self-assignment check is crucial.

    std::cout << "\n===============================================================" << std::endl;
    std::cout << "MyVector Project: Testing Step 6B finished." << std::endl;
    return 0;
}