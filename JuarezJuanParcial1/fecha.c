#include "fecha.h"

int altaFecha(eFecha* vec){
    int rtn = 0;
    int vInt;
    if(vec != NULL){
        printf("Ingrese dia: ");
        fflush(stdin);
        vInt = scanf("%d", &vec->dia);
        while(!(validarIntRango(vInt, vec->dia, 1, 31))){
            printf("Error! Ingrese dia: ");
            fflush(stdin);
            vInt = scanf("%d", &vec->dia);
        }
        printf("Ingrese mes: ");
        fflush(stdin);
        vInt = scanf("%d", &vec->mes);
        while(!(validarIntRango(vInt, vec->mes, 1, 12))){
            printf("Error! Ingrese mes: ");
            fflush(stdin);
            vInt = scanf("%d", &vec->mes);
        }
        printf("Ingrese anio: ");
        fflush(stdin);
        vInt = scanf("%d", &vec->anio);
        while(!(validarIntRango(vInt, vec->anio, 2015, 2025))){
            printf("Error! Ingrese anio: ");
            fflush(stdin);
            vInt = scanf("%d", &vec->anio);
        }
        rtn = 1;
    }
    return rtn;
}
