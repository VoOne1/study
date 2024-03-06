#include "stdafx.h"

 Reshetov::Reshetov(const Reshetov& obj) : data(new std::list<std::string*>())
{
    std::list <std::string*> ::iterator obj_It = obj.data->begin();
    for (; obj_It != obj.data->end(); ++obj_It)
        data->push_back(new std::string(**obj_It));
}
