#include<iostream>

class NonVirtualBase{
    void foo(){}
};

class VirtualBase{
    virtual void foo(){}
};
 

int main(int argc, char** argv){
    
    NonVirtualBase b1;
    VirtualBase b2;

    std::cout << "The size of the a normal classs: " << sizeof(b1) << " Bytes" << std::endl;
    std::cout << "The size of a class has at least one virtual function: " << sizeof(b2) << " Bytes" << std::endl;

    return 0;
}

//Output
// The size of the a normal classs: 1 Bytes
// The size of a class has at least one virtual function: 8 Bytes