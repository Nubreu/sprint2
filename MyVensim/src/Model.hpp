#ifndef MODEL_HPP
#define MODEL_HPP
#include "System.hpp"
#include "Flow.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
class Model
{
	vector <System*> system_container;
	vector <Flow*> flow_container;

public:

	Model(){};
	Model(Model &model){
		flow_container = model.flow_container;
		system_container = model.system_container;
	}
	void add(System* system);
	void add(Flow* flow);
	void execute(int t_start, int t_end,int shift);
	void report();
	const vector<Flow*>& getFlowContainer() const {
		return flow_container;
	}
	void setFlowContainer(const vector<Flow*>& flowContainer);
	const vector<System*>& getSystemContainer() const {
		return system_container;
	}
	void setSystemContainer(const vector<System*>& systemContainer);

	Model& operator = (const Model& model)
	{
		if(this == &model)
			return *this;
		flow_container.clear();
		system_container.clear();
		flow_container = model.flow_container;
		system_container = model.system_container;
		return *this;
	}
};



void Model:: add(Flow* flow)
{
	flow_container.push_back(flow);
}


////////////////////////////////////

void Model::add(System* system)
{
	system_container.push_back(system);
}


void Model::setFlowContainer(const vector<Flow*>& flowContainer) {
	flow_container = flowContainer;
}

void Model:: report()
{	int i=0;
	for_each(system_container.begin(),system_container.end(),[&i](System* s){ cout << s->getName() << ": " << fixed << setprecision(4) << s->getStock() << "\t"; i++;});
	cout << endl;
}

void Model::setSystemContainer(const vector<System*>& systemContainer) {
	system_container = systemContainer;
}

#endif /* MODEL_HPP_ */
