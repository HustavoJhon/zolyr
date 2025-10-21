#ifndef COLA_H
#define COLA_H

// cola.h
// Declaración de la cola de prioridad para la atención.

struct NodoCola {
  char dni[9];
  int prioridad; // 1 = mayor prioridad (VIP)
  NodoCola *siguiente;
};

extern NodoCola *colaAtencion;

void encolarCliente();
void atenderCliente();
void mostrarCola();

#endif // COLA_H
