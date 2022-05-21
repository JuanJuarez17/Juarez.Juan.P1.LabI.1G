#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#endif // VALIDACIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int guardarStr(char vec[]);

int validarChar(char cEvaluar, char opcion1, char opcion2);

int validarFloatRango(float fEvaluar, float Float, int limInf, int limSup);

int validarInt(int iEvaluar);

int validarIntRango(int iEvaluar, int Int, int limInf, int limSup);

int validarStr(char vec[]);
