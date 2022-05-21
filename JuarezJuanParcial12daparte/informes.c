#include "informes.h"

int informes(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, eTrabajo vecTrab[], int tamTrab, eServicio vecServ[], int tamServ){
	char salir = 'N';
	int opcion;
	int opcion2;
    int vOpcion;
    eFecha auxFecha;
	do{
		switch(informesMenu()){
			case 1:
			    listarColor(vecColor, tamColor);
                printf("\nIngrese el ID del color que desea buscar: ");
                fflush(stdin);
                scanf("%d", &opcion);
                while(!validarColor(vecColor, tamColor, opcion)){
                    printf("Error! Ingrese el ID del color que desea buscar: ");
                    fflush(stdin);
                    scanf("%d", &opcion);
                }
                listarMotoPorColor(vec, tam, vecTipo, tamTipo, vecColor, tamColor, opcion);
                break;
			case 2:
			    listarTipo(vecTipo, tamTipo);
                printf("\nIngrese el ID del tipo que desea buscar: ");
                fflush(stdin);
                scanf("%d", &opcion);
                while(!validarTipo(vecTipo, tamTipo, opcion)){
                    printf("Error! Ingrese el ID del tipo que desea buscar: ");
                    fflush(stdin);
                    scanf("%d", &opcion);
                }
                promedioPuntajeTipo(vec, tam, vecTipo, tamTipo, vecColor, tamColor, opcion);
                break;
			case 3:
                printf("Ingrese la cilindrada de la moto a partir de la cual quiere mostrar (50 - 125 - 500 - 600 - 750): ");
                fflush(stdin);
                vOpcion = scanf("%d", &opcion);
                while(!(opcion == 50 || opcion == 125 || opcion == 500 || opcion == 600 || opcion == 750)){
                    printf("Error! Ingrese la cilindrada de la moto a partir de la cual quiere mostrar (50 - 125 - 500 - 600 - 750): ");
                    fflush(stdin);
                    vOpcion = scanf("%d", &opcion);
                }
                listarMotoPorCilindrada(vec, tam, vecTipo, tamTipo, vecColor, tamColor, opcion);
                break;
            case 4:
                listarMotosPorTipos(vec, tam, vecTipo, tamTipo, vecColor, tamColor, opcion);
                break;
			case 5:
			    listarColor(vecColor, tamColor);
                printf("\nIngrese el ID del color que desea buscar: ");
                fflush(stdin);
                scanf("%d", &opcion);
                while(!validarColor(vecColor, tamColor, opcion)){
                    printf("Error! Ingrese el ID del color que desea buscar: ");
                    fflush(stdin);
                    scanf("%d", &opcion);
                }
			    listarTipo(vecTipo, tamTipo);
                printf("\nIngrese el ID del tipo que desea buscar: ");
                fflush(stdin);
                scanf("%d", &opcion2);
                while(!validarTipo(vecTipo, tamTipo, opcion2)){
                    printf("Error! Ingrese el ID del tipo que desea buscar: ");
                    fflush(stdin);
                    scanf("%d", &opcion2);
                }
                listarMotoPorColorTipo(vec, tam, vecTipo, tamTipo, vecColor, tamColor, opcion, opcion2);
                break;
            case 6:
                colorMasMotos(vec, tam, vecTipo, tamTipo, vecColor, tamColor);
                break;
            case 7:
		        if(buscarIndexCompletoMoto(vec, tam)){
                    listarMoto(vec, tam, vecTipo, tamTipo, vecColor, tamColor);
                    printf("\nIngrese el ID de la moto que desea buscar: ");
                    fflush(stdin);
                    scanf("%d", &opcion);
                    while(!validarMoto(vec, tam, opcion)){
                        printf("Error! Ingrese el ID de la moto que desea buscar: ");
                        fflush(stdin);
                        scanf("%d", &opcion);
                    }
                    trabajosPorMoto(vecTrab, tamTrab, vecServ, tamServ, opcion);

		        }
		        else{
                    printf("Primero debe realizar el alta de una o mas motos.\n\n");
		        }
                break;
            case 8:
		        if(buscarIndexCompletoMoto(vec, tam)){
                    listarMoto(vec, tam, vecTipo, tamTipo, vecColor, tamColor);
                    printf("\nIngrese el ID de la moto que desea buscar: ");
                    fflush(stdin);
                    scanf("%d", &opcion);
                    while(!validarMoto(vec, tam, opcion)){
                        printf("Error! Ingrese el ID de la moto que desea buscar: ");
                        fflush(stdin);
                        scanf("%d", &opcion);
                    }
                    importePorMoto(vecTrab, tamTrab, vecServ, tamServ, opcion);
		        }
		        else{
                    printf("Primero debe realizar el alta de una o mas motos.\n\n");
		        }
                break;
            case 9:
                listarServicio(vecServ, tamServ);
                printf("\nIngrese el ID de servicio: ");
                fflush(stdin);
                scanf("%d", &opcion);
                while(!validarServicio(vecServ, tamServ, opcion)){
                    printf("Error! Ingrese el ID del tipo de servicio: ");
                    fflush(stdin);
                    scanf("%d", &opcion);
                }
                servicioPorMoto(vecTrab, tamTrab, vecServ, tamServ, opcion, vec, tam);
                break;
            case 10:
                altaFecha(&auxFecha);
                trabajosPorfecha(vecTrab, tamTrab, vecServ, tamServ, auxFecha);
                break;
		    case 11:
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

int listarMotoPorColor(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int idColor){
    int rtn = 0;
    int flag = 1;
    char descripcion[15];
    cargarDescripcionColor(vecColor, tamColor, idColor, descripcion);
    if(vec != NULL && vecTipo != NULL && vecColor != NULL && tam > 0 && tamTipo > 0 && tamColor > 0){
        //system("cls");
        printf("\n                            - MOTOS COLOR: %s -                             \n", descripcion);
        printf("-----------------------------------------------------------------------------\n");
        printf(" ID                 MARCA             CILINDRADA  PUNTAJE    TIPO       COLOR\n");
        printf("-----------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++){
            if(vec[i].isEmpty == 0 && vec[i].idColor == idColor){
                mostrarMoto(vec[i], vecTipo, tamTipo, vecColor, tamColor);
                flag = 0;
            }
        }
        if(flag){
            printf("                       - NO HAY MOTOS EN EL SISTEMA -                        \n");
            printf("-----------------------------------------------------------------------------\n");
        }
        rtn = 1;
    }
    return rtn;
}

int promedioPuntajeTipo(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int idTipo){
    int rtn = 0;
    int flag = 1;
    int cont = 0;
    int acumPuntaje = 0;
    float promedioPuntaje;
    char descripcion[15];
    cargarDescripcionTipo(vecTipo, tamTipo, idTipo, descripcion);
    if(vec != NULL && vecTipo != NULL && vecColor != NULL && tam > 0 && tamTipo > 0 && tamColor > 0){
        system("cls");
        printf("                      - PUNTAJES PARA MOTO TIPO %s -                     \n", descripcion);
        printf("\n-----------------------------------------------------------------------------\n");
        printf(" ID                 MARCA             CILINDRADA  PUNTAJE    TIPO       COLOR\n");
        printf("-----------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++){
            if(vec[i].isEmpty == 0 && vec[i].idTipo == idTipo){
                mostrarMoto(vec[i], vecTipo, tamTipo, vecColor, tamColor);
                acumPuntaje = acumPuntaje + vec[i].puntaje;
                cont++;
                flag = 0;
            }
        }
        if(flag){
            printf("                      - NO HAY TRABAJOS EN EL SISTEMA -                      \n");
            printf("-----------------------------------------------------------------------------\n");
        }
        else{
            promedioPuntaje = (float) acumPuntaje / cont;
            printf("\nEl promedio de puntaje para este tipo de moto es %.2f\n", promedioPuntaje);
        }
        rtn = 1;
    }
    return rtn;
}

int listarMotoPorCilindrada(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int cilind){
    int rtn = 0;
    int flag = 1;
    eMoto aux;
    if(vec != NULL && vecTipo != NULL && vecColor != NULL && tam > 0 && tamTipo > 0 && tamColor > 0){
        //system("cls");
        printf("\n                  - MOTOS DE CILINDRADA MAYOR QUE %d cc -                  \n", cilind);
        printf("-----------------------------------------------------------------------------\n");
        printf(" ID                 MARCA             CILINDRADA  PUNTAJE    TIPO       COLOR\n");
        printf("-----------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++){
            for(int j = i + 1; j < tam; j++){
                if(vec[i].cilindrada > vec[j].cilindrada){
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
            if(vec[i].isEmpty == 0 && vec[i].cilindrada >= cilind){
                mostrarMoto(vec[i], vecTipo, tamTipo, vecColor, tamColor);
                flag = 0;
            }
        }
        if(flag){
            printf("                       - NO HAY MOTOS EN EL SISTEMA -                        \n");
            printf("-----------------------------------------------------------------------------\n");
        }
        rtn = 1;
    }
    return rtn;
}

int listarMotoPorTipo(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int idTipo){
    int rtn = 0;
    int flag = 1;
    char descripcion[15];
    cargarDescripcionTipo(vecTipo, tamTipo, idTipo, descripcion);
    if(vec != NULL && vecTipo != NULL && vecColor != NULL && tam > 0 && tamTipo > 0 && tamColor > 0){
        //system("cls");
        printf("\n                             - MOTOS TIPO: %s -                             \n", descripcion);
        printf("-----------------------------------------------------------------------------\n");
        printf(" ID                 MARCA             CILINDRADA  PUNTAJE    TIPO       COLOR\n");
        printf("-----------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++){
            if(vec[i].isEmpty == 0 && vec[i].idTipo == idTipo){
                mostrarMoto(vec[i], vecTipo, tamTipo, vecColor, tamColor);
                flag = 0;
            }
        }
        if(flag){
            printf("                       - NO HAY MOTOS EN EL SISTEMA -                        \n");
            printf("-----------------------------------------------------------------------------\n");
        }
        rtn = 1;
    }
    return rtn;
}

int listarMotosPorTipos(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int idTipo){
    int rtn = 0;
    int flag = 1;
    if(vec != NULL && vecTipo != NULL && vecColor != NULL && tam > 0 && tamTipo > 0 && tamColor > 0){
        //system("cls");
        for(int i = 0; i < tamTipo; i++){ // Recorro el array sectores.
            listarMotoPorTipo(vec, tam, vecTipo, tamTipo, vecColor, tamColor, vecTipo[i].id); // Aca lo obtengo recorriendo el array
        }
        rtn = 1;
    }
    return rtn;
}

int listarMotoPorColorTipo(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int idColor, int idTipo){
    int rtn = 0;
    int flag = 1;
    int cont = 0;
    char descColor[15];
    cargarDescripcionColor(vecColor, tamColor, idColor, descColor);
    char descTipo[15];
    cargarDescripcionTipo(vecTipo, tamTipo, idTipo, descTipo);
    if(vec != NULL && vecTipo != NULL && vecColor != NULL && tam > 0 && tamTipo > 0 && tamColor > 0){
        //system("cls");
        printf("\n                    - LISTA DE MOTOS COLOR %s Y TIPO %s -                   \n", descColor, descTipo);
        printf("-----------------------------------------------------------------------------\n");
        printf(" ID                 MARCA             CILINDRADA  PUNTAJE    TIPO       COLOR\n");
        printf("-----------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++){
            if(vec[i].isEmpty == 0 && vec[i].idColor == idColor && vec[i].idTipo == idTipo){
                mostrarMoto(vec[i], vecTipo, tamTipo, vecColor, tamColor);
                cont++;
                flag = 0;
            }
        }
        if(flag){
            printf("                       - NO HAY MOTOS EN EL SISTEMA -                        \n");
            printf("-----------------------------------------------------------------------------\n");
        }
        printf("\nLa cantidad de motos con estas caracteristicas es: %d", cont);
        rtn = 1;
    }
    return rtn;
}

int totalMotosXColor(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int idColor, int* pTotal){
    int rtn = 0;
    int cont = 0;
    if(vec != NULL && vecTipo != NULL && vecColor != NULL && pTotal != NULL && tam > 0 && tamTipo > 0 && tamColor > 0){
        for(int i = 0; i < tam; i++){
            if(!vec[i].isEmpty && vec[i].idColor == idColor){
                cont++;
            }
        }
        *pTotal = cont;
        rtn = 1;
    }
    return rtn;
}

int colorMasMotos(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor){
    int rtn = 0;
    int totales[5] = {0}; // Me creo un vector de enteros del mismo tamaño del vector color. Como van a ser contadores los tengo que inicializar
    int flag = 1;
    float mayor;

    if(vec != NULL && vecTipo != NULL && vecColor != NULL && tam > 0 && tamTipo > 0 && tamColor > 0){ // Valido
        for(int i = 0; i < tamColor; i++){ // Sumo los sueldos por sector
            totalMotosXColor(vec, tam, vecTipo, tamTipo, vecColor, tamColor, vecColor[i].id, &totales[i]); // Cargo en cada posicion del vector el total
        }
        // Aca ya tengo cargados los totales
        for(int i = 0; i < tamColor; i++){ // Busco el contador mas grande
            if(flag || totales[i] > mayor){
                mayor = totales[i];
                flag = 0;
            }
        }
        printf("\nEl color/es mas elegido es: \n\n");
        for(int i = 0; i < tamColor; i++){
            if(totales[i] == mayor){ // Busco en que color hay mas motos (o es mayor el contador)
                printf("%s\n", vecColor[i].nombreColor);
            }
        }
        rtn = 1;
    }
    return rtn;
}

int trabajosPorMoto(eTrabajo vec[], int tam, eServicio vecServ[], int tamServ, int idMoto){
    int rtn = 0;
    int flag = 1;
    if(vec != NULL && vecServ != NULL && tam > 0 && tamServ > 0){
        system("cls");
        printf("             - TRABAJOS PARA MOTO ID %d -             \n", idMoto);
        printf("\n----------------------------------------------------\n");
        printf(" ID TRABAJO   ID SERVICIO   DESCRIPCION     FECHA   \n");
        printf("----------------------------------------------------\n");
        for(int i = 0; i < tam; i++){
            if(vec[i].isEmpty == 0 && vec[i].idMoto == idMoto){
                mostrarTrabajoYServicio(vec[i], vecServ, tamServ);
                flag = 0;
            }
        }
        if(flag){
            printf("         - NO HAY TRABAJOS EN EL SISTEMA -          \n");
            printf("----------------------------------------------------\n");
        }
        rtn = 1;
    }
    return rtn;
}

int importePorMoto(eTrabajo vec[], int tam, eServicio vecServ[], int tamServ, int idMoto){
    int rtn = 0;
    int flag = 1;
    float auxFloat;
    float acumImporte = 0;
    if(vec != NULL && vecServ != NULL && tam > 0 && tamServ > 0){
        system("cls");
        printf("             - IMPORTE PARA MOTO ID %d -             \n", idMoto);
        printf("\n----------------------------------------------------\n");
        printf(" ID TRABAJO   ID SERVICIO   DESCRIPCION     FECHA   \n");
        printf("----------------------------------------------------\n");
        for(int i = 0; i < tam; i++){
            if(vec[i].isEmpty == 0 && vec[i].idMoto == idMoto){
                mostrarTrabajoYServicio(vec[i], vecServ, tamServ);
                cargarImporteServicio(vecServ, tamServ, vec[i].idServicio, &auxFloat);
                acumImporte = acumImporte + auxFloat;
                flag = 0;
            }
        }
        if(flag){
            printf("         - NO HAY TRABAJOS EN EL SISTEMA -          \n");
            printf("----------------------------------------------------\n");
        }
        else{
            printf("\nEl importe total de los trabajos es de $%.2f\n", acumImporte);
        }
        rtn = 1;
    }
    return rtn;
}

int servicioPorMoto(eTrabajo vec[], int tam, eServicio vecServ[], int tamServ, int idServ, eMoto vecMoto[], int tamMoto){
    int rtn = 0;
    int flag = 1;
    char descServ[15];
    cargarDescripcionServicio(vecServ, tamServ, idServ, descServ);
    if(vec != NULL && vecServ != NULL && vecMoto != NULL && tam > 0 && tamServ > 0 && tamMoto > 0){
        system("cls");
        printf("   - MOTOS A LAS QUE SE REALIZO %s -       \n", descServ);
        printf("\n---------------------------------------------\n");
        printf(" ID TRABAJO   ID MOTO      MARCA     FECHA   \n");
        printf("---------------------------------------------\n");
        for(int i = 0; i < tam; i++){
            if(vec[i].isEmpty == 0 && vec[i].idServicio == idServ){
                mostrarServicioYMoto(vec[i], vecServ, tamServ, vecMoto, tamMoto);
                flag = 0;
            }
        }
        if(flag){
            printf("      - NO HAY TRABAJOS EN EL SISTEMA -      \n");
            printf("---------------------------------------------\n");
        }
        rtn = 1;
    }
    return rtn;
}

int trabajosPorfecha(eTrabajo vec[], int tam, eServicio vecServ[], int tamServ, eFecha fechaTrab){
    int rtn = 0;
    int flag = 1;
    if(vec != NULL && vecServ != NULL && tam > 0 && tamServ > 0){
        system("cls");
        printf("   - SERVICIOS REALIZADOS EN LA FECHA %02d/%02d/%d -   \n", fechaTrab.dia, fechaTrab.mes, fechaTrab.anio);
        printf("\n------------------------------\n");
        printf(" ID MOTO   ID TRABAJO   SERVICIO\n");
        printf("--------------------------------\n");
        for(int i = 0; i < tam; i++){
            if(vec[i].isEmpty == 0 && vec[i].fecha.dia == fechaTrab.dia && vec[i].fecha.mes == fechaTrab.mes && vec[i].fecha.anio == fechaTrab.anio){
                mostrarMotoYServicio(vec[i], vecServ, tamServ);
                flag = 0;
            }
        }
        if(flag){
            printf("- NO HAY TRABAJOS EN EL SISTEMA -\n");
            printf("--------------------------------\n");
        }
        rtn = 1;
    }
    return rtn;
}
