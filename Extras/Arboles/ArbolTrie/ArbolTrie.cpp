// ---------------------------------------
// ESTRUCTURA DE DATOS - 4698
// UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
// ALMEIDA, CALAPAQUI, HERNANDEZ Y JARA
// ---------------------------------------
#define NUMERO_DE_LETRAS 26
#include <iostream>
using namespace std;
// Estructura del Nodo Trie
class NodoTrie
{
   public:
      NodoTrie *hijo[NUMERO_DE_LETRAS];
      NodoTrie *padre = nullptr;
      bool esFinDePalabra;
      bool impreso;
      int x;
      int y;
      string letraDib;
      NodoTrie() : esFinDePalabra(false), impreso(false), x(0), y(0), letraDib("")
      {
         for (int i = 0; i < NUMERO_DE_LETRAS; i++)
            hijo[i] = NULL;
      }
      void Insertar(NodoTrie *raiz, const char *palabra);
      void imprimirTodasLasPalabras(NodoTrie *raiz, char *palabra, int pos = 0);
      void imprimirRamas(NodoTrie *raiz, char *palabra, int pos = 0);
      void imprimirNivelRec(NodoTrie *raiz, char *palabra, int pos, int num);
      void sumarNivelRec(NodoTrie *raiz, char *palabra, int pos, int num);
      void imprimirNiveles(NodoTrie *raiz, char *palabra); 
      bool esPalabraValida(NodoTrie *r, const char *palabra);
      void BorrarPalabra(NodoTrie *r, const char *palabra);
};

NodoTrie *abuelo;
int niveles = 0;
int suma = 0;

// Inserta la palabra en el Trie
void NodoTrie::Insertar(NodoTrie *raiz, const char *palabra)
{
   string letra = " ";
   for (int i = 0; palabra[i] != '\0'; i++)
   {
      if (raiz->hijo[palabra[i] - 'a'] == NULL)
      {
         raiz->hijo[palabra[i] - 'a'] = new NodoTrie;
         raiz->hijo[palabra[i] - 'a']->padre = raiz;
         letra = palabra[i];
      }
      raiz = raiz->hijo[palabra[i] - 'a'];
      if (letra != " ")
      {
         raiz->letraDib = letra;
      }
   }
   raiz->esFinDePalabra = true;
   string pal = palabra;
   if (pal.length() > niveles)
   {
      niveles = pal.length();
   }
}

// Imprime todas las palabras actuales del Trie.
void NodoTrie::imprimirTodasLasPalabras(NodoTrie *raiz, char *palabra, int pos)// = 0)
{
   if (raiz == NULL)
      return;
   if (raiz->esFinDePalabra)
   {
      for (int i = 0; i < pos; i++)
         {
            cout << palabra[i];  
         }
      cout << endl;
   }
   for (int i = 0; i < NUMERO_DE_LETRAS; i++)
   {
      if (raiz->hijo[i] != NULL)
      {
         palabra[pos] = i + 'a';
         imprimirTodasLasPalabras(raiz->hijo[i], palabra, pos + 1);
      }
   }
}

// Imprimir gráfico
void NodoTrie::imprimirRamas(NodoTrie *raiz, char *palabra, int pos)// = 0)
{
   if (raiz == NULL)
   {
      return;
   }
   if (raiz->esFinDePalabra)
   {
      for (int i = 0; i < pos; i++)
      {
         cout << palabra[i];  
      }
      cout << endl;
      for (int i = 0; i < NUMERO_DE_LETRAS; i++)
      {
         palabra[i] = ' ';
      }
   }
   for (int i = 0; i < NUMERO_DE_LETRAS; i++)
   {
      if (raiz->hijo[i] != NULL)
      {
         palabra[pos] = i + 'a';
         imprimirRamas(raiz->hijo[i], palabra, pos + 1);
      }
   }
}
// Imprimir por niveles
void NodoTrie::imprimirNiveles(NodoTrie *raiz, char *palabra)
{
   int num = niveles + 1;
   for (int i = 1; i < num; i++)
   {
      suma = 0;
      imprimirNivelRec(raiz,palabra,0,i);
      sumarNivelRec(raiz,palabra,0,i);
      cout << ": " << suma <<endl;
   }
   cout <<endl;
}
//Imprime todos los nodos de un nivel.
void NodoTrie::imprimirNivelRec(NodoTrie *raiz, char *palabra, int pos, int num)
{
   if (raiz == NULL)
   {
      return;
   }
   if (pos == num)
   {
      cout << palabra[pos-1];
   }
   for (int i = 0; i < NUMERO_DE_LETRAS; i++)
   {
      if (raiz->hijo[i] != NULL)
      {
         palabra[pos] = i + 'a';
         imprimirNivelRec(raiz->hijo[i], palabra, pos + 1, num);
      }
   }
}
//Suma todos los nodos de un nivel.
void NodoTrie::sumarNivelRec(NodoTrie *raiz, char *palabra, int pos, int num)
{
   if (raiz == NULL)
   {
      return;
   }
   if (pos == num)
   {
      suma = suma + palabra[pos-1];
   }
   for (int i = 0; i < NUMERO_DE_LETRAS; i++)
   {
      if (raiz->hijo[i] != NULL)
      {
         palabra[pos] = i + 'a';
         sumarNivelRec(raiz->hijo[i], palabra, pos + 1, num);
      }
   }
}
// Verifica si la palabra está presente en el árbol.
bool NodoTrie::esPalabraValida(NodoTrie *r, const char *palabra)
{
   if (palabra == NULL)
      {
         return true;
      }
   if (*palabra == '\0')
      {
         return r->esFinDePalabra;
      }
   if (r->hijo[*palabra - 'a'] == NULL)
      {
         return false;
      }
   return esPalabraValida(r->hijo[*palabra - 'a'], palabra + 1);
}

// Borra la Palabra del Árbol Trie si es que existe.
void NodoTrie::BorrarPalabra(NodoTrie *r, const char *palabra)
{
   if (esPalabraValida(r, palabra))
   {
      abuelo = r;
      bool salir = false;
      string pal = palabra;

      for (int i = 0; i < pal.length(); i++)
      {
         r = r->hijo[palabra[i] - 'a'];
      }
      r->esFinDePalabra = false;
      while (r != abuelo)
      {
         int hijos = 0;
         for (int i = 0; i < NUMERO_DE_LETRAS; i++)
         {
            if (r->hijo[i] != NULL)
            {
               hijos++;
            }
         }
         if (hijos < 1)
         {
            string id = r->letraDib;
            r = r->padre;
            r->hijo[id.at(0) - 'a'] = NULL;
         }
         else
         {
            r = r->padre;
         }
      }
   }
}
