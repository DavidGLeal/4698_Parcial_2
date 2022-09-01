#include <iostream>
using namespace std;

int main()
{
	int *ptInt;
	float *ptFloat;
	int var1 = 7, var2 = 27;
	float x = 1.2345, y = 32.14;
	void *general;

	ptInt = &var1;
	*ptInt += var2;
	cout << " var1 tiene ahora el valor \t" << *ptInt << '\n';
	general = ptInt;

	ptFloat = &x;
	y += 5 * (*ptFloat);
	cout << " y tiene ahora el valor \t" << y << '\n';
	general = ptFloat;
	system("pause>null");

}
