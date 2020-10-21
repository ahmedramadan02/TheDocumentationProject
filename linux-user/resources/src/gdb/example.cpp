#include <stdio.h>

int func2(){
    return 0;
}

void func1(){
    int r = func2();
}


int main(int argc, char** argv) {
    int i;
    for(i=0; i < 10; i++) 
        puts("Hello, world!\n");
 
    func1();

    return 0; 
}