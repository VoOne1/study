#pragma once
#include"stdafx.h"


class DB : private std::list<Reshetov*>
{

public:

	void push(Reshetov*);
    DB() :std::list<Reshetov*>() {}
//
    ~DB()
    {
        std::list<Reshetov*>::iterator it = this->begin();
        for (; it != this->end(); ++it)
            delete *it;
    }
//
    // Конструктор копирования
    DB( DB& obj)
    {
        std::list<Reshetov*>::iterator obj_it = obj.begin();
        for (; obj_it != obj.end(); ++obj_it)
            (*obj_it)->copy(*this, obj, obj_it);
    }

    DB* copy() { return new DB(*this); }
    void print();

    DB& operator = ( DB& obj)
    {
        if (this == &obj) return *this;

        
        DB::iterator it = this->begin();
        for (; it != this->end(); ++it)
            delete* it;
        this->clear();
        
        DB::iterator obj_it = obj.begin();
        for (; obj_it != obj.end(); )
        {
            ((*obj_it)->copy(*this, obj, obj_it));         
        }

        return *this;
    }
};