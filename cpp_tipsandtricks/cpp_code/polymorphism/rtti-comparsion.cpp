#include <iostream>
#include <typeinfo>

typedef int MyInt_t;

int main() {
    // the == operator
    (typeid(int) == typeid(MyInt_t)) ? std::cout << "same type\n" : std::cout << "differnet type\n";

    // the != operator
    (typeid(int) != typeid(int*)) ? std::cout << "differnet type" : std::cout << "same type";
}