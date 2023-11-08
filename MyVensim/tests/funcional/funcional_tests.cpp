#include "funcional_tests.h"
#include <iostream>

void exponentialTest()
{
	class MyFlow : public Flow
	{
	public:
		MyFlow(System* source = NULL,System* target = NULL, string name = "\0") : Flow(source, target, name) {}
		virtual ~MyFlow(){}
		double equation()
		{
			return getSource()->getStock() * 0.01;
		}
	};
	{
		System *pop1 = new System(100,"pop1"), *pop2 = new System(0,"pop2");
		MyFlow *exponential = new MyFlow(NULL,NULL,"exponential");
		Model *m = new Model();

		exponential->connect(pop1,pop2);

		m->add(pop1); m->add(pop2);
		m->add(exponential);

		m->execute(0,100,1);
		//m->report();

		assert( fabs(pop1->getStock() - 36.6032) < 0.0001 );
		assert( fabs(pop2->getStock() - 63.3968) < 0.0001 );
	}
}