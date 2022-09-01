//paresEImpares
#include <conio.h>
#include <string.h>
#include <iostream>

using namespace std;
int main()
{
	int *vec[20];
	int pares[10];
	int impares[10];
	for (int i = 0; i < 10; i++) {
		pares[i] = 2 * i;
		impares[i] = 2 * i - 1;
	}
	for (int i = 1; i < 10; i++) {
		vec[i] = &pares[i];
		vec[i + 10] = &impares[i];
	}
	cout << "Pares\n";
	for (int i = 1; i < 10; i++) {
		cout << *vec[i]<<"  ";
	}
	cout << "\nImpares\n";
	for (int i = 1; i < 10; i++) {
		cout << *vec[i+10]<<"  ";
	}

	system("pause>NULL");
    return 0;
}
