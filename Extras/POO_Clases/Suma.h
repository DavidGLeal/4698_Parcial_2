#pragma once
#include <iostream>

using namespace std;

class Suma{
	private:
		float a;
		float b;
		
	public:
		//Constructor
		Suma(float, float);
		Suma();
		
		//Metodos Get-Set
		float getA();
		float getB();
		void setA(float);
		void setB(float);

};