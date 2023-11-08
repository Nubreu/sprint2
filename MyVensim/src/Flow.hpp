#ifndef FLOW_HPP
#define FLOW_HPP
#include "System.hpp"
class Flow
{
protected:
	System* source;
	System* target;
	string name;

public:

//CONSTRUCTOR AND DESTRUCTOR
	virtual ~Flow(){};
	Flow()
	{
		source = NULL;
		target = NULL;
		name = "\0";
	}
	Flow(System* source,System* target,string name)
	{
		this->source = source;
		this->target = target;
		this->name = name;
	}
	Flow(const Flow& flow)
	{
		source = flow.source;
		target = flow.target;
		name = flow.name;
	}

//GETS AND SETS
	void setSource(System* source)
	{
		this->source = source;
	}
	System* getSource(void)
	{
		return source;
	}
	void setTarget(System* target)
	{
		this->target = target;
	}
	System* getTarget(void)
	{
		return target;
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
	void connect(System* source, System* target)
	{
		setSource(source);
		setTarget(target);
	}
	void update(System* source, System* target, string name)
	{
		setSource(source);
		setTarget(target);
		setName(name);
	}
	virtual double equation() = 0;
//OPERATORS
	Flow& operator = (const Flow& flow)
	{
		if(&flow == this)
			return *this;
		delete this->source;
		delete this->target;
		source = flow.source;
		target = flow.target;
		name = flow.name;
		return *this;
	}
};
#endif /* FLOW_HPP_ */
