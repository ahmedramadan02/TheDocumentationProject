#include <iostream>

template<class T>
void Display (T); 

class A
{
public:
    A(int n = 2) : m_i(n) { 
        Display("A Construction"); 
    }

    ~A() { 
        Display("A Destruction");
        Display(m_i);
     }

protected:
    int m_i;
};

class B : public A
{
public:
    B(int n) : m_a1(m_i + 1), m_a2(n) { 
        Display("B Construction");
    }

public:
    ~B()
    {
        Display("B Destruction");
        Display(m_i);
        --m_i;
    }

private:
    A m_a1;
    A m_a2;
};

class C : public virtual A {


};

template<class T>
void Display (T msg) {
    std::cout << msg << std::endl;    
}

int main(int argc, char** argv)
{
    { B b(5); }

    std::cout << std::endl;

    return 0;
}

/* Output:
 * A Construction
 * A Construction
 * A Construction
 * B Construction
 * B Destruction
 * 2
 * A Destruction
 * 5
 * A Destruction
 * 3
 * A Destruction
 * 1
*/
