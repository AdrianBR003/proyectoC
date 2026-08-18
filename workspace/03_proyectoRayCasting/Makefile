# ==========================================
# CONFIGURACIÓN GENERAL
# ==========================================

RAYLIB_PATH ?= C:/raylib/raylib

CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wno-missing-braces

# DEBUG / RELEASE
BUILD_MODE ?= DEBUG

ifeq ($(BUILD_MODE),RELEASE)
	CXXFLAGS += -O2
else
	CXXFLAGS += -g -D_DEBUG
endif

# ==========================================
# RUTAS DEL PROYECTO
# ==========================================

SRC_DIR = src
INC_DIR = include

SRC  := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/**/*.cpp)
EXEC := main.exe

INCLUDES = \
	-I$(INC_DIR) \
	-I$(RAYLIB_PATH)/src \
	-I$(RAYLIB_PATH)/src/external

LDFLAGS = \
	-L$(RAYLIB_PATH)/src \
	-lraylib \
	-lopengl32 \
	-lgdi32 \
	-lwinmm

# ==========================================
# COMPILACIÓN
# ==========================================

all: $(EXEC)

$(EXEC): $(SRC)
	@echo ----------------------------------------------------
	@echo Compilando...
	@echo ----------------------------------------------------
	$(CXX) $(SRC) -o $(EXEC) $(CXXFLAGS) $(INCLUDES) $(LDFLAGS)
	@echo ----------------------------------------------------
	@echo Compilación completada
	@echo Ejecutable: $(EXEC)
	@echo ----------------------------------------------------

clean:
	del /f /q *.exe 2>nul || exit 0