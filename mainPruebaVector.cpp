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

<<<<<<< Updated upstream
=======
//<<<<<<< HEAD
	/*
    OrdenamientoInterno *intercambio = new OrdenamientoInterno(v);
    OrdenamientoInterno *burbuja = new OrdenamientoInterno(v);
	OrdenamientoInterno *shellsort = new OrdenamientoInterno(v);
	*/
	OrdenamientoInterno *bucket = new OrdenamientoInterno(v);
	//OrdenamientoInterno *radix = new OrdenamientoInterno(v);
	
	//OrdenamientoInterno *distribucion = new OrdenamientoInterno(v);
	/*
    intercambio->imprimirInterno();
    intercambio->ordenarIntercambio();
    intercambio->imprimirInterno();
	
    burbuja->imprimirInterno();
    burbuja->ordenarBurbuja();
	burbuja->imprimirInterno(); 
	
	shellsort->imprimirInterno();
    shellsort->ordenarShellSort(); 
	shellsort->imprimirInterno(); 
	
	distribucion->imprimirInterno();
    distribucion->ordenarDistribucion();
	distribucion->imprimirInterno(); 
	
	bucket->imprimirInterno();
    bucket->ordenarBucket();
	bucket->imprimirInterno(); 
=======
>>>>>>> Stashed changes

    OrdenamientoInterno *a = new OrdenamientoInterno(v);

    a->imprimirInterno();
    a->ordenarCountingSort();
    a->imprimirInterno();
<<<<<<< Updated upstream

=======
>>>>>>> 75531d9be243a3f8b16078e2c3f0ba449988d961
	
    radix->imprimirInterno();
    radix->ordenarRadix();
	radix->imprimirInterno();
    */
	 
	bucket->imprimirInterno();
    bucket->ordenarBucket();
	bucket->imprimirInterno(); 
    
>>>>>>> Stashed changes
    return 0;
}
