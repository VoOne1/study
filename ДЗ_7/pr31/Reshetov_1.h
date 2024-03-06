#pragma once
#include "stdafx.h"

class Reshetov_1 :public Reshetov
{
	std::list <int*>* l1;
	char c[10];
public:
	void change() override;
	Reshetov* copyR(int tmp) override;
	int getNum() override;

	Reshetov_1(const Reshetov_1& obj);
	Reshetov_1();
	Reshetov_1(int tmp);
	Reshetov_1& operator=(const Reshetov_1& obj);
	Reshetov* copy() override;
	~Reshetov_1();
};