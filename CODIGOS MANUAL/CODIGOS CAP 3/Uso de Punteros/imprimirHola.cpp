#include <conio.h>
#include <string.h>
#include <iostream>

using namespace std;

void cambiar(char *a){
	gets(a);
	puts(a);
	char b[10];
	strcpy(b,a);
	puts(b);
}

int main(){
	char a[10];
	cambiar(a);
	return 0;
}
