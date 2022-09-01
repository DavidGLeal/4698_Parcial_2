#include "Nodo.h"

Nodo::Nodo()
{
    strcpy_s(ID, "");
    strcpy_s(nombre, "");
    n1 = 0.00;
    n2 = 0.00;
    n3 = 0.00;
    promedio = 0.00;
    sig = NULL;
}

Nodo::~Nodo()
{
}
void Nodo::setID(char *i)
{
    strcpy(ID, i);
}
char *Nodo::getID()
{
    return ID;
}
void Nodo::setNombre(char *nom)
{
    strcpy(nombre, nom);
}
char *Nodo::getNombre()
{
    return nombre;
}
void Nodo::setN1(float n)
{
    n1 = n;
}
float Nodo::getN1()
{
    return n1;
}
void Nodo::setN2(float no)
{
    n2 = no;
}
float Nodo::getN2()
{
    return n2;
}
void Nodo::setN3(float nota)
{
    n3 = nota;
}

float Nodo::getN3()
{
    return n3;
}

float Nodo::getPromedio()
{
    return promedio;
}
void Nodo::setsig(lista sgt)
{
    sig = sgt;
}
Nodo *Nodo::getsig()
{
    return sig;
}
float Valorpromedio(float n1, float n2, float n3)
{
    float prome = 0;
    prome = (n1 + n2 + n3) / 3;
    return prome;
}

// Validacion solo letras
void Nodo::ingreso(char *cd)
{
    char c;
    int i = 0;
    while ((c = _getch()) != 13)
    {
        c = tolower(c);
        if (c >= 'a' && c <= 'z')
        {
            printf("%c", c);
            *(&(*cd) + i) = c;
            i++;
        }
    }
    // cd[i++] = '\0'; //Toda cadena termina con \0, siempre toca poner el \0.
}

void Nodo::insertar(lista &lis, fin &f, char *id, char *n, float n1, float n2, float n3, int &numeroNodos)
{
    Nodo *nuevo;

    nuevo = new Nodo;
    nuevo->setID(id);
    fflush(stdin);
    nuevo->setNombre(n);
    nuevo->setN1(n1);
    nuevo->setN2(n2);
    nuevo->setN3(n3);
    nuevo->promedio = Valorpromedio(nuevo->n1, nuevo->n2, nuevo->n3);
    nuevo->sig = NULL;
    if (lis == NULL)
    {
        cout << "PRIMER ELEMENTO..!!!\n";
        lis = nuevo;
        lis->sig = lis;
        f = nuevo;
        numeroNodos++;
    }
    else
    {
        nuevo->sig = lis;
        lis = nuevo;
        f->sig = lis;
        numeroNodos++;
    }
}

void Nodo::mostrar(lista lis)
{
    lista auxiliar;
    auxiliar = new (Nodo);
    auxiliar = lis;
    int Pos = 0;
    if (lis != NULL)
    {
        do
        {
            Pos++;
            cout << Pos << "\t" << auxiliar->getID() << "\t" << auxiliar->getNombre() << "\t" << auxiliar->getN1() << "\t" << auxiliar->getN2() << "\t" << auxiliar->getN3() << "\t" << auxiliar->getPromedio() << endl;
            auxiliar = auxiliar->getsig();

        } while (auxiliar != lis);
    }
    else
    {
        printf("\n");
        printf("\t\t------------------------");
        printf("\n\t\tLa lista esta vacia!!!");
        printf("\n\t\t------------------------\n");
    }
}

void Nodo::agregarCPosicion(lista &listInicio, lista &listFinal, int posicion, char Nombre[], char ID[], float n1, float n2, float n3, int &numeroNodos)
{
    lista aux = new (Nodo);
    lista aux2 = new (Nodo);
    lista aux3 = new (Nodo);
    lista nuevoDato = new (Nodo);
    aux = listInicio;
    aux2 = listFinal;
    aux3 = aux->getsig();
    for (int i = 1; i < posicion; i++)
    {
        aux = aux->getsig();
        aux3 = aux3->getsig();
    }
    nuevoDato->setID(ID);
    nuevoDato->setNombre(Nombre);
    nuevoDato->setN1(n1);
    nuevoDato->setN2(n2);
    nuevoDato->setN3(n3);
    nuevoDato->promedio = Valorpromedio(nuevoDato->n1, nuevoDato->n2, nuevoDato->n3);
    aux->setsig(nuevoDato);
    nuevoDato->setsig(aux3);
    numeroNodos++;
    printf("\n");
    printf("\t\t-----------------------------");
    printf("\n\t\tDato Agregado Correctamente");
    printf("\n\t\t-----------------------------\n");
}
void Nodo::eliminar(lista &lis)
{
    lista p, aux, actual;
    p = lis;
    actual = lis;
    char id[5];
    cout << "Buscar Id a eliminar\n";
    cin >> id;
    string str1(id);
    if (lis != NULL)
    {

        do
        {
            if (str1.compare(p->getID()) == 0)
            {
                if (p == lis)
                {
                    if (lis == lis->getsig())
                    {
                        delete (lis);
                        lis = NULL;
                    }
                    else
                    {
                        lis = lis->getsig();
                    }
                }
                else
                    aux->setsig(p->getsig());
                delete (p);
                if (lis == actual)
                    return;
            }
            if (actual == p->getsig())
            {
                p->setsig(lis);
                actual = lis;
                return;
            }
            aux = p;
            p = p->getsig();
        } while ((actual != p) || (lis != NULL));
    }
    else
    {
        cout << " Lista vacia..!";
    }
}
