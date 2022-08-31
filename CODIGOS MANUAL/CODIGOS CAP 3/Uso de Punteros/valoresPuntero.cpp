//Valores de Punteros
#include <iostream>

using namespace std;

int main()
{
    int valor_e=100;
    int *ptr1=&valor_e;
    int **ptr5=&ptr1;

    cout<<"el valor de valor_e es:"<<valor_e<<endl;
    cout<<"la direccion de valor_e es:"<<&valor_e<<endl;
    cout<<"el valor de ptr1 es:"<<ptr1<<endl;
    cout<<"la direccion de ptr1 es:"<<ptr1<<endl;
    cout<<"la variable apuntada por ptr1 es:"<<*ptr1<<endl;
    cout<<"el valor de ptr5 es:"<<ptr5<<endl;
    cout<<"la direccion de ptr5 es:"<<ptr5<<endl;
    cout<<"la variable apuntada por ptr5 es:"<<*ptr5<<endl;
    cout<<"la variable apuntada por ptr5 (que apunta a ptr1) es:"<<**ptr5<<endl;

    return 0;
}
