#ifndef FUNCIONAL_TESTS_H_
#define FUNCIONAL_TESTS_H_

#include <iostream>
#include <string>
#include <assert.h>
#include <math.h>
#include "../../src/System.hpp"
#include "../../src/Flow.hpp"
#include "../../src/Model.hpp"

void exponentialTest();

void logisticalTest()
{
	class MyFlow : public Flow
	{
	public:
		MyFlow(System* source = NULL,System* target = NULL, string name = "\0") : Flow(source, target, name) {}
		virtual ~MyFlow(){}
		double equation()
		{
			return 0.01 * getTarget()->getStock() * (1- getTarget()->getStock() / 70);
		}
	};
	{
		System *p1 = new System(100,"p1"), *p2 = new System(10,"p2");
		MyFlow *logistics = new MyFlow(NULL,NULL,"logistics");
		Model *m = new Model();

		logistics->connect(p1,p2);

		m->add(p1); m->add(p2);
		m->add(logistics);

		m->execute(0,100,1);
		//m->report();

		assert( fabs(p1->getStock() - 88.2167) < 0.0001 );
		assert( fabs(p2->getStock() - 21.7834) < 0.0001 );
	}
}
void complexTest()
{
	class MyFlow : public Flow
	{
	public:
		MyFlow(System* source = NULL,System* target = NULL, string name = "\0") : Flow(source, target, name) {}
		virtual ~MyFlow(){}
		double equation()
		{
			return 0.01 * getSource()->getStock();
		}
	};

	{
		System *Q1 = new System(100,"Q1"), *Q2 = new System(0,"Q2");
		System *Q3 = new System(100,"Q3"), *Q4 = new System(0,"Q4");
		System *Q5 = new System(0,"Q5");
		
		MyFlow *f = new MyFlow(NULL,NULL,"f"), *g = new MyFlow(NULL,NULL,"g");
		MyFlow *r = new MyFlow(NULL,NULL,"r"), *t = new MyFlow(NULL,NULL,"t");
		MyFlow *u = new MyFlow(NULL,NULL,"u"), *v = new MyFlow(NULL,NULL,"v");
		
		Model *m = new Model();

		f->connect(Q1,Q2);
		g->connect(Q1,Q3);
		r->connect(Q2,Q5);
		t->connect(Q2,Q3);
		u->connect(Q3,Q4);
		v->connect(Q4,Q1);

		m->add(Q1);
		m->add(Q2);
		m->add(Q3);
		m->add(Q4);
		m->add(Q5);
		m->add(f);
		m->add(g);
		m->add(r);
		m->add(t);
		m->add(u);
		m->add(v);

		m->execute(0,100,1);
		//m->report();

		assert( fabs(Q1->getStock() - 31.8513) < 0.0001 );
		assert( fabs(Q2->getStock() - 18.4003) < 0.0001 );
		assert( fabs(Q3->getStock() - 77.1143) < 0.0001 );
		assert( fabs(Q4->getStock() - 56.1728) < 0.0001 );
		assert( fabs(Q5->getStock() - 16.4612) < 0.0001 );
	}
}

#endif