#include <iostream>// Factorial de un número
#include <conio.h>
#include <windows.h>
using namespace std;
int factorial(int);
int main (void)
{
	int n;// Número ingresado
	int i;     // Contador
	cout << "Ingresar un numero: ";
	cin >> n;
	cout << "\n" << n << "! = " << factorial(n) << "\n";
	getch();
	return 0;
}
		
	
	int factorial(int n) {
	if (n <= 1) return 1;
	else return n * factorial(n - 1);
		}
