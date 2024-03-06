#pragma once
#include "stdafx.h"

struct Leaks {
    ~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;

int main()
{
    DB db1, db2;

    db1.add(new Reshetov_1());
    db1.add(new Reshetov_2());
    db1.add(new Reshetov_3());

    for (int i = 0; i < 2; i++)
    {
        db2.add(new Reshetov_1());
        db2.add(new Reshetov_2());
        db2.add(new Reshetov_3());
    }

    db1.change();
    db2 = db1;

    std::cout << "................db1..............." << std::endl;
    db1.print();

    std::cout << "................db2..............." << std::endl;
    db2.print();
   
    return 0;
}

