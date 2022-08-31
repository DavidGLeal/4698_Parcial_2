#include <stdio.h>
#include <stdlib.h>
int  main(){
	int *p, i;
	int mat[10] = { 1, 2, 3, 4, 4, 7, 8, 9, 5, 4 };
	p = mat;
	for (i = 0; i <= 3; i++)     {
		printf("\n mat[%d] = %d ", i, *p);
		printf("\tDireccion: %x", p);
		p++;
	}
	system("pause>null");
}
