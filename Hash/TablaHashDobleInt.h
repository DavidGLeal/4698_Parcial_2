#pragma once
#include "TablaCerradaEnteros.cpp"

class TablaHashDobleInt : public TablaCerradaEnteros
{
	public:
		TablaHashDobleInt();
		~TablaHashDobleInt();
		int hash2(int) override;
};