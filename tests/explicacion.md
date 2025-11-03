# FINPROC - Explicación Completa del Código

A continuación se presenta una explicación detallada, sección por sección, del funcionamiento del programa **FINPROC - Sistema de Simulación Bancaria**, escrito en C++. Cada bloque incluye qué hace, por qué existe y cómo se relaciona con el sistema completo.

---

## 🟦 1. Encabezado del Proyecto

```cpp
// ============================================================
// FINPROC - Sistema de Simulación Bancaria
// ============================================================
// Autor:
// @hustavojhon
// @C3b1taz
// @BLUESKY211206
// Curso: Estructura de Datos
// Descripción: Este programa simula la atención de clientes en un
// banco utilizando estructuras dinámicas simples y validaciones.
// ============================================================
```

**Explicación:**

* Es el encabezado descriptivo del proyecto.
* Incluye los autores y el objetivo del programa.
* Indica que se trata de una simulación que usa estructuras dinámicas.

---

## 🟦 2. Librerías Incluidas

```cpp
#include <cstring>
#include <iostream>
using namespace std;
```

**Explicación:**

* `cstring`: permite usar funciones como `strlen`, `strcpy`, `strcmp`.
* `iostream`: permite mostrar datos en pantalla y recibir entrada del usuario.
* `using namespace std;`: evita tener que escribir `std::` constantemente.

---

## 🟦 3. Constantes de Colores

```cpp
#define COLOR_RESET "\033[0m"
#define COLOR_TITULO "\033[1;36m"
#define COLOR_MENU "\033[1;33m"
#define COLOR_INFO "\033[1;37m"
#define COLOR_ERROR "\033[1;31m"
#define COLOR_OK "\033[1;32m"
```

**Explicación:**

* Estas constantes agregan colores al texto del terminal.
* Mejoran la estética y la legibilidad del sistema.
* Son códigos ANSI compatibles con Linux y algunos terminales Windows.

---

## 🟦 4. Estructura `Cliente`

```cpp
struct Cliente {
  char dni[9];
  char nombre[50];
  char tipo[15];
  Cliente *sig;
};
```

**Explicación:**

* Representa un cliente registrado.
* Almacena DNI, nombre y tipo (VIP, Preferencial o Regular).
* Posee un puntero `sig` para formar una **lista enlazada**.

---

## 🟦 5. Estructura `Transaccion`

```cpp
struct Transaccion {
  char tipo[20];
  double monto;
  Transaccion *sig;
};
```

**Explicación:**

* Representa un movimiento bancario.
* Se usa como **pila**, agregando nuevas transacciones al inicio.

---

## 🟦 6. Estructura `NodoCola`

```cpp
struct NodoCola {
  char dni[9];
  int prioridad;
  NodoCola *sig;
};
```

**Explicación:**

* Representa un nodo de la **cola de prioridad**.
* Guarda DNI y nivel de prioridad.
* Se usa para simular el turno de atención bancaria.

---

## 🟦 7. Punteros Globales

```cpp
Cliente *listaClientes = NULL;
Transaccion *pilaTrans = NULL;
NodoCola *cola = NULL;
```

**Explicación:**

* Señalan el inicio de cada estructura dinámica.
* `NULL` indica que comienzan vacías.

---

## 🟦 8. Función `limpiarPantalla()`

```cpp
void limpiarPantalla() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
```

**Explicación:**

* Limpia la consola según el sistema operativo.
* Mejora la presentación durante el menú.

---

## 🟦 9. Función `pausa()`

```cpp
void pausa() {
  cout << COLOR_INFO << "\nPresione Enter para continuar..." << COLOR_RESET;
  cin.ignore();
  cin.get();
}
```

**Explicación:**

* Detiene la ejecución hasta que el usuario presione Enter.
* Se usa después de mensajes importantes.

---

## 🟦 10. Banner ASCII

```cpp
void mostrarBanner() {
    cout << COLOR_TITULO;
    cout << "===============================================\n";
    ...
    cout << "===============================================\n";
    cout << "            FINPROC - ATENCIÓN BANCARIA          \n";
    cout << "===============================================\n";
    cout << COLOR_RESET;
}
```

**Explicación:**

* Muestra un diseño ASCII llamativo.
* Le da identidad visual al proyecto.

---

## 🟦 11. Función `validarDNI()`

```cpp
bool validarDNI(const char *dni) {
  if (strlen(dni) != 8)
    return false;
  for (int i = 0; i < 8; i++) {
    if (dni[i] < '0' || dni[i] > '9')
      return false;
  }
  return true;
}
```

**Explicación:**

* Comprueba que el DNI tenga **exactamente 8 números**.
* Si no cumple, devuelve `false`.

---

## 🟦 12. Función `registrarCliente()`

Explica cómo registrar un cliente en la lista enlazada.

**Incluye:**

* Validación de DNI
* Registro de nombre
* Selección de tipo de cliente
* Inserción al final de la lista

---

## 🟦 13. Función `buscarCliente()`

**Qué hace:**

* Recorre la lista enlazada buscando un DNI.
* Devuelve un puntero al cliente o `NULL`.

---

## 🟦 14. Función `mostrarClientes()`

**Qué hace:**

* Recorre la lista enlazada y muestra DNI, nombre y tipo.
* Indica si la lista está vacía.

---

## 🟦 15. Funciones de Pila (`Transaccion`)

### ✅ `registrarTransaccion()`

* Solicita DNI.
* Verifica cliente.
* Crea nueva transacción.
* Inserta al inicio de la pila.

### ✅ `mostrarTransacciones()`

* Recorre la pila desde la transacción más reciente.

---

## 🟦 16. Funciones de Cola de Prioridad

### ✅ `obtenerPrioridad()`

* VIP: 1
* Preferencial: 2
* Regular: 3

### ✅ `encolarCliente()`

* Inserta en posición ordenada según prioridad.
* Mantiene estructura de cola de prioridad.

### ✅ `atenderCliente()`

* Elimina el primer nodo de la cola.
* Muestra el cliente atendido.

### ✅ `mostrarCola()`

* Lista el DNI y prioridad de todos los clientes en espera.

---

## 🟦 17. Función `main()` — Control principal del sistema

**Incluye:**

* Menú interactivo
* Selección de opciones por el usuario
* Llamada a todas las funciones según la opción
* Uso de bucle `do-while` para mantener el sistema activo

**Es el "centro de control" del programa.**

---

## ✅ Conclusión

Este README divide el código completo por bloques funcionales para que puedas **exponer fácilmente** cada parte del sistema FINPROC.

Si deseas puedo:
✅ Generar diagramas de flujo
✅ Crear explicaciones más largas para exposición oral
✅ Hacer una versión PDF para entregar
✅ Añadir ejemplos de ejecución
