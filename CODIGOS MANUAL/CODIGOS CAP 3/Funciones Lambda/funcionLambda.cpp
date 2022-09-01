#include <iostream>
using namespace std;

int main() {

  // Creamos una función lambda que imprime Hola Mundo!
  auto saludar = []() {
    cout << "Hola Mundo!";
  };

  // Llamamos a la función lambda
  saludar();

  return 0;
}