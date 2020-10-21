#include <iostream>

class Base {
public:
    virtual void bFunc(){ 
        std::cout << "Hello I am the Base!" << std::endl;     
    }
};


class Derived : public Base {
    void Display(){
        std::cout << "Hey from Dervied !" << std::endl;        
    }
};

int main(int argc, char** argv){
    Derived derivedObj;

    Derived* pDerived = &derivedObj;;
    Base* pBase;

    // This is up casting: Assing pointer of derived to base pointer
    // The upcasting is supported by default in Cpp
    pBase = pDerived;
    pBase->bFunc();

    // In Down Casting, the base class pointer is assigned to Derived call pointer
    //Error from the complier 
    // This is not supported you need to make a Dynamic cast
    pDerived = pBase; //Not valid
    pDerived->bFunc();
    
    //pDerived = dynamic_cast<Derived*>(pBase); //This can be achived using dynamic_cast
    //pDerived->bFunc();

    return 0;
}