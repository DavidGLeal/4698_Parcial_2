#include "OrdenamientoSectores.h"
#include "2OrdenamientoInterno.h"

OrdenamientoSectores::OrdenamientoSectores(int total_fragmentos)
{
    _vector = new Vector;
    _total_fragmentos = total_fragmentos;
}

void OrdenamientoSectores::rellenar(int cantidad, int minimo, int maximo)
{
	for (int i = 0; i < cantidad; i++) {
        _vector->push_back(aleatorio_entre(minimo, maximo));
	}
}

void OrdenamientoSectores::ordenamiento_zambrano_cristopher() {
	OrdenamientoInterno ordenamientoInterno;
	int inicio = 0;
	int contador = 0;
	int* arreglo = _vector->getArrayInterno();
	int tamanio = _vector->size();

	std::cout << "arreglo original: \n";

	for (int i = 0; i < 100; i++) {
		std::cout << i + 1 << ": " << *(arreglo + i) << "\n";
	}

	for (int i = 0; i < 100; i++) {
		contador++;

		if (contador == _total_fragmentos || (contador < _total_fragmentos && i == (tamanio - 1))) {
			int posfinal = (_total_fragmentos + inicio > tamanio ? tamanio - inicio : _total_fragmentos);
			shell_sort(arreglo + inicio, posfinal);
			contador = 0;
			inicio = i;
			inicio++;
		}
	}

	std::cout << "\n\n\narreglo ordenado: \n";

	for (int i = 0; i < 100; i++) {
		std::cout << i + 1 << ": " << *(arreglo + i) << "\n";
	}
}

int OrdenamientoSectores::aleatorio_entre(int minimo, int maximo)
{
    return rand() % (maximo - minimo + 1) + minimo;
}

void OrdenamientoSectores::shell_sort(int* arreglo, int tamanio) {
	int j, incremento, aux; // incremento: Tamaño del bloque de separación de los elementos dentro del método Shell.
	incremento = tamanio / 2; // De acuerdo al algoritmo original, el incremento se divide en 2 en cada iteración.
	while (incremento > 0)
	{
		for (int i = incremento; i < tamanio; i++)
		{
			j = i - incremento; // j es un índice de secuenciamiento.
			while (j >= 0)
			{
				if (*(arreglo + j) >= *(arreglo + j + incremento)) // Se comparan los elementos distales a un factor incremental de separación.
				{
					aux = *(arreglo + j); // Se intercambian los valores, logrando el ordenamiento.
					*(arreglo + j) = *(arreglo + j + incremento);
					*(arreglo + j + incremento) = aux;
				}
				else
				{
					j = 0; // Se retrocede el índice de secuenciamiento del vector.
				}
				j = j - incremento;
			}
		}
		incremento = incremento / 2; // Se divide el bloque de comparación en cada iteración.
	}
}

