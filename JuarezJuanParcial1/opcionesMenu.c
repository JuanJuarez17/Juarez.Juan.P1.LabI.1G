#include "opcionesMenu.h"

int menuOpciones(){
    int opcion;

    system("cls");
    printf("1 - Alta moto.\n");
    printf("2 - Modificar moto.\n");
    printf("3 - Baja moto.\n");
    printf("4 - Listar motos.\n");
    printf("5 - Ordenar moto por tipo y ID.\n");
    printf("6 - Listar tipos de motos.\n");
    printf("7 - Listar colores de motos.\n");
    printf("8 - Listar servicios de trabajo.\n");
    printf("9 - Salir.\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

void salida(char *pSalir)
{
	if (pSalir != NULL) {
		printf("Confirma salida? (S/N): ");
		fflush(stdin);
		scanf("%c", pSalir);
		*pSalir = toupper(*pSalir);

		while(!(validarChar(*pSalir, 'S', 'N'))){
            printf("Error! Confirma salida? (S/N): ");
            fflush(stdin);
            scanf("%c", pSalir);
            *pSalir = toupper(*pSalir);
		}
	}
}

int modifMotoMenu(){
    int opcion;
    printf("\n1 - MARCA.\n");
    printf("2 - CILINDRADA.\n");
    printf("3 - PUNTAJE.\n");
    printf("4 - TIPO.\n");
    printf("5 - COLOR.\n");
    printf("Ingrese campo a modificar: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
