#include <iostream>

class A {
    int iNum = 0;
    mutable int iNum_m = 0;

public:
    void Display() const{
        iNum = 50; //This is not allowed, iNum is readonly in this function
        // You can change the value because we used const_cast
        (const_cast<A*>(this))->iNum = 50; 

        //You can change the value as it's tagged mutable
        iNum_m = 50; 

        std::cout << this->iNum << ", " << this->iNum_m;
    }
};

int main(int argc, char** argv){
   
    A a;
    a.Display();

    return 0;
}