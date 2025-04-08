# Configuración básica
BIN       = bin
SRC       = src
OBJ       = obj
CXX       = g++
CPPFLAGS  = -Wall -g -ansi

# Lista de programas que queremos compilar
PROGRAMAS = burbuja fibonacci hanoi heapsort insercion mergesort quicksort seleccion

# Obtener todos los archivos .cpp del directorio SRC
SOURCES = $(wildcard $(SRC)/*.cpp)

# Regla principal: compilar todos los programas
all: $(PROGRAMAS)

# Crear el directorio BIN si no existe
$(BIN)/:
	mkdir -p $(BIN)

# Compilación individual para cada programa
$(PROGRAMAS): $(BIN)/$@ | $(BIN)/
	$(CXX) $(CPPFLAGS) $(SRC)/$@.cpp -o $(BIN)/$@

# Ejecución Scripts
exeResultados:
	./scripts/script.sh
	./scripts/script_fibonacci.sh
	./scripts/script_hanoi.sh

# Limpieza de archivos temporales
.PHONY: clean
clean:
	@echo Limpiando archivos intermedios...
	rm -rf $(BIN) resultados