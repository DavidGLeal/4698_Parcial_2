#include "Ordenamiento_Guarderas_David.cpp"
#include "1IngresoDatos.h"
#include <stdlib.h>

using namespace std;

int main()
{
	IngresoDatos ing;
	
	Ordenamiento_Guarderas_David dav;
	int em;
	
	Vector ord;
	
	for(int i=0;i<100;i++)
	{
		ord.push_back(rand()%101);
	}
	
	cout<<"Ingrese un numero: ";
	em = ing.funcionPrincipalEnteros();
	
	cout<<endl;
	dav.setInter(em);
	
	
	dav.setOrde(ord);
	dav.ordenamiento_Guarderas_David();
}