#include "eColor.h"

int cargarDescripcionColor(eColor vecColor[], int tamColor, int id, char desc[]){
    int todoOk = 0;
    if(vecColor != NULL && tamColor > 0 && desc != NULL){
        for(int i = 0; i < tamColor; i++){
            if(vecColor[i].id == id){ // El id del array sector coincide con el buscado
                strcpy(desc, vecColor[i].nombreColor);
                todoOk = 1;
            }
        }
    }
    return todoOk;
}
int listarColor(eColor vecColor[], int tamColor){
    int todoOk = 0;
    if(vecColor != NULL && tamColor > 0){
        printf("\n     *** LISTADO COLORES ***    \n");
        printf("  ID      Descripcion    \n");
        printf("-------------------------\n");
        for(int i = 0; i < tamColor; i++){
            printf(" %4d   %20s\n", vecColor[i].id, vecColor[i].nombreColor);
            todoOk = 1;
        }
    }
    return todoOk;
}

int buscarColor(eColor vecColor[], int tamColor, int id, int* pIndex){
    int todoOk = 0;
    if(vecColor != NULL && pIndex != NULL && tamColor > 0){ // (vec && pIndex && tam > 0)
        *pIndex = -1;
        for(int i = 0; i < tamColor; i++){
            if(vecColor[i].id == id){
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarColor(eColor vecColor[], int tamColor, int id){
    int todoOk = 0; // No valido vec y tam porque vienen validadas de la funcion buscarSector. El retorno solo se encarga de validar el indice.
    int indice;
    if(buscarTipo(vecColor, tamColor, id, &indice)){
        if(indice != -1){
            todoOk = 1;
        }
    }
    return todoOk;
}
