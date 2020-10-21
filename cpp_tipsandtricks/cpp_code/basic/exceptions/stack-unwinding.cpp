#include <iostream>


void func1( int x  )
{
    char* pleak = new char[1024]; 
    std::cout << "func1 start" << std::endl;

    if ( x ) throw std::runtime_error( "error" );
    
    delete [] pleak; //possible memory leadk
    std::cout << "func1 end" << std::endl; //not reached
}

void func2()
{
    char* pleak = new char[1024];
    std::cout << "func2 start" << std::endl;

    func1( 1 );

    delete [] pleak;  //Possible memory leak
    std::cout << "func2 end" << std::endl;//not reached
}

int main()
{
    try
    {
        func2();
    }
    catch ( const std::exception& e )
    {
        std::cout << "Catch clause";
    }

    return 0;
}

//Output
/*

*/