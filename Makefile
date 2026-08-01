# ==========================================
# CONFIGURACIÓN GENERAL Y RUTAS DE RAYLIB
# ==========================================
RAYLIB_PATH ?= C:/raylib/raylib
CXX          = g++
CXXFLAGS     = -std=c++17 -Wall -Wno-missing-braces

# Determinar modo de compilación (DEBUG / RELEASE)
BUILD_MODE ?= DEBUG
ifeq ($(BUILD_MODE),RELEASE)
    CXXFLAGS += -O2
else
    CXXFLAGS += -g -D_DEBUG
endif

# ==========================================
# DETECCIÓN AUTOMÁTICA DEL SUBPROYECTO
# ==========================================
# Normalizar barras diagonales de Windows a formato Unix para Make
TARGET_FILE_FIXED := $(subst \,/,$(TARGET_FILE))

# Extraer el nombre de la carpeta dentro de workspace/ (Ej: 01_proyecto)
PROJECT_DIR := $(shell echo $(TARGET_FILE_FIXED) | sed -n "s/.*workspace\/\([^\/]*\).*/\1/p")

# Si no hay ningún archivo abierto, asigna '01_proyecto' por defecto
ifeq ($(PROJECT_DIR),)
    PROJECT_DIR := 01_proyecto
endif

# Rutas locales del subproyecto detectado
PROJ_PATH    := workspace/$(PROJECT_DIR)
SRC_DIR      := $(PROJ_PATH)/src
INC_DIR      := $(PROJ_PATH)/include

# ==========================================
# ARCHIVOS FUENTE, LIBRERÍAS Y SALIDA
# ==========================================
# Busca todos los .cpp dentro de workspace/<proyecto>/src/
SRC          := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/**/*.cpp)
EXEC         := $(PROJ_PATH)/main.exe

INCLUDES     := -I$(INC_DIR) -I$(RAYLIB_PATH)/src -I$(RAYLIB_PATH)/src/external
LDFLAGS      := -L$(RAYLIB_PATH)/src -lraylib -lopengl32 -lgdi32 -lwinmm

# ==========================================
# REGLAS DE COMPILACIÓN
# ==========================================
all: $(EXEC)

$(EXEC): $(SRC)
	@echo ----------------------------------------------------
	@echo Compilando subproyecto: [ $(PROJECT_DIR) ]
	@echo ----------------------------------------------------
	$(CXX) $(SRC) -o $(EXEC) $(CXXFLAGS) $(INCLUDES) $(LDFLAGS)
	@echo ----------------------------------------------------
	@echo ¡Compilacion completada! Ejecutable en: $(EXEC)
	@echo ----------------------------------------------------

clean:
	del /f /q workspace\*\*.exe 2>nul || exit 0