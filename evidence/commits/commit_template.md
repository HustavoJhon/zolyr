# Plantilla y buenas practicas para commits – FINPROC

Este archivo define la estructura recomendada para escribir commits claros y ordenados en el proyecto FINPROC. Tambien explica el uso de etiquetas estandar para mejorar la lectura del historial de cambios.

La idea es que cada commit tenga una finalidad clara, una descripcion simple y un formato facil de entender.

---

## 1. Formato recomendado de commit

Formato general:

```
tipo: descripcion breve

Descripcion detallada (opcional).
Archivos modificados (opcional).
Motivo del cambio (opcional).
```

Ejemplo real:

```
feat: agregar funcion para encolar clientes

Se implementa la funcion encolarCliente usando prioridad.
Permite ordenar clientes segun tipo.
```

---

## 2. Tipos de commits y su significado

### 2.1 feat
Nueva funcionalidad.

### 2.2 fix
Correccion de errores.

### 2.3 chore
Mantenimiento sin afectar la logica.

### 2.4 refactor
Reescritura sin cambiar comportamiento.

### 2.5 docs
Cambios en documentacion.

### 2.6 test
Cambios en pruebas.

### 2.7 build
Cambios en compilacion o dependencias.

### 2.8 perf
Mejoras de rendimiento.

---

## 3. Plantilla para completar antes de un commit

```
# Fecha:
(ingresar fecha)

# Autor:
(nombre del integrante)

# Tipo de commit:
(elegir: feat, fix, chore, refactor, docs, test, build, perf)

# Descripcion breve:
(explicar en una linea lo que se cambio)

# Descripcion detallada:
(explicar los cambios de ser necesario)

# Archivos modificados:
- archivo_1
- archivo_2

# Motivo del cambio:
(breve explicacion del por que)

# Notas adicionales:
(opcional)
```