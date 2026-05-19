/* calificaciones.h - Definiciones y prototipos del programa */

#ifndef CALIFICACIONES_H
#define CALIFICACIONES_H

#define NUM_ASIGNATURAS  3
#define MAX_ESTUDIANTES  100
#define MAX_NOMBRE       50
#define NOTA_APROBATORIA 6.0

/* Nombres de las asignaturas (se definen en calificaciones.c) */
extern char asignaturas[NUM_ASIGNATURAS][20];

/* Estructura que representa a un estudiante */
typedef struct {
    char  nombre[MAX_NOMBRE];
    float notas[NUM_ASIGNATURAS];  /* vector de calificaciones */
} Estudiante;

