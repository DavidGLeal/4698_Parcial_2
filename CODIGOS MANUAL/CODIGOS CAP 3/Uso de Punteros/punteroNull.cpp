//Uso de Null
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(){
	int y = 5;
	int z = 3;
	int *nptr;
	int *mptr;
	nptr = &y;
	z = *nptr;
	*nptr = 7;
	mptr = nptr;
	*mptr = NULL;
	*mptr = *nptr;
	y = (*nptr) + 1;
	cout << "La dirección de mptr después de utilizar el valor del puntero NULL es:" << mptr << endl;
	system("pause>null");}
