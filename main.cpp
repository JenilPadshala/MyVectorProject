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


int main() {
    std::cout << "MyVector Project: Testing Step 5B (Copy Assignment) started." << std::endl;
    std::cout << "=============================================================" << std::endl;

    MyVector<int> vec_a;
    vec_a.push_back(1);
    vec_a.push_back(2);
    std::cout << "Initial state of vec_a:" << std::endl;
    print_vector_details(vec_a, "vec_a");

    MyVector<int> vec_b;
    vec_b.push_back(100);
    vec_b.push_back(200);
    vec_b.push_back(300);
    std::cout << "\nInitial state of vec_b:" << std::endl;
    print_vector_details(vec_b, "vec_b");

    std::cout << "\nPerforming vec_a = vec_b;" << std::endl;
    vec_a = vec_b; // Calls Copy Assignment Operator
    std::cout << "After vec_a = vec_b:" << std::endl;
    print_vector_details(vec_a, "vec_a");
    print_vector_details(vec_b, "vec_b");

    std::cout << "\nModifying vec_b to ensure vec_a is a deep copy..." << std::endl;
    vec_b.push_back(400);
    if (vec_b.size() > 0) vec_b[0] = 999;
    print_vector_details(vec_b, "vec_b (modified)");
    print_vector_details(vec_a, "vec_a (should be unaffected)");

    std::cout << "\nTesting assignment to an empty vector:" << std::endl;
    MyVector<int> vec_c; // empty
    MyVector<int> vec_d;
    vec_d.push_back(7);
    vec_d.push_back(8);
    print_vector_details(vec_c, "vec_c (empty)");
    print_vector_details(vec_d, "vec_d");
    std::cout << "Performing vec_c = vec_d;" << std::endl;
    vec_c = vec_d;
    print_vector_details(vec_c, "vec_c (after assignment)");
    print_vector_details(vec_d, "vec_d");


    std::cout << "\nTesting assignment from an empty vector:" << std::endl;
    MyVector<int> vec_e; // empty
    print_vector_details(vec_d, "vec_d (non-empty)");
    print_vector_details(vec_e, "vec_e (empty)");
    std::cout << "Performing vec_d = vec_e;" << std::endl;
    vec_d = vec_e;
    print_vector_details(vec_d, "vec_d (after assignment from empty)");
    print_vector_details(vec_e, "vec_e (still empty)");


    std::cout << "\nTesting self-assignment:" << std::endl;
    MyVector<int> vec_f;
    vec_f.push_back(50);
    vec_f.push_back(60);
    print_vector_details(vec_f, "vec_f (before self-assignment)");
    std::cout << "Performing vec_f = vec_f;" << std::endl;
    vec_f = vec_f; // Calls Copy Assignment, should be handled by self-assignment check
    print_vector_details(vec_f, "vec_f (after self-assignment)");

    std::cout << "\nTesting chained assignment:" << std::endl;
    MyVector<int> v_x, v_y;
    MyVector<int> v_z;
    v_z.push_back(11); v_z.push_back(22);
    std::cout << "Performing v_x = v_y = v_z;" << std::endl;
    v_x = v_y = v_z;
    print_vector_details(v_z, "v_z");
    print_vector_details(v_y, "v_y");
    print_vector_details(v_x, "v_x");


    std::cout << "\n=============================================================" << std::endl;
    std::cout << "MyVector Project: Testing Step 5B finished." << std::endl;
    return 0;
}