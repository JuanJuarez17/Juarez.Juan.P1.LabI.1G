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

#define TAM_TRABAJO 50
#define TAM_MOTO 50

int main()
{
	char salir = 'N';
    int nextIdMoto = 1000;

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
        {20000, "Ajuste", 300},
        {20000, "Balanceo", 150},
        {20000, "Cadena", 390},
    };

    eMoto listaMotos[TAM_MOTO];

    iniMoto(listaMotos, TAM_MOTO);

    hardcodearMotos(listaMotos, TAM_MOTO, 10, &nextIdMoto);

	do{
		switch(menuOpciones()){
			case 1:
                altaMoto(listaMotos, TAM_TRABAJO, listaTipos, 4, listaColores, 5, &nextIdMoto);
                break;
		    case 2:
		        if(buscarIndexCompletoMoto(listaMotos, TAM_MOTO)){
                   modifMoto(listaMotos, TAM_MOTO, listaTipos, 4, listaColores, 5);
		        }
		        else{
                    printf("Primero debe realizar el alta de uno o mas pasajeros.\n\n");
		        }
                break;
		    case 3:
                if(buscarIndexCompletoMoto(listaMotos, TAM_MOTO)){
                    bajaMoto(listaMotos, TAM_MOTO, listaTipos, 4, listaColores, 5);
                }
		        else{
                    printf("Primero debe realizar el alta de uno o mas pasajeros.\n\n");
		        }
                break;
		    case 4:
                if(buscarIndexCompletoMoto(listaMotos, TAM_MOTO)){
                    listarMoto(listaMotos, TAM_MOTO, listaTipos, 4, listaColores, 5);
                }
		        else{
                    printf("Primero debe realizar el alta de uno o mas pasajeros.\n\n");
		        }
                break;
		    case 5:
                ordenarMotoTipoId(listaMotos, TAM_MOTO);
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



