//Multiplos de 5 y 10
#include <conio.h>
#include <string.h>
#include <iostream>

using namespace std;
int main()
{
	int *vec[20];
	int mul5[10];
	int mul3[10];
	for (int i = 0; i < 10; i++) {
		mul5[i] = 5 * i;
		mul3[i] = 3 * i ;
	}
	for (int i = 0; i < 10; i++) {
		vec[i] = &mul5[i];
		vec[i + 10] = &mul3[i];
	}
	cout << "Multiplos 5\n";
	for (int i = 0; i < 10; i++) {
		cout << *vec[i]+5<<"  ";
	}
	cout << "\nMultiplos 3\n";
	for (int i = 1; i < 10; i++) {
		cout << *vec[i+10]+3<<"  ";
	}

	system("pause>NULL");
    return 0;
}
