 
#include <iostream>
#include <string>
#include <exception>

class MyException : public std::exception {
private:
    int errorCode; 
    std::string errorMsg;



public:
explicit MyException(int code ,const std::string& msg): 
        errorMsg(msg),errorCode(code) {  }

const char *what() const throw(){
    std::string message = std::to_string(errorCode) + " " + errorMsg;
    return message.c_str();
}

~MyException() throw () {}

};


int main(int argc, char** argv){
    try {
        throw MyException(404, "Page not found!" );
    } catch (const std::exception& e) { 
        std::cout << "Caught " << typeid(e).name() << std::endl;
        std::cout << e.what() << std::endl; 
    }
}

//Output
// Caught 11MyException
// É$X╗ //garbage