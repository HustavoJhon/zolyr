# Idea para mejorar el menu de FINPROC usando ASCII y colores

Esta nota documenta una idea de mejora para el menu principal del sistema FINPROC. El objetivo es hacer que el programa se vea mas agradable y mas claro para el usuario mediante el uso de arte ASCII simple y colores ANSI en la consola.

La idea es agregar:

1. Un titulo en ASCII al iniciar el programa.
2. Colores para resaltar opciones del menu.
3. Un estilo visual consistente en todo el sistema.

## ASCII propuesto para el titulo

Se propone usar un titulo simple como:

```ascii
| _**_(_) | | | __ \  
| |** _ _ __ | |_| |**) |** _ _ __ ___  
| __| | | '_ | __| ___/ _ \ '_ ` _ \  
| | | | | | | |_| | | **/ | | | | |  
|_| |_|_| |_|__|_| _**|_| |_| |_|
```

Este titulo aparece una sola vez al iniciar el sistema.

## Uso de colores ANSI

Los colores no afectan el funcionamiento y hacen que el menu sea mas claro.

Ejemplo de colores disponibles:

- `\033[1;32m` verde claro  
- `\033[1;34m` azul  
- `\033[1;31m` rojo  
- `\033[1;33m` amarillo  
- `\033[0m` reset para volver al color normal  

Se propone usar:

- Azul para el titulo  
- Verde para las opciones validas  
- Amarillo para mensajes informativos  
- Rojo para errores  

## Ejemplo del menu con colores

Pseudocodigo del menu con colores:

```cpp
cout << "\033[1;34m";
cout << ascii_logo;
cout << "\033[0m";

cout << "\033[1;32m1.\033[0m Registrar cliente\n";
cout << "\033[1;32m2.\033[0m Encolar cliente\n";
cout << "\033[1;32m3.\033[0m Atender cliente\n";
cout << "\033[1;32m4.\033[0m Registrar transaccion\n";
cout << "\033[1;32m5.\033[0m Mostrar clientes\n";
cout << "\033[1;32m6.\033[0m Mostrar cola\n";
cout << "\033[1;32m7.\033[0m Mostrar transacciones\n";
cout << "\033[1;32m8.\033[0m Guardar datos\n";
cout << "\033[1;32m9.\033[0m Cargar datos\n";
cout << "\033[1;32m0.\033[0m Salir\n";

```

## Beneficios

- Interfaz mas clara para el usuario final
- El menu se ve mas profesional
- La organizacion visual mejora la experiencia
- No se usa ninguna libreria externa
- Funciona en Linux, macOS y muchas consolas de Windows
