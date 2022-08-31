/*Universidad de las Fuerzas Armadas - ESPE
PROYECTO - Parcial 3: 
Por medio de un algoritmo de busqueda exhaustiva, ordenar una matriz de colores en función de sus códigos RGB.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 20/08/2022
FECHA DE MODIFICACIÓN: 23/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/
#pragma once
#include "Login.h"

using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Login::Login()
// Purpose:     Implementation of Login::Login()
// Parameters:
// Return:     
////////////////////////////////////////////////////////////////////////

Login::Login()
{
	
}

////////////////////////////////////////////////////////////////////////
// Name:       Login::verificarIngreso()
// Purpose:     Implementation of Login::verificarIngreso()
// Parameters:
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Login::verificarIngreso()
{
	string usuarios[4]={"admin1","admin2"};
	string contras[4]={"adminpass1","adminpass2"};
	string user;
	char cpass;
	bool pasar=false;
	while(pasar==false)
	{
		system("cls");
		cout<<"\n \t\t\t\tINICIE SESION \n";
		cout<<"\tIngrese su usuario: ";
		cin>>user;
		cout<<"\tIngrese su contrasena: ";
		
        cpass=getch();
        string pass="";
        
        while (cpass!=13)
		{
            if (cpass!= 8)
			{
                pass.push_back(cpass);
                cout<<"*";
            }
            else{
                if (pass.length()>0)
				{
                    cout<<"\b \b";
                    pass=pass.substr(0, pass.length()-1);
                }
                
            }
            cpass=getch();     
        }
		for(int i=0;i<=sizeof(usuarios);i++)
		{
			if(user==usuarios[i] && pass==contras[i])
			{
				pasar=true;
				break;
			}
		}
	}
	return pasar;
}
