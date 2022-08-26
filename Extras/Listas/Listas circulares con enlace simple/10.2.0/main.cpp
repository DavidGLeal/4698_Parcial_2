void Lista() {
	inicio = null;
	ultimo = null;
	tamanio = 0;
}
boolean  Circular::esVacia() {
	return inicio == null;
}
int Circular::getTamanio() { return tamanio; }
void agregarAlFinal(int valor) {
	Nodo nuevo = new Nodo();
	nuevo.setValor(valor);
	if (esVacia()) {
		inicio = nuevo;
		ultimo = nuevo;
		ultimo.setSiguiente(inicio);
	}
	else {
		ultimo.setSiguiente(nuevo);
		nuevo.setSiguiente(inicio);
		ultimo = nuevo;
	}
	tamanio++;
}
void Circular::agregarAlInicio(int valor) {
	Nodo nuevo = new Nodo();
	nuevo.setValor(valor);
	if (esVacia()) {
		inicio = nuevo;
		ultimo = nuevo;
		ultimo.setSiguiente(inicio);
	}
	else {
		nuevo.setSiguiente(inicio);
		inicio = nuevo;
		ultimo.setSiguiente(inicio);
	}
	tamanio++;
}
public int getValor(int posicion) throws Exception {
	if (posicion >= 0 && posicion<tamanio) {
		if (posicion == 0) {
			return inicio.getValor();
		}
		else {
			Nodo aux = inicio;
			for (int i = 0; i < posicion; i++) {
				aux = aux.getSiguiente();
			}
			return aux.getValor();
		}
	}
	else {
		throw new Exception("Posicion inexistente en la lista.");
        }
    }

void Lista() {
	inicio = null;
	ultimo = null;
	tamanio = 0;
}
boolean  Circular::esVacia() {
	return inicio == null;
}
int Circular::getTamanio() { return tamanio; }
void agregarAlFinal(int valor) {
	Nodo nuevo = new Nodo();
	nuevo.setValor(valor);
	if (esVacia()) {
		inicio = nuevo;
		ultimo = nuevo;
		ultimo.setSiguiente(inicio);
	}
	else {
		ultimo.setSiguiente(nuevo);
		nuevo.setSiguiente(inicio);
		ultimo = nuevo;
	}
	tamanio++;
}
void Circular::agregarAlInicio(int valor) {
	Nodo nuevo = new Nodo();
	nuevo.setValor(valor);
	if (esVacia()) {
		inicio = nuevo;
		ultimo = nuevo;
		ultimo.setSiguiente(inicio);
	}
	else {
		nuevo.setSiguiente(inicio);
		inicio = nuevo;
		ultimo.setSiguiente(inicio);
	}
	tamanio++;
}
public int getValor(int posicion) throws Exception {
	if (posicion >= 0 && posicion<tamanio) {
		if (posicion == 0) {
			return inicio.getValor();
		}
		else {
			Nodo aux = inicio;
			for (int i = 0; i < posicion; i++) {
				aux = aux.getSiguiente();
			}
			return aux.getValor();
		}
	}
	else {
		throw new Exception("Posicion inexistente en la lista.");
        }
    }
public boolean buscar(int referencia) {
Nodo aux = inicio;
boolean encontrado = false;
do {
if (referencia == aux.getValor()) {
encontrado = true;
}
else {
aux = aux.getSiguiente();
}
} while (aux != inicio && encontrado != true);
return encontrado;
}
public int getPosicion(int referencia) throws Exception {
if (buscar(referencia)) {
Nodo aux = inicio;
int cont = 0;
while (referencia != aux.getValor()) {
cont++;
aux = aux.getSiguiente();
}
return cont;
}
else {
throw new Exception("Valor inexistente en la lista.");
}
}

public void removerPorReferencia(int referencia) {
if (buscar(referencia)) {
if (inicio.getValor() == referencia) {
inicio = inicio.getSiguiente();
ultimo.setSiguiente(inicio);
}
else {
Nodo aux = inicio;
while (aux.getSiguiente().getValor() != referencia) {
aux = aux.getSiguiente();
}
if (aux.getSiguiente() == ultimo) {
aux.setSiguiente(inicio);
ultimo = aux;
}
else {
Nodo siguiente = aux.getSiguiente();
aux.setSiguiente(siguiente.getSiguiente());
}
}
tamanio--;
}
}

public void removerPorPosicion(int posicion) {
if (posicion >= 0 && posicion<tamanio) {
if (posicion == 0) {
inicio = inicio.getSiguiente();
ultimo.setSiguiente(inicio);
}
else {
Nodo aux = inicio;
for (int i = 0; i < posicion - 1; i++) {
aux = aux.getSiguiente();
}
if (aux.getSiguiente() == ultimo) {
aux.setSiguiente(inicio);
ultimo = aux;
}
else {

Nodo siguiente = aux.getSiguiente();
aux.setSiguiente(siguiente.getSiguiente());
}
}
tamanio--;
}
}
public void eliminar() {
inicio = null;
ultimo = null;
tamanio = 0;
}
public void listar() {
if (!esVacia()) {
Nodo aux = inicio;
int i = 0;
System.out.print("-> ");
do {
System.out.print(i + ".[ " + aux.getValor() + " ]" + " ->  ");
aux = aux.getSiguiente();
i++;
} while (aux != inicio);
}
}