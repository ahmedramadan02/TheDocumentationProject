#include <iostream>
#include <vector>

class MyClass{
private:
    int size;
    std::vector<int> vec;
MyClass(){
    this->size = 3;
    this->vec.push_back( 3 );
    this->vec.push_back( 4 );
    this->vec.push_back( 8 );
}

int getSize() const { //By having the const after the function operator, you assure that getInt won't modify any of the members
    return size;
}

void alterSize() const{
    this->size = 4; //Compliation error
}

int getValue(int index)const{
    return vec[index];
}

//Use const iterators with const safe function as a good practice
void alterVector() const{
    for ( std::vector<int>::const_iterator itr = vec.begin(), end = vec.end(); itr != end; ++itr ){
            *itr = 0; //compliation error
            // just print out the values...
            std::cout<< *itr <<std::endl;
    }
}

//FYI: If you are passing const vectors, you can access them only with const iterators
static void printOtherConstVector (const std::vector<std::int>& _vec){
        for ( std::vector<std::int>::const_iterator itr = _vec.begin(), end = _vec.end(); itr != end; ++itr ){
            // just print out the values...
            std::cout<< *itr <<std::endl;
    }
}

};

int main(int argc, char** argv){
    
}