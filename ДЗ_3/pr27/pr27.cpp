#include"stdafx.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

struct Leaks {
	~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;


class House {
	float* Price;
public:
	virtual void GetMaterial(){}
	House(): Price(new float(1000.00F)) {}
	House(const House& obj) :Price(new float(0.0F)) { *Price = *obj.Price; }
	virtual House* copy() { return new House(*this); }
	virtual ~House()
	{
		delete Price;
	}
	void GetPrice() { std::cout << *Price << std::endl; }
	
};

class Wooden : public House {
	std::string material = "wood";
public:
	void GetMaterial() { std::cout << this->material << std::endl; }
	Wooden() {}
	Wooden(const Wooden& obj) :House(obj){}
	virtual ~Wooden(){}
	House* copy() { return new Wooden(*this); }
};

class Brick : public House {
	std::string material = "brick";
public:
	void GetMaterial() { std::cout << this->material << std::endl; }
	Brick() {}
	Brick(const Brick& obj) :House(obj) {}
	virtual ~Brick() {}
	House* copy() { return new Brick(*this); }
};

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<House*>v;
	std::vector<House*>v2;

	for (int i = 0; i < 3; i++)
	{
		v.push_back(new Wooden);
	}

	for (int i = 3; i < 5; i++)
	{
		v.push_back(new Brick);
	}


	for (std::vector<House*>::iterator it = v.begin(); it != v.end(); ++it)
	{
		House* new_obj = (*it)->copy();
		v2.insert(v2.end(), new_obj);
	}	

	for (House* obj : v) { //очистка первого вектора
		delete obj;
	}
	v.clear();

	for (int i = 0; i < v2.size(); i++) //проверка корректного заполнения второго вектора
	{
		v2.at(i)->GetMaterial();
	}

	for (House* obj : v2) { //очистка второго вектора
		delete obj;
	}
	v2.clear();

	
	return 0;
}
