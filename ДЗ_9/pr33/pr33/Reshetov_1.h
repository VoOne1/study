#pragma once
#include"stdafx.h"

class Reshetov_1:public Reshetov {
private:
    std::string* data1;
public:
    virtual void copy(class DB& obj, std::list<Reshetov*>& db, std::list<Reshetov*>::iterator it);
    Reshetov_1():Reshetov(), data1 (new std::string(typeid(this).name())){}
    Reshetov_1(const Reshetov_1& obj) : Reshetov(obj), data1(new std::string( *(obj.data1) )){};

    void change() {}

    ~Reshetov_1()
    {
        delete data1;
    }

    void print() const 
    {
        std::cout << *data1 << '\n';
    }

    
};