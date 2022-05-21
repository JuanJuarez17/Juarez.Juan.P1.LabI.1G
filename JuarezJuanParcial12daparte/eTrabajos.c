#include "eTrabajos.h"

int iniTrabajo(eTrabajo vec[], int tam){
    int rtn = 0;
    if(vec != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            vec[i].isEmpty = 1;
        }
        rtn = 1;
    }
    return rtn;
}

int buscarIndexLibre(eTrabajo vec[], int tam, int* pIndex){ // Devuelve el indice del primer vector de la estructura libre.
    int rtn = 0;
    if(vec != NULL && pIndex != NULL && tam > 0){ // (vec && pIndex && tam > 0)
        *pIndex = -1;
        for(int i = 0; i < tam; i++){
            if(vec[i].isEmpty){ // (vec[i].isEmpty == 1)
                *pIndex = i;
                break; // Para devovler el indice de la primer estructura libre y no el de la ultima.
            }
        }
        rtn = 1;
    }
    return rtn;
}

int buscarIndexCompleto(eTrabajo vec[], int tam){
    int rtn = 0;
    if(vec != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(!vec[i].isEmpty){
                rtn = 1;
                break;
            }
        }
    }
    return rtn;
}

int hardcodearTrabajo(eTrabajo vec[], int tam, int cant, int* pNextId){ // cant: Cantidad de pasajeros que quiero cargar a pesar de que el array sea de 10
    int rtn = 0;
    eTrabajo trabajo[20] = {
        {0, 1000, 20030, {1,4,2022}, 0},
        {0, 1001, 20000, {1,4,2022}, 0},
        {0, 1002, 20010, {13,2,2022}, 0},
        {0, 1003, 20010, {27,5,2020}, 0},
        {0, 1004, 20020, {6,1,2019}, 0},
        {0, 1001, 20010, {17,2,2022}, 0},
        {0, 1002, 20030, {23,3,2021}, 0},
        {0, 1000, 20000, {12,4,2019}, 0},
        {0, 1003, 20000, {8,1,2021}, 0},
        {0, 1001, 20010, {23,4,2022}, 0},
        {0, 1003, 20010, {17,7,2021}, 0},
        {0, 1003, 20030, {5,12,2022}, 0},
        {0, 1000, 20020, {23,4,2022}, 0},
        {0, 1004, 20000, {26,5,2022}, 0},
        {0, 1000, 20020, {1,4,2022}, 0},
        {0, 1002, 20030, {7,9,2021}, 0},
        {0, 1004, 20020, {8,10,2019}, 0},
        {0, 1002, 20000, {25,8,2022}, 0},
        {0, 1000, 20010, {19,2,2020}, 0},
        {0, 1002, 20030, {30,6,2021}, 0},
    };
    if(vec != NULL && pNextId != NULL && tam > 0 && tam <= 100 && cant <= tam){
        for(int i = 0; i < cant; i++){
            vec[i] = trabajo[i];
            vec[i].id = *pNextId;
            (*pNextId)++;
        }
        rtn = 1;
    }
    return rtn;
}

void mostrarTrabajo(eTrabajo vec){
    printf("    %4d       %4d        %5d      %02d/%02d/%d\n",
           vec.id,
           vec.idMoto,
           vec.idServicio,
           vec.fecha.dia,
           vec.fecha.mes,
           vec.fecha.anio);
}

void mostrarTrabajoYServicio(eTrabajo vec, eServicio vecServ[], int tamServ){
    char descServ[20];
    cargarDescripcionServicio(vecServ, tamServ, vec.idServicio, descServ);
    printf("    %4d         %5d       %10s   %02d/%02d/%d\n",
           vec.id,
           vec.idServicio,
           descServ,
           vec.fecha.dia,
           vec.fecha.mes,
           vec.fecha.anio);
}

void mostrarMotoYServicio(eTrabajo vec, eServicio vecServ[], int tamServ){
    char descServ[20];
    cargarDescripcionServicio(vecServ, tamServ, vec.idServicio, descServ);
    printf("  %4d        %4d    %10s\n",
           vec.idMoto,
           vec.id,
           descServ);
}

void mostrarServicioYMoto(eTrabajo vec, eServicio vecServ[], int tamServ, eMoto vecMoto[], int tamMoto){
    char descServ[20];
    cargarDescripcionServicio(vecServ, tamServ, vec.idServicio, descServ);
    char descMoto[20];
    cargarDescripcionMoto(vecMoto, tamMoto, vec.idMoto, descMoto);
    printf("    %4d      %5d   %10s   %02d/%02d/%d\n",
           vec.id,
           vec.idMoto,
           descMoto,
           vec.fecha.dia,
           vec.fecha.mes,
           vec.fecha.anio);
}

int listarTrabajo(eTrabajo vec[], int tam){
    int rtn = 0;
    int flag = 1;
    if(vec != NULL && tam > 0){
        system("cls");
        printf("             - LISTA DE TRABAJOS -             \n");
        printf("\n------------------------------------------------\n");
        printf(" ID TRABAJO   ID MOTO   ID SERVICIO     FECHA   \n");
        printf("------------------------------------------------\n");
        for(int i = 0; i < tam; i++){
            if(vec[i].isEmpty == 0){
                mostrarTrabajo(vec[i]);
                flag = 0;
            }
        }
        if(flag){
            printf("        - NO HAY TRABAJOS EN EL SISTEMA -        \n");
            printf("------------------------------------------------\n");
        }
        rtn = 1;
    }
    return rtn;
}

int altaTrabajo(eTrabajo vec[], int tam, eMoto vecMoto[], int tamMoto, eServicio vecServ[], int tamServ, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int* pNextId){
    int rtn = 0;
    int indice;
    eTrabajo auxTrabajo;
    eFecha auxFecha;
    char confirma;
    int idMoto;
    int idServ;

    if(vec && pNextId && tam > 0){
        system("cls");
        printf("                - ALTA TRABAJO -                \n\n");
        buscarIndexLibre(vec, tam, &indice);
        if(indice == -1){
            printf("------------------------------------------------\n");
            printf("         - NO HAY LUGAR EN EL SISTEMA -         \n");
            printf("------------------------------------------------\n");
        }
        else{
            auxTrabajo.id = *pNextId;

            listarMoto(vecMoto, tamMoto, vecTipo, tamTipo, vecColor, tamColor);
            printf("\nIngrese el ID de moto: ");
            fflush(stdin);
            scanf("%d", &idMoto);

            while(!validarMoto(vecMoto, tamMoto, idMoto)){
                printf("Error! Ingrese el ID de moto: ");
                fflush(stdin);
                scanf("%d", &idMoto);
            }
            auxTrabajo.idMoto = idMoto;

            listarServicio(vecServ, tamServ);
            printf("\nIngrese el ID de servicio: ");
            fflush(stdin);
            scanf("%d", &idServ);

            while(!validarServicio(vecServ, tamServ, idServ)){
                printf("Error! Ingrese el ID de servicio: ");
                fflush(stdin);
                scanf("%d", &idServ);
            }
            auxTrabajo.idServicio = idServ;

            altaFecha(&auxFecha);
            auxTrabajo.fecha = auxFecha;

            printf("\n------------------------------------------------\n");
            printf(" ID TRABAJO   ID MOTO   ID SERVICIO     FECHA   \n");
            printf("------------------------------------------------\n");
            mostrarTrabajo(auxTrabajo);

            printf("\nConfirma carga? (S/N): ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = toupper(confirma);

            while(!(validarChar(confirma, 'S', 'N'))){
                printf("Error! Confirma carga? (S/N): ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = toupper(confirma);
            }

            if(confirma == 'S'){ // Valido que sea sea afirmativo
                auxTrabajo.isEmpty = 0;
                vec[indice] = auxTrabajo;
                (*pNextId)++;
                printf("Carga exitosa.\n"); // Aviso del cambio
                rtn = 1;
            }
            else{ // Si no es afirmativo
                printf("Carga cancelada.\n");
            }
        }
    }
    return rtn;
}



