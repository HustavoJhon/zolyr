#include <iostream>
#include <string>
using namespace std;

// ============================================================
// Estructuras del sistema
// ============================================================

// Lista enlazada de clientes
struct Cliente {
  string dni; //unicamente de 8 cifras
  string nombre; // 
  string tipo; // VIP, Preferencial, Regular
  Cliente *sig;
};

// Pila de transacciones
struct Transaccion {
  string tipo;
  double monto;
  Transaccion *sig;
};

// Cola de prioridad
struct NodoCola {
  string dni;
  int prioridad;
  NodoCola *sig;
};

// ============================================================
// Variables globales (para mantener el codigo simple)
// ============================================================

Cliente *listaClientes = NULL;
Transaccion *pilaTrans = NULL;
NodoCola *cola = NULL;

// ============================================================
// Funciones de lista enlazada (clientes)
// ============================================================

void agregarCliente() {
  Cliente *nuevo = new Cliente();
  cout << "Ingrese DNI: ";
  cin >> nuevo->dni;

  cout << "Ingrese nombre: ";
  cin.ignore();
  getline(cin, nuevo->nombre);

  cout << "Tipo (VIP / Preferencial / Regular): ";
  cin >> nuevo->tipo;

  nuevo->sig = NULL;

  if (listaClientes == NULL) {
    listaClientes = nuevo;
  } else {
    Cliente *aux = listaClientes;
    while (aux->sig != NULL)
      aux = aux->sig;
    aux->sig = nuevo;
  }

  cout << "Cliente registrado.\n";
}

Cliente *buscarCliente(string dni) {
  Cliente *aux = listaClientes;
  while (aux != NULL) {
    if (aux->dni == dni)
      return aux;
    aux = aux->sig;
  }
  return NULL;
}

void mostrarClientes() {
  cout << "\nLista de clientes:\n";
  Cliente *aux = listaClientes;
  while (aux != NULL) {
    cout << aux->dni << " - " << aux->nombre << " (" << aux->tipo << ")\n";
    aux = aux->sig;
  }
}

// ============================================================
// Funciones de pila (transacciones)
// ============================================================

void registrarTransaccion() {
  string dni;
  cout << "Ingrese DNI: ";
  cin >> dni;

  if (buscarCliente(dni) == NULL) {
    cout << "Cliente no encontrado.\n";
    return;
  }

  Transaccion *nueva = new Transaccion();
  cout << "Tipo de transaccion (deposito/retiro): ";
  cin >> nueva->tipo;
  cout << "Monto: ";
  cin >> nueva->monto;

  nueva->sig = pilaTrans;
  pilaTrans = nueva;

  cout << "Transaccion registrada.\n";
}

void mostrarPila() {
  cout << "\nHistorial de transacciones:\n";
  Transaccion *aux = pilaTrans;
  while (aux != NULL) {
    cout << aux->tipo << " - " << aux->monto << "\n";
    aux = aux->sig;
  }
}

// ============================================================
// Funciones de cola de prioridad
// ============================================================

int obtenerPrioridad(string tipo) {
  if (tipo == "VIP")
    return 1;
  if (tipo == "Preferencial")
    return 2;
  return 3;
}

void encolarCliente() {
  string dni;
  cout << "Ingrese DNI: ";
  cin >> dni;

  Cliente *cli = buscarCliente(dni);
  if (cli == NULL) {
    cout << "Cliente no existe.\n";
    return;
  }

  NodoCola *nuevo = new NodoCola();
  nuevo->dni = dni;
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

  cout << "Cliente encolado.\n";
}

void atenderCliente() {
  if (cola == NULL) {
    cout << "No hay clientes en cola.\n";
    return;
  }

  cout << "Atendiendo a: " << cola->dni << endl;
  NodoCola *temp = cola;
  cola = cola->sig;
  delete temp;
}

void mostrarCola() {
  cout << "\nCola de atencion:\n";
  NodoCola *aux = cola;
  while (aux != NULL) {
    cout << aux->dni << " (P=" << aux->prioridad << ")\n";
    aux = aux->sig;
  }
}

// ============================================================
// Menu principal
// ============================================================

int main() {
  int op;

  do {
    cout << "\n======= FINPROC =======\n";
    cout << "1. Registrar cliente\n";
    cout << "2. Encolar cliente\n";
    cout << "3. Atender cliente\n";
    cout << "4. Registrar transaccion\n";
    cout << "5. Mostrar clientes\n";
    cout << "6. Mostrar cola\n";
    cout << "7. Mostrar transacciones\n";
    cout << "0. Salir\n";
    cout << "Opcion: ";
    cin >> op;

    switch (op) {
    case 1:
      agregarCliente();
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
      mostrarPila();
      break;
    case 0:
      cout << "GRACIAS POR USAR FINPROC..\n";
      break;
    default:
      cout << "Opcion no valida.\n";
      break;
    }

  } while (op != 0);

  return 0;
}

