#include <algorithm>
#include <iostream>
#include <list>

struct P
{
    //Define a functor
    bool operator()(const int &n) const
    {
        return (n % 3 == 0);
    }
};

int main(int argc, char** argv)
{
    std::list <int>::iterator pend;
    std::list<int> l({ 5, 2, 6, 1, 13, 9, 19 });
    std::cout << "Size before: "<< l.size() << std::endl;
    pend = std::remove_if(l.begin(), l.end(), P());

    std::cout << "Size after: "<< l.size() << std::endl;
    std::cout << "After remove_if : "; 
    for ( std :: list<int> :: iterator q=l.begin(); q != pend; ++q) 
        std :: cout << ' ' << *q;
    //Note: It reports that the size still 7 while there are only 5 elements

    return 0;
} 

//Output
//Size before: 7
//Size after: 7
//After remove_if :  5 2 1 13 19