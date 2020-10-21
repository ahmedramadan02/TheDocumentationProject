#include <iostream>

class A { 
public:
    void foo(); 
};

class B : public A {  };
class C : public A {  };

class D : public B, public C { };

int main(int argc, char** argv){

    D dObj;
    dObj.foo(); //D::foo is ambiguous!

    return 0;
}