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