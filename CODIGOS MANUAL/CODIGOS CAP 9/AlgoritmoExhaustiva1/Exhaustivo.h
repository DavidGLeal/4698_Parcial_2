#include <iostream>

class Exhaustivo
{

public:
    Exhaustivo(/* args */);
    int metodoexhaustivo(int cabeza, int pie, int *pollo, int *conejo);
    ~Exhaustivo();
};

Exhaustivo::Exhaustivo(/* args */)
{
}

Exhaustivo::~Exhaustivo()
{
}

int Exhaustivo::metodoexhaustivo(int cabeza, int pie, int *pollo, int *conejo)
{
    int re, i, j;
    re = 0;
    for (i = 0; i <= cabeza; i++) // ciclo
    {
        j = cabeza - i;
        if (i * 2 + j * 4 == pie) // Condicion
        {
            re = 1; // Encuentra la respuesta
            *pollo = i;
            *conejo = j;
        }
    }
    return re;
}