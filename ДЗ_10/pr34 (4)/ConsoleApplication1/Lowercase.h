#pragma once
#include "stdafx.h"
class Lowercase :public Word
{

public:
	Lowercase(std::wstring& tmp) : Word(tmp){}
	Lowercase(const Uppercase& obj) :Word(obj)
	{}
	Lowercase() : Word(){}
	void copyUpper(class DB& db);
	~Lowercase() {}
};