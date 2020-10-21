#include <iostream>
#include <string>

class Employee {
private:
    std::string eName;
    float salary;

public:
    Employee(std::string _name, int _salary) : eName(_name), salary(_salary) { }
    virtual void Display(){
        std::cout << this->eName << std::endl;
        std::cout << this->salary << std::endl;
    }

};


class Programmer : public Employee {
private:
    std::string skills;

public:
    Programmer(std::string name, int salary , std::string _skill) : Employee(name, salary), skills(_skill){ }
    void Display(){
        Employee::Display();
        std::cout << this->skills << std::endl;
    }
};

// Global method, Base class object is passed by value 
void someFunc (Employee obj) 
{ 
    obj.Display(); 
} 
  

int main(int argc, char** argv){
    Programmer* pProgrammer = nullptr;
    Employee* pEmp = nullptr;
    
    Employee e = Employee("Ahmed", 5000);
    //e.Display();

    Programmer p = Programmer("Mohamed", 7000, "C++");
    //p.Display();

    // Setting a Derived class object to Base class object is allowed
    p = e;
    e.Display();

    //The reverse is not allowed, as "A Programmer is an Employee, but not every Employee is a Programmmer"
    //std::cout << "P of size: " << sizeof(p)  << " Bytes can't be assigned to e of size: " << sizeof(e) << " Bytes\n";
    e = p; //this is not allowed, slice off !, in some compliers it causes error
    someFunc(p); // Slice-off also happens

    //Upcasting: Assign Derived class pointer to Base class pointer
    pProgrammer = &p;
    pEmp = pProgrammer;
    pEmp->Display();

    //Downcasting (is not allowed in C++), you can achieve using the dynamic cast
    //pProgrammer = pEmp; //Error: downcast is not allowed, you can achieve using the dynamic_cast

   return 0;
}