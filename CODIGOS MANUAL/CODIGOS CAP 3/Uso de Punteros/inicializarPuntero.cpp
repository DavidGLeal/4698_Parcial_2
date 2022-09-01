#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int X[6] = { 1, 2, 3, 4, 5, 6 };
	int *prtX;

	prtX = X; // incializo el valor del puntero.
	cout << endl << *prtX;
	prtX += 2;
	cout << endl << *prtX;
	prtX -= 2;
	cout << endl << *prtX;
	prtX++;
	cout << endl << *prtX;
	system("pause>null");
}
