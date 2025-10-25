#include <iostream>
#include <string>
using namespace std;

struct Nodo {
  string dni;
  int prioridad;
  Nodo *sig;
};

Nodo *cola = NULL;

void encolar(string dni, int pr) {
  Nodo *nuevo = new Nodo();
  nuevo->dni = dni;
  nuevo->prioridad = pr;
  nuevo->sig = NULL;

  if (cola == NULL || pr < cola->prioridad) {
    nuevo->sig = cola;
    cola = nuevo;
    return;
  }

  Nodo *aux = cola;
  while (aux->sig != NULL && aux->sig->prioridad <= pr)
    aux = aux->sig;

  nuevo->sig = aux->sig;
  aux->sig = nuevo;
}

void mostrar() {
  Nodo *aux = cola;
  while (aux != NULL) {
    cout << aux->dni << " (P=" << aux->prioridad << ")\n";
    aux = aux->sig;
  }
}

int main() {
  encolar("A", 3);
  encolar("B", 1);
  encolar("C", 2);
  encolar("D", 1);

  mostrar();
  return 0;
}
