
#include "OpSuma.h"
#include "Suma.h"

//IMPLEMENTAR - CLASE HIJA
//Para el "extend" herencia se usa ":"

//OpNumercias es hija de OpSuma

class OpNumericas:public OpSuma{ 
	
	private:
		Suma s1;
		
	public:
		OpNumericas(Suma);
};