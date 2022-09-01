#include <stdio.h>
#include <conio.h>  
#define ELEMENTOS       3  
struct estructura_amigo {
	char nombre[30];
	char apellido[40];
	int edad;
};
struct estructura_amigo amigo[ELEMENTOS], *p_amigo;

int main(){
	int num_amigo;
	/* apuntamos al primer elemento */
	p_amigo = amigo;
	/* Introducimos los datos mediante punteros */
	for (num_amigo = 0; num_amigo<ELEMENTOS; num_amigo++)	{
		printf("Datos amigo %i\n", num_amigo);
		printf("Nombre: "); fflush(stdin);
		gets(p_amigo->nombre);
		printf("Apellido: "); fflush(stdin);
		gets(p_amigo->apellido);
		printf("Edad: "); fflush(stdin);
		scanf("%d", &p_amigo->edad);
		/* saltamos al siguiente elemento */
		p_amigo++;
	}
	/* Ahora imprimimos sus datos */
	p_amigo = amigo;
	for (num_amigo = 0; num_amigo<ELEMENTOS; num_amigo++)	{
		printf("El amigo %s ", p_amigo->nombre);
		printf("%s tiene ", p_amigo->apellido);
		printf("%d años.\n", p_amigo->edad);
		p_amigo++;
	}
    getch();
}
