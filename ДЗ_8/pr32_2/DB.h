#pragma once
#include"stdafx.h"

template <class T>
class DB : public std::list<T>
{
    std::list<T> t;
public:
 
    void operator=(DB const& obj) = delete;
    DB() :std::list<T>() {}

    ~DB<T>()
    {
        typename DB<T>::const_iterator it = this->begin();
        for (; it != this->end(); ++it)
            delete* it;
    }

    // Конструктор копирования
    DB<T>(const DB<T>& obj)
    {
        typename DB<T>::const_iterator obj_It = obj.begin();
        for (; obj_It != obj.end(); ++obj_It)
            this->push_back((*obj_It)->copy());
    }

};