# Manual de Instalacion y Ejecucion con Docker

**Proyecto FINPROC v1.0**

Este documento explica como ejecutar FINPROC dentro de un contenedor Docker. El objetivo es ofrecer una instalacion sencilla, sin necesidad de configurar compiladores locales.

---

## 1. Requisitos

Para usar esta version es necesario tener instalado:

- Docker Desktop (Windows o macOS)
- Docker Engine (Linux)
- Conexion a internet para la primera descarga de imagenes
No es necesario instalar Dev-C++ ni g++ en la maquina local.

---

## 2. Estructura del proyecto

FINPROC debe tener la siguiente estructura de carpetas:
```bash
FINPROC/
│── src/
│     └── main.cpp        # Codigo principal del sistema
│── Dockerfile            # Archivo para construir la imagen
│── clientes.txt          # Archivo generado por el programa (opcional)
└── README.md
```
El archivo `main.cpp` debe estar dentro de la carpeta `src`.

## 3. Dockerfile del proyecto

El archivo Dockerfile es el encargado de preparar el entorno del programa dentro del contenedor. El contenido necesario es el siguiente:
```bash
FROM gcc:latest

WORKDIR /app

COPY src/ /app/src/

RUN g++ /app/src/main.cpp -o finproc

CMD ["./finproc"]

```
Este archivo realiza tres tareas principales:

1. Descarga una imagen oficial de gcc.
2. Copia el codigo fuente dentro del contenedor.
3. Compila el archivo main.cpp.
    

---

## 4. Construccion de la imagen

Para crear la imagen, abra una terminal en la carpeta `FINPROC` y ejecute:
```bash
docker build -t finproc .
```
Explicacion:

- `docker build` crea una imagen a partir del Dockerfile
- `-t finproc` asigna el nombre "finproc" a la imagen
- `.` indica que el Dockerfile esta en el directorio actual
    

La primera vez puede tardar unos minutos.

---

## 5. Ejecucion del programa

Para ejecutar FINPROC dentro de un contenedor:
```bash
docker run -it finproc
```
Significado:

- `-it` permite usar el programa en modo interactivo
- `finproc` es el nombre de la imagen creada anteriormente
    

Al ejecutar el comando, aparecera el menu principal del sistema por consola.

---

## 6. Persistencia de datos

El programa FINPROC genera un archivo `clientes.txt` para guardar informacion.
Para hacer que ese archivo quede guardado fuera del contenedor, se usa un volumen:

### Linux o macOS
```bash
docker run -it -v $(pwd):/app finproc

```
### Windows PowerShell
```bash
docker run -it -v ${PWD}:/app finproc

```
Esto permite que:

- Los archivos creados dentro del contenedor se almacenen en su computadora
- La informacion no se pierda al cerrar el contenedor
    

---

## 7. Reconstruccion del contenedor

Si modifica el archivo `main.cpp`, debera volver a construir la imagen:
```bash
docker build --no-cache -t finproc .
```
El parametro `--no-cache` asegura que Docker no reutilice datos antiguos.

---

## 8. Problemas comunes

|Problema|Causa|Solucion|
|---|---|---|
|Docker no encuentra `main.cpp`|Estructura incorrecta|Verifique que el archivo este en `src/`|
|Error al ejecutar|No existe ejecutable|Asegurese de construir la imagen antes de ejecutar|
|Cambie el codigo y no se actualiza|Imagen antigua|Ejecutar con `--no-cache`|
