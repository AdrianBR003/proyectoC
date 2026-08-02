# Plantilla de proyectos Raylib

## Estructura de cada proyecto

Cada proyecto debe ser completamente independiente:

```
MiProyecto/
│
├── .vscode/
│   ├── c_cpp_properties.json
│   ├── launch.json
│   └── tasks.json
│
├── include/
├── src/
├── assets/
├── Makefile
└── README.md
```

> **Importante:** Cada proyecto debe tener su propio `Makefile` y su propia carpeta `.vscode`.

---

## Crear un nuevo proyecto

1. Copiar la plantilla de un proyecto anterior.
2. Cambiar el nombre de la carpeta.
3. Abrir **esa carpeta** en VS Code para trabajar.

---

## Añadir el proyecto al Workspace

Si quieres tener varios proyectos abiertos a la vez:

1. Abrir el archivo `.code-workspace`.
2. `Archivo -> Agregar carpeta al área de trabajo...`
3. Seleccionar la nueva carpeta del proyecto.
4. Guardar el Workspace (`Ctrl + S`).

Así podrás comparar archivos entre proyectos sin que IntelliSense mezcle clases o cabeceras.

---

## Git

No hay que hacer ninguna configuración especial.

Mientras el `.git` esté en la carpeta padre del repositorio:

```
proyectoC/
│
├── .git/
├── 01_proyecto/
├── 02_proyecto/
├── 03_proyecto/
└── proyecto.code-workspace
```

Git detectará automáticamente todos los proyectos aunque abras el `.code-workspace`.

---

## Compilar

```
Ctrl + Shift + B
```

---

## Problemas comunes

### IntelliSense no autocompleta variables

Probablemente has abierto la carpeta padre en lugar del `.code-workspace` o del proyecto individual.

### `#include <raylib.h>` da error

Comprobar que `c_cpp_properties.json` contiene la ruta de Raylib y que `compilerPath` apunta a `g++.exe` de `w64devkit`.

### `make: No makefile found`

Falta el `Makefile` en la raíz del proyecto.

---

## Recomendación

Mantener una carpeta **RaylibTemplate** con toda esta estructura preparada y copiarla cada vez que empieces un proyecto nuevo.