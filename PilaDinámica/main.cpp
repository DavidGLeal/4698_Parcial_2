#include "Pila.cpp"
#include "Nodo.cpp"

int main(){
	Pila pila;
	
	cout<<"\tObtener mayor cuando la pila esta vacia."<<endl;
	pila.obtenerMayor();
	
	cout<<"\n\tEliminar elemento cuando la pila esta vacia.";
	pila.pop();
	
	cout<<"\tMostrar elementos cuando la pila esta vacia."<<endl;
	pila.mostrarPila();
	
	cout<<"\tInsertamos elementos."<<endl;
	pila.push(8);
	pila.push(70);
	pila.push(16);
	pila.push(15);
	pila.push(25);
	pila.push(3);
	
	cout<<"\n";
	
	cout<<"\tMostrar elementos cuando la pila tiene datos.\n"<<endl;
	pila.mostrarPila ();   
	
	cout<<"\tObtener mayor cuando la pila tiene datos."<<endl;
	pila.obtenerMayor();
	
	return 0;
}
