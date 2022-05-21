#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#include "opcionesMenu.h"
#include "eTrabajos.h"
#include "eColor.h"
#include "eTipo.h"
#include "eServicio.h"
#include "eMoto.h"


#endif // INFORMES_H_INCLUDED

int informes(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, eTrabajo vecTrab[], int tamTrab, eServicio vecServ[], int tamServ);

int listarMotoPorColor(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int idColor);

int promedioPuntajeTipo(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int idTipo);

int listarMotoPorCilindrada(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int cilind);

int listarMotoPorTipo(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int idTipo);

int listarMotosPorTipos(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int idTipo);

int listarMotoPorColorTipo(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int idColor, int idTipo);

int totalMotosXColor(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int idColor, int* pTotal);

int colorMasMotos(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor);

int trabajosPorMoto(eTrabajo vec[], int tam, eServicio vecServ[], int tamServ, int idMoto);

int importePorMoto(eTrabajo vec[], int tam, eServicio vecServ[], int tamServ, int idMoto);

int servicioPorMoto(eTrabajo vec[], int tam, eServicio vecServ[], int tamServ, int idServ, eMoto vecMoto[], int tamMoto);

int trabajosPorfecha(eTrabajo vec[], int tam, eServicio vecServ[], int tamServ, eFecha fechaTrab);
