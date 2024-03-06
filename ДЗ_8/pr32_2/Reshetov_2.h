#pragma once
#include"stdafx.h"
class Reshetov_2 : public Reshetov_1 {
    std::list<float>* listP;
public:
    Reshetov* copy() { return new Reshetov_2(*this); }
    Reshetov_2();
    Reshetov_2(const Reshetov_2& obj);

    void change();

    ~Reshetov_2();

    void print() const override;

};