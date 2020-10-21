#include <iostream>

int main(int argc, char** argv){

    //It's little bit dangerous to use the reinterpret
    //As you can cast any type to any other type.
    int num = 1000000;
    char* pc = num; //It's not allowed to make this conversion implicitly
    char* pc = reinterpret_cast<char*>(num); //you can achieve using reinterpret_cast

    //the reinterpret_cast, can convert from any pointer to any other pointer type
    int* pInt = new int(65); 
    char* pChar = pInt; //It's not allowed to make this conversion
    char* pChar = reinterpret_cast<char*>(pInt); 

    return 0;
}