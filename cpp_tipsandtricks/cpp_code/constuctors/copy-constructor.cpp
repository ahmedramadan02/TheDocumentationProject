#include<iostream> 
using namespace std; 
  
class Point 
{ 
private: 
    int x, y; 
public: 

//paramterized constructor
    Point(int x1, int y1) { x = x1; y = y1; } 
  
    // Copy constructor 
    Point(const Point &otherPoint) {
        x = otherPoint.x; 
        y = otherPoint.y; 
    } 
  
    int getX() { return x; } 
    int getY() { return y; } 
}; 
  
int main(int argc, char** argv) 
{ 
    Point p1(10, 15); //paramterized constructor is called here
    Point p2 = p1;    // Copy constructor is called here
    Point p3(p2);     //Also the copy constructor is called here
  
    return 0; 
}