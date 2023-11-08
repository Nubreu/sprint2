#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#include <string>
using namespace std;
class System
{
	double stock;
	string name;

public:

// CONSTRUCTOR AND DESTRUCTOR
	System(double stock = 0, string name = "\0")
	{
		this->stock = stock;
		this->name = name;
	}
	System(const System& system)
	{
		stock = system.stock;
		name = system.name;
	}
	~System(){}
//GETS AND SETS
	void setStock(double stock)
	{
		this->stock = stock;
	}
	double getStock(void)
	{
		return stock;
	}
	void setName(string name)
	{
		this->name = name;
	}
	string getName(void)
	{
		return name;
	}
//METHODS
	void update(double stock, string name)
	{
		setStock(stock);
		setName(name);
	}
//OPERATORS
	System& operator = (const System& system)
	{
		if(&system == this)
			return *this;
		setStock(system.stock);
		setName(system.name);
		return *this;
	}
};




#endif /* SYSTEM_HPP_ */
