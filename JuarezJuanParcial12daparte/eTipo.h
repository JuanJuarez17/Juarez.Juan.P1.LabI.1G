#ifndef ETIPO_H_INCLUDED
#define ETIPO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int id;
    char descripcion[20];
}eTipo;

#endif // ETIPO_H_INCLUDED

int listarTipo(eTipo vec[], int tamTipo);

int cargarDescripcionTipo(eTipo vec[], int tam, int id, char desc[]);

int buscarTipo(eTipo vec[], int tamTipo, int id, int* pIndex);

int validarTipo(eTipo vec[], int tamTipo, int id);
