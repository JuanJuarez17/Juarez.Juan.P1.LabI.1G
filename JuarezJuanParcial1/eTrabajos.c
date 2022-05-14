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

void mostrarTrabajo(eTrabajo vec){
    //char descripcion[20];
    //cargarDescripcionDestino(destinos, tamdest, vec.idDestino, descripcion);
    printf("%4d %02d/%02d/%d\n",
           vec.id,
           vec.fecha.dia,
           vec.fecha.mes,
           vec.fecha.anio);
}

int altaTrabajo(eTrabajo vec[], int tam, int* pNextId){
    int rtn = 0;
    int indice;
    eTrabajo auxTrabajo;
    eFecha auxFecha;
    char confirma;
    if(vec && pNextId && tam > 0){ //(vec != NULL && pNextId != NULL && tam > 0)
        system("cls");
        printf("                          - ALTA TRABAJO -                       \n\n");
        buscarIndexLibre(vec, tam, &indice);
        if(indice == -1){
            printf("-------------------------------------------------------------\n");
            printf("                - NO HAY LUGAR EN EL SISTEMA -               \n");
            printf("-------------------------------------------------------------\n");
        }
        else{
            auxTrabajo.id = *pNextId;

            altaFecha(&auxFecha);
            auxTrabajo.fecha = auxFecha;

            printf("\n------------------------------------------------------------------\n");
            printf(" ID    FECHA       DESTINO                                          \n");
            printf("------------------------------------------------------------------\n");
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

int listarTrabajo(eTrabajo vec[], int tam){
    int rtn = 0;
    int flag = 1;
    if(vec != NULL && tam > 0){
        //system("cls");
        printf("\n                     - LISTA DE VUELOS -                     \n");
        printf("------------------------------------------------------------------\n");
        printf(" ID    FECHA       DESTINO                                          \n");
        printf("------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++){
            if(vec[i].isEmpty == 0){
                mostrarTrabajo(vec[i]);
                flag = 0;
            }
        }
        if(flag){
            printf("                - NO HAY VUELOS EN EL SISTEMA -                \n");
            printf("------------------------------------------------------------------\n");
        }
        rtn = 1;
    }
    return rtn;
}
