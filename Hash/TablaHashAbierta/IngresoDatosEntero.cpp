/*
	*Universidad de las Fuerzas Armadas "ESPE"
    *Enunciado del problema:
	    *Programa que realize hash abierto.
     *Autores:
        *Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 15-07-2022
	*Fecha de modificacion:
        * 19-07-2022
    *GitHub del grupo:	
        https://github.com/DavidGLeal/4698_Parcial_2/tree/Codigos_proyecto/Hash/TablaHashAbierta
*/

#include "IngresoDatosEntero.h"
#define LONGITUD 10

IngresoDatos::IngresoDatos(){

}

char *IngresoDatos::ingresoDatosEntero(const char *msj){
    char *dato=new char[LONGITUD+1];
    char c;
    printf("%s",msj);
    int i=0;
    while(c = getch()){
		if (c==13){
			dato[i]='\0';
			break;
		}
		else if (c == 8){ //backspace
			if (i>0){
				i--;
				printf("\b \b");
			}	
		}
		else{
			if (i<LONGITUD && c>='0'&& c<='9') //limite de longitud
			{
				printf("%c",c);
				dato[i]=c;
				i++;
			}
			
		}
	}

	return dato;

}

int IngresoDatos::convertirEntero(){
    char dato[10];
	int valor=0;
	strcpy(dato,ingresoDatosEntero(""));
	valor=atoi(dato);
	return valor;

	
}
