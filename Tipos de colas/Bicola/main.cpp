#include"Bicola.cpp"
int main(){
	//Creamos nuestro objeto de la clase Bicola
	Bicola bicola;
	//Insertamos al frente
	bicola.ponerFrente(5);
	bicola.ponerFrente(7);
	//Insertamos al final
	bicola.ponerFinal(9);
	bicola.ponerFrente(3);
	//Imprimimos los valores de la bicola
	bicola.mostrarBicola();
	cout<<endl;
	//Eliminamos datos por el frente y final
	cout<<"Elemento eliminado: "<<bicola.quitarFinal()<<endl;
	cout<<"Elemento eliminado: "<<bicola.quitarFrente()<<endl;
	//Imprimimos los valores de la bicola
	bicola.mostrarBicola();
	
	return 0;
}