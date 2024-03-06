#pragma once
#include "stdafx.h"

void Vladimir::print(std::wostream& os)
{
	this->getText(os);
	std::vector<std::wstring>::iterator it = m_txt1.begin();
	for (; it != m_txt1.end(); it++)
		os << *it << std::endl;
}

void Vladimir::erase(std::vector<Reshetov*>& db, std::vector<Reshetov*>::iterator& it, bool& ReshetovFlag, bool& VladimirFlag)
{
	if (VladimirFlag == 1)
	{
		delete* it;
		it = db.erase(it);
		return;
	}
	else
	{
		it++;
		VladimirFlag = 1;
	}
}