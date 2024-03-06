#pragma once
#include"stdafx.h"
class Reshetov {
private:
    std::list<std::string*>* data;
public:
    virtual Reshetov* copy() { return new Reshetov(*this); }
    Reshetov():data (new std::list<std::string*>())
    {
        data->push_back(new std::string("Hello"));
        data->push_back(new std::string("World"));
    }
    Reshetov(const Reshetov& obj);
    virtual void change() {}
    virtual ~Reshetov()
    {
        std::list <std::string*> ::iterator it = data->begin();
        for (; it != data->end(); ++it)
            delete* it;
        delete data;
    }

    virtual void print() const 
    {
        std::list <std::string*> ::iterator it = data->begin();
        for (; it != data->end(); ++it)
        {
            std::cout << **it << " ";
        }
        std::cout << std::endl;
    }
};