#pragma once

class Reshetov
{
protected:
	int testField;
public:
	Reshetov();
	Reshetov(int tmp);
	virtual ~Reshetov();
	virtual Reshetov* copy() = 0;
	virtual Reshetov* copyR(int tmp) = 0;
	virtual void change() = 0;
	virtual int getNum() = 0;
};