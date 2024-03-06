#include "stdafx.h"
struct Leaks {
	~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;
class DB
{
	std::vector<Reshetov*> v;
public:
	
	void Add(Reshetov* tmp)
	{
		v.push_back(tmp);
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
			(obj.v[i])->copy(v);

		return *this;
	}
	DB* copy() { return new DB(*this); }

	DB(const DB& obj)
	{
		for (int i = 0; i < obj.v.size(); i++)
		{
			((obj.v[i])->copy(v));
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
void create(DB& obj )
{
	Reshetov_1* r11 = new Reshetov_1;
	Reshetov_2* r21 = new Reshetov_2;
	Reshetov_1* r12 = new Reshetov_1;
    Reshetov_2* r22 = new Reshetov_2;
	obj.Add(r11);
	obj.Add(r21);
	obj.Add(r12);
	obj.Add(r22);
	
}
int main()
{
	DB* db1 = new DB; 
	DB* db2 = new DB;
	create(*db1); // наполнение db1
	*db2 = *db1;  // заполнение пустого db2 из db1 
	db1->print(); // вывод значений автоматических и динамических полей объектов
	std::cout << "--------------" << std::endl;
	*db1 = *db2;  
	db2->print(); // вывод значений автоматических и динамических полей объектов
	std::cout << "--------------" << std::endl;
	db1->print(); // вывод значений автоматических и динамических полей объектов
	delete db1;
	delete db2;
	return 0;
}
