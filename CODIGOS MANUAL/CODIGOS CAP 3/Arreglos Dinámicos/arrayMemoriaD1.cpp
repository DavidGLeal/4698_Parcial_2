#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <conio.h>
#define MAX 20


using namespace std;

typedef struct jugador{ //Estructura principal LLamada "jugador"

char nombre[15];
char apellido[15];
int num;
char posicion[15];
char nacionalidad[15];
float peso;
int edad;
float altura;
}j;

//void presentacion();
j lectura();
void impresion(int, jugador*);

int main(){

system("cls");
system("COLOR 3F");

//Reservamos memoria dinamica con el uso del operador new
jugador *fichas = new j[MAX];
//presentacion();

//variables
int i = 0, jug = 1;
char op;
//usamos el do y realiza la misma accion hasta q el usuario diga que no.
do{
system("cls");
cout << "\t\t\t\tINGRESO DE DATOS DEL ESTUDIANTE" << endl;
cout << "INGRESO DE DATOS DEL JUGADOR " << jug << endl;;
fichas[i] = lectura();
i++; jug++;
cout << "desea ingresar otro registro, escriba n para no y 0 para si? : ";
cin >> op;

} while (i<MAX && op != 'N'&& op != 'n');

//imprimimos los datos.
system("cls");
cout << "\t\t\t\tIMPRESION DE DATOS DEL ESTUDIANTE" << endl;
impresion(i, fichas);

//Limpiamos la memoria con el uso de la funcion free();
free(fichas);

_getch();
}
j lectura(){
int i = 0;
jugador x;
static int in = 0;

cout << "Ingresar el nombre del jugador:       ";
fflush(stdin);
cin >> x.nombre;
cout << "Ingresar el apellido del jugador:     ";
fflush(stdin);
cin >> x.apellido;
cout << "Ingresar la posicion en la que juega: ";
fflush(stdin);
cin >> x.posicion;
cout << "Ingresar la nacionalidad del jugador: ";
fflush(stdin);
cin >> x.nacionalidad;
cout << "Ingresar el peso del jugador:         ";
fflush(stdin);
cin >> x.peso;
cout << "Ingresar la edad del jugador:         ";
fflush(stdin);
cin >> x.edad;
cout << "Ingresar la altura del jugador:       ";
fflush(stdin);
cin >> x.altura;

return x;
}
void impresion(int i, jugador *ficha){
int cont = 1;
for (int a = 0; a<i; a++){
cout << endl;
cout << "Datos del jugador" << cont << endl;
cout << endl;
cout << "Nombre del jugador " << cont << ":       " 
<<  ficha[a].nombre << endl;
cout << "Apellido del jugador " << cont << ":     " 
<< ficha[a].apellido << endl;
cout << "Nacionalidad del jugador " << cont << ": " 
<< ficha[a].nacionalidad << endl;
cout << "posicion del jugador " << cont << ":     " 
<< ficha[a].posicion << endl;
cout << "edad del jugador " << cont << ":    " 
<< ficha[a].edad << endl;
cout << "peso del jugador " << cont << ":    " 
<< ficha[a].peso << endl;
cout << "altura del jugador " << cont << ":  " 
<< ficha[a].altura << endl;
cout << endl;
cont++;
}
}
