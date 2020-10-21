#include <iostream>

class Type{
private:
    int num;

public:    
    //We have here two constructors
    Type(int i) { std::cout << i; }
    Type(char* c) { std::cout << c; }
    Type(std::string s){ std::cout << s; }

};

void foo(const Type& local){

}

int main(int argc, char** argv){

    Type typeObj = 1; //here 1 is implicitly converted to Type object, equivalent to Type(1) 
    Type anotherObj = 'D'; // the same here the character D is converted to A('D') class
    foo('C'); //The same here, C is converted to Type class

    return 0;
}