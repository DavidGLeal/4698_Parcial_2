#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(){
	int foo, bar;
	foo = 81923;
bar = 81923;
	int *const ptrFoo = &foo;
	*ptrFoo = 53;
	*ptrFoo = bar;
	cout << "El valor del apuntador constante es: " <<bar<<endl;
	system("pause>null");
}
