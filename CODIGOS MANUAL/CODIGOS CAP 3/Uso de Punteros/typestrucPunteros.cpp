#include <iostream>
//definimos la estructura
typedef struct {
	char *nombre;// inializacion del puntero
	unsigned calif;//inializacion de variable sin signo
} Alumno;//nombre de la estructura
unsigned mayor_calif(Alumno *p)//metodo sin signo para order el mayor numero
{
	unsigned mayor = 0;
	for (; p->nombre; p++)
		if (p->calif > mayor)
			mayor = p->calif;
	return mayor;
}
int main(){
	Alumno *p, grupo[] = {//asignacion de valores a la variable de la  estructura alumno
		{ "Juan", 73 },
		{ "Ana", 86 },
		{ "Luis", 89 },
		{ NULL, 0 }
	};
	//impresion de datos en pantalla
	printf("|--------------|\n");
	for (p = grupo; p->nombre; p++)
		printf("| %6s | %3d |\n", p->nombre, p->calif);
	printf("|--------------|\n");
	printf("\nla calificacion mas alta del grupo es: %d",mayor_calif(grupo));
	printf(" ");
	printf(" ");
	system("pause");
}
