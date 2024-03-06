#pragma once
#include "stdafx.h"

class DB
{
    std::list <Reshetov*> l;
public:
    void add(Reshetov* tmp);
    void print();
    void change();

    DB();
    DB(DB& obj);
    DB& operator= (DB& obj);
    ~DB();
};
