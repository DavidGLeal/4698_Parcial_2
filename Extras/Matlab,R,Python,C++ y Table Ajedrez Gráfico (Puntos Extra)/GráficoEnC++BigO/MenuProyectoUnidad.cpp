
/*Universidad de las Fuerzas Armadas - ESPE
TAREA #3 - Parcial 3: 
Graficar, en base a algoritmos, los distintos casos de la notación asintótica Big O.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 18/08/2022
FECHA DE MODIFICACIÓN: 19/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/


/***********************************************************************
 * Module:  MenuProyectoUnidad.cpp
 * Author:  matia
 * Modified: Thursday, June 9, 2022 9:35:53 PM
 * Purpose: Implementation of the class MenuProyectoUnidad
 ***********************************************************************/

#include "MenuProyectoUnidad.h"
#include "BigO.cpp"
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

////////////////////////////////////////////////////////////////////////
// Name:       MenuProyectoUnidad::menuCursor(const char* titulo, const char* opciones[], int n)
// Purpose:    Implementation of MenuProyectoUnidad::menuCursor()
// Parameters:
// - titulo
// - opciones[]
// - n
// Return:     int
////////////////////////////////////////////////////////////////////////
int fib(int n){

    if(n < 2)
        return n;
        
    return fib(n-1) + fib(n-2);
  }
  
  int divide(int *array, int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;

    pivot = array[start];
    left = start;
    right = end;

    // Mientras no se cruzen los índices
    while (left < right) {
        while (array[right] > pivot) {
            right--;
        }

        while ((left < right) && (array[left] <= pivot)) {
            left++;
        }

        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }

    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[right];
    array[right] = array[start];
    array[start] = temp;

    // La nueva posición del pivot
    return right;
}
void quicksort(int *array, int start, int end)
{
    int pivot;

    if (start < end) {
        pivot = divide(array, start, end);

        // Ordeno la lista de los menores
        quicksort(array, start, pivot - 1);

        // Ordeno la lista de los mayores
        quicksort(array, pivot + 1, end);
    }
}

int MenuProyectoUnidad::menuCursor(const char* titulo, const char* opciones[], int n)
{
   	int opcionSeleccionada = 1;
	int tecla;
	bool repite = true;
	
	do
	{
		system("cls");
		
	    gotoxy(5, 3 + opcionSeleccionada); cout << "==>";
	    
	    //Imprime el título
	    gotoxy(15,2); cout << titulo;
	    
	    //Imprime las opciones
	    int i;
	    
	    for((i=0);(i<n);(i++))
	    {
	    	gotoxy(10, 4 + i); cout << i+1 << ") " << opciones[i];
		}
		
		do
		{
			tecla = getch();
		}
		while(tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);
		
		switch(tecla)
		{
			case TECLA_ARRIBA:
				opcionSeleccionada --;
				
				if (opcionSeleccionada < 1)
				{
					opcionSeleccionada = n;
				}
				
				break;
			
			case TECLA_ABAJO:
				opcionSeleccionada ++;
				
				if (opcionSeleccionada > n)
				{
					opcionSeleccionada = 1;
				}
				
				break;
				
			case ENTER:
				repite = false;
				break;
		}
    }
    while(repite);
	
	return opcionSeleccionada;
}

////////////////////////////////////////////////////////////////////////
// Name:       MenuProyectoUnidad::gotoxy(int x, int y)
// Purpose:    Implementation of MenuProyectoUnidad::gotoxy()
// Parameters:
// - x
// - y
// Return:     void
////////////////////////////////////////////////////////////////////////

void MenuProyectoUnidad::gotoxy(int x, int y)
{
   	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition(hCon, dwPos);
}

////////////////////////////////////////////////////////////////////////
// Name:       MenuProyectoUnidad::presentarMenu()
// Purpose:    Implementation of MenuProyectoUnidad::presentarMenu()
// Return:     void
////////////////////////////////////////////////////////////////////////

void MenuProyectoUnidad::presentarMenu(void)
{
	BigO BO(700,600);
	FuncionesParaValidar objFunVal;	
	const char *tituloGeneral = "NOTACION ASINTOTICA BIG(O)";
	const char *opcionesGeneral[] = {"O(1)", "O(n)","O(n^2)",
	"O(n^3)","O(2^n)","O(log(n))","O(n*log(n))","Salir."};	
	int op=0,nGenerales=8;	
	char nombre[50];
	do{	 
		op=menuCursor(tituloGeneral,opcionesGeneral,nGenerales);
		switch(op){
			case 1:{
				system("cls");
				cout<<"\nHola mundo"<<endl<<"Caracteres: 11"<<endl;
			  	BO.o1(11);
			  	system("cls");
				break;
			}
			case 2: {
				system("cls");				
				int n=10;
				cout<<"n = "<<n<<endl<<endl;
				for(int i=0;i<n;i++)
				{
					cout<<i<<endl;
				}
				
			  	BO.oN(n);
				system("cls");
				break;
			}
			case 3:{
				system("cls");
				int n=5;
				cout<<"n = "<<n<<endl<<endl;
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<n;j++)
					{
						cout<<j<<"\t";
					}
					cout<<endl;
				}
				
			  	BO.oCua(n);
			  	system("cls");
				break;
			}
			case 4:
			{	system("cls");
				int n=0;
 				cout<<"\nIngrese el orden: \n";
 				cin>>n;
 				int matriz[n][n];

    			for(int i = 0; i < n; i++)//Ciclo externo
    			{
       
        			for(int j = 0; j < n; j++)//Ciclo interno
        			{
            			for(int k=0;k<n;k++){
            				matriz[i][j] = (i+k+1)*(j+k+1);	
					}
            		cout<<matriz[i][j]<<" ";
        		}
        		cout<<endl;
    
    }
			  	BO.oCub(n);
			  	cin.ignore();
			  	system("cls");
	          	break;
			}
			case 5:{	
				system("cls");
				int n;
				cout<<"Ingrese el numero de terminos a calcular: "<<endl;
  				cin >> n;
  				cout<<endl;
				fib(n);
				for(int i =0; i <= n-1; i++)
					cout << fib(i) << " ";

			  	BO.o2N(n);
			  	cin.ignore();
				break;
			}
			case 6:
			{
				system("cls");
				int numero;
				cout << "Introduzca un numero: ";
				cin >> numero;
				int numeros[] = {1,6,7,8,9,12,15,18,19,29};
				int tamano = sizeof(numeros) /sizeof(int);
				int limiteIzquierdo = 0;
				int limiteDerecho = tamano - 1;
				int puntoMedio = 0;
				bool est =false;
				while (limiteIzquierdo <= limiteDerecho){
					puntoMedio = (limiteIzquierdo + limiteDerecho) / 2;
					if(numeros[puntoMedio] < numero){
						limiteIzquierdo = puntoMedio + 1;
					}else if(numeros[puntoMedio] > numero){
						limiteDerecho = puntoMedio -1;
					}else{
						est=true;
						break;
					}
				}
				if(est)
				{
					cout << numero << " esta contenido en el arreglo" << endl;
				}
				else
					cout << numero << " no esta contenido en el arreglo" << endl;
			  	BO.oLog(numero);
			  	cin.ignore();
			  	system("cls");
				break;
			}
			case 7:
				{
					system("cls");
					int n=10;
					
					int a[n]={80, 45, 3, 95, 15, 2, 10, 50, 43, 22};
				    cout << "Array antes de ordenarse: " << endl;
				    for (int i = 0; i < n; i++) {
				        cout << a[i] << " ";
				    }
				    cout << endl << endl;
				
				    quicksort(a, 0, n - 1);
				    cout << "Array ordenado " << endl;
				    for (int i = 0; i < n; i++ ){
				        cout << a[i] << "-";
				    }
				    cout << endl << endl;
			  		BO.oNLog(n);
			  		system("cls");
					break;
				}
			case 8:{
				system("cls");
				cout<<"\nGracias por usar nuestro programa."<<endl;
				exit(EXIT_SUCCESS);
				break;
			}
				
			default:
				{
					printf("\nComando no reconocido. Vuelva a intentar.\n");
					system("pause");
					break;
				}
			}			
		}while(op!=8);
}