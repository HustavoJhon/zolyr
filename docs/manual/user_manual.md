# **Manual de Usuario – FINPROC v1.0**

## 1. Introducción
**FINPROC** es un sistema diseñado para simular el flujo real de atención en una entidad financiera.  
Permite gestionar clientes, ordenarlos en una cola de atención según prioridad y registrar sus transacciones mediante estructuras dinámicas de datos.

Este manual explica paso a paso cómo **instalar**, **ejecutar** y **utilizar** todas las funciones del sistema, incluso si el usuario no tiene experiencia técnica.

---
## 2. Instalación y Requisitos

### 2.1. Requisitos de Software

Para utilizar FINPROC, se necesita:

- **Compilador C++** (sugerido: Dev-C++ 5.11, CodeBlocks o g++ en Linux).
- **Sistema Operativo** compatible:
    - Windows 7/10/11
    - Linux (Ubuntu, Debian, Arch, etc.)
    - macOS (con XCode o Clang)
- **Memoria mínima:** 2 GB RAM
- **Espacio en disco:** 50 MB
FINPROC funciona completamente por **consola**, por lo que no requiere gráficos avanzados.

---

### 2.2. Descarga del Programa

1. Abra su navegador.
2. Ingrese al repositorio del proyecto en GitHub:  
    👉 _[Repositorio](https://github.com/HustavoJhon/FinProc)._
3. Descargue el archivo ZIP o clone el repositorio.

---

### 2.3. Compilación (Windows / Dev-C++)

1. Abra **Dev-C++**.
2. Haga clic en **Archivo > Abrir proyecto**.
3. Seleccione la carpeta del proyecto FINPROC.
4. Presione **F11** o vaya a **Ejecutar > Compilar y ejecutar**.
5. El sistema generará un archivo ejecutable llamado:  
    ✅ `finproc.exe` (en Windows)  
    ✅ `./finproc` (en Linux o macOS)
    

---

## 3. Guía de Uso

FINPROC funciona mediante un **menú de consola**, donde el usuario ingresa números para elegir una función.

Al abrir el programa verá:
```markdown
==============================================
       FINPROC - GESTOR DE PROCESOS BANCARIOS
==============================================

1. Gestión de Clientes
2. Gestión de Atención
3. Gestión de Transacciones
4. Cargar Datos
5. Guardar Datos
6. Mostrar Reportes
7. Salir

Ingrese una opción:

```

A continuación se explica cada una de ellas.

### 3.1 Gestión de Clientes

Esta sección usa una **Lista Enlazada**, ideal para administrar clientes de forma rápida y ordenada.

### Opciones disponibles:

|Función|¿Qué hace?|¿Para qué sirve?|
|---|---|---|
|**Registrar Cliente**|Permite crear un nuevo cliente ingresando su nombre, DNI y tipo.|Agregar personas al sistema bancario.|
|**Buscar Cliente por DNI**|Encuentra un cliente existente.|Verificar si un cliente ya está registrado.|
|**Eliminar Cliente**|Borra un cliente de la lista.|Actualizar la base cuando ya no será atendido.|
|**Mostrar Lista**|Visualiza todos los clientes registrados.|Revisar el estado del registro.|
### ¿Qué datos solicita?
- Nombre completo
- DNI
- Tipo de cliente (VIP, Normal, Preferencial)
- Número de cuenta

✅ **FINPROC valida que el DNI no esté repetido**, evitando duplicados.

### 3.2 Gestión de Atención (Cola de Prioridad)

Representa la cola de espera del banco.  
Los clientes se ordenan automáticamente por **prioridad**, de mayor a menor.  
Ejemplo:

- VIP → prioridad 1 (más urgente)
- Preferencial → prioridad 2
- Regular → prioridad 3 (últimos)

### Opciones disponibles:

|Sub-Opción|Propósito|Estructura|
|---|---|---|
|**1. Encolar Cliente**|Agrega un cliente a la cola según su prioridad.|`priority_queue`|
|**2. Atender Siguiente**|Atiende al cliente que tiene mayor prioridad.|`dequeue()`|
|**3. Mostrar Cola**|Lista todos los clientes en orden de atención.|Ordenador por prioridad|
### Ejemplo de uso:

1. Registrar varios clientes.
2. Encolarlos según orden de llegada.
3. FINPROC los ordenará automáticamente.
4. Atender al siguiente mostrará quién es el próximo en ventanilla.

✅ Esto simula el funcionamiento real de un banco.

### 3.3 Gestión de Transacciones (Pila)

Cada cliente posee su propio **historial de transacciones** almacenado en una **pila**:

- La última operación realizada es la primera en mostrarse.
- Ideal para operaciones tipo _deshacer_ (undo).

### Opciones disponibles:

|Sub-Opción|¿Qué hace?|
|---|---|
|**Registrar Transacción**|Agrega un depósito, retiro o movimiento.|
|**Deshacer Última**|Elimina la última transacción (si existe).|
|**Mostrar Historial**|Muestra todas las operaciones del cliente.|
### Datos solicitados:

- Tipo de operación (retiro, depósito, consulta)
- Monto
- Fecha (generada automáticamente)
✅ FINPROC valida montos, tipo de acción y pila vacía.

### 3.4 Persistencia – Cargar y Guardar Datos

Permite que el usuario recupere su información cuando cierre el programa.

####  **Cargar Datos**

Lee los archivos del sistema
- Lista de Clientes
- Cola de Prioridad
- Historiales (Pilas)
    

#### **Guardar Datos**

Guarda automáticamente toda la información en formato de texto legible
✅ Recomendado usarlo **antes de salir** del programa.

---

###  3.5 Mostrar Reportes

FINPROC permite visualizar un panel resumen:

✅ Lista de clientes registrados  
✅ Estado actual de la cola  
✅ Transacciones de cada cliente  
✅ Consultas rápidas

Todo en formato limpio por consola.

---

### 3.6 Salir del Programa

Finaliza la ejecución de FINPROC.  
Si el usuario no guardó los datos, el sistema mostrará un aviso preventivo.

---

###  4. Buenas Prácticas de Uso

- Use **Cargar Datos** al iniciar para recuperar su información.
- Guarde la información siempre antes de salir.
- Evite usar DNIs repetidos.
- No ingrese montos negativos.
- Asegúrese de atender a los clientes en la cola antes de registrar transacciones.
    

---

### 5. Soporte / Contacto

Para soporte técnico, consulte el repositorio GitHub del proyecto o contacte al equipo de desarrollo:

- **Scrum Master:** Gustavo Ccarita
- **Analista:** Rodrigo Sevillanos
- **Tester / Documentación:** André Espinoza