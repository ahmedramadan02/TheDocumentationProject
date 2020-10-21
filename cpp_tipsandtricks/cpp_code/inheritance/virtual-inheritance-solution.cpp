#include <iostream>

class A { 
public:
    void foo() { std::cout << "Hello from A!"; }  
};

class B : public virtual A {  };
class C : public virtual A {  };

class D : public B, public C { };

int main(int argc, char** argv){

    D dObj;
    dObj.foo(); //D::foo is not ambiguous anymore

    return 0;
}