class A
{
private:
    int x;

public:
    A(int x = 1): x(x) {} // user-defined default constructor
};
 
class B: A
{
    // B::B() is implicitly-defined, calls A::A()
};
 
class C
{
    A a;
    // C::C() is implicitly-defined, calls A::A()
};
 
class D: A
{
public:
    D(int y): A(y) {}
    // D::D() is not declared because another constructor exists
};
 
class E: A
{
public:
    E(int y): A(y) {}
    E() = default; // explicitly defaulted, calls A::A()
};
 
class F
{
    int& ref; // reference member
    const int c; // const member
    // F::F() is implicitly defined as deleted
};
 
int main()
{
    A a;
    B b;
    C c;
//  D d; // compilation error
    E e;
//  F f; // compilation error
}