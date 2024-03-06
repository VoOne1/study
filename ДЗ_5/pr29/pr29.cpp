#include"stdafx.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

struct Leaks {
	~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;


class Reshetov
{

public:

	virtual Reshetov* copy() = 0;
	virtual void SetData(int tmp) = 0;

	Reshetov(){};
	virtual ~Reshetov() {};
	virtual void print() {};
};

class Reshetov_1 :public Reshetov
{
	int* i;
public:
	int Get_i() { return *i; }
	void SetData(int tmp) { *i = tmp; }
	void print() 
	{
		std::cout << "Value in Reshetov_1: " << *i << std::endl;
	}
	Reshetov_1(const Reshetov_1& obj) :Reshetov(obj), i(new int(33)) { *i = *obj.i; }
	Reshetov_1* copy()  { return new Reshetov_1(*this); }

	Reshetov_1& operator = (const Reshetov_1& obj)
	{
		if (this == &obj) return *this;

		*i = *obj.i;

		return *this;
	}

	Reshetov_1() : i(new int(33)), Reshetov() {}

	virtual ~Reshetov_1() { delete i; }
};

class Reshetov_2 :public Reshetov_1 
{
	float* f;
public:
	float Get_f() { return *f; }
	void SetData(float tmp) { *f = tmp; }
	void print()
	{
		std::cout << "Value in Reshetov_2: " << *f << std::endl;
	}

	Reshetov_2(const Reshetov_2& obj) :Reshetov_1(obj), f(new float(0.001F)) { *f = *obj.f; }
	Reshetov_2* copy() { return new Reshetov_2(*this); } 

	Reshetov_2& operator = (const Reshetov_2& obj)
	{
		if (this == &obj) return *this;
		Reshetov_1::operator=(obj);

		*f = *obj.f;

		return *this;
	}

	Reshetov_2() : f(new float(0.001F)), Reshetov_1() {}
	virtual~Reshetov_2() { delete f; }

};

class DB
{
	std::vector<Reshetov*> v;
public:
	int vSize = v.size();
	void Add(Reshetov* tmp) 
	{
		v.push_back(tmp);
	}

	void change(int tmp)
	{
		for (int i = 0; i < v.size(); i++)
		{
			v[i]->SetData(tmp);
		}
	}

	void print() 
	{
		for (int i = 0; i < v.size(); i++) 
		{
			v[i]->print();
		}
	}

	DB& operator = (const DB& obj)
	{
		if (this == &obj) return *this;
		for (int i = 0; i < v.size(); i++)
		{
			delete this->v[i];
		}
		v.clear();
		
		for (int i = 0; i < obj.v.size(); i++)
			v.push_back(obj.v[i]->copy());

		return *this;
	}
	DB* copy() { return new DB(*this); }

	DB(const DB& obj)
	{
		for (int i = 0; i < obj.v.size(); i++)
		{
			v.push_back((obj.v[i])->copy());
		}
	}

	DB() {};
	
	~DB() {
		for (int i = 0; i < v.size(); i++)
		{
			delete v[i];
		}
	};
};


void change(DB* db1, int tmp) 
{
	db1->change(tmp);
}

int main() 
{
	DB* db1 = new DB;
	
	Reshetov_1* r1 = new Reshetov_1;
	db1->Add(r1);
	Reshetov_2* r2 = new Reshetov_2;
	db1->Add(r2);
	Reshetov_1* r12 = new Reshetov_1;
	db1->Add(r12);
	Reshetov_2* r22 = new Reshetov_2;
	db1->Add(r22);

	Reshetov_1 q1, q2;
	q1 = q2;
	

	DB db2(*db1), db3;
	delete db1;
	db3 = db2;
	change(&db3, 55);
	db3.print();

	return 0;
}