int Suma(Lista L, Posicion inicial, Posicion final)
{
	int n;

	if (inicial != final) {
		Recuperar(&n, inicial, L);
		return n + Suma(L, Siguiente(inicial, L), final);
	}
	else return 0;
}
