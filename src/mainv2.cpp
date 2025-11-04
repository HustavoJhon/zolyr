// ============================================================
// FINPROC - Sistema de Simulacion Bancaria
// ============================================================
// Autor:
// @hustavojhon
// @C3b1taz
// @BLUESKY211206
// Curso: Estructura de Datos
// Descripcion: Este programa simula la atencion de clientes en un
// banco utilizando estructuras dinamicas simples y validaciones.
// ============================================================

#include <cstring>
#include <iostream>
using namespace std;

// Definicion de constantes para colores usados en la salida del terminal
#define COLOR_RESET "\033[0m"      // Reset del color
#define COLOR_TITULO "\033[1;36m"  // Color para los titulos (cyan)
#define COLOR_MENU "\033[1;33m"    // Color para los menus (amarillo)
#define COLOR_INFO "\033[1;37m"    // Color para la informacion general (blanco)
#define COLOR_ERROR "\033[1;31m"   // Color para los mensajes de error (rojo)
#define COLOR_OK "\033[1;32m"      // Color para los mensajes de exito (verde)

// Estructura Cliente: Define a un cliente con su informacion basica
struct Cliente {
  char dni[9];        // DNI del cliente
  char nombre[50];    // Nombre del cliente
  char tipo[15];      // Tipo de cliente (regular, premium, etc.)
  Cliente *sig;       // Puntero al siguiente cliente en la lista (lista enlazada)
};

// Estructura Transaccion: Representa las transacciones realizadas por los clientes
struct Transaccion {
  char tipo[20];      // Tipo de transaccion (deposito, retiro, etc.)
  double monto;       // Monto de la transaccion
  Transaccion *sig;   // Puntero a la siguiente transaccion (lista enlazada)
};

// Estructura NodoCola: Representa un nodo en la cola de clientes en espera
struct NodoCola {
  char dni[9];        // DNI del cliente en la cola
  int prioridad;      // Prioridad del cliente (define el orden de atencion)
  NodoCola *sig;      // Puntero al siguiente nodo en la cola (lista enlazada)
};


// Punteros globales
Cliente *listaClientes = NULL;
Transaccion *pilaTrans = NULL;
NodoCola *cola = NULL;

// Funciones de utilidad
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
    cout << COLOR_TITULO;  // Aplicar color al titulo

    cout << "===============================================\n";
    cout << "            FINPROC - ATENCION BANCARIA          \n";
    cout << "===============================================\n";

    cout << COLOR_RESET;  // Restablecer color al valor predeterminado
}

// Funcion que verifica si un DNI es valido (solo debe tener 8 digitos numericos)
bool validarDNI(const char *dni) {
  // Verifica que la longitud del DNI sea exactamente 8 caracteres
  if (strlen(dni) != 8)
    return false;

  // Recorre cada caracter del DNI
  for (int i = 0; i < 8; i++) {
    // Si algun caracter no esta entre '0' y '9', el DNI no es valido
    if (dni[i] < '0' || dni[i] > '9')
      return false;
  }

  // Si pasa todas las validaciones, el DNI es valido
  return true;
}

// ============================================================
// Funciones de lista enlazada
// ============================================================
void registrarCliente() {
  limpiarPantalla(); // Limpia la pantalla antes de mostrar el formulario de registro
  mostrarBanner();   // Muestra el encabezado o banner del programa
  cout << COLOR_MENU << "== REGISTRAR CLIENTE ==" << COLOR_RESET << endl; // Titulo del menu

  Cliente *nuevo = new Cliente(); // Crea dinamicamente un nuevo objeto Cliente

  // Solicita el DNI del cliente
  cout << "Ingrese DNI (8 digitos): ";
  cin >> nuevo->dni;

  // Verifica si el DNI ingresado es valido (solo 8 digitos numericos)
  if (!validarDNI(nuevo->dni)) {
    cout << COLOR_ERROR << "Error: DNI invalido.\n" << COLOR_RESET;
    delete nuevo; // Libera la memoria del cliente creado
    pausa();      // Pausa la ejecucion para que el usuario lea el mensaje
    return;       // Sale de la funcion sin registrar al cliente
  }

  // Solicita el nombre completo del cliente
  cout << "Ingrese nombre completo: ";
  cin.ignore();                   // Limpia el buffer del teclado
  cin.getline(nuevo->nombre, 50); // Captura el nombre completo (max. 50 caracteres)

  // Submenu para elegir el tipo de cliente
  int tipoOpcion;
  cout << "\nSeleccione tipo de cliente:\n";
  cout << "1. VIP\n";
  cout << "2. Preferencial\n";
  cout << "3. Regular\n";
  cout << "Opcion: ";
  cin >> tipoOpcion;

  // Asigna el tipo de cliente segun la opcion seleccionada
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
    // En caso de opcion invalida, muestra error y cancela el registro
    cout << COLOR_ERROR << "Opcion invalida\n" << COLOR_RESET;
    delete nuevo;
    pausa();
    return;
  }

  nuevo->sig = NULL; // Inicializa el puntero siguiente como nulo (fin de la lista)

  // Inserta el nuevo cliente al final de la lista enlazada
  if (listaClientes == NULL) {
    listaClientes = nuevo; // Si la lista esta vacia, el nuevo cliente sera el primero
  } else {
    Cliente *aux = listaClientes; // Recorre la lista hasta el ultimo nodo
    while (aux->sig != NULL)
      aux = aux->sig;
    aux->sig = nuevo; // Enlaza el nuevo cliente al final de la lista
  }

  // Mensaje de confirmacion
  cout << COLOR_OK << "\nCliente registrado exitosamente.\n" << COLOR_RESET;
  pausa(); // Espera que el usuario presione una tecla antes de continuar
}

// Funcion que busca un cliente en la lista enlazada por su DNI
Cliente *buscarCliente(const char *dni) {
  Cliente *aux = listaClientes; // Puntero auxiliar que recorre la lista de clientes

  // Recorre la lista mientras existan nodos
  while (aux != NULL) {
    // Compara el DNI del cliente actual con el DNI buscado
    if (strcmp(aux->dni, dni) == 0)
      return aux; // Si coincide, devuelve el puntero al cliente encontrado

    aux = aux->sig; // Avanza al siguiente cliente en la lista
  }

  // Si no se encuentra ningun cliente con ese DNI, retorna NULL
  return NULL;
}

// Funcion que muestra en pantalla la lista de todos los clientes registrados
void mostrarClientes() {
  limpiarPantalla(); // Limpia la pantalla antes de mostrar la lista
  mostrarBanner();   // Muestra el encabezado o titulo principal del programa
  cout << COLOR_MENU << "== LISTA DE CLIENTES ==" << COLOR_RESET << endl; // Titulo de la seccion

  // Verifica si la lista de clientes esta vacia
  if (listaClientes == NULL) {
    // Si no hay clientes, muestra un mensaje informativo
    cout << COLOR_INFO << "No hay clientes registrados.\n" << COLOR_RESET;
  } else {
    // Si existen clientes, recorre la lista enlazada desde el inicio
    Cliente *aux = listaClientes;
    while (aux != NULL) {
      // Muestra la informacion del cliente: DNI, nombre y tipo
      cout << aux->dni << " - " << aux->nombre << " (" << aux->tipo << ")\n";
      aux = aux->sig; // Avanza al siguiente nodo de la lista
    }
  }

  pausa(); // Espera una accion del usuario antes de continuar
}

// ============================================================
// Funciones de pila
// ============================================================

// Funcion que registra una nueva transaccion (deposito o retiro) para un cliente
void registrarTransaccion() {
  limpiarPantalla(); // Limpia la pantalla antes de mostrar el formulario
  mostrarBanner();   // Muestra el encabezado del sistema
  cout << COLOR_MENU << "== REGISTRAR TRANSACCION ==" << COLOR_RESET << endl; // Titulo de la seccion

  char dni[9]; // Variable para almacenar el DNI del cliente
  cout << "Ingrese DNI del cliente: ";
  cin >> dni; // Solicita el DNI al usuario

  // Busca al cliente en la lista enlazada usando el DNI ingresado
  Cliente *cli = buscarCliente(dni);
  if (cli == NULL) { // Si no se encuentra el cliente, muestra mensaje de error
    cout << COLOR_ERROR << "Cliente no encontrado.\n" << COLOR_RESET;
    pausa();
    return;
  }

  Transaccion *nueva = new Transaccion(); // Crea dinamicamente una nueva transaccion
  cout << "Tipo de transaccion (deposito/retiro): ";
  cin >> nueva->tipo; // Solicita el tipo de transaccion

  cout << "Monto: ";
  cin >> nueva->monto; // Solicita el monto de la transaccion

  // Verifica que el monto sea mayor que cero
  if (nueva->monto <= 0) {
    cout << COLOR_ERROR << "Monto invalido.\n" << COLOR_RESET;
    delete nueva;
    pausa();
    return;
  }

  // Inserta la transaccion en la pila (al inicio)
  nueva->sig = pilaTrans;
  pilaTrans = nueva;

  // Mensaje de confirmacion
  cout << COLOR_OK << "\nTransaccion registrada correctamente.\n"
       << COLOR_RESET;
  pausa();
}

// Funcion que muestra en pantalla el historial de transacciones registradas
void mostrarTransacciones() {
  limpiarPantalla(); // Limpia la pantalla antes de mostrar la informacion
  mostrarBanner();   // Muestra el encabezado del sistema
  cout << COLOR_MENU << "== HISTORIAL DE TRANSACCIONES ==" << COLOR_RESET << endl; // Titulo

  // Verifica si la pila de transacciones esta vacia
  if (pilaTrans == NULL) {
    cout << COLOR_INFO << "No hay transacciones registradas.\n" << COLOR_RESET;
  } else {
    // Recorre la pila desde la mas reciente a la mas antigua
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
// Funcion que obtiene la prioridad de atencion segun el tipo de cliente
int obtenerPrioridad(const char *tipo) {
  if (strcmp(tipo, "VIP") == 0)
    return 1;               // Prioridad mas alta
  if (strcmp(tipo, "Preferencial") == 0)
    return 2;               // Prioridad media
  return 3;                 // Prioridad regular
}

// Funcion que agrega un cliente a la cola de prioridad
void encolarCliente() {
  limpiarPantalla();
  mostrarBanner();
  cout << COLOR_MENU << "== ENCOLAR CLIENTE ==" << COLOR_RESET << endl;

  char dni[9];
  cout << "Ingrese DNI: ";
  cin >> dni;

  // Buscar al cliente registrado previamente
  Cliente *cli = buscarCliente(dni);
  if (cli == NULL) {
    cout << COLOR_ERROR << "Cliente no existe.\n" << COLOR_RESET;
    pausa();
    return;
  }

  // Crear nodo nuevo para la cola
  NodoCola *nuevo = new NodoCola();
  strcpy(nuevo->dni, dni);
  nuevo->prioridad = obtenerPrioridad(cli->tipo); // Obtener prioridad segun tipo
  nuevo->sig = NULL;

  // Insertar en la cola respetando la prioridad
  if (cola == NULL || nuevo->prioridad < cola->prioridad) {
    // Insertar al inicio si es de mayor prioridad
    nuevo->sig = cola;
    cola = nuevo;
  } else {
    // Buscar posicion adecuada en la cola
    NodoCola *aux = cola;
    while (aux->sig != NULL && aux->sig->prioridad <= nuevo->prioridad)
      aux = aux->sig;

    nuevo->sig = aux->sig; // Insertar en la posicion correcta
    aux->sig = nuevo;
  }

  cout << COLOR_OK << "Cliente encolado correctamente.\n" << COLOR_RESET;
  pausa();
}

// Funcion que atiende (desencola) al cliente con mayor prioridad
void atenderCliente() {
  limpiarPantalla();
  mostrarBanner();
  cout << COLOR_MENU << "== ATENDER CLIENTE ==" << COLOR_RESET << endl;

  // Verificar si la cola esta vacia
  if (cola == NULL) {
    cout << COLOR_INFO << "No hay clientes en cola.\n" << COLOR_RESET;
    pausa();
    return;
  }

  // Atender al primer cliente de la cola
  cout << "Atendiendo a cliente con DNI: " << cola->dni << endl;

  NodoCola *temp = cola; // Guardar referencia temporal
  cola = cola->sig;      // Mover la cola al siguiente nodo
  delete temp;           // Eliminar nodo atendido

  cout << COLOR_OK << "Cliente atendido con exito\n" << COLOR_RESET;
  pausa();
}

// Funcion que muestra todos los clientes actualmente en cola
void mostrarCola() {
  limpiarPantalla();
  mostrarBanner();
  cout << COLOR_MENU << "== COLA DE ATENCION ==" << COLOR_RESET << endl;

  // Verificar si no hay clientes
  if (cola == NULL) {
    cout << COLOR_INFO << "No hay clientes en cola.\n" << COLOR_RESET;
  } else {
    // Recorrer la cola e imprimir DNI + prioridad
    NodoCola *aux = cola;
    while (aux != NULL) {
      cout << aux->dni << " (Prioridad " << aux->prioridad << ")\n";
      aux = aux->sig;
    }
  }

  pausa();
}

// Funcion principal (menu del sistema)
int main() {
  setlocale(LC_CTYPE, "Spanish");  // Soporte para caracteres especiales

  int opcion;
  do {
    limpiarPantalla();
    mostrarBanner();

    // Mostrar menu principal
    cout << COLOR_MENU;
    cout << "1. Registrar cliente\n";
    cout << "2. Encolar cliente\n";
    cout << "3. Atender cliente\n";
    cout << "4. Registrar transaccion\n";
    cout << "5. Mostrar clientes\n";
    cout << "6. Mostrar cola\n";
    cout << "7. Mostrar transacciones\n";
    cout << "0. Salir\n";
    cout << COLOR_RESET;

    cout << "\nSeleccione una opcion: ";
    cin >> opcion;

    // Procesar la opcion seleccionada
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
      // Manejo de errores por opcion invalida
      cout << COLOR_ERROR << "\nOpcion invalida. Intente nuevamente.\n"
           << COLOR_RESET;
      pausa();
      break;
    }
  } while (opcion != 0);

  return 0;
}

