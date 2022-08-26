void imprimeInverso(Posicion p, Lista l)
{
	int aux;

	if (p != FinLista(l)) {
		imprimeInverso(Siguiente(p, l), l);
		Recuperar(&aux, p, l);
		print("%d", aux);
	}
}
