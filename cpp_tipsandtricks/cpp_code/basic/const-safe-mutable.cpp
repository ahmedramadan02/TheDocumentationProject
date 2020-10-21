#include <iostream>
#include <vector>

class MyClass{
private:
    int size;
    mutable int value;

int getSize() const { //By having the const after the function operator, you assure that getInt won't modify any of the members
    return size;
}

int alterValues() const{
    value = 50; //it's alerable as we use the word mutable
    const_cast<MyClass*>(this)->size = 5; // also you can alter size using a const_cast()
}

};

int main(int argc, char** argv){
    
}