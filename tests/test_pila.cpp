#include <iostream>
using namespace std;

struct Trans {
  string tipo;
  double monto;
  Trans *sig;
};

Trans *pila = NULL;

void push(string tipo, double monto) {
  Trans *nuevo = new Trans();
  nuevo->tipo = tipo;
  nuevo->monto = monto;
  nuevo->sig = pila;
  pila = nuevo;
}

void pop() {
  if (pila == NULL) {
    cout << "Pila vacia.\n";
    return;
  }
  cout << "Se elimina: " << pila->tipo << " - " << pila->monto << "\n";
  Trans *aux = pila;
  pila = pila->sig;
  delete aux;
}

void mostrar() {
  Trans *aux = pila;
  while (aux != NULL) {
    cout << aux->tipo << " - " << aux->monto << "\n";
    aux = aux->sig;
  }
}

int main() {
  push("deposito", 200);
  push("retiro", 100);
  push("consulta", 0);

  mostrar();
  pop();
  mostrar();

  return 0;
}
