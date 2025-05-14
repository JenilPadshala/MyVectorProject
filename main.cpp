#include <iostream>
#include "MyVector.hpp"

int main(){
    std::cout << "MyVector Project: Testing started." << std::endl;
    std::cout << "----------------------------------" << std::endl;

    std::cout << "Creating v1 (MyVector<int>)..." << std::endl;
    MyVector<int> v1;
    std::cout << "v1.size(): " << v1.size() << std::endl;
    std::cout << "v1.capacity(): " << v1.capacity() << std::endl;
    std::cout << "v1.empty(): " << (v1.empty() ? "true" : "false") << std::endl;
    std::cout << "\n----------------------------------" << std::endl;
    std::cout << "Creating v2 (MyVector<double>) in a local scope..." << std::endl;
    {
        MyVector<double> v2;
        std::cout << "v2.size(): " << v2.size() << std::endl;         // Expected: 0
        std::cout << "v2.capacity(): " << v2.capacity() << std::endl; // Expected: 0
        std::cout << "v2.empty(): " << (v2.empty() ? "true" : "false") << std::endl; // Expected: true
        std::cout << "Exiting local scope for v2..." << std::endl;
    } 
    std::cout << "Local scope for v2 exited." << std::endl;
    
    std::cout << "\n----------------------------------" << std::endl;
    std::cout << "MyVector Project: Testing finished." << std::endl;
    std::cout << "Exiting main..." << std::endl;

    return 0;
}
