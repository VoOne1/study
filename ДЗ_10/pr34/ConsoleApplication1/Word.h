#pragma once
class Word: public std::wstring
{
	int* i;
public:
	Word(std::wstring& tmp) : std::wstring(tmp), i(new int(0)) {}
	Word():std::wstring(), i(new int(0)) {}

    Word(const Word& obj) :i(new int(*(obj.i))),std::wstring(obj){}

	virtual void copy(class DB& db){}
	virtual ~Word() { delete i; }
};