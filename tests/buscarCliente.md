```cpp
Cliente *buscarCliente(const char *dni) {
  Cliente *aux = listaClientes;
  while (aux != NULL) {
    if (strcmp(aux->dni, dni) == 0)
      return aux;
    aux = aux->sig;
  }
  return NULL;
}

```

Explicación detallada

Entrada: DNI a buscar (const char *).

Proceso: recorre la lista usando strcmp por cada nodo hasta encontrar coincidencia.

Salida: puntero Cliente* si encuentra, NULL si no.

Complejidad: O(n).

Uso: utilizada por registrarTransaccion, encolarCliente, etc.


Mostrar clientes
```cpp
void mostrarClientes() {
  limpiarPantalla();
  mostrarBanner();
  cout << COLOR_MENU << "== LISTA DE CLIENTES ==" << COLOR_RESET << endl;

  if (listaClientes == NULL) {
    cout << COLOR_INFO << "No hay clientes registrados.\n" << COLOR_RESET;
  } else {
    Cliente *aux = listaClientes;
    while (aux != NULL) {
      cout << aux->dni << " - " << aux->nombre << " (" << aux->tipo << ")\n";
      aux = aux->sig;
    }
  }

  pausa();
}

```

Explicación detallada

Entrada: ninguna.

Proceso: imprime cada nodo de la lista con formato DNI - nombre (tipo).

Salida: visual en consola; si lista vacía muestra mensaje informativo.

Complejidad: O(n).