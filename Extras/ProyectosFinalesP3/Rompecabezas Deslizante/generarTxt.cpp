/**
 * Project Untitled
 */
#pragma once
#include "generarTxt.h"
/**
 * GenerarTxt implementation
 */

/**
 * @param ListaCelulares
 */

void generarTxt::generarTxtCelulares(ListaCelulares lista){
    ofstream archivo;//tipo de dato para archivo
    string nombreUsuario;
    string nombreArchivo;

    cout<<"Digite el nombre del archivo: ";
    getline(cin,nombreUsuario);
    //abrir el archivo
    //C://Users//User//Desktop//Archivos//
    nombreArchivo.append("C://Users//Usuario//OneDrive//Escritorio//Archivos//").append(nombreUsuario).append(".txt");
    archivo.open(nombreArchivo,ios::out);

    if(archivo.fail()){
        cout<<"Se ha producido un error al crear el archivo"<<endl;
        return;
    }

    //llena el archivo
    if(lista.ListaVacia()){
		archivo<<"\tLa lista esta vacia "<<endl;
	}
	else{
		archivo<<"-------------INFORME STOCK EN TIENDA------------ \n"<<endl;
		NodoCelular *temp=lista.getCabeza();
		int i=1;
		while(temp->getSiguiente() !=lista.getCabeza()){//verdadero no entra
			archivo<<"\t\t"<<i<<endl;
                archivo<<"\t\tModelo: "<<temp->getCelular().getModelo()<<endl;
                archivo<<"\t\tPrecio: "<<temp->getCelular().getPrecio()<<endl;
                archivo<<"\t\tStock: "<<temp->getCelular().getStock()<<endl;
			temp=temp->getSiguiente() ;
			i++;
		}
		archivo<<"\t\t"<<i<<endl;
		archivo<<"\t\tModelo: "<<temp->getCelular().getModelo()<<endl;
        archivo<<"\t\tPrecio: "<<temp->getCelular().getPrecio()<<endl;
        archivo<<"\t\tStock: "<<temp->getCelular().getStock()<<endl;
	}
	archivo<<endl<<endl;

    //cierra el archivo
    archivo.close();
    cout<<"Se ha generado un archivo txt en la direccion: "<< nombreArchivo <<endl;
    cout<<"Con el nombre "<< nombreUsuario<<endl;
}

/**
 * @param ListaCompras
 */

void generarTxt::generarTxtCompras(ListaCompras listaC){
    ofstream archivo;//tipo de dato para archivo
    string nombreUsuario;
    string nombreArchivo;

    cout<<"Digite el nombre del archivo: ";
    getline(cin,nombreUsuario);
    //abrir el archivo
    nombreArchivo.append("C://Users//Usuario//OneDrive//Escritorio//Archivos//").append(nombreUsuario).append(".txt");
    archivo.open(nombreArchivo,ios::out);

    if(archivo.fail()){
        cout<<"Se ha producido un error al crear el archivo"<<endl;
        return;
    }

    //llena el archivo
    if(listaC.ListaVacia()){
		archivo<<"\tLa lista esta vacia "<<endl;
	}
	else{
		archivo<<"------------- INFORME VENTAS REALIZADAS ------------ \n"<<endl;
		NodoCompra *temp=listaC.getCabeza();
		int i=1;
		while(temp->getSiguiente() !=listaC.getCabeza()){//verdadero no entra
			archivo<<"\t\t"<<i<<endl;
            //imprimir nodo
            archivo<<"\t\t"<<temp->getFecha()<<endl;
            //imprimir datos cliente
            archivo<<"\t\tNombre: "<<temp->getCliente().getNombre()<<endl;
            archivo<<"\t\tApellido: "<<temp->getCliente().getApellido()<<endl;
            archivo<<"\t\tCedula: "<<temp->getCliente().getCedula()<<endl;
            archivo<<"\t\tEdad: "<<temp->getCliente().getEdad()<<endl;
            archivo<<"\t\tCorreo: "<<temp->getCliente().getCorreo()<<endl;
            archivo<<"\t\tCorreo: "<<temp->getCliente().getTelfContacto()<<endl;
            //imprimir datos celular
            archivo<<"\t\tModelo: "<<temp->getCelular().getModelo()<<endl;
            archivo<<"\t\tPrecio: "<<temp->getCelular().getPrecio()<<endl;
            archivo<<"\t\tStock: "<<temp->getCelular().getStock()<<endl;
            
            cout<<"\n\n"<<endl;
			temp=temp->getSiguiente() ;	
			i++;
		}

            archivo<<"\t\t"<<i<<endl;
            //imprimir nodo
            archivo<<"\t\t"<<temp->getFecha()<<endl;
            //imprimir datos cliente
            archivo<<"\t\tNombre: "<<temp->getCliente().getNombre()<<endl;
            archivo<<"\t\tApellido: "<<temp->getCliente().getApellido()<<endl;
            archivo<<"\t\tCedula: "<<temp->getCliente().getCedula()<<endl;
            archivo<<"\t\tEdad: "<<temp->getCliente().getEdad()<<endl;
            archivo<<"\t\tCorreo: "<<temp->getCliente().getCorreo()<<endl;
            archivo<<"\t\tCorreo: "<<temp->getCliente().getTelfContacto()<<endl;
            //imprimir datos celular
            archivo<<"\t\tModelo: "<<temp->getCelular().getModelo()<<endl;
            archivo<<"\t\tPrecio: "<<temp->getCelular().getPrecio()<<endl;
            archivo<<"\t\tStock: "<<temp->getCelular().getStock()<<endl;

	}

	archivo<<endl<<endl;



    //cierra el archivo
    archivo.close();
    cout<<"Se ha generado un archivo txt en la direccion: "<< nombreArchivo <<endl;
    cout<<"Con el nombre "<< nombreUsuario<<endl;
}

