#include <iostream>

int main(int argc, char** argv){

    
    int inumber = 0;

    // In some compliers, a warning for the incompatible types will raised
    float fnumber = 3.557f;
    //Then use static casting
    inumber = static_cast<int>(fnumber);

    //Here is another example
    int  iNum = 85;
    char c = iNum; // this should give warning as well
    c = static_cast<char>(iNum);

    return 0;
}