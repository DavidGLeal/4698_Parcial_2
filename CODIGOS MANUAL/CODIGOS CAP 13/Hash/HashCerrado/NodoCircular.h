#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class NodoCircular
{
private:
	int valor;
	NodoCircular *sig;
public:
	NodoCircular(int val);
	~NodoCircular();
	int getValor();
	void setValor(int _valor);
	NodoCircular* getSig();
	void setSig(NodoCircular *_sig);
};
