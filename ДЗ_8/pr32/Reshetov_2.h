#pragma once
#include "stdafx.h"


class Reshetov_2 :public Reshetov_1
{
	float* f;
public:
	void change() override;
	Reshetov* copyR(int num) override;
	int getNum() override;

	Reshetov_2(const Reshetov_2& obj);
	Reshetov_2();
	Reshetov_2(int num);
	Reshetov_2& operator=(const Reshetov_2& obj);
	Reshetov* copy() override;
	~Reshetov_2();
};