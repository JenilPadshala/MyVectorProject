#include <iostream>
#include "MyVector.hpp"

void print_vector_stats(const MyVector<int>& vec, const std::string& name) {
    std::cout << name << ".size(): " << vec.size() 
              << ", " << name << ".capacity(): " << vec.capacity() 
              << ", " << name << ".empty(): " << (vec.empty() ? "true" : "false") 
              << std::endl;
}

int main(){
    std::cout << "MyVector Project: Testing started." << std::endl;
    std::cout << "----------------------------------" << std::endl;

    MyVector<int> v_int;
    print_vector_stats(v_int, "v_int (initial)");

    std::cout << "\nPushing back 10..." << std::endl;
    v_int.push_back(10);
    print_vector_stats(v_int, "v_int (after 1 push_back)");

    std::cout << "\nPushing back 20..." << std::endl;
    v_int.push_back(20);
    print_vector_stats(v_int, "v_int (after 2 push_back)");

    std::cout << "\nPushing back 30..." << std::endl;
    v_int.push_back(30);
    print_vector_stats(v_int, "v_int (after 3 push_back)");

    std::cout << "\nPushing back 40..." << std::endl;
    v_int.push_back(40);
    print_vector_stats(v_int, "v_int (after 4 push_back)");

    std::cout << "\nPushing back 50..." << std::endl;
    v_int.push_back(50);
    print_vector_stats(v_int, "v_int (after 5 push_back)");

    std::cout << "\nPushing back multiple elements to trigger more reallocations..." << std::endl;
    for (int i=60; i<=100; i++) {
        v_int.push_back(i);
        print_vector_stats(v_int, "v_int");
    }
    
    std::cout << "\n----------------------------------" << std::endl;
    std::cout << "MyVector Project: Testing finished." << std::endl;
    std::cout << "Exiting main..." << std::endl;

    return 0;
}
