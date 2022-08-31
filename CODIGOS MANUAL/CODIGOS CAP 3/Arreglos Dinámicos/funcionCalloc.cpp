#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* calloc, exit, free */

int main()
{
int i, n;
int * pData;
printf("Cantidad de numeros a introducir: ");
scanf("%d", &i);
pData = (int*)calloc(i, sizeof(int));
if (pData == NULL) exit(1);
for (n = 0; n<i; n++)
{
     printf("Introduzca el numero #%d: ", n + 1);
     scanf("%d", &(*(pData + n)));
}
printf("Ha ingresado: ");
for (n = 0; n<i; n++) 
     printf("%d ", *(pData + n));
free(pData);
system("pause ");
return 0;
}
