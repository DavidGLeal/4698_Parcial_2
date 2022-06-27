#pragma once
#include "TablaHashCerrada.cpp"

class TablaHashDobleText: public TablaHashCerrada
{
	public:
		TablaHashDobleText();
		~TablaHashDobleText();
		int hash2(int) override;
};