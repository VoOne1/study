#pragma once
#include"stdafx.h"
#include <codecvt>   // для работы с фасетом codecvt_utf8 локали

class Reshetov
{
    std::vector<std::wstring> m_txt;
public:
    virtual Reshetov* copy()
    {
        return (new Reshetov(*this));
    }
    virtual void print(std::wostream& os) {}

    void getText(std::wostream& os);

    Reshetov(const Reshetov& obj):m_txt(obj.m_txt) {}

    virtual void erase(std::vector<Reshetov*>& db, std::vector<Reshetov*>::iterator& it, bool& ReshetovFlag, bool& VladimirFlag)
    {
        if (ReshetovFlag == 1)
        {
            delete* it;
            it = db.erase(it);
            return;
        }
        else
        {
            it++;
            ReshetovFlag = 1;
        }
    }

    Reshetov()
    {
        using  std::locale;
        
        const locale utf8_locale = locale(locale(), new std::codecvt_utf8<wchar_t>());

        std::wifstream infile(L"text.txt");      // создать объект класса wifstream
        infile.imbue(utf8_locale);               // связываем наш поток с нужной локалью

        std::wstring tmp;

        int count = 0;
        while (std::getline(infile, tmp))
        {
            if (count <= 15) m_txt.push_back(tmp);
            else break;
            count++;
        }

        infile.clear();
    }

    virtual ~Reshetov() {}


};