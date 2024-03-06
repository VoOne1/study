#pragma once
#include "stdafx.h"
class Reshetov_2 :public Reshetov_1
{
	int i;
	int* id;
public:
	void copy(std::vector<Reshetov*>& v);
	Reshetov_2& operator = (const Reshetov_2& obj)
	{
		if (this == &obj) return *this;
		Reshetov_1::operator=(obj);

		*id = *obj.id;

		return *this;
	}
	void print();
	Reshetov_2() :id(new int(1)), i(2) {}
	Reshetov_2(const Reshetov_2& obj) :Reshetov_1(obj), id(new int(0)),i(obj.i) { *id = *obj.id; }
	~Reshetov_2() { delete id; }
};