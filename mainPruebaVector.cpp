#include <iostream>
#include "0Vector.cpp"
#include "6ImprimirInterno.cpp"
#include "2OrdenamientoInterno.cpp"
using namespace std;
   

int main(){

    Vector v;
    v.push_back(13);
    v.push_back(4);
    v.push_back(7);
    v.push_back(47);
    v.push_back(2);
    v.push_back(36);
    v.push_back(98);
    v.push_back(8);
    v.push_back(74);
    v.push_back(1);


	OrdenamientoInterno *bucket = new OrdenamientoInterno(v);

	 
	bucket->imprimirInterno();
    bucket->ordenarBucket();
	bucket->imprimirInterno(); 
    
    return 0;
}
