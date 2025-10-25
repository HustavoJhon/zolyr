---

kanban-plugin: board

---

## TODO

- [ ] **Registrar cliente en lista enlazada**
	
	- **Asignado a:** @HUSTAVOJHON
	    
	- **Descripción:** Validar DNI, ingresar nombre y tipo de cliente, guardar en lista enlazada.
	    
	- **Subtareas:**
		- Validar DNI
		- Ingresar nombre
		- Seleccionar tipo (VIP, Preferencial, Regular)
		- Insertar al final de la lista
- [ ] **Registrar transacción en pila**
	
	- **Asignado a:** @RODRIGO
	    
	- **Descripción:** Registrar depósitos y retiros, almacenar en estructura LIFO.
	    
	- **Subtareas:**
		- Validar tipo de transacción
		- Validar monto
		- Insertar en pila
- [ ] **Implementar cola de prioridad**
	
	- **Asignado a:** @SEBASTIAN
	    
	- **Descripción:** Clientes se encolan según prioridad (VIP, Preferencial, Regular).
	    
	- **Subtareas:**
		- Determinar prioridad según tipo de cliente
		- Insertar en la cola respetando orden
- [ ] **Documentar estructuras de datos para informe**
	
	- **Asignado a:** @HUSTAVOJHON
	    
	- **Descripción:** Explicar lista, pila y cola; justificar elección.


## IN PROGRESS

- [ ] **Codificar función `mostrarClientes()`**
	
	- **Asignado a:** @RODRIGO
	    
	- **Descripción:** Mostrar la lista de clientes con DNI, nombre y tipo.
- [ ] **Codificar función `atenderCliente()`**
	
	- **Asignado a:** @SEBASTIAN
	    
	- **Descripción:** Retirar cliente de la cola de atención y mostrar mensaje.
- [ ] **Preparar pseudocódigo de algoritmos principales**
	
	- **Asignado a:** @HUSTAVOJHON
	    
	- **Descripción:** Pseudocódigo para agregar proceso y cambiar estado de proceso.


## TEST

- [ ] **Probar transacciones**
	
	- **Asignado a:** @SEBASTIAN
	    
	- **Descripción:** Verificar que la pila respete LIFO y que se registren correctamente los montos.
- [ ] **Probar registro de clientes**
	
	- **Asignado a:** @RODRIGO
	    
	- **Descripción:** Ingresar clientes de prueba, verificar inserción correcta en lista.
- [ ] **Probar cola de atención**
	
	- **Asignado a:** @HUSTAVOJHON
	    
	- **Descripción:** Verificar que los clientes se atiendan según prioridad y orden de llegada.


## DONE

- [ ] **Agregar colores a la consola**
	
	- **Asignado a:** @RODRIGO
	    
	- **Descripción:** Diferenciar títulos, errores, información y confirmaciones usando colores.
- [ ] **Implementar menú principal**
	
	- **Asignado a:** @HUSTAVOJHON
	    
	- **Descripción:** Opciones para registrar cliente, transacción, mostrar lista, cola y transacciones.
- [ ] **Validar entradas de datos**
	
	- **Asignado a:** @SEBASTIAN
	    
	- **Descripción:** Validar DNI, montos y tipos de clientes antes de insertar en estructuras.




%% kanban:settings
```
{"kanban-plugin":"board","list-collapse":[false,false,false,false]}
```
%%