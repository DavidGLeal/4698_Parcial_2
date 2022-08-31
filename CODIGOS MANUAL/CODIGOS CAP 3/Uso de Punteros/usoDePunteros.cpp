#include <stdio.h>
#include <iostream>
using namespace std;

int  main(){

	int a, *pt;
	a = 7;
	pt = &a;
	cout << "La direccion de a es : " << &a << endl;
	cout << "El contenido de pt es : " << pt << endl;
	cout << "El valor de a es : " << a << endl;
	cout << "El valor de pt es : " << *pt << endl;
	cout << "El valor de &*pt es : " << &*pt << endl;
	cout << "El valor de *&pt es : " << *&pt << endl;
	system("pause>null");
	return 0;
}
