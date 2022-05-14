#include "eServicio.h"

int listarServicio(eServicio vecServicio[], int tamServicio){
    int todoOk = 0;
    if(vecServicio != NULL && tamServicio > 0){
        printf("\n     *** LISTADO SERVICIOS ***    \n");
        printf("  ID      DESCRIPCION    PRECIO\n");
        printf("-------------------------\n");
        for(int i = 0; i < tamServicio; i++){
            printf(" %4d   %20s %6.2f\n", vecServicio[i].id, vecServicio[i].descripcion, vecServicio[i].precio);
            todoOk = 1;
        }
    }
    return todoOk;
}
