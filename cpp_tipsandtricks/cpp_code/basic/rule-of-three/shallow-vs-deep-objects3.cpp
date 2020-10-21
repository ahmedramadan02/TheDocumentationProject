#include<iostream> 
using namespace std; 
  
class Point 
{ 
private: 
    int x, y;
    int* p; 
public: 
    Point(){}
    Point(int x1, int y1, int val) { 
        x = x1; 
        y = y1;
        //Init p
        p = new int;
        *p = val;
     } 
   
    Point(const Point &otherPoint) {
        x = otherPoint.x; 
        y = otherPoint.y;

        //Init P
        p = new int;
        *p = *(otherPoint.p);
    } 

    int getX() { return x; } 
    int getY() { return y; } 

    void setX(int val) { x = val; } 
    void setY(int val) { y = val; }

    void setP(int val) { *p = val; } 
    int getP() { return *p; } 
}; 
  
int main(int argc, char** argv) 
{ 
    Point p1(10, 15, 20);
    Point p2 =p1;   

    std::cout << "Changing X:" << std::endl;    
    p1.setX(30); //When we modify x in P1, X in P2 won't affected
    cout << "X in P2: "<<p2.getX() << std::endl;
    cout << "X in P1: "<< p1.getX() << std::endl;

    std::cout << "Changing Poiner P:" << std::endl;    
    p1.setP(30);
    cout << "P Pointer in P2: "<< p2.getP() << std::endl;
    cout << "P Pointer in P1: "<< p1.getP() << std::endl;
  
    return 0; 
}

//Output
/*
Changing X:
X in P2: 10
X in P1: 30

Changing Poiner P:
P Pointer in P2: 20
P Pointer in P1: 30
*/