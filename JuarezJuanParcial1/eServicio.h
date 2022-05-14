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
