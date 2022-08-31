#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define S 10
#define NUM 99

struct array{
	int *v; /* puntero al array */
	int n;  /* numero de elementos del array */
};
typedef struct array vector;  /* declaracion del nuevo tipo: vector */

void  gen_array(vector* inic);  /* genera array con n valores */
void nuevo_array(vector inic, vector* nd);  /* genera nuevo vector sin duplicados */
void escribe_array(vector W);

int main(){
	vector prim, dest;
	do{
		printf_s("\nNumero de elementos del array: ");
		scanf_s("%d", &prim.n);
	} while (prim.n<1);
	rand();

	gen_array(&prim);
	escribe_array(prim);

	nuevo_array(prim, &dest);
	escribe_array(dest);
	system("pause>null");
	return 0;
}

void gen_array(vector* inic){
	int k;
	inic->v = (int*)calloc(inic->n, sizeof(int));  /* reserva memoria */
	for (k = 0; k<inic->n; k++)
		inic->v[k] = rand() + 1;  /* genera valores enteros de 1 a NUM */
}

void escribe_array(vector w){
	int k;
	printf_s("\n\t Valores que contiene el vector\n");
	for (k = 0; k<w.n; k++)
              /* cada 19 enteros salta de linea */
		printf_s("%d%c", w.v[k], (k + 1) % 19 == 0 ? '\n' : ' ');  
}

void nuevo_array(vector inic, vector* nd){
	int k, tam;
	/* Reserva inicial de memoria para 10 valores */
	nd->v = NULL;
	tam = sizeof(int)*S;
	nd->v = (int*)realloc(nd->v, tam);
	/* copia el primer elemento */
	nd->v[0] = inic.v[0];
	nd->n = 1;
	/* copia los demas elementos si no estan ya en el array.
	Cuenta los elementos copiados para reservar memoria */
	for (k = 1; k< inic.n; k++)	{
		int j, dup;
		j = dup = 0;
		while ((j<nd->n) && !dup)
		{
			dup = inic.v[k] == nd->v[j++];
		}

		if (!dup){
			if ((nd->n)&(S == 0)){  /* amplia memoria */
			       tam += sizeof(int)*S;
				nd->v = (int*)realloc(nd->v, tam);
				/* asigna el elemento. Los indices en C estan en el    rango de 0 a n-1, por esa razon se asigna y despues se incrementa. */
			}
			nd->v[nd->n++] = inic.v[k];
		}}}
