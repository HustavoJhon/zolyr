#ifndef CLIENTE_H
#define CLIENTE_H

// cliente.h
// Definición de la estructura Cliente y declaraciones de funciones
// relativas a la lista enlazada de clientes.

struct Cliente {
  char dni[9];     // DNI como cadena de 8 caracteres + '\0'
  char nombre[50]; // Nombre completo (máx. 49 caracteres)
  char tipo[15];   // Tipo: "VIP", "Preferencial", "Regular"
  Cliente *siguiente;
};

// Puntero global a la lista (declarado extern en .cpp)
extern Cliente *listaClientes;

// Operaciones públicas para la lista de clientes
void inicializarClientes(); // opcional, inicializa la lista
void registrarCliente();    // registro interactivo (entrada por consola)
Cliente *buscarCliente(const char *dni);
void mostrarClientes();

#endif // CLIENTE_H
