#ifndef ECOLOR_H_INCLUDED
#define ECOLOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nombreColor[20];
}eColor;

#endif // ECOLOR_H_INCLUDED

int listarColor(eColor vecColor[], int tamColor);

int cargarDescripcionColor(eColor vecColor[], int tamColor, int id, char desc[]);

int buscarColor(eColor vecColor[], int tamColor, int id, int* pIndex);

int validarColor(eColor vecColor[], int tamColor, int id);
