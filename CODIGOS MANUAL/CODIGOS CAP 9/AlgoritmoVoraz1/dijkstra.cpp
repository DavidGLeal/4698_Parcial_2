#include "dijkstra.h"

dijkstra::dijkstra(/* args */)
{
}

dijkstra::~dijkstra()
{
}

void dijkstra::metododijkstra(int vertices, int origen, int destino, int *costos)
{
    int i, v, cont = 0;
    int *ant, *tmp;
    int *z; /* vertices para los cuales se conoce el
   camino minimo */
    double min;
    double *dist = new double[vertices]; /* vector con los costos de
   dos caminos */
    /* aloca las lineas de la matriz */
    ant = new int[vertices];
    tmp = new int[vertices];
    if (ant == NULL)
    {
        cout << "** Error: Memoria Insuficiente **";
        exit(-1);
    }
    z = new int[vertices];
    if (z == NULL)
    {
        cout << "** Error: Memoria Insuficiente **";
        exit(-1);
    }
    for (i = 0; i < vertices; i++)
    {
        if (costos[(origen - 1) * vertices + i] != -1)
        {
            ant[i] = origen - 1;
            dist[i] = costos[(origen - 1) * vertices + i];
        }
        else
        {
            ant[i] = -1;
            dist[i] = HUGE_VAL;
        }
        z[i] = 0;
    }
    z[origen - 1] = 1;
    dist[origen - 1] = 0;
    /* Bucle principal */
    do
    {
        /* Encontrando el vertice que debe entrar en z */
        min = HUGE_VAL;
        for (i = 0; i < vertices; i++)
            if (!z[i])
                if (dist[i] >= 0 && dist[i] < min)
                {
                    min = dist[i];
                    v = i;
                }
        /* Calculando las distancias de los nodos vecinos de z */
        if (min != HUGE_VAL && v != destino - 1)
        {
            z[v] = 1;
            for (i = 0; i < vertices; i++)
                if (!z[i])
                {
                    if (costos[v * vertices + i] != -1 && dist[v] +
                                                                  costos[v * vertices + i] <
                                                              dist[i])
                    {
                        dist[i] = dist[v] + costos[v * vertices + i];
                        ant[i] = v;
                    }
                }
        }
    } while (v != destino - 1 && min != HUGE_VAL);
    /* Muestra el resultado de la búsqueda */
    cout << "\tDe " << origen << " para " << destino << " \t";
    if (min == HUGE_VAL)
    {
        cout << "No Existe\n";
        cout << "\tCoste: \t- \n";
    }
    else
    {
        i = destino;
        i = ant[i - 1];
        while (i != -1)
        {
            // printf("<-%d",i+1);
            tmp[cont] = i + 1;
            cont++;
            i = ant[i];
        }
        for (i = cont; i > 0; i--)
        {
            cout << tmp[i - 1] << " -> ";
        }
        cout << destino;
        cout << "\n\tCoste: " << dist[destino - 1] << "\n";
    }
    delete (dist);
    delete (ant);
    delete (tmp);
    delete (z);
}
void dijkstra::add(void)
{
    do
    {
        cout << "\nInforme o numero de vertices (no minimo 2 ): ";
        cin >> vertices;
    } while (vertices < 2);
    if (!custos)
        delete (custos);
    custos = new int[vertices * vertices];
    for (int i = 0; i <= vertices * vertices; i++)
        custos[i] = -1;
    cout << "Ya tenemos el número de vertices. Nº Vertices = " << vertices << endl;
    cout << "Ahora unamos los vértices:\n";
    bool sigo = true;
    int origen;
    int destino;
    while (sigo)
    {
        cout << "Escoga el primer vértice de la arista: " << endl;
        do
        {
            cin >> origen;
            if (origen > vertices)
            {
                cout << "Me temo que se ha equivocado al hacer la selección.El número de vertice ha de ser menor de " << vertices << endl;
            }
        } while (origen > vertices);
        cout << "Escoga el segundo vértice de la arista: " << endl;
        do
        {
            cin >> destino;
            if (destino > vertices)
            {
                cout << "Me temo que se ha equivocado al hacer la selección.El número de vertice ha de ser menor de " << vertices << endl;
            }
        } while (destino > vertices);
        int peso = 0;
        cout << "Ahora queda el peso" << endl;
        cin >> peso;
        custos[(origen - 1) * vertices + destino - 1] = peso;
        int seguir = 1;
        cout << "Quiere añadir otra arista (0 - NO, 1 - SÍ, por defecto 1): ";
        cin >> seguir;
        sigo = (seguir == 1);
    }
}

void dijkstra::buscar(void)
{
    int i, j;
    cout << "Lista dos Menores Caminos en Grafo Dado: \n";
    for (i = 1; i <= vertices; i++)
    {
        for (j = 1; j <= vertices; j++)
            metododijkstra(vertices, i, j, custos);
        cout << endl;
    }
    cout << "<Presione ENTER para volver al menu principal. \n";
}