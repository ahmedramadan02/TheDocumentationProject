#include <iostream>
#include <string>
#include <exception>

class MyException : public std::exception {
private:
    int errorCode; 
    std::string errorMsg;
    std::string message;

void ConstructMessage()
{
    message = std::to_string(errorCode) + " " + errorMsg;
}

public:
explicit MyException(int code ,const std::string& msg): 
        errorMsg(msg),errorCode(code) { ConstructMessage(); }

const char *what() const throw(){
    return this->message.c_str();
}

~MyException() throw () {}

};


int main(int argc, char** argv){
    try {
        try {
            throw MyException(404, "Page not found!" );
        } catch (const std::exception& e) { 
            std::cout << "Caught " << typeid(e).name() << std::endl;
            std::cout << e.what() << std::endl; 
            // /throw e; //Slicing
            //the solution is to use throw only!, try the following
            throw;
        }
    }catch(const std::exception& e){
        std::cout << "Caught " << typeid(e).name() << std::endl;
        std::cout << e.what() << std::endl;
    }
}