// pr32_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "stdafx.h"

struct Leaks {
    ~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;

int main() 
{
    DB<Reshetov*> db1;
    db1.push_back(new Reshetov_1());
    db1.push_back(new Reshetov_2());

    for (Reshetov* item : db1) {
        item->print();
    } //вывод до изменения

    for (Reshetov* item : db1) {
        item->change();
    } //изменение данных типа Reshetov_2

    DB<Reshetov*> db2 = db1;
    //db1 = db2;
    for (Reshetov* item : db1) {
        item->print();
    }//вывод после изменения

    // Вывод db2
    for (Reshetov* item : db2) {
        item->print();
    }

    DB<Reshetov*> db11;
    db11.push_back(new Reshetov_1());
    db11.push_back(new Reshetov_2());
    
    return 0;
}