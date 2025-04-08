#!/bin/bash

# Configuración
INICIO=5000
FIN=50000
INCREMENTO=5000
BIN=./bin/*

# Resultados
mkdir -p resultados

# Ejecución
for file in $BIN; do
    for (( i = $INICIO; i <= $FIN; i += $INCREMENTO )); do

        # Verificar si el archivo existe
        if [ ! -f "$file" ]; then
            echo "Error: $file no existe"
            continue
        fi

        # Verificar si el archivo es fibonacci o hanoi
        if [ "$file" = "./bin/fibonacci" ] || [ "$file" = "./bin/hanoi" ]; then
            continue
        fi

        # Ejecutar el archivo
        
        echo "Ejecutando $file, n=$i"
        ./$file $i>> resultados/$(basename "$file" .out).csv
    done
done