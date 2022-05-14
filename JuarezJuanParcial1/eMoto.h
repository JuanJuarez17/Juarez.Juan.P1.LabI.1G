#ifndef EMOTO_H_INCLUDED
#define EMOTO_H_INCLUDED
#include "validaciones.h"
#include "opcionesMenu.h"
#include "eTipo.h"
#include "eColor.h"
#include <string.h>

typedef struct{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int cilindrada;
    int puntaje;
    int isEmpty;
}eMoto;

#endif // EMOTO_H_INCLUDED

int iniMoto(eMoto vec[], int tam);

int buscarIndexLibreMoto(eMoto vec[], int tam, int* pIndex);

int buscarIndexCompletoMoto(eMoto vec[], int tam);

void mostrarMoto(eMoto vec, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor);

int altaMoto(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int* pNextId);

int listarMoto(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor);

int buscarMotoPorId(eMoto vec[], int tam, int id, int* pIndex);

int bajaMoto(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor);

int modifMoto(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor);

int ordenarMotoTipoId(eMoto vec[], int tam);

int hardcodearMotos(eMoto vec[], int tam, int cant, int* pNextId);
