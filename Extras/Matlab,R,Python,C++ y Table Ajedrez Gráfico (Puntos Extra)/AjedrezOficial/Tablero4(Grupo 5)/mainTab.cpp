/*Universidad de las Fuerzas Armadas - ESPE
EXTRA - Parcial 3: 
Graficar en la consola un tablero de ajedrez.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 07/08/2022
FECHA DE MODIFICACIÓN: 07/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/

#include "Tablero.cpp"
#include "FuncionesParaValidar.cpp"

int main()
{
	FuncionesParaValidar valid;
	int num;
	char *chas;
	
	do{
		system("cls");
		
		chas = valid.ingresarDatos("Ingrese un numero del 1 al 8 ->");
		num = atoi(chas);
		
	}
	while(num<0 || num>8);
	
	Tablero tab(num);
	
	tab.jugarTorre();

	//tab.graficarTablero();
	cin.ignore();
}