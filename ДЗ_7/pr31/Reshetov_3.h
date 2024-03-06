#pragma once
#include "stdafx.h"


class Reshetov_3 :public Reshetov_2
{
	double* d;
public:
	void change() override;
	Reshetov* copyR(int tmp) override;
	int getNum() override;

	Reshetov_3(const Reshetov_3& obj);
	Reshetov_3();
	Reshetov_3(int tmp);
	Reshetov_3& operator=(const Reshetov_3& obj);
	Reshetov* copy() override;
	~Reshetov_3();
};