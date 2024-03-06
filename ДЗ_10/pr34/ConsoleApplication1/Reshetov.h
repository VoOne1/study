#pragma once
#include "stdafx.h"
#include <codecvt>   // ��� ������ � ������� codecvt_utf8 ������
class Reshetov
{
	std::vector<std::wstring> m_txt;
public:
	Reshetov(const Reshetov& obj){}
	Reshetov()
	{
		using  std::locale;

		const locale utf8_locale = locale(locale(), new std::codecvt_utf8<wchar_t>());


		std::wifstream infile(L"text.txt");      // ������� ������ ������ wifstream
		infile.imbue(utf8_locale);               // ��������� ��� ����� � ������ �������

		std::wstring tmp;

		int i = 0;
		while (std::getline(infile, tmp))
		{
			if(i <= 15) m_txt.push_back(tmp);
			i++;
		}

		infile.clear();
	}
	
	void copy(class DB& db);

	~Reshetov(){}


};