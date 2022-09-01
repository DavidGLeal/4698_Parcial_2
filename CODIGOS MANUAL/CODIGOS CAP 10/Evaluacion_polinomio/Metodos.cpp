#include <iostream>
#include "Metodos.h"

using std::cout;
using std::cin;
using std::endl;

double Metodos::evaluaPolinomio1(double coef [], double x) {
double total = 0;
for (int i = 0; i < sizeof coef/sizeof coef[0] ; i++) {
// bucle 1
double xn = 1.0;
for (int j = 0; j < i; j++)
// bucle 2
xn *= x;
total += coef[i] * xn;
}
return total;
}