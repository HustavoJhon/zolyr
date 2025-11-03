```cpp

void mostrarTransacciones() {
  limpiarPantalla();
  mostrarBanner();
  cout << COLOR_MENU << "== HISTORIAL DE TRANSACCIONES ==" << COLOR_RESET << endl;

  if (pilaTrans == NULL) {
    cout << COLOR_INFO << "No hay transacciones registradas.\n" << COLOR_RESET;
  } else {
    Transaccion *aux = pilaTrans;
    while (aux != NULL) {
      cout << aux->tipo << " - " << aux->monto << endl;
      aux = aux->sig;
    }
  }

  pausa();
}

```
Explicación detallada

Entrada: ninguna.

Proceso: recorre la pila desde la cima mostrando tipo - monto.

Salida: impresión del historial en orden LIFO.

Complejidad: O(m) con m número de transacciones.