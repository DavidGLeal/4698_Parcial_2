
#include "ArbolJuego.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ArbolJuego bst;
	bst.insertar(33);
	bst.insertar(44);
	bst.insertar(67);
	bst.insertar(5);
	bst.insertar(89);
	bst.insertar(41);
	bst.insertar(98);
	bst.insertar(1);
	bst.imprimirBonito();
	cout<<"\n";
	bst.inorden();
	cout<<"\n";
	cout<<"-------------------------------\n";
	bst.buscarArbol(17);
	cout<<"-------------------------------\n";
	bst.imprimirBonito();
	bst.eliminarNodo(89);
	cout<<"-------------------------------\n";
	bst.imprimirBonito();
	return 0;
}