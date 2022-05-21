#ifndef ETRABAJOS_H_INCLUDED
#define ETRABAJOS_H_INCLUDED
#include "fecha.h"
#include "eMoto.h"
#include "eServicio.h"

typedef struct{
    int id;
    int idMoto;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // ETRABAJOS_H_INCLUDED

int iniTrabajo(eTrabajo vec[], int tam);

int buscarIndexLibre(eTrabajo vec[], int tam, int* pIndex);

int buscarIndexCompleto(eTrabajo vec[], int tam);

void mostrarTrabajo(eTrabajo vec);

void mostrarTrabajoYServicio(eTrabajo vec, eServicio vecServ[], int tamServ);

void mostrarMotoYServicio(eTrabajo vec, eServicio vecServ[], int tamServ);

int altaTrabajo(eTrabajo vec[], int tam, eMoto vecMoto[], int tamMoto, eServicio vecServ[], int tamServ, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int* pNextId);

int listarTrabajo(eTrabajo vec[], int tam);

int hardcodearTrabajo(eTrabajo vec[], int tam, int cant, int* pNextId);

void mostrarServicioYMoto(eTrabajo vec, eServicio vecServ[], int tamServ, eMoto vecMoto[], int tamMoto);


