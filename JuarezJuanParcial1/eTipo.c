#include "eTipo.h"

int cargarDescripcionTipo(eTipo vec[], int tam, int id, char desc[]){
    int todoOk = 0;
    if(vec != NULL && tam > 0 && desc != NULL){
        for(int i = 0; i < tam; i++){
            if(vec[i].id == id){ // El id del array sector coincide con el buscado
                strcpy(desc, vec[i].descripcion);
                todoOk = 1;
            }
        }
    }
    return todoOk;
}
int listarTipo(eTipo vec[], int tamTipo){
    int todoOk = 0;
    if(vec != NULL && tamTipo > 0){
        printf("\n     *** LISTADO TIPOS ***    \n");
        printf("  ID      Descripcion    \n");
        printf("-------------------------\n");
        for(int i = 0; i < tamTipo; i++){
            printf(" %4d   %20s\n", vec[i].id, vec[i].descripcion);
            todoOk = 1;
        }
    }
    return todoOk;
}

int buscarTipo(eTipo vec[], int tamTipo, int id, int* pIndex){
    int todoOk = 0;
    if(vec != NULL && pIndex != NULL && tamTipo > 0){ // (vec && pIndex && tam > 0)
        *pIndex = -1;
        for(int i = 0; i < tamTipo; i++){
            if(vec[i].id == id){
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarTipo(eTipo vec[], int tamTipo, int id){
    int todoOk = 0; // No valido vec y tam porque vienen validadas de la funcion buscarSector. El retorno solo se encarga de validar el indice.
    int indice;
    if(buscarTipo(vec, tamTipo, id, &indice)){
        if(indice != -1){
            todoOk = 1;
        }
    }
    return todoOk;
}
