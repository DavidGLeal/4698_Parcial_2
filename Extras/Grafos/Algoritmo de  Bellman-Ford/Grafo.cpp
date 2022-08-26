#include "Grafo.h"

void Grafo::inicializar(){
    for( int i = 0 ; i <= vertices ; ++i ){
        distancia_entre_nodos[ i ] = INF;  
        nodo_previo[ i ] = -1;      
    }
}

void Grafo::impresion( int destino ){
    if( nodo_previo[ destino ] != -1 )    
        impresion( nodo_previo[ destino ] );  
    printf("%d " , destino );        
}

bool Grafo::relajacion( int actual , int adyacente , int peso ){
    
    if( distancia_entre_nodos[ actual ] + peso < distancia_entre_nodos[ adyacente ] ){
        distancia_entre_nodos[ adyacente ] = distancia_entre_nodos[ actual ] + peso;  
        nodo_previo[ adyacente ] = actual;                         
        return true;                                          
    }
    return false; 
}

void Grafo::bellmanFord( int inicial ){
    inicializar(); 
    distancia_entre_nodos[ inicial ] = 0;      

    
    for( int i = 1 ; i <= vertices - 1 ; ++i ){ 
        for( int actual = 1 ; actual <= vertices ; ++actual ){  
            for( int j = 0 ; j < matriz_adyacente[ actual ].size() ; ++j ){ 
                int adyacente = matriz_adyacente[ actual ][ j ].first;    
                int peso = matriz_adyacente[ actual ][ j ].second;        
                
                relajacion( actual , adyacente , peso );
            }
        }
    }

    
    for( int actual = 1 ; actual <= vertices ; ++actual ){  
        for( int j = 0 ; j < matriz_adyacente[ actual ].size() ; ++j ){ 
            int adyacente = matriz_adyacente[ actual ][ j ].first;    
            int peso = matriz_adyacente[ actual ][ j ].second;       
            
            if( relajacion( actual , adyacente , peso ) ){
                puts("Existe Ciclo Negativo");
                return;
            }
        }
    }

    puts("No Existe Ciclo Negativo");

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