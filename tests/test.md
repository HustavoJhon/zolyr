# Pruebas manuales del sistema FINPROC

Este archivo documenta pruebas simples realizadas de forma manual para validar el correcto funcionamiento del proyecto.

## Pruebas de lista enlazada
1. Registrar varios clientes.
2. Buscar uno existente.
3. Buscar uno que no existe.
4. Mostrar la lista completa.

## Pruebas de cola de prioridad
1. Insertar clientes con diferentes prioridades.
2. Validar que se ordenan correctamente.
3. Atender al cliente con mayor prioridad.

## Pruebas de pila
1. Registrar varias transacciones.
2. Eliminar la ultima transaccion.
3. Mostrar el historial completo.

## Pruebas de persistencia
1. Guardar datos.
2. Cerrar el programa.
3. Ejecutarlo otra vez.
4. Cargar datos.
5. Verificar que se mantienen.

## Contenido

### test_lista.cpp
Prueba la estructura de lista enlazada:
- agregar clientes
- recorrer lista
- buscar por DNI

### test_cola.cpp
Prueba la cola de prioridad:
- insercion segun prioridad
- orden correcto de la cola
- extraccion del primer elemento

### test_pila.cpp
Prueba la pila:
- agregar transacciones
- remover la ultima
- recorrido LIFO

### manual_tests.md
Documento con instrucciones para pruebas manuales y comandos usados durante la verificacion.

## Notas
- Estos archivos no forman parte del sistema principal.
- Se pueden compilar de forma independiente.
- Se usan para verificar que las estructuras funcionan antes de integrarlas a `main.cpp`.