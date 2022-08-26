Lista Mezcla2(Lista l1, Lista l2)
{	Lista L;
	Posicion p1, p2;
	int aux1, aux2;
	/*En la lista L guardaremos el resultado*/
	L = CrearLista(sizeof(int));
	/*Utilizamos p1 y p2 para recorrer las dos listas*/
	p1 = PrimeroLista(l1);
	p2 = PrimeroLista(l2);
	/*Obtenemos los elementos apuntados por p1 y p2 ,el menor*/
	/*de ellos se inserta en el resultado y se adelanta en una*/
	/*posicion.Se repite el proceso hasta que una lista queda */
	/*sin elementos (cuando p1 o p2 llegan al final) */
	while (p != FinLista(l1) && p2 != FinLista(l2)) {
		Recuperar(&aux1, p1, l1);
		Recuperar(&aux2, p2, l2);
		if (aux1 < aux2) {
			p1 = Siguiente(p1, l1);
			Insertar(&aux1, FinLista(L), L);
		}
		else {
			p2 = Siguiente(p2, l2);
			Insertar(&aux2, FinLista(L), L);
		}
	}
	/*Si p1 no ha llegado al final hay que vaciar l1 al final*/
	/*de la lista resultado*/
	While(p1 != FinLista(l1)) {
		Recuperar(&aux1, p1, l1);
		p1 = Siguiente(p1, l1);
		Insertar(&aux1, FinLista(L), L);
	}
	/*Si p2 no ha llegado al final hay que vaciar l2 al final*/
	/*de la lista resultado*/
	while (p2 != FinLista(l2)) {
		Recuperar(&aux2, p2, l2);
		p2 = Siguiente(p2, l2);
		Insertar(&aux2, FinLista(L), L);
	}
	/*Devolvemos L como resultado estando ya l1 y l2 vacias */
	return L;
}
