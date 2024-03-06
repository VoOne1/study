#pragma once
#include"stdafx.h"

class Reshetov
{
public:
	Reshetov() {}
	virtual ~Reshetov() {};
	virtual void print() = 0;
	virtual void copy(std::vector<Reshetov*>& v) = 0;
};