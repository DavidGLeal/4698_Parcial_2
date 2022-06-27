#pragma once
#include "TablaCerradaEnteros.h"
#include "TablaCerradaEnteros.cpp"

class TablaSondeoLinealInt : public TablaCerradaEnteros
{
	public:
		TablaSondeoLinealInt();
		~TablaSondeoLinealInt();
		int hash2(int) override;
};