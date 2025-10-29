// ============================================================
// FINPROC - Sistema de Simulaciónn Bancaria
// ============================================================
// Autor: @hustavojhon
// Curso: Estructura de Datos
// Descripción: Este programa simula la atención de clientes en un
// banco, usando estructuras dinámicas simples y validaciones.
// ============================================================

#include <cstring>
#include <iostream>
using namespace std;

// Definición de constantes para colores que se usarán en la salida del terminal
#define COLOR_RESET "\033[0m"  // Reset del color
#define COLOR_TITULO "\033[1;36m"  // Color para los títulos (cyan)
#define COLOR_MENU "\033[1;33m"  // Color para los menús (amarillo)
#define COLOR_INFO "\033[1;37m"  // Color para la información general (blanco)
#define COLOR_ERROR "\033[1;31m"  // Color para los mensajes de error (rojo)
#define COLOR_OK "\033[1;32m"  // Color para los mensajes de éxito (verde)

// Estructura Cliente: Define a un cliente con su información básica
struct Cliente {
  char dni[9];  // DNI del cliente (identificación)
  char nombre[50];  // Nombre del cliente
  char tipo[15];  // Tipo de cliente (por ejemplo, 'regular', 'premium', etc.)
  Cliente *sig;  // Puntero al siguiente cliente en la lista (para crear una lista enlazada)
};

// Estructura Transaccion: Define las transacciones realizadas por los clientes
struct Transaccion {
  char tipo[20];  // Tipo de transacción (por ejemplo, 'depósito', 'retiro', etc.)
  double monto;  // Monto involucrado en la transacción
  Transaccion *sig;  // Puntero a la siguiente transacción (enlazado para crear una lista de transacciones)
};

// Estructura NodoCola: Representa un nodo en la cola de clientes para procesamiento
struct NodoCola {
  char dni[9];  // DNI del cliente en la cola
  int prioridad;  // Prioridad del cliente en la cola (para determinar el orden de atención)
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
  cout << COLOR_TITULO;  // Aplicar color al título
  
  // Imprimir el banner con líneas decorativas
  cout << "============================================\n";
  cout << "   FINPROC - SISTEMA DE ATENCIÓN BANCARIA   \n";  // Título principal
  cout << "============================================\n";
  
  cout << COLOR_RESET;  // Restablecer color al valor predeterminado
}

// Función que verifica si un DNI es válido (solo debe tener 8 dígitos numéricos)
bool validarDNI(const char *dni) {
  // Verifica que la longitud del DNI sea exactamente 8 caracteres
  if (strlen(dni) != 8)
    return false;

  // Recorre cada carácter del DNI
  for (int i = 0; i < 8; i++) {
    // Si algún carácter no está entre '0' y '9', el DNI no es válido
    if (dni[i] < '0' || dni[i] > '9')
      return false;
  }

  // Si pasa todas las validaciones, el DNI es válido
  return true;
}

// ============================================================
// Funciones de lista enlazada
// ============================================================
void registrarCliente() {
  limpiarPantalla(); // Limpia la pantalla antes de mostrar el formulario de registro
  mostrarBanner();   // Muestra el encabezado o banner del programa
  cout << COLOR_MENU << "== REGISTRAR CLIENTE ==" << COLOR_RESET << endl; // Título del menú

  Cliente *nuevo = new Cliente(); // Crea dinámicamente un nuevo objeto Cliente

  // Solicita el DNI del cliente
  cout << "Ingrese DNI (8 dígitos): ";
  cin >> nuevo->dni;

  // Verifica si el DNI ingresado es válido (solo 8 dígitos numéricos)
  if (!validarDNI(nuevo->dni)) {
    cout << COLOR_ERROR << "Error: DNI inválido.\n" << COLOR_RESET;
    delete nuevo; // Libera la memoria del cliente creado
    pausa();       // Pausa la ejecución para que el usuario lea el mensaje
    return;        // Sale de la función sin registrar al cliente
  }

  // Solicita el nombre completo del cliente
  cout << "Ingrese nombre completo: ";
  cin.ignore();                  // Limpia el buffer del teclado
  cin.getline(nuevo->nombre, 50); // Captura el nombre completo (máx. 50 caracteres)

  // Submenú para elegir el tipo de cliente
  int tipoOpcion;
  cout << "\nSeleccione tipo de cliente:\n";
  cout << "1. VIP\n";
  cout << "2. Preferencial\n";
  cout << "3. Regular\n";
  cout << "Opción: ";
  cin >> tipoOpcion;

  // Asigna el tipo de cliente según la opción seleccionada
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
    // En caso de opción inválida, muestra error y cancela el registro
    cout << COLOR_ERROR << "Opción inválida\n" << COLOR_RESET;
    delete nuevo;
    pausa();
    return;
  }

  nuevo->sig = NULL; // Inicializa el puntero siguiente como nulo (fin de la lista)

  // Inserta el nuevo cliente al final de la lista enlazada
  if (listaClientes == NULL) {
    listaClientes = nuevo; // Si la lista está vacía, el nuevo cliente será el primero
  } else {
    Cliente *aux = listaClientes; // Recorre la lista hasta el último nodo
    while (aux->sig != NULL)
      aux = aux->sig;
    aux->sig = nuevo; // Enlaza el nuevo cliente al final de la lista
  }

  // Mensaje de confirmación
  cout << COLOR_OK << "\nCliente registrado exitosamente.\n" << COLOR_RESET;
  pausa(); // Espera que el usuario presione una tecla antes de continuar
}

// Función que busca un cliente en la lista enlazada por su DNI
Cliente *buscarCliente(const char *dni) {
  Cliente *aux = listaClientes; // Puntero auxiliar que recorre la lista de clientes

  // Recorre la lista mientras existan nodos
  while (aux != NULL) {
    // Compara el DNI del cliente actual con el DNI buscado
    if (strcmp(aux->dni, dni) == 0)
      return aux; // Si coincide, devuelve el puntero al cliente encontrado

    aux = aux->sig; // Avanza al siguiente cliente en la lista
  }

  // Si no se encuentra ningún cliente con ese DNI, retorna NULL
  return NULL;
}

// Función que muestra en pantalla la lista de todos los clientes registrados
void mostrarClientes() {
  limpiarPantalla(); // Limpia la pantalla antes de mostrar la lista
  mostrarBanner();   // Muestra el encabezado o título principal del programa
  cout << COLOR_MENU << "== LISTA DE CLIENTES ==" << COLOR_RESET << endl; // Título de la sección

  // Verifica si la lista de clientes está vacía
  if (listaClientes == NULL) {
    // Si no hay clientes, muestra un mensaje informativo
    cout << COLOR_INFO << "No hay clientes registrados.\n" << COLOR_RESET;
  } else {
    // Si existen clientes, recorre la lista enlazada desde el inicio
    Cliente *aux = listaClientes;
    while (aux != NULL) {
      // Muestra la información del cliente: DNI, nombre y tipo
      cout << aux->dni << " - " << aux->nombre << " (" << aux->tipo << ")\n";
      aux = aux->sig; // Avanza al siguiente nodo de la lista
    }
  }

  pausa(); // Espera una acción del usuario antes de continuar (por ejemplo, presionar una tecla)
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
  cout << "Tipo de transacciónn (deposito/retiro): ";
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

  cout << COLOR_OK << "Cliente atendido con éxito \n" << COLOR_RESET;
  pausa();
}

void mostrarCola() {
  // Limpiar la pantalla antes de mostrar la información
  limpiarPantalla();
  
  // Mostrar un banner con información general
  mostrarBanner();
  
  // Mostrar título con color personalizado
  cout << COLOR_MENU << "== COLA DE ATENCIÓN ==" << COLOR_RESET << endl;

  // Verificar si la cola está vacía
  if (cola == NULL) {
    // Si no hay clientes, mostrar un mensaje informativo
    cout << COLOR_INFO << "No hay clientes en cola.\n" << COLOR_RESET;
  } else {
    // Si hay clientes en la cola, mostrar su DNI y prioridad
    NodoCola *aux = cola;
    while (aux != NULL) {
      cout << aux->dni << " (Prioridad " << aux->prioridad << ")\n";  // Mostrar cada cliente con su DNI y prioridad
      aux = aux->sig;  // Avanzar al siguiente nodo de la cola
    }
  }

  // Pausar para que el usuario pueda ver la información antes de continuar
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
      cout << COLOR_ERROR << "\n Opción inválida. Intente nuevamente.\n"
           << COLOR_RESET;
      pausa();
      break;
    }
  } while (opcion != 0);

  return 0;
}
