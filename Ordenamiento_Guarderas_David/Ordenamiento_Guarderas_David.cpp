#include "Ordenamiento_Guarderas_David.h"

Vector Ordenamiento_Guarderas_David::getOrde()
{
	return orde;
}

void Ordenamiento_Guarderas_David::setOrde(Vector nov)
{
	orde = nov;
}

int Ordenamiento_Guarderas_David::getInter()
{
	return inter;
}

void Ordenamiento_Guarderas_David::setInter(int in)
{
	inter = in;
}

void Ordenamiento_Guarderas_David::ordenamiento_Guarderas_David()
{
	int i=0;
	int max = orde.size();
	while(i<max)
	{
		Vector conj;
		for(int j =i;j<i+inter;j++)
		{	
			int val = *(orde.get(j));
			conj.push_back(val);
		}
		func.copiarVector(conj);
		func.ordenarShellSort();
		imprimir(func.getVector());
		i+=inter;
		conj.~Vector();
	}
}

void Ordenamiento_Guarderas_David::imprimir(Vector vec)
{
	for(int i=0;i<getInter();i++)
	{
		cout<<*vec.get(i)<<"\t";
	}
	cout<<endl;
}