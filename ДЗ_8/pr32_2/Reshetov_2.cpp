#pragma once
#include "stdafx.h"
Reshetov_2::Reshetov_2() :Reshetov_1() {
    listP = new std::list<float>();
    listP->push_back(1.1);
    listP->push_back(2.2);
}
Reshetov_2::Reshetov_2(const Reshetov_2& obj) : Reshetov_1(obj), listP(new std::list<float>())
{
    std::list <float> ::iterator obj_It = obj.listP->begin();
    for (; obj_It != obj.listP->end(); ++obj_It)
        listP->push_back(*obj_It);
}

void Reshetov_2::change()
{
    std::list <float> ::iterator it = listP->begin();
    for (; it != listP->end(); it++)
        *it = 0.0F;
}

Reshetov_2::~Reshetov_2()
{
    delete listP;
}

void Reshetov_2::print() const  {
    std::list <float> ::iterator it = listP->begin();
    for (; it != listP->end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}
