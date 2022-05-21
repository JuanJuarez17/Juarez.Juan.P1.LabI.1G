#include "eServicio.h"

int listarServicio(eServicio vecServicio[], int tamServicio){
    int todoOk = 0;
    if(vecServicio != NULL && tamServicio > 0){
        printf("\n     * LISTADO SERVICIOS *   \n\n");
        printf("   ID   DESCRIPCION   PRECIO\n");
        printf("----------------------------\n");
        for(int i = 0; i < tamServicio; i++){
            printf(" %4d   %10s   %6.2f\n", vecServicio[i].id, vecServicio[i].descripcion, vecServicio[i].precio);
            todoOk = 1;
        }
    }
    return todoOk;
}

int buscarServicio(eServicio vec[], int tam, int id, int* pIndex){
    int todoOk = 0;
    if(vec != NULL && pIndex != NULL && tam > 0){
        *pIndex = -1;
        for(int i = 0; i < tam; i++){
            if(vec[i].id == id){
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarServicio(eServicio vec[], int tam, int id){
    int todoOk = 0;
    int indice;
    if(buscarServicio(vec, tam, id, &indice)){
        if(indice != -1){
            todoOk = 1;
        }
    }
    return todoOk;
}

int cargarDescripcionServicio(eServicio vecServ[], int tamServ, int id, char desc[]){
    int rtn = 0;
    if(vecServ != NULL && tamServ > 0 && desc != NULL){
        for(int i = 0; i < tamServ; i++){
            if(vecServ[i].id == id){ // El id del array sector coincide con el buscado
                strcpy(desc, vecServ[i].descripcion);
                rtn = 1;
            }
        }
    }
    return rtn;
}

int cargarImporteServicio(eServicio vecServ[], int tamServ, int id, float* pImporte){
    int rtn = 0;
    if(vecServ != NULL && tamServ > 0 && pImporte != NULL){
        for(int i = 0; i < tamServ; i++){
            if(vecServ[i].id == id){ // El id del array sector coincide con el buscado
                *pImporte = vecServ[i].precio;
                rtn = 1;
            }
        }
    }
    return rtn;
}
