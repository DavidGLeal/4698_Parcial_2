#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
typedef struct persona
{
	char* nom;
	int edad;
	char* dir;
}PERSONA;
typedef struct alumno
{
	PERSONA p;
	char* depar;
	short nivel;
} ALUMNO;
typedef struct profesor
{
	PERSONA p;
	short expe;
}PROFESOR;
struct curso
{
	ALUMNO* ptral;
	PROFESOR* pf;
	char* descrip;
	short dias;
	short n;	/* Numero de alumnos del curso */
};

char* asigcad(void);
PERSONA* asigper(void);
PROFESOR* asigprof(void);
ALUMNO* asigalms(short n);

int main()
{
	struct curso dom;
	int j;
	printf("\n\tCurso de perfeccionamiento.\nDescripcion del curso: ");
	strcpy(dom.descrip, asigcad());
	printf("Dias lectivos del curso: ");
	scanf("%d%*c", &dom.dias);

	printf("\t Datos del profesor del curso.\n");
	dom.pf = asigprof();

	printf("\t Numero de alumnos del curso: ");
	scanf("%d%*c", &dom.n);
	dom.ptral = asigalms(dom.n);
	/* Muestra de los datos del curso */

	printf("\n\n\t\t Curso: %s\n", dom.descrip);
	puts("\t\t ---");
	printf("\tProfesor: %s\n", dom.pf->p.nom);
	printf("Relacion de asistentes al curso\n");
	for (j = 0; j<dom.n; j++)
	{
		printf("\t\t%s\n", (dom.ptral + j)->p.nom);
	}
	system("pause>null");
	return 0;

}

char* asigcad()
{
	char b[121], *cd;
	gets(b);
	cd = (char*)malloc((strlen(b) + 1)*sizeof(char));
	if (cd == NULL)
	{
		puts("/n/t!! Error de asignacion de memoria, fin de ejecucion.!!");
		exit(-1);
	}
	strcpy(cd, b);
	return cd;
}

PERSONA* asigper()
{
	PERSONA* p;
	p = (PERSONA*)malloc(sizeof(PERSONA));
	printf("\nNombre: ");
	p->nom = asigcad();
	printf("Edad: ");
	scanf("%d%*c", &p->edad);
	return p;
}

PROFESOR* asigprof()
{
	PROFESOR* t;
	t = (PROFESOR*)malloc(sizeof(PERSONA));
	t->p = *asigper();
	printf("\nAños de experiencia: ");
	scanf("%d%*c", &t->expe);
	return t;
}

ALUMNO* asigalms(short n)
{
	int j;
	ALUMNO* a;
	a = (ALUMNO*)calloc(n, sizeof(ALUMNO));
	if (a == NULL)
	{
		puts("\n\t! ! Error de asignacion de memoria, fin de ejecucion.!!");
		exit(-1);
	}

	/* Entrada de datos de cada alumno */
	for (j = 0; j<n; j++)
	{
		(a + j)->p = *asigper();
		printf("Departamento al que pertenece: ");
		(a + j)->depar = asigcad();
		printf("Nivel en que se encuentra: ");
		scanf("%d%*c", &(a + j)->nivel);
	}
	return a;
}
