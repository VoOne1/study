#pragma once
#include"stdafx.h"
#include <codecvt>   // для работы с фасетом codecvt_utf8 локали

class Vladimir : public Reshetov
{
	std::vector<std::wstring> m_txt1;
public:
    Reshetov* copy()
	{
		return (new Vladimir(*this));
	}
	void print(std::wostream& os);
	void erase(std::vector<Reshetov*>& db, std::vector<Reshetov*>::iterator& it, bool& ReshetovFlag, bool& VladimirFlag);
	Vladimir(const Vladimir& obj): Reshetov(obj), m_txt1(obj.m_txt1) {}
	Vladimir():Reshetov()
	{
		using  std::locale;

		const locale utf8_locale = locale(locale(), new std::codecvt_utf8<wchar_t>());


		std::wifstream infile(L"text.txt");      // создать объект класса wifstream
		infile.imbue(utf8_locale);               // связываем наш поток с нужной локалью

		std::wstring tmp;

		int i = 0;
		while (std::getline(infile, tmp))
		{
			if (i > 15) m_txt1.push_back(tmp);
			i++;
		}

		infile.clear();
	}

	~Vladimir() {}


};