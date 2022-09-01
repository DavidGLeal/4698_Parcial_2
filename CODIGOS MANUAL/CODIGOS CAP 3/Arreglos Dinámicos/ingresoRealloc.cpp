#include <stdio.h>      /* printf, scanf, puts */
#include <stdlib.h>     /* realloc, free, exit, NULL */

int main()
{
int input, n;
int count = 0;
int* numbers = NULL;

int* more_numbers = NULL;

do {
printf("Introduzca un valor entero (0 para terminar): ");
scanf("%d", &input);
count++;

more_numbers = (int*)realloc(numbers, count * sizeof(int));

if (more_numbers != NULL) 

{
numbers = more_numbers;
*(numbers + count - 1) = input;
}
else 
{
free(numbers);
puts("Error (re)asignacion de memoria");
exit(1);
}
} while (input != 0);

printf("Numeros introducidos: ");
for (n = 0; n<count; n++) 
printf("%d ", *(numbers + n));

free(numbers);
system("pause");

return 0;
}
