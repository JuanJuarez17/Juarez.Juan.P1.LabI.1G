#include "opcionesMenu.h"

int menuOpciones(){
    int opcion;

    system("cls");
    printf("       * MENU PRINCIPAL *       \n\n");
    printf("1 - ALTA MOTO.\n");
    printf("2 - MODIFICAR MOTO.\n");
    printf("3 - BAJA MOTO.\n");
    printf("4 - LISTAR MOTOS.\n");
    printf("5 - ORDENAR MOTOS POR TIPO Y ID.\n");
    printf("6 - LISTAR TIPOS DE MOTOS.\n");
    printf("7 - LISTAR COLORES DE MOTOS.\n");
    printf("8 - LISTAR SERVICIOS DE TRABAJO.\n");
    printf("9 - ALTA TRABAJO.\n");
    printf("10 - LISTAR TRABAJO.\n");
    printf("11 - INFORMES.\n");
    printf("12 - SALIR.\n\n");
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
    printf("6 - SALIR.\n");
    printf("\nIngrese campo a modificar: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int informesMenu(){
    int opcion;
    system("cls");
    printf("                      * MENU INFORMES *                     \n\n");
    printf("1 - MOSTRAR MOTOS POR COLOR.\n");
    printf("2 - MOSTRAR PROMEDIO DE PUNTAJE POR TIPO DE MOTO.\n");
    printf("3 - MOSTRAR MOTOS DE MAYOR CILINDRADA.\n");
    printf("4 - MOSTRAR MOTOS SEPARADAS POR TIPO.\n");
    printf("5 - MOSTRAR CANTIDAD DE MOTOS POR TIPO Y COLOR.\n");
    printf("6 - MOSTRAR COLOR/ES MAS ELEGIDO.\n");
    printf("7 - MOSTRAR TRABAJOS REALIZADOR A UNA MOTO.\n");
    printf("8 - MOSTRAR IMPORTE TOTAL POR TRABAJOS A UNA MOTO.\n");
    printf("9 - MOSTRAR MOTOS A LAS QUE SE REALIZO DETERMINADO SERVICIO.\n");
    printf("10 - MOSTRAR SERVICIOS REALIZADOR EN UNA FECHA.\n");
    printf("11 - SALIR.\n");
    printf("\nIngrese informe deseado: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
