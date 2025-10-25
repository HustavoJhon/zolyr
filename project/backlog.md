---
kanban-plugin: basic
---

# 🧪 Kanban de Pruebas Unitarias – FINPROC

## 📌 BACKLOG (Casos de prueba pendientes)
- [ ] CP-L01: Verificar inserción en lista enlazada cuando está vacía.
- [ ] CP-L02: Verificar inserción al final de la lista enlazada.
- [ ] CP-L03: Buscar cliente por DNI existente.
- [ ] CP-L04: Buscar cliente por DNI inexistente.
- [ ] CP-L05: Eliminar nodo en diferentes posiciones (inicio, medio, final).

- [ ] CP-C01: Encolar cliente FIFO correctamente.
- [ ] CP-C02: Encolar con prioridad y validar orden correcto.
- [ ] CP-C03: Atender cliente cuando la cola está vacía.
- [ ] CP-C04: Atender cliente con prioridades iguales → usar timestamp.
- [ ] CP-C05: Mostrar estado actual de la cola.

- [ ] CP-P01: Registrar transacción (push).
- [ ] CP-P02: Deshacer última transacción (pop).
- [ ] CP-P03: Mostrar historial de transacciones.
- [ ] CP-P04: Manejo de pila vacía.
- [ ] CP-P05: Validar que la transacción tenga tipo y monto válidos.

- [ ] CP-F01: Guardar lista de clientes en archivo.
- [ ] CP-F02: Cargar lista de clientes desde archivo.
- [ ] CP-F03: Guardar cola de atención (estructurada).
- [ ] CP-F04: Cargar cola de atención.
- [ ] CP-F05: Guardar y cargar historial de transacciones.

- [ ] CP-I01: Integrar lista + cola (encolar cliente directamente desde registro).
- [ ] CP-I02: Integración cola + pila (registrar transacción al atender).
- [ ] CP-I03: Integración completa: registrar → encolar → atender → transaccionar → guardar → cargar.
- [ ] CP-I04: Validación del menú principal saltando entre módulos.
- [ ] CP-I05: Recuperación de estado completo tras reiniciar el programa.

## 🛠️ TO DO
- [ ] Crear archivo base `tests/test_list.cpp` @Rodrigo
- [ ] Crear archivo base `tests/test_queue.cpp` @Gustavo
- [ ] Crear archivo base `tests/test_stack.cpp` @Andre
- [ ] Crear archivo `tests/test_persistence.cpp`
- [ ] Crear archivo `tests/test_integration.cpp`

## 🚧 IN PROGRESS
- [ ] Implementación del entorno de pruebas (Makefile + compilación automática)
- [ ] Diseño de casos de prueba con ejemplos reales de clientes
- [ ] Revisión cruzada de casos de prueba para evitar solapamientos

## ✅ DONE
- [x] Estructura inicial de la carpeta `tests/`
- [x] Primer test de cola funcionando (`test_queue.cpp`)
- [x] Plantillas `.hpp` listas para ser importadas en pruebas
