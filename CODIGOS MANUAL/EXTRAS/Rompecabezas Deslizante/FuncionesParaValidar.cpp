/***********************************************************************
 * Module:  FuncionesParaValidar.cpp
 * Author:  matia
 * Modified: Thursday, June 9, 2022 9:32:06 PM
 * Purpose: Implementation of the class FuncionesParaValidar
 ***********************************************************************/

#include "FuncionesParaValidar.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////
// Name:       FuncionesParaValidar::ingresarDatos(const char* msj)
// Purpose:    Implementation of FuncionesParaValidar::ingresarDatos()
// Parameters:
// - msj
// Return:     char*
////////////////////////////////////////////////////////////////////////

char* FuncionesParaValidar::ingresarDatos(const char* msj)
{
   	char *dato=new char[10],c;
	int i=0;
	int pos=0,k=0;
	printf("%s",msj);	
	while((c=getch())!=13)
	{
		if(c>='0' && c<='9')
		{
			printf("%c",c);
			dato[i++]=c;
        }else if(c==8)
		{
			printf("\n");
			if(k==0)
			{
				dato[i--]=' ';
			}else{
				for(int j=k;j<i;j++)
				{
					dato[j-1]=dato[j];

				}
				dato[i--]=' ';
				k=0;
				pos=0;
			}
			
			for(int y=0;y<i;y++)
			{
				printf("%c",dato[y]);
			}
		}
		else if (c==75)
		{
			printf("\b");
			pos++;
			k =i-pos;
		}
		else if(c==77)
		{
			
			printf("\n");
			for(int j=k+1;j<i;j++)
				{
			dato[j]=dato[j+1];
				}
				dato[i--]=' ';
				k=0;
				pos=0;
			for(int y=0;y<i;y++)
			{
				printf("%c",dato[y]);
			}
		}	
	}
	dato[i]='\0';
	return dato;
}

////////////////////////////////////////////////////////////////////////
// Name:       FuncionesParaValidar::ingresarDatosReales(const char* msj)
// Purpose:    Implementation of FuncionesParaValidar::ingresarDatosReales()
// Parameters:
// - msj
// Return:     char*
////////////////////////////////////////////////////////////////////////

char* FuncionesParaValidar::ingresarDatosReales(const char* msj)
{
   	char *dato=new char[10],c;
	int i=0,x=0;
	int pos=0,k=0;
	bool present;
	printf("%s",msj);
	while((c=getch())!=13)
	{
		
		if((c>='0' && c<='9')||c=='.')
		{
			if(c=='.'&& !present)
			{
				dato[i++]=c;
				printf("%c",c);
				present=true;
			}else if(c>='0' && c<='9'){
				dato[i++]=c;
				printf("%c",c);
			}

		}else if(c==8)
		{
			printf("\n");
			if(k==0)
			{
				if(dato[i]=='.')
				{
					present=false;
				}
				dato[i--]=' ';
			}else{
				for(int j=k;j<i;j++)
				{
					if(dato[j-1]=='.')
					{
						present=false;
					}
					dato[j-1]=dato[j];
				}
				dato[i--]=' ';
				k=0;
				pos=0;
			}
			for(int y=0;y<i;y++)
			{
				printf("%c",dato[y]);
			}
		}
		else if (c==75)
		{
			printf("\b");
			pos++;
			k =i-pos;
		}
		else if(c==77)
		{
			printf("\n");
			for(int j=k+1;j<i;j++)
				{
					dato[j]=dato[j+1];

				}
				dato[i--]=' ';
				k=0;
				pos=0;
			for(int y=0;y<i;y++)
			{
				printf("%c",dato[y]);
			}

		}
	}
	dato[i]='\0';
	return dato;
}

////////////////////////////////////////////////////////////////////////
// Name:       FuncionesParaValidar::validarNombre(char c[])
// Purpose:    Implementation of FuncionesParaValidar::validarNombre()
// Parameters:
// - c[]
// Return:     int
////////////////////////////////////////////////////////////////////////


int FuncionesParaValidar::validarNombre(char c[])
{
   	int i;
	for(i=0; i<strlen(c);i++)
	{
	 	if(!(c[i]>=65 && c[i]<=90 ||c[i]>=97 && c[i]<=122||c[i]==32))
	 	{
	 		printf("Error: unicamente se puden ingresar letras");
	 		return 0;
	 	}	
	}
	return 1;
}