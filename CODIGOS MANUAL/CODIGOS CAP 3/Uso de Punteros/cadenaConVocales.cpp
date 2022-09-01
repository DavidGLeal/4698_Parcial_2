#include <iostream>
using namespace std;
int cuenta_vocales(char *);// prototipo de la funcion cuenta vocales.
int main(){
	char cadena[80];
	cout << "Introduce cadena: ";
	cin.getline(cadena, 80);
	//en la llamada a la funcion se envía 
	//el array de caracteres
	cout << "Numero de vocales: " << cuenta_vocales(cadena) << endl;
       //Se imprime el numero de vocales
system("pause");
}
int cuenta_vocales(char *s) {//s contiene la dirección de inicio del array de caracteres
	int cont = 0;
	while (*s) {//mientras no llegue al nulo
		switch (toupper(*s)){ //toupper pasa el carácter a mayúsculas para hacer la comprobación. 
                    //el carácter original no se modifica.
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':  cont++;
		}
		s++;
	}
	return cont;
}
