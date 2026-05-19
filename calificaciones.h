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

/* --- Prototipos de funciones --- */

/* Entrada de datos */
int   pedirNumeroEstudiantes();
void  leerEstudiante(Estudiante *e, int numero);

/* Calculos por estudiante */
float promedioEstudiante(Estudiante *e);
float notaMasAltaEstudiante(Estudiante *e);
float notaMasBajaEstudiante(Estudiante *e);

/* Calculos por asignatura */
float promedioAsignatura(Estudiante lista[], int total, int columna);
float notaMasAltaAsignatura(Estudiante lista[], int total, int columna);
float notaMasBajaAsignatura(Estudiante lista[], int total, int columna);
void  contarAprobadosReprobados(Estudiante lista[], int total, int columna,
                                int *aprobados, int *reprobados);

/* Mostrar resultados */
void  mostrarTablaGeneral(Estudiante lista[], int total);
void  mostrarResultadosPorEstudiante(Estudiante lista[], int total);
void  mostrarResultadosPorAsignatura(Estudiante lista[], int total);

#endif
