// ============================================================
// FINPROC - Sistema de Simulación Bancaria
// ============================================================
// Autor: @hustavojhon
// Curso: Estructura de Datos
// Descripción: Este programa simula la atención de clientes en un
// banco, usando estructuras dinámicas simples y validaciones.
// ============================================================

#include <cstring>
#include <iostream>
using namespace std;

#define COLOR_RESET "\033[0m"
#define COLOR_TITULO "\033[1;36m"
#define COLOR_MENU "\033[1;33m"
#define COLOR_INFO "\033[1;37m"
#define COLOR_ERROR "\033[1;31m"
#define COLOR_OK "\033[1;32m"

struct Cliente {
  char dni[9];
  char nombre[50];
  char tipo[15];
  Cliente *sig;
};

struct Transaccion {
  char tipo[20];
  double monto;
  Transaccion *sig;
};

struct NodoCola {
  char dni[9];
  int prioridad;
  NodoCola *sig;
};

// ============================================================
// Punteros globales
// ============================================================

Cliente *listaClientes = NULL;
Transaccion *pilaTrans = NULL;
NodoCola *cola = NULL;

// ============================================================
// Funciones de utilidad
// ============================================================

// Limpia la consola
void limpiarPantalla() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

// Pausa hasta que el usuario presione Enter
void pausa() {
  cout << COLOR_INFO << "\nPresione Enter para continuar..." << COLOR_RESET;
  cin.ignore();
  cin.get();
}

// Muestra el banner principal
void mostrarBanner() {
  cout << COLOR_TITULO;
  cout << "============================================\n";
  cout << "   FINPROC - SISTEMA DE ATENCIÓN BANCARIA   \n";
  cout << "============================================\n";
  cout << COLOR_RESET;
}

// Verifica si un DNI es válido (8 dígitos numéricos)
bool validarDNI(const char *dni) {
  if (strlen(dni) != 8)
    return false;
  for (int i = 0; i < 8; i++) {
    if (dni[i] < '0' || dni[i] > '9')
      return false;
  }
  return true;
}

// ============================================================
// Funciones de lista enlazada
// ============================================================

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

  // Submenú para tipo de cliente
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
    cout << COLOR_ERROR << "Opción inválida.\n" << COLOR_RESET;
    delete nuevo;
    pausa();
    return;
  }

  nuevo->sig = NULL;

  // Insertar al final de la lista
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

Cliente *buscarCliente(const char *dni) {
  Cliente *aux = listaClientes;
  while (aux != NULL) {
    if (strcmp(aux->dni, dni) == 0)
      return aux;
    aux = aux->sig;
  }
  return NULL;
}

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

// ============================================================
// Funciones de pila
// ============================================================

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

void mostrarTransacciones() {
  limpiarPantalla();
  mostrarBanner();
  cout << COLOR_MENU << "== HISTORIAL DE TRANSACCIONES ==" << COLOR_RESET
       << endl;

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

// ============================================================
// Funciones de cola de prioridad
// ============================================================

int obtenerPrioridad(const char *tipo) {
  if (strcmp(tipo, "VIP") == 0)
    return 1;
  if (strcmp(tipo, "Preferencial") == 0)
    return 2;
  return 3;
}

void encolarCliente() {
  limpiarPantalla();
  mostrarBanner();
  cout << COLOR_MENU << "== ENCOLAR CLIENTE ==" << COLOR_RESET << endl;

  char dni[9];
  cout << "Ingrese DNI: ";
  cin >> dni;

  Cliente *cli = buscarCliente(dni);
  if (cli == NULL) {
    cout << COLOR_ERROR << "Cliente no existe.\n" << COLOR_RESET;
    pausa();
    return;
  }

  NodoCola *nuevo = new NodoCola();
  strcpy(nuevo->dni, dni);
  nuevo->prioridad = obtenerPrioridad(cli->tipo);
  nuevo->sig = NULL;

  if (cola == NULL || nuevo->prioridad < cola->prioridad) {
    nuevo->sig = cola;
    cola = nuevo;
  } else {
    NodoCola *aux = cola;
    while (aux->sig != NULL && aux->sig->prioridad <= nuevo->prioridad)
      aux = aux->sig;
    nuevo->sig = aux->sig;
    aux->sig = nuevo;
  }

  cout << COLOR_OK << "Cliente encolado correctamente.\n" << COLOR_RESET;
  pausa();
}

void atenderCliente() {
  limpiarPantalla();
  mostrarBanner();
  cout << COLOR_MENU << "== ATENDER CLIENTE ==" << COLOR_RESET << endl;

  if (cola == NULL) {
    cout << COLOR_INFO << "No hay clientes en cola.\n" << COLOR_RESET;
    pausa();
    return;
  }

  cout << "Atendiendo a cliente con DNI: " << cola->dni << endl;
  NodoCola *temp = cola;
  cola = cola->sig;
  delete temp;

  cout << COLOR_OK << "Cliente atendido con éxito.\n" << COLOR_RESET;
  pausa();
}

void mostrarCola() {
  limpiarPantalla();
  mostrarBanner();
  cout << COLOR_MENU << "== COLA DE ATENCIÓN ==" << COLOR_RESET << endl;

  if (cola == NULL) {
    cout << COLOR_INFO << "No hay clientes en cola.\n" << COLOR_RESET;
  } else {
    NodoCola *aux = cola;
    while (aux != NULL) {
      cout << aux->dni << " (Prioridad " << aux->prioridad << ")\n";
      aux = aux->sig;
    }
  }
  pausa();
}

int main() {
  int opcion;
  do {
    limpiarPantalla();
    mostrarBanner();
    cout << COLOR_MENU;
    cout << "1. Registrar cliente\n";
    cout << "2. Encolar cliente\n";
    cout << "3. Atender cliente\n";
    cout << "4. Registrar transacción\n";
    cout << "5. Mostrar clientes\n";
    cout << "6. Mostrar cola\n";
    cout << "7. Mostrar transacciones\n";
    cout << "0. Salir\n";
    cout << COLOR_RESET;
    cout << "\nSeleccione una opción: ";
    cin >> opcion;

    switch (opcion) {
    case 1:
      registrarCliente();
      break;
    case 2:
      encolarCliente();
      break;
    case 3:
      atenderCliente();
      break;
    case 4:
      registrarTransaccion();
      break;
    case 5:
      mostrarClientes();
      break;
    case 6:
      mostrarCola();
      break;
    case 7:
      mostrarTransacciones();
      break;
    case 0:
      cout << COLOR_INFO << "\nSaliendo del sistema...\n" << COLOR_RESET;
      break;
    default:
      cout << COLOR_ERROR << "\nOpción inválida. Intente nuevamente.\n"
           << COLOR_RESET;
      pausa();
      break;
    }
  } while (opcion != 0);

  return 0;
}
