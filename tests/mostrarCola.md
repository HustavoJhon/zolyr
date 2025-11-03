```cpp
void mostrarCola() {
  limpiarPantalla();
  mostrarBanner();
  cout << COLOR_MENU << "== COLA DE ATENCIÓN ==" << COLOR_RESET << endl;

  if (cola == NULL) {
    cout << COLOR_INFO << "No hay clientes en cola.\n" << COLOR_RESET;
  } else {
    NodoCola *aux = cola;
    while (aux != NULL) {
      cout << aux->dni << " (Prioridad " << aux->prioridad << ")\n";
      aux = aux->sig;
    }
  }

  pausa();
}

```

### Explicación línea a línea

- Preparación visual: limpia pantalla y muestra banner.
    
- `if (cola == NULL) { ... } else { ... }`
    
    - Si vacía muestra mensaje; si no, procede a recorrer.
        
- `NodoCola *aux = cola;`
    
    - `aux` es puntero temporal que empieza en la cabeza de la cola.
        
- `while (aux != NULL) { cout << ...; aux = aux->sig; }`
    
    - Itera por toda la lista enlazada imprimiendo `dni` y `prioridad` de cada nodo.
        
    - No modifica la cola; solo lectura.
        
- `pausa();`
    
    - Espera para que el usuario vea la lista.
        

### Ejemplo de salida

Si la cola contiene:

- 11111111 (Prioridad 1)
    
- 22222222 (Prioridad 2)
    
- 33333333 (Prioridad 2)  
    La impresión será:

## Flujo completo de ejemplo (paso a paso)

1. Estado inicial: `cola = NULL`.
    
2. `encolarCliente()` con DNI `A`, tipo VIP → `nuevo.prio = 1` → cola = [A p1].
    
3. `encolarCliente()` con DNI `B`, tipo Regular → `nuevo.prio = 3` → cola = [A p1] -> [B p3].
    
4. `encolarCliente()` con DNI `C`, tipo Preferencial → `nuevo.prio = 2` → se recorre y queda: [A p1] -> [C p2] -> [B p3].
    
5. `mostrarCola()` imprime A, C, B.
    
6. `atenderCliente()` elimina A → cola = [C p2] -> [B p3].
    
7. `atenderCliente()` elimina C → cola = [B p3].
    

---

## Errores y casos borde a exponer

- **DNI no registrado:** `encolarCliente` valida y rechaza; importante para coherencia de datos.
    
- **Entrada demasiado larga:** `char dni[9]` y `cin >> dni` → si se ingresa más, puede causar problemas; ideal validar longitud explícita.
    
- **`tipo` inesperado:** `obtenerPrioridad` devuelve `3` por defecto; explicar que esto es deliberado como fallback.
    
- **Fugas de memoria:** `new` en `encolarCliente` debe emparejarse con `delete` en `atenderCliente`. Si terminas el programa sin vaciar estructuras, hay fugas residuales; para proyecto académico está bien, pero ideal liberar toda la memoria al salir.
    
- **Concurrencia:** diseño no es thread-safe (no es necesario aquí, pero mencionarlo cuando presente).
    
- **Sensibilidad a mayúsculas/minúsculas:** `strcmp` es exacto.