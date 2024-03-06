#include "stdafx.h"
void Reshetov::getText(std::wostream& os)
{
    std::vector<std::wstring>::iterator it = m_txt.begin();
    for (; it != m_txt.end(); it++)
        os << *it << std::endl;
}

