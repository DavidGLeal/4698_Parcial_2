#include <iostream>
//Declaramos la estructura kids
struct {
    //declaracion de los miembros de la estructura
	char initial;
	int age;
	int grade;

} kids[12], *point;

int main(){
	int index;
	for (index = 0; index < 12; index++) {
		point = kids + index;//asignamos al puntero point el valor de kids ´+ index
		point->initial = 'A' + index;
		point->age = index;
		point->grade = 84;
	}
	//asignamos valores a las posiciones del arreglo kinds
	kids[3].age = kids[5].age = 17;
	kids[2].grade = kids[6].grade = 92;
	kids[4].grade = 57;
	//imprimimos los datos guardados
	for (index = 0; index < 12; index++) {
		point = kids + index;
		printf("%c tiene %d anios y un grado escolar de %d\n",
        (*point).initial, kids[index].age,
     	point->grade);
	}
	system("pause");
	return 0;
}
