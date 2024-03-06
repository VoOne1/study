#pragma once
#include"stdafx.h"
template <typename T>
class DB
{
    std::vector <T> v;
public:
    void add(Reshetov* tmp)
    {
        v.push_back((tmp->copy()));
        delete tmp;
    }

    friend std::wostream& operator<<(std::wostream& os, const DB& db) 
    {
        std::vector<Reshetov*>::const_iterator obj_it = db.v.begin();
        for (; obj_it != db.v.end(); ++obj_it)
            (*obj_it)->print(os);

        return os;
    }

    void erase()
    {
        bool ReshetovFlag = 0;
        bool VladimirFlag = 0;

        std::vector<Reshetov*>::iterator obj_it = this->v.begin();
        for (; obj_it != this->v.end();)
            (*obj_it)->erase(this->v, obj_it, ReshetovFlag, VladimirFlag);

    }

    DB() 
    {}
   DB(const DB& obj)
   {
       std::vector<Reshetov*>::const_iterator obj_it = obj.v.begin();
       for (; obj_it != obj.v.end(); obj_it++)
       {
           this->v.push_back(((*obj_it)->copy()));
       }
   }

    DB& operator = (const DB& obj)
    {
        if (this == &obj) return *this;


        std::vector<Reshetov*>::iterator it = this->v.begin();
        for (; it != this->v.end(); it++)
        {
            delete* it;
        }
        this->v.clear();

        std::vector<Reshetov*>::const_iterator obj_it = obj.v.begin();
        for (; obj_it != obj.v.end(); obj_it++)
        {
            this->v.push_back(((*obj_it)->copy()));
        }

        return *this;
    }


    ~DB()
    {
        std::vector<Reshetov*>::iterator it = v.begin();
        for (; it != v.end(); ++it)
            delete* it;
        v.clear();
    }
};