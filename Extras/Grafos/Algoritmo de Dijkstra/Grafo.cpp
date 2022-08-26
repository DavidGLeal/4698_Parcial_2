#include "Grafo.h"

void Grafo::inicializacion(){
    for( int i = 0 ; i <= vertices ; ++i ){
        distancia_entre_nodos[ i ] = INF;  //inicializamos todas las distancias con valor infinito
        nodo_visitado[ i ] = false; //inicializamos todos los vertices como no visitados
        nodo_previo[ i ] = -1;      //inicializamos el previo del vertice i con -1
    }
}

//Paso de relajacion
void Grafo::relajacion( int actual , int adyacente , int peso ){
    //Si la distancia del origen al vertice actual + peso de su arista es menor a la distancia del origen al vertice adyacente
    if( distancia_entre_nodos[ actual ] + peso < distancia_entre_nodos[ adyacente ] ){
        distancia_entre_nodos[ adyacente ] = distancia_entre_nodos[ actual ] + peso;  //relajamos el vertice actualizando la distancia
        nodo_previo[ adyacente ] = actual;                         //a su vez actualizamos el vertice previo
        Q.push( Node( adyacente , distancia_entre_nodos[ adyacente ] ) ); //agregamos adyacente a la cola de prioridad
    }
}

//Impresion del camino mas corto desde el vertice inicial y final ingresados
void Grafo::impresion( int destino ){
    if( nodo_previo[ destino ] != -1 )    //si aun poseo un vertice nodo_previo
        impresion( nodo_previo[ destino ] );  //recursivamente sigo explorando
    printf("%d " , destino );        //terminada la recursion imprimo los vertices recorridos
}

void Grafo::algoritmo_dijkstra( int inicial ){
    inicializacion(); //inicializamos nuestros arreglos
    Q.push( Node( inicial , 0 ) ); //Insertamos el v?rtice inicial en la Cola de Prioridad
    distancia_entre_nodos[ inicial ] = 0;      //Este paso es importante, inicializamos la distancia del inicial como 0
    int actual , adyacente , peso;
    while( !Q.empty() ){                   //Mientras cola no este vacia
        actual = Q.top().first;            //Obtengo de la cola el nodo con menor peso, en un comienzo ser? el inicial
        Q.pop();                           //Sacamos el elemento de la cola
        if( nodo_visitado[ actual ] ) continue; //Si el vrtice actual ya fue nodo_visitado entonces sigo sacando elementos de la cola
        nodo_visitado[ actual ] = true;         //Marco como visitado el v?rtice actual

        for( int i = 0 ; i < matriz_adyacente[ actual ].size() ; ++i ){ //reviso sus adyacentes del vertice actual
            adyacente = matriz_adyacente[ actual ][ i ].first;   //id del vertice adyacente
            peso = matriz_adyacente[ actual ][ i ].second;        //peso de la arista que une actual con adyacente ( actual , adyacente )
            if( !nodo_visitado[ adyacente ] ){        //si el vertice adyacente no fue visitado
                relajacion( actual , adyacente , peso ); //realizamos el paso de relajacion
            }
        }
    }


    printf( "Distancias mas cortas iniciando en vertice %d\n" , inicial );
    for( int i = 1 ; i <= vertices ; ++i ){
        printf("Vertice %d , distancia mas corta = %d\n" , i , distancia_entre_nodos[ i ] );
    }

    puts("\n**************Impresion de camino mas corto**************");
    printf("Ingrese vertice destino: ");
    int destino;
    scanf("%d" , &destino );
    impresion( destino );
    printf("\n");
}
