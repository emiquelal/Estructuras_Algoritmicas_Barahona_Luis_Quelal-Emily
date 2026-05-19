#include <stdio.h>
#include "calificaciones.h"

int main() 
{
    /* Matriz de estudiantes (arreglo de structs) */
    Estudiante lista[MAX_ESTUDIANTES];
    int total, i;

    printf("  SISTEMA DE CALIFICACIONES\n");

    /* 1. Pedir cuantos estudiantes hay */
    total = pedirNumeroEstudiantes();

    /* 2. Leer los datos de cada estudiante */
    printf("\n-- Ingreso de datos --\n");
    for (i = 0; i < total; i++) {
        leerEstudiante(&lista[i], i + 1);
    }

    /* 3. Mostrar todos los resultados */
    mostrarTablaGeneral(lista, total);
}