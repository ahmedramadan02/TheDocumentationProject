 
#include <iostream>
#include <string>
#include <exception>

class MyException : public std::exception {
private:
    int *errorCode; //Potential Memory leak, use shared pointer instead, RAII-type wrappers to manage all resources
    std::string* errorMsg;

public:
explicit MyException(int code ,std::string msg){
        errorCode = new int(code);
        errorMsg = new std::string(msg);
}

// Potential leak! When a constructor emits an exception,
// the destructor will not be invoked.
~MyException() {
    delete this->errorCode; 
    delete errorMsg;
}
};


int main(int argc, char** argv){
    try {
        throw MyException(404, "Page not found!" );
    } catch (const MyException& e) { 
        std::cout << "Caught " << typeid(e).name() << std::endl;
    }
}