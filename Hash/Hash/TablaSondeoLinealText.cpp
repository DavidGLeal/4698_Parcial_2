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
		pos=(pos+i)%NCASILLAS;
	return pos;
}