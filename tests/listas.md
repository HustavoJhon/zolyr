```cpp
void registrarCliente() {
  limpiarPantalla();
  mostrarBanner();
  cout << COLOR_MENU << "== REGISTRAR CLIENTE ==" << COLOR_RESET << endl;

  Cliente *nuevo = new Cliente();

  cout << "Ingrese DNI (8 dígitos): ";
  cin >> nuevo->dni;

  if (!validarDNI(nuevo->dni)) {
    cout << COLOR_ERROR << "Error: DNI inválido.\n" << COLOR_RESET;
    delete nuevo;
    pausa();
    return;
  }

  cout << "Ingrese nombre completo: ";
  cin.ignore();
  cin.getline(nuevo->nombre, 50);

  int tipoOpcion;
  cout << "\nSeleccione tipo de cliente:\n";
  cout << "1. VIP\n";
  cout << "2. Preferencial\n";
  cout << "3. Regular\n";
  cout << "Opción: ";
  cin >> tipoOpcion;

  switch (tipoOpcion) {
  case 1:
    strcpy(nuevo->tipo, "VIP");
    break;
  case 2:
    strcpy(nuevo->tipo, "Preferencial");
    break;
  case 3:
    strcpy(nuevo->tipo, "Regular");
    break;
  default:
    cout << COLOR_ERROR << "Opción inválida\n" << COLOR_RESET;
    delete nuevo;
    pausa();
    return;
  }

  nuevo->sig = NULL;

  if (listaClientes == NULL) {
    listaClientes = nuevo;
  } else {
    Cliente *aux = listaClientes;
    while (aux->sig != NULL)
      aux = aux->sig;
    aux->sig = nuevo;
  }

  cout << COLOR_OK << "\nCliente registrado exitosamente.\n" << COLOR_RESET;
  pausa();
}

```
Explicación detallada

Entrada: DNI, nombre, tipo (mediante prompts interactivas).

Proceso paso a paso:

Limpia pantalla y muestra banner.

Crea nuevo con new.

Lee y valida DNI con validarDNI. Si inválido, libera memoria y retorna.

Lee nombre con getline (asegura espacio en buffer con cin.ignore()).

Muestra menú para tipo; asigna cadena tipo. Si opción inválida, cancela.

Inserta el nodo al final de la lista (listaClientes): recorre hasta NULL y enlaza.

Salida / efecto: listaClientes se actualiza añadiendo el nuevo cliente. No retorna valor.

Complejidad: inserción al final O(n) con n número de clientes.

Precauciones: usar delete en ramas de error para evitar fugas; nombre truncado si >49 chars.