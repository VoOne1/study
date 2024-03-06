#pragma once
#include"stdafx.h"
class Reshetov {
private:
    std::string* data;
public:
    // Эта версия функции не работает потому что класс DB неизвестный
    //virtual void (class DB& obj, typename DB& db, std::list<Reshetov*>::iterator it)
    /*{
        delete* it;
        it = db.erase(it);
    }*/

    virtual void copy(class DB& obj, std::list<Reshetov*>& db, std::list<Reshetov*>::iterator& it) 
    { 
        delete* it;
        it = db.erase(it); 
    }
    //virtual void copy(class DB& obj, std::list<Reshetov*>& db, std::list<Reshetov*>::iterator& it) { };
    // ошибка

    virtual void clear( std::list<Reshetov*>::iterator it) {};

    Reshetov():data(new std::string(typeid(this).name())){}
    Reshetov(const Reshetov& obj);

    virtual void change() {}
    

    virtual ~Reshetov()
    {
        delete data;
    }

    virtual void print() const 
    {
        std::cout << *data << '\n';
    }
};