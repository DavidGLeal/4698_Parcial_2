#include <iostream>
#include "Lista_Circular_Doblemente_Enlazada.cpp"

using namespace std;
int main()
{
    Lista_Circular_Doblemente_Enlazada lst;
    int op=0,num;
	do{
	do{
	system("cls");
	cout<<"Escoja: ";
	cout<<"\n 1) Insertar"<<endl;
	cout<<"\n 2) Eliminar  "<<endl;
	cout<<"\n 3) Mostrar "<<endl;
	cout<<"\n 4) Buscar "<<endl;
	cout<<"\n 5) Finalizar programa "<<endl;
	cout<<"\n Seleccione una opcion"<<endl;
	cin>>op;
	}while(op<1 || op >8);
    system("cls");
		if(op==1){	
            cout<<"Ingreso"<<endl;
            cin>>num;
			lst.Insertar(num);
			cout<<"\nPresione Doble Enter  para continuar...";
			getchar();
			getchar();
		}
		else if(op==2){
            cout<<"Ingreso"<<endl;
            cin>>num;
            lst.Eliminar(num);
			cout<<"\nPresione Doble Enter para continuar...";
			getchar();
			getchar();
		}
		else if(op==3){
            lst.Mostrar();
			cout<<"Presione Doble Enter  para continuar...";
			getchar();
			getchar();
			}
		else if(op==4){
            cout<<"Ingreso"<<endl;
            cin>>num;
            lst.Buscar(num);
			cout<<"Presione Doble Enter para continuar...";
			getchar();
			getchar();
			}
		else{	
			lst.~Lista_Circular_Doblemente_Enlazada();
			exit(0);
		}
		}while(op!=5);
	return 0;
}
