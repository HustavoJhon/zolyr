// ============================================================
// FINPROC - Sistema de Simulaci贸n Bancaria
// ============================================================
// Autor: @hustavojhon
// Curso: Estructura de Datos
// Descripci贸n: Este programa simula la atenci贸n de clientes en un
// banco, usando estructuras din谩micas simples y validaciones.
// ============================================================

#include <cstring>
#include <iostream>
using namespace std;

// Definici髇 de constantes para colores que se usar醤 en la salida del terminal
#define COLOR_RESET "\033[0m"  // Reset del color
#define COLOR_TITULO "\033[1;36m"  // Color para los t韙ulos (cyan)
#define COLOR_MENU "\033[1;33m"  // Color para los men鷖 (amarillo)
#define COLOR_INFO "\033[1;37m"  // Color para la informaci髇 general (blanco)
#define COLOR_ERROR "\033[1;31m"  // Color para los mensajes de error (rojo)
#define COLOR_OK "\033[1;32m"  // Color para los mensajes de 閤ito (verde)

// Estructura Cliente: Define a un cliente con su informaci髇 b醩ica
struct Cliente {
  char dni[9];  // DNI del cliente (identificaci髇)
  char nombre[50];  // Nombre del cliente
  char tipo[15];  // Tipo de cliente (por ejemplo, 'regular', 'premium', etc.)
  Cliente *sig;  // Puntero al siguiente cliente en la lista (para crear una lista enlazada)
};

// Estructura Transaccion: Define las transacciones realizadas por los clientes
struct Transaccion {
  char tipo[20];  // Tipo de transacci髇 (por ejemplo, 'dep髎ito', 'retiro', etc.)
  double monto;  // Monto involucrado en la transacci髇
  Transaccion *sig;  // Puntero a la siguiente transacci髇 (enlazado para crear una lista de transacciones)
};

// Estructura NodoCola: Representa un nodo en la cola de clientes para procesamiento
struct NodoCola {
  char dni[9];  // DNI del cliente en la cola
  int prioridad;  // Prioridad del cliente en la cola (para determinar el orden de atenci髇)
  NodoCola *sig;  // Puntero al siguiente nodo en la cola (lista enlazada de clientes en espera)
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
  cout << "   FINPROC - SISTEMA DE ATENCI脫N BANCARIA   \n";
  cout << "============================================\n";
  cout << COLOR_RESET;
}

// Verifica si un DNI es v谩lido (8 d铆gitos num茅ricos)
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

  cout << "Ingrese DNI (8 d铆gitos): ";
  cin >> nuevo->dni;
  if (!validarDNI(nuevo->dni)) {
    cout << COLOR_ERROR << "Error: DNI inv谩lido.\n" << COLOR_RESET;
    delete nuevo;
    pausa();
    return;
  }

  cout << "Ingrese nombre completo: ";
  cin.ignore();
  cin.getline(nuevo->nombre, 50);

  // Submen煤 para tipo de cliente
  int tipoOpcion;
  cout << "\nSeleccione tipo de cliente:\n";
  cout << "1. VIP\n";
  cout << "2. Preferencial\n";
  cout << "3. Regular\n";
  cout << "Opci贸n: ";
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
    cout << COLOR_ERROR << "Opci贸n inv谩lida.\n" << COLOR_RESET;
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
  cout << COLOR_MENU << "== REGISTRAR TRANSACCI脫N ==" << COLOR_RESET << endl;

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
  cout << "Tipo de transacci贸n (deposito/retiro): ";
  cin >> nueva->tipo;

  cout << "Monto: ";
  cin >> nueva->monto;
  if (nueva->monto <= 0) {
    cout << COLOR_ERROR << "Monto inv谩lido.\n" << COLOR_RESET;
    delete nueva;
    pausa();
    return;
  }

  nueva->sig = pilaTrans;
  pilaTrans = nueva;

  cout << COLOR_OK << "\nTransacci贸n registrada correctamente.\n"
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

  cout << COLOR_OK << "Cliente atendido con 茅xito.\n" << COLOR_RESET;
  pausa();
}

void mostrarCola() {
  limpiarPantalla();
  mostrarBanner();
  cout << COLOR_MENU << "== COLA DE ATENCI脫N ==" << COLOR_RESET << endl;

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
	setlocale(LC_CTYPE, "Spanish");
  int opcion;
  do {
    limpiarPantalla();
    mostrarBanner();
    cout << COLOR_MENU;
    cout << "1. Registrar cliente\n";
    cout << "2. Encolar cliente\n";
    cout << "3. Atender cliente\n";
    cout << "4. Registrar transacci贸n\n";
    cout << "5. Mostrar clientes\n";
    cout << "6. Mostrar cola\n";
    cout << "7. Mostrar transacciones\n";
    cout << "0. Salir\n";
    cout << COLOR_RESET;
    cout << "\nSeleccione una opci贸n: ";
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
      cout << COLOR_ERROR << "\nOpci贸n inv谩lida. Intente nuevamente.\n"
           << COLOR_RESET;
      pausa();
      break;
    }
  } while (opcion != 0);

  return 0;
}
