#include <iostream>
using namespace std;

int main()
{
	char c[] = "Hello World!";
	char *pchar;
	int x[] = { 0, 1, 2 };
	int *pint;

	pchar = c;
	pint = x;

	cout << c << "\n" << x << "\n" << pchar << "\n" << pint << "\n";

	system("pause>null");
}
