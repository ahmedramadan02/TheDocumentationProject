#include <iostream>
#include <string>

class Type{
private:
    int num;

public:    
    //We have here two constructors
    explicit Type(int i) { std::cout << i << std::endl; }
    explicit Type(char* c) { std::cout << c << std::endl; }
    explicit Type(std::string s){ std::cout << s << std::endl; }

};

void foo(const Type& local){

}

int main(int argc, char** argv){

    //Type typeObj = 1; //Compilation error, no type conversion happens
    //Type anotherObj = 'D'; //Compilation error
    //foo('C'); //Compilation error

    //In order to make it work, you should call the construtor explicitly
    Type type1 = Type(1);
    Type type2 = static_cast<Type>("string");
    Type type3('c');

    return 0;
}