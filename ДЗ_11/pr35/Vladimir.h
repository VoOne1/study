#pragma once
#include "stdafx.h"
class Vladimir :public Reshetov
{
	std::vector<std::wstring> m_txt;
public:
	Vladimir(std::wstring& tmp){}
	Vladimir(const Reshetov& obj)
	{}
	Vladimir(){
	{
		using  std::locale;

		const locale utf8_locale = locale(locale(), new std::codecvt_utf8<wchar_t>());


		std::wifstream infile(L"text.txt");      // создать объект класса wifstream
		infile.imbue(utf8_locale);               // связываем наш поток с нужной локалью

		std::wstring tmp;

		int i = 0;
		while (std::getline(infile, tmp))
		{
			if (i <= 15) m_txt.push_back(tmp);
			i++;
		}

		infile.clear();
	}
	void copy(class DB& db);
	~Vladimir() {}
};