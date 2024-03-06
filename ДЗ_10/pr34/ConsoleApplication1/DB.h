#pragma once
#include"stdafx.h"
template <typename T>
class DB
{
    //std::vector <T>;
    std::vector<Word*>* v;
public:
	void push(Word* w);

    void print(std::wofstream& outfile);
    DB():v(new std::vector<Word*>){}

    DB(const DB& obj) :v(new std::vector<Word*>)
    {
        std::vector<Word*>::const_iterator obj_it = obj.v->begin();
        for (; obj_it != obj.v->end(); obj_it++)
        {
            ((*obj_it)->copy(*this));
        }
    }

    DB& operator = (const DB& obj)
    {
        if (this == &obj) return *this;


        std::vector<Word*>::const_iterator it = v->begin();
        for (; it != v->end(); ++it)
            delete *it;
        v->clear();

        std::vector<Word*>::const_iterator obj_it = obj.v->begin();
        for (; obj_it != obj.v->end(); obj_it++)
        {
            ((*obj_it)->copy(*this));
        }

        return *this;
    }

    ~DB()
    {
        std::vector<Word*>::iterator it = v->begin();
        for (; it != v->end(); ++it)
            delete *it;
        v->clear();
        delete v;
    }
};