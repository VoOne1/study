#pragma once
#include "stdafx.h"

int Reshetov_3::getNum() { return testField; };
Reshetov* Reshetov_3::copy() { return new Reshetov_3(*this); }
void Reshetov_3::change() { *d = 3.142; testField = 31; }

Reshetov* Reshetov_3::copyR(int tmp) { return new Reshetov_3(tmp); }
Reshetov_3::Reshetov_3() : Reshetov_2(),d(new double(2.718)){}
Reshetov_3::Reshetov_3(int tmp) : Reshetov_2(tmp), d(new double(2.718)) {}
Reshetov_3::Reshetov_3(const Reshetov_3& obj) : Reshetov_2(obj), d (new double(*obj.d)){}
Reshetov_3& Reshetov_3:: operator=(const Reshetov_3& obj)
{
	if (this == &obj) return *this;
	*d = *obj.d;
	return *this;
}
Reshetov_3::~Reshetov_3() { delete d; }
