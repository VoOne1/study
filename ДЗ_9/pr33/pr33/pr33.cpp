// pr33.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdafx.h"
struct Leaks {
    ~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;

int main()
{
    DB d1;
    DB d2;
    d1.push(new Reshetov_1);
    d1.push(new Reshetov);
    
    d1.push(new Reshetov_2);
    d1.push(new Reshetov_2);

    d2 = d1;
    //d1 = d2;

    d1.print();
    std::cout << "----------" << '\n';

    d2.print();
    
    return 0;
}
