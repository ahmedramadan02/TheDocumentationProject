#include<iostream> 
using namespace std; 
  
class Point 
{ 
private: 
    int x, y;
public: 

    Point(int x1, int y1) :x(x1), y(y1){ }
    int getX() { return x; } 
    int getY() { return y; } 

    void setX(int val) { x = val; } 
    void setY(int val) { y = val; }

}; 
  
int main(int argc, char** argv) 
{ 
    Point p1(10, 15);
    Point p2 =p1; //A deep copy is taken from P1 set to P2
    
    std::cout << "Changing X:" << std::endl;    
    p1.setX(30); //When we modify x in P1, X in P2 won't affected
    cout << "X in P2: "<<p2.getX() << std::endl;
    cout << "X in P1: "<< p1.getX() << std::endl;
  
    return 0; 
}

//Output
/*
Changing X:
X in P2: 10
X in P1: 30
*/