// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<fstream>
#include<string>
#include<set>
#include<map>
#include<list>
#include<vector> 
#include<algorithm>
#include<cmath>
#include <tchar.h>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

struct Leaks {
    ~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;

class Part
{

protected:

    Part() {}

    template <typename T>
    friend void add(std::vector<Part*>& v);

public:
   virtual void print()
        {
           std::cout << typeid(*this).name() << std::endl;
        }
};

class Assembling: protected Part
{

protected:

    Assembling() {}

    template <typename T>
    friend void add(std::vector<Part*>& v);

public:
    void print()
    {
        std::cout << typeid(*this).name() << std::endl;
    }

};

template <typename T>
void add(std::vector<Part*>& v)
{
    v.push_back(new T);

}

int main()
{
    std::vector<Part*> p;

    for (int i = 0; i < 10; i++)
        {
            (i <= 5) ? add<Part>(p): add<Assembling>(p);
        }
        
    for (int i = 0; i < 10; i++)
        {
            p.at(i)->print();
        }
    for (int i = 0; i < p.size(); i++)
    {
        delete p.at(i);
    }
}
//class Base
//{
//    int field1 = 0;
//protected:
//    
//public:
//    Base() {}
//    virtual void print()
//    {
//        std::cout << "Base" << std::endl;
//    }
//
//    Base(const Base& obj):field1(obj.field1){}
//
//    virtual Base* copy()
//    {
//        return new Base(*this);
//    }
//
//};
//
//class Derived:public Base
//{
//    int field2 = 0;
//protected:
//
//public:
//    Derived() {}
//    
//    void print()
//    {
//        std::cout << "Derived" << std::endl;
//    }
//    Derived(const Derived& obj) :field2(obj.field2) {}
//     Base* copy()
//    {
//        return new Derived(*this);
//    }
//
//};
//
//template <typename T>
//void add(std::vector<Base*>& v,  T* t)
//{
//    v.push_back(t->copy());
//    delete t;
//}
//
//int main()
//{
//    std::vector<Base*> p;
//
//    for (int i = 0; i < 10; i++)
//    {
//        (i%2 == 0) ? add<Base>(p, new Base): add<Derived>(p, new Derived);
//    }
//
//    for (int i = 0; i < 10; i++)
//    {
//        p.at(i)->print();
//    }
//
//   for (int i = 0; i < p.size(); i++)
//        {
//            delete p.at(i);
//        }
//
//}
