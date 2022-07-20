#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "Mezcla_Directa.h"
using namespace std;

int main(){
    int num,i;
    cout<<"  -------------------------------"<<endl;
    cout<<"   Programa mezcla directa (merge_sort)         "<<endl;
    cout<<"  ------------------------------- "<<endl;
    cout<<endl<<endl;
    cout<<"Ingrese la cantidad de elementos que quiere ordenar"<<endl;
    cin>>num;
    cout<<endl;
    cout<<"Ingrese los elementos:"<<endl;
    for(i=1;i<=num;i++){
        cin>>a[i] ;
    }
    merge_sort(1,num);
    cout<<endl;
    cout<<endl<<endl;
    cout<<"El nuevo orden de los elementos ingresados es:"<<endl;
    for(i=1;i<=num;i++){
        cout<<a[i]<<"   ";
    }
    system("pause");
}