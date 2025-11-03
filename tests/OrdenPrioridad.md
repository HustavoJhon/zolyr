```cpp
int obtenerPrioridad(const char *tipo) {
  if (strcmp(tipo, "VIP") == 0)
    return 1;
  if (strcmp(tipo, "Preferencial") == 0)
    return 2;
  return 3;
}

```
### Explicación línea a línea

1. `int obtenerPrioridad(const char *tipo) {`
    
    - Declara la función que recibe un `const char*` (cadena C) llamada `tipo` y devuelve un `int`.
        
    - **Entrada esperada:** cadenas como `"VIP"`, `"Preferencial"`, `"Regular"` (o cualquier otra cadena para fallback).
        
2. `if (strcmp(tipo, "VIP") == 0)`
    
    - Compara la cadena `tipo` con `"VIP"` usando `strcmp`. `strcmp` devuelve 0 si son exactamente iguales (carácter por carácter).
        
    - Importante: la comparación es **sensible a mayúsculas/minúsculas** (`"vip"` no coincide).
        
3. `return 1;`
    
    - Si `tipo` es `"VIP"`, devuelve prioridad `1` (la más alta en este diseño).
        
4. `if (strcmp(tipo, "Preferencial") == 0)`
    
    - Si no era `"VIP"`, compara con `"Preferencial"`.
        
5. `return 2;`
    
    - Si coincide, devuelve `2`.
        
6. `return 3;`
    
    - Si ninguna comparacion anterior fue cierta, retorna `3` por defecto (regular).
        
    - **Comportamiento implícito:** cualquier valor no reconocido cae en prioridad `3`.
        

### Notas prácticas

- **Complejidad:** O(1) (comparaciones de cadenas cortas).
    
- **Precaución:** si `tipo` es `NULL`, `strcmp` provoca UB; asegúrate de que `tipo` siempre apunte a una cadena válida.
    
- **Mejora opcional:** normalizar `tipo` (toupper / trim) para robustez.
```cpp

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

  cout << COLOR_OK << "Cliente atendido con éxito\n" << COLOR_RESET;
  pausa();
}

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

### Explicación detallada (línea a línea / bloque por bloque)

#### Inicio y entrada DNI

- `void encolarCliente() {`
    
    - Función que no recibe parámetros (solicita entrada al usuario internamente).
        
- `limpiarPantalla(); mostrarBanner(); cout << COLOR_MENU << "== ENCOLAR CLIENTE ==" << COLOR_RESET << endl;`
    
    - Limpia la pantalla y muestra cabecera/efecto visual para UX.
        
- `char dni[9];`
    
    - Reserva arreglo `dni` para leer el DNI (8 caracteres + `'\0'`).
        
- `cout << "Ingrese DNI: "; cin >> dni;`
    
    - Pide al usuario el DNI. `cin >>` elimina espacios y lee hasta el primer espacio/newline.
        

#### Buscar cliente existente

- `Cliente *cli = buscarCliente(dni);`
    
    - Llama a `buscarCliente` para obtener el puntero al cliente registrado con ese DNI (busca en `listaClientes`).
        
- `if (cli == NULL) { ... return; }`
    
    - Si no existe cliente con ese DNI: muestra error, pausa y sale sin encolar.
        
    - **Importante:** esto evita encolar DNIs no registrados.
        

#### Crear nuevo nodo de cola

- `NodoCola *nuevo = new NodoCola();`
    
    - Reserva memoria dinámica para el nuevo nodo de la cola.
        
    - **Estado:** `nuevo` apunta a memoria recién asignada, contenido indeterminado hasta inicializar.
        
- `strcpy(nuevo->dni, dni);`
    
    - Copia la cadena `dni` al campo `nuevo->dni`.
        
    - **Precaución:** asume que `dni` cabe en `nuevo->dni` (9 bytes). Si usuario ingresó más, `cin >>` truncará o provocará overflow; en tu código previo asumes 8 dígitos.
        
- `nuevo->prioridad = obtenerPrioridad(cli->tipo);`
    
    - Calcula prioridad usando el `tipo` del cliente encontrado (`cli->tipo`) y la almacena.
        
- `nuevo->sig = NULL;`
    
    - Inicializa el siguiente puntero a `NULL` (actualmente no enlazado).
        

#### Insertar en la cola manteniendo orden por prioridad

- `if (cola == NULL || nuevo->prioridad < cola->prioridad) {`
    
    - Caso A: **cola vacía** (`cola == NULL`) **o** el nuevo tiene **mayor prioridad** (nota: prioridad numérica menor => más importante).
        
    - Ejemplo: si `cola` apunta a nodo con prioridad 2 y `nuevo->prioridad` es 1, entra aquí.
        
- `nuevo->sig = cola; cola = nuevo;`
    
    - Inserción al inicio: `nuevo` apunta al antiguo primer nodo; `cola` ahora apunta a `nuevo`.
        
    - **Efecto:** `nuevo` se convierte en el primer cliente a atender.
        
- `} else { NodoCola *aux = cola; while (aux->sig != NULL && aux->sig->prioridad <= nuevo->prioridad) aux = aux->sig; nuevo->sig = aux->sig; aux->sig = nuevo; }`
    
    - Caso B: **insertar en medio o al final**:
        
        1. `NodoCola *aux = cola;` — inicia `aux` en el primer nodo.
            
        2. `while (aux->sig != NULL && aux->sig->prioridad <= nuevo->prioridad) aux = aux->sig;`
            
            - Recorre la cola hasta encontrar el punto donde el siguiente nodo tenga **prioridad mayor (número menor)** que `nuevo` o hasta el final.
                
            - La condición `aux->sig->prioridad <= nuevo->prioridad` mantiene **estabilidad** en el orden: clientes con la misma prioridad quedan antes del recién insertado (se inserta después de ellos).
                
            - **Ejemplo de recorrido:** si la cola tiene prioridades `[1,1,2,3]` y `nuevo->prioridad=2`, el bucle saltará los nodos con prioridad `1,1,2` hasta colocarse después del último `2` (porque `<=`). Si quieres insertar antes del primer `2`, usar `<` cambiaría comportamiento.
                
        3. `nuevo->sig = aux->sig; aux->sig = nuevo;` — inserta `nuevo` entre `aux` y `aux->sig`.
            

#### Finalización

- `cout << COLOR_OK << "Cliente encolado correctamente.\n" << COLOR_RESET; pausa();`
    
    - Notifica al usuario y pausa para que vea el mensaje.
        

### Estado de la estructura y ejemplo

Supongamos cola inicialmente vacía (`cola = NULL`).

Caso A (cola vacía):

- Input: DNI `12345678`, tipo del cliente `Preferencial` → prioridad `2`.
    
- Resultado: `cola -> [dni=12345678, prioridad=2, sig=NULL]`.
    

Caso B (cola con nodos):

- Cola actual (de primero a último): (DNI:A p=1) -> (DNI:B p=2) -> (DNI:C p=3)
    
- Insertar nuevo con prioridad `2`: recorre y lo coloca después del primer `2`, resultado: (A p1) -> (B p2) -> (nuevo p2) -> (C p3).
    

### Complejidad e implicaciones

- **Inserción peor caso:** O(n) (cuando se inserta al final).
    
- **Memoria:** `new NodoCola()` cada inserción; no hay liberación en esta función.
    
- **Consistencia:** debido a `<=` en el while, clientes con misma prioridad se mantienen en orden FIFO entre ellos (estabilidad).