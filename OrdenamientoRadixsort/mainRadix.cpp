#include <iostream>
#include <stdlib.h>
#include "Radix.cpp"
#include "0Vector.cpp"


using namespace std;
int main(){

	Radix *radix = new Radix();
	Vector v;
    v.push_back(954);
    v.push_back(354);
    v.push_back(9);
    v.push_back(411);
    v.push_back(236);
    v.push_back(537);
    v.push_back(800);
    v.push_back(459);
    v.push_back(328);
    v.push_back(691);
    radix->setVector(v);

                cout<<"\t\tRADIX"<<endl;
                if(v.empty()){
                    cout << "\nNo ha ingresado datos. Vector vacio" <<endl;
                    system("pause");
                }else{  
                cout<<"\n Arreglo sin ordenar"<<endl;
                radix->imprimirInterno();
                radix->ordenarRadix();                          
                cout<<"\n Arreglo ordenado"<<endl;
                radix->imprimirInterno();
                cout<< "\n~~~ Datos ordenados con exito ~~~\n"<<endl;
                system("pause");
                }
                
                return 0;
            }   
