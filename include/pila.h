#ifndef PILA_H
#define PILA_H

// pila.h
// Declaración de la pila de transacciones (LIFO) y sus operaciones.

struct Transaccion {
  char tipo[20]; // "deposito" o "retiro"
  double monto;
  Transaccion *siguiente;
};

extern Transaccion *pilaTransacciones;

void registrarTransaccion();
void mostrarTransacciones();

#endif // PILA_H
