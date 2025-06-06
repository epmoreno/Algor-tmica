#!/bin/bash

# Configuración
INICIO=20
FIN=40
INCREMENTO=2
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

        # Verificar si el archivo es fibonacci
        if [ "$file" = "./bin/fibonacci" ]; then

            # Ejecutar el archivo
            echo "Ejecutando $file, n=$i"
            ./$file $i>> resultados/$(basename "$file" .out).csv

        fi
    done
done