#pragma once
#include "stdafx.h"

DB::DB() {}
void DB::add(Reshetov* tmp)
{
    l.push_back(tmp);
}

void DB::print()
{
    std::list <Reshetov*> ::iterator it = l.begin();
    for (; it != l.end(); ++it)
        std::cout << (*it)->getNum() << std::endl;
}

void DB::change()
{
    std::list <Reshetov*> ::iterator it = l.begin();
    for (; it != l.end(); ++it)
        (*it)->change();
}

DB::DB(DB& obj)
{
    std::list <Reshetov*> ::iterator itObj = obj.l.begin();
    for (; itObj != obj.l.end(); ++itObj)
        l.push_back((*itObj)->copy());
}
DB::~DB()
{
    std::list <Reshetov*> ::iterator it = l.begin();
    for (; it != l.end(); ++it)
        delete* it;
}

DB& DB::operator= (DB& obj) {
    if (this == &obj) return *this;
    std::list <Reshetov*> ::iterator it = l.begin();
    for (; it != l.end(); ++it)
        delete* it;
    l.clear();
    std::list <Reshetov*> ::iterator it1 = obj.l.begin();
    for (; it1 != obj.l.end(); ++it1)
        l.push_back((*it1)->copyR((*it1)->getNum()));
    return *this;
}
