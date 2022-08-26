/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
ESTRUCTURA DE DATOS
Integrantes: Diego Portilla - Darwin Valdiviezo - Danny Quingaluisa - Alejandro Gallegos
NRC: 4698
Tema: Arbol Rojo Negro - Proyecto Segundo Parcial

*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<direct.h>
#include<string>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include"commonfunctions.h"
#include"constants.h"


void malloc_2d_string_array(char*** variable_name)
{
	*variable_name = (char**)malloc(MAX_NUMBER_OF_FILES_IN_A_DIRECTORY * sizeof(char*));
	for (int i = 0; i < MAX_NUMBER_OF_FILES_IN_A_DIRECTORY; i++)
		(*variable_name)[i] = (char*)malloc((FILE_LENGTH) * sizeof(char)); 
}

void malloc_1d_array(char** variable_name, int size)
{
	if(!((*variable_name)=(char*)malloc(size*sizeof(char))))
	{
		perror("Memory allocation error :(\n\n Exiting...\n");
		exit(-1);
	}
}


int is_file_a_directory(char* file_name_with_path)
{
	struct stat file_stat;

    // if an error occurs, we return 0 for false
    if (stat(file_name_with_path, &file_stat) < 0) 
	{
        return 0;
    }

    // otherwise we return whatever the S_ISDIR returns
}
