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
#include "informes.h"

#define TAM_MOTO 100
#define TAM_TRABAJO 100

int main()
{
	char salir = 'N';
    int nextIdMoto = 1000;
    int nextIdTrabajo = 5000;
    int crit;
    int vCrit;

    eColor listaColores[5] = {
        {10000, "Gris"},
        {10010, "Negro"},
        {10020, "Azul"},
        {10030, "Blanco"},
        {10040, "Rojo"},
    };

    eTipo listaTipos[4] = {
        {1000, "Enduro"},
        {1010, "Chopera"},
        {1020, "Scooter"},
        {1030, "Vintage"},
    };

    eServicio listaServicios[4] = {
        {20000, "Limpieza", 450},
        {20010, "Ajuste", 300},
        {20020, "Balanceo", 150},
        {20030, "Cadena", 390},
    };

    eMoto listaMotos[TAM_MOTO];

    iniMoto(listaMotos, TAM_MOTO);

    hardcodearMotos(listaMotos, TAM_MOTO, 10, &nextIdMoto);

    //hardcodearMotos2(listaMotos, TAM_MOTO, 5, &nextIdMoto);

    eTrabajo listaTrabajos[TAM_TRABAJO];

    iniTrabajo(listaTrabajos, TAM_TRABAJO);

    hardcodearTrabajo(listaTrabajos, TAM_TRABAJO, 20, &nextIdTrabajo);

	do{
		switch(menuOpciones()){
			case 1:
                altaMoto(listaMotos, TAM_MOTO, listaTipos, 4, listaColores, 5, &nextIdMoto);
                break;
		    case 2:
		        if(buscarIndexCompletoMoto(listaMotos, TAM_MOTO)){
                   modifMoto(listaMotos, TAM_MOTO, listaTipos, 4, listaColores, 5);
		        }
		        else{
                    printf("Primero debe realizar el alta de una o mas motos.\n\n");
		        }
                break;
		    case 3:
                if(buscarIndexCompletoMoto(listaMotos, TAM_MOTO)){
                    bajaMoto(listaMotos, TAM_MOTO, listaTipos, 4, listaColores, 5);
                }
		        else{
                    printf("Primero debe realizar el alta de una o mas motos.\n\n");
		        }
                break;
		    case 4:
                listarMoto(listaMotos, TAM_MOTO, listaTipos, 4, listaColores, 5);
                break;
		    case 5:
                printf("Ingrese criterio de ordenamiento (1: Ascendente - 0: Descendente): ");
                fflush(stdin);
                vCrit = scanf("%d", &crit);
                while(!(validarIntRango(vCrit, crit, 0, 1))){
                    printf("Error! criterio de ordenamiento (1: Ascendente - 0: Descendente): ");
                    fflush(stdin);
                    vCrit = scanf("%d", &crit);
                }
                ordenarMotoTipoId(listaMotos, TAM_MOTO, crit);
                listarMoto(listaMotos, TAM_MOTO, listaTipos, 4, listaColores, 5);
                break;
		    case 6:
                listarTipo(listaTipos, 4);
                break;
            case 7:
                listarColor(listaColores, 5);
                break;
            case 8:
                listarServicio(listaServicios, 4);
                break;
            case 9:
                if(buscarIndexCompletoMoto(listaMotos, TAM_MOTO)){
                    altaTrabajo(listaTrabajos, TAM_TRABAJO, listaMotos, TAM_MOTO, listaServicios, 4, listaTipos, 4, listaColores, 5, &nextIdTrabajo);
                }
		        else{
                    printf("Primero debe realizar el alta de una o mas motos.\n\n");
		        }
                break;
            case 10:
                listarTrabajo(listaTrabajos, TAM_TRABAJO);
                break;
            case 11:
                informes(listaMotos, TAM_MOTO, listaTipos, 4, listaColores, 5, listaTrabajos, TAM_TRABAJO, listaServicios, 4);
                break;
		    case 12:
                salida(&salir);
                break;
            default:
                printf("Opcion invalida!\n");
                break;
		}
        //system("pause");
		printf("\nPresione una tecla para continuar...");
		getch();
	}while(salir != 'S');
    return 0;
}



