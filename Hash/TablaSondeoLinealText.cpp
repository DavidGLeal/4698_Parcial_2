#pragma once
#include "TablaSondeoLinealText.h"


TablaSondeoLinealText::TablaSondeoLinealText() : TablaHashCerrada()
{
}

TablaSondeoLinealText::~TablaSondeoLinealText()
{
}

int TablaSondeoLinealText::hash2(int pos)
{
		int i=1;
	
	//while(tabla[pos]!=NULL){
		pos=(pos+i)%NCASILLAS;
		//i++;
	//}
	return pos;
}