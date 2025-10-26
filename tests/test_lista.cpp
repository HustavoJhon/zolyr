#include <iostream>
#include <string>
using namespace std;

struct Cliente {
  string dni;
  string nombre;
  string tipo;
  Cliente *sig;
};

Cliente *lista = NULL;

void agregar(string dni, string nombre, string tipo) {
  Cliente *nuevo = new Cliente();
  nuevo->dni = dni;
  nuevo->nombre = nombre;
  nuevo->tipo = tipo;
  nuevo->sig = lista;
  lista = nuevo;
}

void mostrar() {
  Cliente *aux = lista;
  while (aux != NULL) {
    cout << aux->dni << " - " << aux->nombre << " (" << aux->tipo << ")\n";
    aux = aux->sig;
  }
}

int main() {
  agregar("11111111", "Ana", "VIP");
  agregar("22222222", "Luis", "Regular");
  agregar("33333333", "Carlos", "Preferencial");

  mostrar();
  return 0;
}
