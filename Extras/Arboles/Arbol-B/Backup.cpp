
#include "Backup.h"

Backup::Backup()
{
}

Backup::~Backup()
{
}

void Backup::generarBackup(){
    time_t t;
    t=time(NULL);
    struct tm *f;
    f=localtime(&t);

    int dia,mes,anio,hora,min;
    dia=f->tm_mday;
    mes=f->tm_mon+1;
    anio=f->tm_year+1900;
    hora=f->tm_hour;
    min=f->tm_min;

    std::string linea;
    std::string texto,texto1,texto2, texto3;
    string fecha;
	string direccion;
    std::string anio1=(std::to_string(anio));
    std::string mes1=(std::to_string(mes));
    std::string dia1=(std::to_string(dia));
    std::string hora1=(std::to_string(hora));
    std::string min1=(std::to_string(min));
    fecha = "C:\\Users\\Juan F. Reyes\\Desktop\\Proyecto_Arboles_B\\Backups\\"+dia1+"-"+mes1+"-"+anio1+"-"+hora1+"h"+min1+"m"+"_Backupnumeros"+".txt";
	ifstream original("numeros.txt");
    while (getline(original,linea))
    {
        texto=texto+linea+"\n";
    }
    original.close();
    ofstream backup;
    backup.open(fecha);
    backup<<texto;
    backup.close();
    
    fecha = "C:\\Users\\Juan F. Reyes\\Desktop\\Proyecto_Arboles_B\\Backups\\"+dia1+"-"+mes1+"-"+anio1+"-"+hora1+"h"+min1+"m"+"_Backupborrar"+".txt";
    ifstream original1("borrar.txt");
    while (getline(original1,linea))
    {
        texto1=texto1+linea+"\n";
    }
    original1.close();
    ofstream backup1;
    backup1.open(fecha);
    backup1<<texto1;
    backup1.close();
    
    ifstream original2("usuarios.dat");
    fecha = "C:\\Users\\Juan F. Reyes\\Desktop\\Proyecto_Arboles_B\\Backups\\"+dia1+"-"+mes1+"-"+anio1+"-"+hora1+"h"+min1+"m"+"_Backupusuarios"+".dat";
    while (getline(original2,linea))
    {
        texto2=texto2+linea+"\n";
    }
    original2.close();
    ofstream backup2;
    backup2.open(fecha);
    backup2<<texto2;
    backup2.close();
    
    ifstream original3("prueba.txt");
    fecha = "C:\\Users\\Juan F. Reyes\\Desktop\\Proyecto_Arboles_B\\Backups\\"+dia1+"-"+mes1+"-"+anio1+"-"+hora1+"h"+min1+"m"+"_BackupPrueba"+".txt";
    while (getline(original3,linea))
    {
        texto3=texto3+linea+"\n";
    }
    original3.close();
    ofstream backup3;
    backup3.open(fecha);
    backup3<<texto3;
    backup3.close();
}

void Backup::recuperarBackup(string nombre){
	time_t t;
    t=time(NULL);
    struct tm *f;
    f=localtime(&t);

    int dia,mes,anio,hora,min;
    dia=f->tm_mday;
    mes=f->tm_mon+1;
    anio=f->tm_year+1900;
    hora=f->tm_hour;
    min=f->tm_min;

    std::string linea;
    std::string texto,texto1,texto2, texto3;
    string fecha;
	string direccion;
    std::string anio1=(std::to_string(anio));
    std::string mes1=(std::to_string(mes));
    std::string dia1=(std::to_string(dia));
    std::string hora1=(std::to_string(hora));
    std::string min1=(std::to_string(min));
	direccion = "C:\\Users\\Juan F. Reyes\\Desktop\\Proyecto_Arboles_B\\Backups\\" + nombre;
	ifstream original("numeros.txt");
    while (getline(original,linea))
    {
        texto=texto+linea+"\n";
    }
    original.close();
	ofstream rec;
	rec.open(direccion);
	rec <<texto;
	rec.close(); 
	
	ifstream original1("borrar.txt");
    while (getline(original1,linea))
    {
        texto1=texto1+linea+"\n";
    }
    original1.close();
    ofstream rec1;
    rec1.open(direccion);
    rec1<<texto1;
    rec1.close();
    
    ifstream original2("usuarios.dat");
    while (getline(original2,linea))
    {
        texto2=texto2+linea+"\n";
    }
    original2.close();
    ofstream rec2;
    rec2.open(direccion);
    rec2<<texto2;
    rec2.close();
    
    ifstream original3("prueba.txt");
    while (getline(original3,linea))
    {
        texto3=texto3+linea+"\n";
    }
    original3.close();
    ofstream rec3;
    rec3.open(direccion);
    rec3<<texto3;
    rec3.close();  
}
