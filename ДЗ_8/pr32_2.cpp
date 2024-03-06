// pr32_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "stdafx.h"

struct Leaks {
    ~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;



class Reshetov {
private:
    std::list<std::string*>* data;
public:
    Reshetov() {
        data = new std::list<std::string*>();
        data->push_back(new std::string("Hello"));
        data->push_back(new std::string("World"));
    }
    virtual void change(){}
    virtual ~Reshetov() 
    {
        std::list <std::string*> ::iterator it = data->begin();
        for (; it != data->end(); ++it)
            delete* it;
        delete data;
    }

    virtual void print() const {
        std::list <std::string*> ::iterator it = data->begin();
        for (; it != data->end(); ++it)
        {
            std::cout << **it << " ";
        }
        std::cout << std::endl;
    }
};

class Reshetov_1 : public Reshetov {
public:
    Reshetov_1():Reshetov() {}
    void change(){}
    ~Reshetov_1() {}
};

class Reshetov_2 : public Reshetov_1 {
    std::list<float>* listP;
public:
    Reshetov_2():Reshetov_1() {
        listP = new std::list<float>();
        listP->push_back(1.1);
        listP->push_back(2.2);
    }
    void change() 
    {
        std::list <float> ::iterator it = listP->begin();
        for (; it != listP->end(); it++)
            *it = 0.0F;
    }

    ~Reshetov_2() {
        delete listP;
    }

    void print() const override {
        std::list <float> ::iterator it = listP->begin();
        for (; it != listP->end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

};

template <class T>
class DB : public std::list<T> 
{
public:
    DB() {}
    void operator=(DB const& obj) =  delete;

};

int main() 
{
    DB<Reshetov*> db1;
    db1.push_back(new Reshetov_1());
    db1.push_back(new Reshetov_2());

    for (Reshetov* item : db1) {
        item->print();
    } //вывод до изменения

    for (Reshetov* item : db1) {
        item->change();
    } //изменение данных типа Reshetov_2

    DB<Reshetov*> db2 = db1;
    //db1 = db2;
    for (Reshetov* item : db1) {
        item->print();
    }//вывод после изменения

    // Вывод db2
    for (Reshetov* item : db2) {
        item->print();
    }


    // Очистка памяти
    for (Reshetov* item : db1) {
        delete item;
    }
    
    return 0;
}