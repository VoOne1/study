#pragma once
#include "stdafx.h"
class Uppercase:public Word
{
public:
	Uppercase(std::wstring& tmp): Word(tmp){}
	Uppercase(const Uppercase& obj) :Word(obj){}
	Uppercase() : Word(){}
	
	void copyUpper(class DB& db);

	~Uppercase(){}


};