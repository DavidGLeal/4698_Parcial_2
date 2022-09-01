
#include <iostream>
#include <ctime>
#include <fstream>

class Backup
{
public:
    Backup();
    ~Backup();
    void generarBackup();
    void recuperarBackup(string nombre);
};
