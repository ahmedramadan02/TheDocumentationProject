
#include <iostream>
#include <Exception>

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
        throw MyException(404, "Page not found!" );
    } catch (const std::exception e) { //Slicing of for the MyExcpetion object
        std::cout << "Caught " << typeid(e).name() << std::endl;
        std::cout << e.what() << std::endl; 
    }
}

//Output
// => Caught Std exception