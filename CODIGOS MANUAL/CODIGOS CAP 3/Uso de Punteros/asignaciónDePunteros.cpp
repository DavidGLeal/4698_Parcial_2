#include <iostream>
using namespace std;

int main()
{
	int x = 1, y = 2;
	int *ip; /* ip es un puntero a int */
	ip = &x; /* ip apunta a x */
	y = *ip; /* a y se le asigna lo apuntado por ip */
	*ip = *ip + 3; /* incrementa lo apuntado por ip, x */
	cout << x << endl;
	cout << ip;
	system("pause>null");
	return 0;
}
