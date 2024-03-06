#pragma once
#include "stdafx.h"
void DB::push(Reshetov* obj) 
{
	this->push_back(obj);
}
void DB::print()
{
	std::list<Reshetov*>::iterator obj_it = this->begin();
	for (; obj_it != this->end(); ++obj_it)
		(**obj_it).print();
}