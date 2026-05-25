/* calificaciones.c - Implementacion de todas las funciones */

#include <stdio.h>
#include <string.h>
#include "calificaciones.h"

/* Vector con los nombres de las asignaturas */
char asignaturas[NUM_ASIGNATURAS][20] = {
    "Matematicas",
    "Programacion",
    "Fisica"
};

/* ================================================
   FUNCIONES DE ENTRADA DE DATOS
   ================================================ */

/* Pide al usuario cuantos estudiantes hay */
int pedirNumeroEstudiantes() {
    int n;
    do {
        printf("Cuantos estudiantes hay? (1 a %d): ", MAX_ESTUDIANTES);
        scanf("%d", &n);
        /* Limpiar el buffer del teclado */
        while (getchar() != '\n');

        if (n < 1 || n > MAX_ESTUDIANTES) {
            printf("Numero invalido, intente de nuevo.\n");
        }
    } while (n < 1 || n > MAX_ESTUDIANTES);

    return n;
}

/* Pide el nombre y las notas de un estudiante */
void leerEstudiante(Estudiante *e, int numero) {
    float nota;
    int i;

    printf("\n--- Estudiante #%d ---\n", numero);
    printf("Nombre: ");
    fgets(e->nombre, MAX_NOMBRE, stdin);
    /* Quitar el salto de linea que deja fgets al final */
    e->nombre[strcspn(e->nombre, "\n")] = '\0';

    /* Pedir nota por cada asignatura con validacion */
    for (i = 0; i < NUM_ASIGNATURAS; i++) {
        do {
            printf("  Nota de %s: ", asignaturas[i]);
            scanf("%f", &nota);
            while (getchar() != '\n');

            if (nota < 0 || nota > 10) {
                printf("  Nota invalida. Debe estar entre 0 y 10.\n");
            }
        } while (nota < 0 || nota > 10);

        e->notas[i] = nota;
    }
}

/* ================================================
   FUNCIONES DE CALCULO POR ESTUDIANTE
   ================================================ */

/* Calcula el promedio de un estudiante recorriendo su vector de notas */
float promedioEstudiante(Estudiante *e) {
    float suma = 0;
    int i;
    for (i = 0; i < NUM_ASIGNATURAS; i++) {
        suma = suma + e->notas[i];
    }
    return suma / NUM_ASIGNATURAS;
}

/* Encuentra la nota mas alta de un estudiante */
float notaMasAltaEstudiante(Estudiante *e) {
    float max = e->notas[0];
    int i;
    for (i = 1; i < NUM_ASIGNATURAS; i++) {
        if (e->notas[i] > max) {
            max = e->notas[i];
        }
    }
    return max;
}

/* Encuentra la nota mas baja de un estudiante */
float notaMasBajaEstudiante(Estudiante *e) {
    float min = e->notas[0];
    int i;
    for (i = 1; i < NUM_ASIGNATURAS; i++) {
        if (e->notas[i] < min) {
            min = e->notas[i];
        }
    }
    return min;
}

/* ================================================
   FUNCIONES DE CALCULO POR ASIGNATURA
   ================================================ */

/* Calcula el promedio de una asignatura (columna) en toda la lista */
float promedioAsignatura(Estudiante lista[], int total, int columna) {
    float suma = 0;
    int i;
    for (i = 0; i < total; i++) {
        suma = suma + lista[i].notas[columna];
    }
    return suma / total;
}

/* Nota mas alta de una asignatura en toda la lista */
float notaMasAltaAsignatura(Estudiante lista[], int total, int columna) {
    float max = lista[0].notas[columna];
    int i;
    for (i = 1; i < total; i++) {
        if (lista[i].notas[columna] > max) {
            max = lista[i].notas[columna];
        }
    }
    return max;
}

/* Nota mas baja de una asignatura en toda la lista */
float notaMasBajaAsignatura(Estudiante lista[], int total, int columna) {
    float min = lista[0].notas[columna];
    int i;
    for (i = 1; i < total; i++) {
        if (lista[i].notas[columna] < min) {
            min = lista[i].notas[columna];
        }
    }
    return min;
}

/* Cuenta cuantos aprobaron y reprobaron en una asignatura.
   Usa punteros para devolver dos valores a la vez. */
void contarAprobadosReprobados(Estudiante lista[], int total, int columna,
                               int *aprobados, int *reprobados) {
    int i;
    *aprobados  = 0;
    *reprobados = 0;
    for (i = 0; i < total; i++) {
        if (lista[i].notas[columna] >= NOTA_APROBATORIA) {
            *aprobados = *aprobados + 1;
        } else {
            *reprobados = *reprobados + 1;
        }
    }
}
