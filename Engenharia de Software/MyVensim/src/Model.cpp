#include "Model.hpp"



void Model:: execute(int t_start, int t_end,int shift)
{	vector <double> results;
	int i;
	for(int time = t_start ; time < t_end ; time = time + shift)
	{
		for_each(flow_container.begin(),flow_container.end(),[&results](Flow* f){
			results.push_back(f->equation());
			});
		i=0;
		for_each(flow_container.begin(),flow_container.end(),[&i,&results](Flow* f){double aux = f->getSource()->getStock();
																			f->getSource()->setStock(aux - results[i]);
																			aux = f->getTarget()->getStock();
																			f->getTarget()->setStock(aux + results[i]);	i++;});
		//report();
		results.clear();
	}
}
