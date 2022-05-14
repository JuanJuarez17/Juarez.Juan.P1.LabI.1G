#ifndef ETRABAJOS_H_INCLUDED
#define ETRABAJOS_H_INCLUDED
#include "fecha.h"

typedef struct{
    int id;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // ETRABAJOS_H_INCLUDED

int iniTrabajo(eTrabajo vec[], int tam);

int buscarIndexLibre(eTrabajo vec[], int tam, int* pIndex);

int buscarIndexCompleto(eTrabajo vec[], int tam);

void mostrarTrabajo(eTrabajo vec);

int altaTrabajo(eTrabajo vec[], int tam, int* pNextId);

int listarTrabajo(eTrabajo vec[], int tam);
