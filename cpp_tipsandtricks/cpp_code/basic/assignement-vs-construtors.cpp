#include<iostream>  
  
class MyClass  
{  
    public:  
    MyClass() {
        std::cout << "The construtor is called" << std::endl;
    }  
      
    MyClass(const MyClass &t){
        std::cout << "The construtor (copy) is called" << std::endl;
    }
    
    MyClass& operator= (const MyClass &t) 
    { 
        std:: cout<<"Assignment operator is called "<< std::endl; 
        return *this; 
    }  
};  
  
// Driver code 
int main()  
{  
    MyClass t1, t2; //For sure normal constructor os called

    t2 = t1;  //Of course the assignment operator will be called here

    //Don't be confused, the = operator will be called ONLY if we had already 
    // a constructed copy of t3, otherwise the normal constructor is called.
    MyClass t3 = t1;   

    return 0;  
}  