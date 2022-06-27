#pragma once
#include "TablaHashDobleInt.h"

TablaHashDobleInt::TablaHashDobleInt() : TablaCerradaEnteros()
{

}

TablaHashDobleInt::~TablaHashDobleInt()
{

}

int TablaHashDobleInt::hash2(int pos)
{	
	int dob = pos + (7 - tabla[pos]->getValor()%7); 
	if(dob>28)
	{
		dob=NCASILLAS-dob;
	}
	return dob;
}