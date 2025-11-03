```cpp
truct Cliente {
  char dni[9];        // DNI del cliente
  char nombre[50];    // Nombre del cliente
  char tipo[15];      // Tipo de cliente (regular, premium, etc.)
  Cliente *sig;       // Puntero al siguiente cliente en la lista (lista enlazada)
};

struct Transaccion {
  char tipo[20];      // Tipo de transacción (depósito, retiro, etc.)
  double monto;       // Monto de la transacción
  Transaccion *sig;   // Puntero a la siguiente transacción (lista enlazada)
};

struct NodoCola {
  char dni[9];        // DNI del cliente en la cola
  int prioridad;      // Prioridad del cliente (define el orden de atención)
  NodoCola *sig;      // Puntero al siguiente nodo en la cola (lista enlazada)
};

```
Explicación detallada

Cliente

Entrada: valores al crear un nodo (DNI, nombre, tipo).

Proceso: se enlaza para crear lista de clientes.

Salida / modifica: la lista enlazada listaClientes cambia al insertar/eliminar.

Transaccion

Modela operaciones financieras; usado como nodos de una pila (LIFO).

NodoCola

Nodo para la cola de prioridad: contiene DNI y prioridad numérica.

Notas: Arreglos char[] con tamaño fijo obligan a validar longitudes al ingresar datos.