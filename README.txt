# 🎮 Plantilla de Proyectos con Raylib

Esta plantilla está pensada para crear proyectos con **Raylib**, **VS Code**, **w64devkit** y **Make**, manteniendo cada proyecto completamente independiente del resto.

---

# 📁 Estructura del proyecto

Cada proyecto debe tener su propia configuración y sistema de compilación.

```text
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

# 🚀 Crear un nuevo proyecto

1. Copia la plantilla de un proyecto anterior (o la carpeta `RaylibTemplate`).
2. Cambia el nombre de la carpeta.
3. Abre **esa carpeta** directamente en VS Code.

---

# 📂 Añadir el proyecto al Workspace

Si quieres trabajar con varios proyectos al mismo tiempo:

1. Abre el archivo `.code-workspace`.
2. Ve a **Archivo → Agregar carpeta al área de trabajo...**
3. Selecciona la carpeta del nuevo proyecto.
4. Guarda el Workspace (`Ctrl + S`).

De esta forma podrás cambiar de un proyecto a otro sin que IntelliSense mezcle clases, cabeceras o archivos fuente.

---

# 🌳 Git

No es necesario realizar ninguna configuración especial.

Mientras el directorio `.git` se encuentre en la carpeta padre del repositorio, Git detectará automáticamente todos los proyectos.

```text
Raylib/
│
├── .git/
├── 01_Proyecto/
├── 02_Proyecto/
├── 03_Proyecto/
└── raylib.code-workspace
```

Aunque abras el archivo `.code-workspace`, Git seguirá controlando correctamente todos los proyectos.

---

# 🔨 Compilar

Puedes compilar el proyecto de dos formas:

### Desde VS Code

```text
Ctrl + Shift + B
```

### Desde la terminal

```bash
make
```

---

# 🐞 Problemas comunes

## IntelliSense no autocompleta variables

Lo más probable es que hayas abierto la carpeta padre en lugar del proyecto individual o del archivo `.code-workspace`.

---

## `#include <raylib.h>` da error

Comprueba que:

- `c_cpp_properties.json` contiene la ruta donde está instalada Raylib.
- `compilerPath` apunta al `g++.exe` de **w64devkit**.

---

## `make: No makefile found`

Asegúrate de que existe un `Makefile` en la raíz del proyecto.

---

# 💡 Recomendación

Mantén una carpeta llamada **RaylibTemplate** con toda esta estructura preparada.

Cada vez que empieces un proyecto nuevo:

1. Copia la plantilla.
2. Renombra la carpeta.
3. Ábrela en VS Code.
4. Empieza a programar.

Así todos los proyectos serán independientes, estarán organizados y serán mucho más fáciles de mantener.

---

## 📄 Licencia

Puedes utilizar esta plantilla libremente para proyectos personales, educativos o de aprendizaje.
