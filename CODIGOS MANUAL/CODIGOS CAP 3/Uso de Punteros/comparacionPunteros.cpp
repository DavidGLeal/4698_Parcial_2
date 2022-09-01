//Comparacion de punteros
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
	int i = 100, *p1, *p2;
	p1 = &i;
	p2 = p1;
	if (p1 == p2) /* estamos comparando dos punteros */
	{
		printf("p1 apunta a la misma direccion de memoria que p2");
	}
	*p1 = *p1 + 2; /* El * tiene más prioridad que el + */
	printf("El valor de *p2 es %d\n", *p2);
	(*p2)++; /* ante la duda de prioridades usamos parentesis */
	printf("El valor de *p1 es %d\n", *p1);
	i--;
	printf("El valor de i es %d\n", i);
	system("pause>null");
}
