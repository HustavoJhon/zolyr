---

kanban-plugin: board

---

## BACKLOG

- [ ] RNF1 – Modularidad y documentación del código (≥ 90%)
- [ ] **RF4 – Interfaz de Consola con Menú Principal**  
	Crear navegación clara: registrar cliente, cola, atención, transacciones y reportes.  
	_Criterio de aceptación:_ El usuario puede ejecutar cualquier módulo desde `main.cpp`.
- [ ] **RF5 – Persistencia (guardar/cargar)**  
	Implementar serialización de clientes, cola y transacciones mediante lectura/escritura estructurada.  
	_Criterio de aceptación:_ El estado del sistema se recupera tras reiniciar el programa.\
- [ ] **RF6 – Visualización del Estado de las Estructuras**  
	Mostrar clientes en lista, elementos en cola, y pila de transacciones por cliente.  
	_Criterio de aceptación:_ Al llamar a “Reportes”, se muestran todas las estructuras al instante.
- [ ] **Pruebas Unitarias de Cola, Lista y Pila**  
	Crear tests independientes en `tests/` usando casos básicos.  
	_Criterio de aceptación:_ Todas las pruebas compilan y ejecutan correctamente.


## TO DO

- [ ] **Implementar Lista Enlazada – Gestor de Clientes**  
	**Responsable:** @Rodrigo
	
	- Crear nodos y funciones: insertar, buscar, eliminar, listar.
	    
	- Integrar validación de DNI y generación de ID de cliente.
	    
	- Probar casos edge (lista vacía, duplicados).
	    
	- **Dependencia:** Ninguna.
	    
	- **Resultado esperado:** `client_manager.cpp` funcional.
- [ ] **Implementar Cola de Prioridad – Gestor de Atención**  
	**Responsable:** @Gustavo
	
	- Implementar `priority_queue` con comparador.
	    
	- Añadir timestamp de llegada y niveles de prioridad.
	    
	- Funciones: encolar, atender, mostrar cola.
	    
	- **Dependencia:** Lista enlazada (para obtener clientes).
	    
	- **Resultado esperado:** `queue.cpp` funcional.
- [ ] **Implementar Pila de Transacciones – Gestor de Historial**  
	**Responsable:** @Andre
	
	- Crear estructura tipo LIFO: push, pop, mostrar historial.
	    
	- Manejar revertir transacción (deshacer).
	    
	- **Dependencia:** Cola (para saber qué cliente está siendo atendido).
	    
	- **Resultado esperado:** `stack.cpp` funcional.
- [ ] **Crear Módulo de Persistencia – `file_manager.cpp`**  
	**Responsable:** @Gustavo
	
	- Guardar listas, colas y pilas en formato de texto estructurado.
	    
	- Cargar datos al inicio del programa.
	    
	- Manejar errores de archivo.
	    
	- **Dependencia:** Implementación de las tres estructuras.
	    
	- **Resultado esperado:** Sistemas de guardado/carga operativos.
- [ ] **Integración del Menú Principal – `main.cpp`**  
	**Responsable:** @Gustavo
	
	- Conectar las estructuras al menú.
	    
	- Flujo correcto entre opciones.
	    
	- **Dependencia:** Implementación previa de todas las estructuras.
	    
	- **Resultado esperado:** Programa navegable y funcional.


## IN PROGRESS

- [ ] **Revisión y refinamiento del pseudocódigo de Pila y Cola**
	
	- Adaptación según resultados de la reunión del martes.
	    
	- Ajustes a los diagramas de flujo y mermaid.
	    
	- Preparación para el capítulo 3 del informe.


## 

- [ ] **Finalización del Informe de Diseño – Capítulos 1 y 2**  
	Incluye análisis del problema, requerimientos, diseño modular y estructuras.
- [ ] **Commit inicial con estructura de carpetas + archivos `.hpp` base**
	
	- Proyecto organizado según estándares profesionales.
	    
	- Compatible con Obsidian + GitHub.




%% kanban:settings
```
{"kanban-plugin":"board","list-collapse":[false,false,false,false]}
```
%%