#ifndef ESERVICIO_H_INCLUDED
#define ESERVICIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char descripcion[25];
    float precio;
}eServicio;

#endif // ESERVICIO_H_INCLUDED

int listarServicio(eServicio vecServicio[], int tamServicio);

int buscarServicio(eServicio vec[], int tam, int id, int* pIndex);

int validarServicio(eServicio vec[], int tam, int id);

int cargarDescripcionServicio(eServicio vecServ[], int tamServ, int id, char desc[]);

int cargarImporteServicio(eServicio vecServ[], int tamServ, int id, float* pImporte);
