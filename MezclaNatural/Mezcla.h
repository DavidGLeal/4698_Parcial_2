#include <stdlib.h>
#include <string.h>
#include <stdio.h>
class Mezcla
{

public:
    Mezcla();
    void Mostrar(FILE *fich);
    void Mezcla_(FILE *fich);
    void Separar(FILE *fich, FILE **aux);
    int Mezclar(FILE *fich, FILE **aux);
};
