```cpp
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

  cout << COLOR_OK << "Cliente atendido con éxito\n" << COLOR_RESET;
  pausa();
}

```

### Explicación línea a línea

- `if (cola == NULL) { ... return; }`
    
    - Comprueba cola vacía y sale mostrando mensaje si no hay clientes.
        
- `cout << "Atendiendo a cliente con DNI: " << cola->dni << endl;`
    
    - Muestra el DNI del nodo que está al frente (primer nodo). Ese es el cliente con mayor prioridad/antigüedad según orden.
        
- `NodoCola *temp = cola;`
    
    - Guarda el puntero al nodo que será eliminado en `temp`.
        
- `cola = cola->sig;`
    
    - Desplaza la cabeza de la cola al siguiente nodo. Si solo había un nodo, `cola` queda `NULL`.
        
- `delete temp;`
    
    - Libera la memoria del nodo atendido. **Muy importante**: evita fuga de memoria.
        
    - Después de `delete`, `temp` es dangling; no lo uses.
        
- Mensaje de éxito y `pausa()` muestran confirmación.
    

### Efecto y ejemplo

- Cola antes: (DNI:A p1) -> (DNI:B p2) -> ...
    
- Llamar `atenderCliente()`:
    
    - Muestra "Atendiendo A", elimina nodo A, cola queda (B p2) -> ...
        
    - Operación `O(1)`.
        

### Precauciones

- Asegúrate que no haya referencias a `temp` después de `delete`.
    
- Si hay datos relacionados (por ejemplo contador de atenciones), actualizarlos antes de `delete` si necesitas la información.