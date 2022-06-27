#pragma once
#include "TablaHashCerrada.cpp"

class TablaSondeoCuadraticoText : public TablaHashCerrada
{
	private:
		int i=0;
	public:
		TablaSondeoCuadraticoText();
		~TablaSondeoCuadraticoText();
		
		int hash2(int) override;
};