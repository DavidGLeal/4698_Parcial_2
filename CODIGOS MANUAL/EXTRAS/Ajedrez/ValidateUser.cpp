/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
    INGENIERA DE SOFTWARE
                
	AUTORES:    Luca de Veintemilla
				Kevin Vargas 
                Cristopher Iza
                Denisse Rea
					
	FECHA DE CREACION:        20-05-2022 	
	FECHA DE MODIFICACION:    24-05-2022
	Grupo #6
*/
#include "ValidateUser.hpp"

bool ValidateUser::validate_Login(string Id, string password)
{
    string id2,last_n,paswd,name;
    bool find=false;

    ifstream file_Data;
    file_Data.open("Datos.txt",ios::out | ios::in);
    
    if (file_Data.is_open())
    {
            file_Data>>name;
            while (!file_Data.eof()){
            file_Data>>last_n>>id2>>paswd;
            if (id2==Id && paswd== password)
            {
                find=true;
            }
            file_Data>>id2;
       }
    }
    file_Data.close();
    return find;
}

  
bool ValidateUser::validate_UserName(string userName){
    string id2,last_n,paswd,name;
    bool find=false;

    ifstream file_Data;
    file_Data.open("Datos.txt",ios::out | ios::in);
    
    if (file_Data.is_open())
    {
            file_Data>>name;
            while (!file_Data.eof()){
            file_Data>>last_n>>id2>>paswd;
            if (userName==id2)
            {
                find=true;
            }
            file_Data>>id2;
       }
    }
    file_Data.close();
    return find;
}

void ValidateUser:: Register_Data(string name,string Last_name,string user,string password){
    ofstream file_Data;
    file_Data.open("Datos.txt", ios::out | ios::app);
    if (file_Data.is_open())
    {
        file_Data<<"\n"<<name<<" "<<Last_name<<" "<<user<<" "<<password;
    }
    file_Data.close();
}
