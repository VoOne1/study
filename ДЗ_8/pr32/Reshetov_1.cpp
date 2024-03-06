#pragma once
#include "stdafx.h"

void Reshetov_1::change()
{
	testField = 10;
	for (int i = 0; i < 10; i++)
		c[i] = '_';
}
int Reshetov_1::getNum() { return testField; }

Reshetov* Reshetov_1::copyR(int tmp) { return new Reshetov_1(tmp); }

Reshetov_1::Reshetov_1() : Reshetov(), c("Hi_World"), l1(new std::list <int*>)
{
	for (int i = 0; i < 10; i++)
		l1->push_back(new int(0));
}
Reshetov_1::Reshetov_1(int tmp) : Reshetov(tmp), c("Hi_World"),l1(new std::list <int*>)
{
	for (int i = 0; i < 10; i++)
		l1->push_back(new int(0));
}
Reshetov_1::Reshetov_1(const Reshetov_1& obj): l1(new std::list <int*>)
{
	std::list <int*> ::iterator obj_It = obj.l1->begin();
	for (; obj_It != obj.l1->end(); ++obj_It)
		l1->push_back(new int(**obj_It));
	for (int i = 0; i < 10; i++)
		c[i] = obj.c[i];
}

Reshetov_1& Reshetov_1:: operator=(const Reshetov_1 &obj)
{
	if (this == &obj) return *this;
	std::list <int*> ::iterator obj_It = obj.l1->begin();
	std::list <int*> ::iterator it = l1->begin();
	for (; obj_It != obj.l1->end(); ++it, ++obj_It)
		**it = **obj_It;
	for (int i = 0; i < 10; i++)
		c[i] = obj.c[i];
	return *this;
}
Reshetov* Reshetov_1::copy(){ return new Reshetov_1(*this);}
Reshetov_1::~Reshetov_1()
{
	std::list <int*> ::iterator it = l1->begin();
	for (; it != l1->end(); ++it)
		delete* it;
	delete l1;
}
