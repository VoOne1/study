#pragma once
#include "stdafx.h"

int Reshetov_2::getNum() { return testField; }
Reshetov* Reshetov_2::copy() { return new Reshetov_2(*this); }
void Reshetov_2::change() { *f = 2.228F; testField = 28; }

Reshetov* Reshetov_2::copyR(int num) { return new Reshetov_2(num); }
Reshetov_2::Reshetov_2() : Reshetov_1(),f(new float(1.337F)){}
Reshetov_2::Reshetov_2(int num) : Reshetov_1(num), f(new float(1.337F)){}
Reshetov_2::Reshetov_2(const Reshetov_2& obj) : Reshetov_1(obj), f(new float(*obj.f)){}
Reshetov_2& Reshetov_2:: operator=(const Reshetov_2& obj)
{
	if (this == &obj) return *this;
	*f = *obj.f;
	return *this;
}
Reshetov_2::~Reshetov_2() { delete f; }
