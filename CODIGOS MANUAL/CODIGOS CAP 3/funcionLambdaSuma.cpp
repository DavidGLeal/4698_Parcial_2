#include<iostream>
using namespace std;

int main() {


  auto operacion = []  (int a, int b,  string op) -> double {
    if (op == "suma") {
      return a + b;
    }
    else {
      return (a + b) / 2.0;
    }
  };

  int num1 = 1;
  int num2 = 2;


  auto suma = operacion(num1, num2, "suma"); 
  cout << "Suma = " << suma << endl;


  auto promedio = operacion(num1, num2, "promedio"); 
  cout << "Promedio = " << promedio;

  return 0;
}