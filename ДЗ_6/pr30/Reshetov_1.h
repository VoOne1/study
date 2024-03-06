#pragma once
#include "stdafx.h"
class Reshetov_1 :public Reshetov
{
	float f;
	float* fd;
public:
	void copy(std::vector<Reshetov*>& v){}
	Reshetov_1& operator = (const Reshetov_1& obj)
	{
		if (this == &obj) return *this;

		*fd = *obj.fd;

		return *this;
	}
	void print();
	Reshetov_1() :fd(new float(3.14F)), f(2.71F) {}
	Reshetov_1(const Reshetov_1& obj) :Reshetov(obj), fd(new float(3.14F)), f(obj.f)
	{
		*fd = *obj.fd; 
	}
	~Reshetov_1() { delete fd; }
};