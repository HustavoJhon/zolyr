```cpp
void registrarTransaccion() {
  limpiarPantalla();
  mostrarBanner();
  cout << COLOR_MENU << "== REGISTRAR TRANSACCIÓN ==" << COLOR_RESET << endl;

  char dni[9];
  cout << "Ingrese DNI del cliente: ";
  cin >> dni;

  Cliente *cli = buscarCliente(dni);
  if (cli == NULL) {
    cout << COLOR_ERROR << "Cliente no encontrado.\n" << COLOR_RESET;
    pausa();
    return;
  }

  Transaccion *nueva = new Transaccion();
  cout << "Tipo de transacción (deposito/retiro): ";
  cin >> nueva->tipo;

  cout << "Monto: ";
  cin >> nueva->monto;

  if (nueva->monto <= 0) {
    cout << COLOR_ERROR << "Monto inválido.\n" << COLOR_RESET;
    delete nueva;
    pausa();
    return;
  }

  nueva->sig = pilaTrans;
  pilaTrans = nueva;

  cout << COLOR_OK << "\nTransacción registrada correctamente.\n"
       << COLOR_RESET;
  pausa();
}
```

Explicación detallada

Entrada: DNI (para identificar cliente), tipo de transacción, monto.

Proceso:

Busca cliente con buscarCliente. Si no existe, cancela.

Crea nodo Transaccion, lee tipo y monto.

Valida monto (>0).

Inserta al inicio de la pila (push): nueva->sig = pilaTrans; pilaTrans = nueva;.

Salida / efecto: pila pilaTrans actualizada; no retorna valor.

Complejidad: inserción O(1).

Nota de exposición: La pila conserva historial LIFO (lo último registrado aparece primero).