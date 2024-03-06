#pragma once
#include"stdafx.h"
class Reshetov_2 :public Reshetov_1 {
private:
    std::string* data2;
public:
    virtual void copy(class DB& obj, std::list<Reshetov*>& db, std::list<Reshetov*>::iterator& it);
    Reshetov_2() :Reshetov_1(), data2(new std::string(typeid(*this).name())) {}
    Reshetov_2(const Reshetov_2& obj) : Reshetov_1(obj), data2(new std::string(*(obj.data2))) {};

    void change() {}

    ~Reshetov_2()
    {
        delete data2;
    }

    void print() const
    {
        std::cout << *data2 << '\n';
    }


};