#pragma once
#include "TablaCerradaEnteros.cpp"

class TablaSondeoCuadraticoInt : public TablaCerradaEnteros
{
	private:
		int i=0;
	public:
		TablaSondeoCuadraticoInt();
		~TablaSondeoCuadraticoInt();
		
		int hash2(int) override;
};