#pragma once
#include "TablaHashCerrada.cpp"

class TablaSondeoLinealText : public TablaHashCerrada
{
	public:
		TablaSondeoLinealText();
		~TablaSondeoLinealText();
		int hash2(int) override;
};