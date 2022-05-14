#include "eMoto.h"

int iniMoto(eMoto vec[], int tam){
    int rtn = 0;
    if(vec != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            vec[i].isEmpty = 1;
        }
        rtn = 1;
    }
    return rtn;
}

int buscarIndexLibreMoto(eMoto vec[], int tam, int* pIndex){ // Devuelve el indice del primer vector de la estructura libre.
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

int buscarIndexCompletoMoto(eMoto vec[], int tam){
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

void mostrarMoto(eMoto vec, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor){
    char descTipo[20];
    cargarDescripcionTipo(vecTipo, tamTipo, vec.idTipo, descTipo);
    char descColor[20];
    cargarDescripcionColor(vecColor, tamColor, vec.idColor, descColor);
    printf("%4d          %20s        %3d       %2d  %10s %10s\n",
           vec.id,
           vec.marca,
           vec.cilindrada,
           vec.puntaje,
           descTipo,
           descColor);
}

int altaMoto(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int* pNextId){
    int rtn = 0;
    int indice;
    eMoto auxMoto;
    char confirma;
    char auxCad[100];
    int vInt;
    int auxInt;
    int idTipo;
    int idColor;
    if(vec && pNextId && tam > 0){ //(vec != NULL && pNextId != NULL && tam > 0)
        system("cls");
        printf("                          - ALTA MOTO -                       \n\n");
        buscarIndexLibreMoto(vec, tam, &indice);
        if(indice == -1){
            printf("-------------------------------------------------------------\n");
            printf("                - NO HAY LUGAR EN EL SISTEMA -               \n");
            printf("-------------------------------------------------------------\n");
        }
        else{
            auxMoto.id = *pNextId;

            printf("Ingrese marca: ");
            fflush(stdin);
            gets(auxCad);
            while(strlen(auxCad) >= 20){
                printf("Nombre demasiado largo! Reingrese: ");
                fflush(stdin);
                gets(auxCad);
            }
            while(validarStr(auxCad)){
                printf("Error! Reingrese marca: ");
                fflush(stdin);
                gets(auxCad);
            }
            strcpy(auxMoto.marca, auxCad);
            guardarStr(auxMoto.marca);

            printf("Ingrese cilindrada de la moto (50 - 125 - 500 - 600 - 750): ");
            fflush(stdin);
            vInt = scanf("%d", &auxInt);
            if(!(auxInt == 50 || auxInt == 125 || auxInt == 500 || auxInt == 600 || auxInt == 750)){
                printf("Error! Ingrese cilindrada de la moto (50 - 125 - 500 - 600 - 750): ");
                fflush(stdin);
                vInt = scanf("%d", &auxInt);
            }
            auxMoto.cilindrada = auxInt;

            printf("Ingrese puntaje de la moto (1 al 10): ");
            fflush(stdin);
            vInt = scanf("%d", &auxInt);
            while(!(validarIntRango(vInt, auxInt, 1, 10))){
                printf("Ingrese puntaje de la moto (1 al 10): ");
                fflush(stdin);
                vInt = scanf("%d", &auxInt);
            }
            auxMoto.puntaje = auxInt;

            listarTipo(vecTipo, tamTipo);
            printf("Ingrese el ID del tipo de moto: ");
            fflush(stdin);
            scanf("%d", &idTipo);

            while(!validarTipo(vecTipo, tamTipo, idTipo)){
                printf("Error! Ingrese el ID de su destino: ");
                fflush(stdin);
                scanf("%d", &idTipo);
            }
            auxMoto.idTipo = idTipo;

            listarColor(vecColor, tamColor);
            printf("Ingrese el ID del color de la moto: ");
            fflush(stdin);
            scanf("%d", &idColor);

            while(!validarColor(vecColor, tamColor, idColor)){
                printf("Error! Ingrese el ID del color de la moto: ");
                fflush(stdin);
                scanf("%d", &idColor);
            }
            auxMoto.idColor = idColor;

            printf("\n-----------------------------------------------------------------------------\n");
            printf(" ID                 MARCA             CILINDRADA  PUNTAJE    TIPO       COLOR\n");
            printf("-----------------------------------------------------------------------------\n");
            mostrarMoto(auxMoto, vecTipo, tamTipo, vecColor, tamColor);

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
                auxMoto.isEmpty = 0;
                vec[indice] = auxMoto;
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

int listarMoto(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor){
    int rtn = 0;
    int flag = 1;
    if(vec != NULL && tam > 0){
        //system("cls");
        printf("\n                     - LISTA DE MOTOS -                     \n");
        printf("-----------------------------------------------------------------------------\n");
        printf(" ID                 MARCA             CILINDRADA  PUNTAJE    TIPO       COLOR\n");
        printf("-----------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++){
            if(vec[i].isEmpty == 0){
                mostrarMoto(vec[i], vecTipo, tamTipo, vecColor, tamColor);
                flag = 0;
            }
        }
        if(flag){
            printf("                - NO HAY MOTOS EN EL SISTEMA -                \n");
            printf("------------------------------------------------------------------\n");
        }
        rtn = 1;
    }
    return rtn;
}

int buscarMotoPorId(eMoto vec[], int tam, int id, int* pIndex){
    int rtn = 0;
    if(vec != NULL && pIndex != NULL && tam > 0){
        *pIndex = -1;
        for(int i = 0; i < tam; i++){
            if(!vec[i].isEmpty && vec[i].id == id){
                *pIndex = i;
                break;
            }
        }
        rtn = 1;
    }
    return rtn;
}

int bajaMoto(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor){
    int rtn = 0;
    int indice;
    int vIndice;
    int id;
    char confirma;
    if(vec && vecTipo && vecColor && tam > 0 && tamTipo > 0 && tamColor > 0){
        system("cls");
        printf("                        - BAJA MOTO -                         \n");
        listarMoto(vec, tam, vecTipo, tamTipo, vecColor, tamColor);
        printf("\nIngrese ID: ");
        fflush(stdin);
        vIndice = scanf("%d", &id);

        while(!(validarInt(vIndice))){
            printf("Error! Ingrese ID: ");
            fflush(stdin);
            vIndice = scanf("%d", &id);
        }

        if(buscarMotoPorId(vec, tam, id, &indice)){
            if(indice == -1){
                printf("\nNo existe un pasajero con ID: %d en el sistema.\nVolviendo al menu principal\n", id);
            }
            else{ // Si existe
                printf("-----------------------------------------------------------------------------\n");
                printf(" ID                 MARCA             CILINDRADA  PUNTAJE    TIPO       COLOR\n");
                printf("-----------------------------------------------------------------------------\n");
                mostrarMoto(vec[indice], vecTipo, tamTipo, vecColor, tamColor);
                printf("\nConfirma baja? (S/N): ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = toupper(confirma);

                while(!(validarChar(confirma, 'S', 'N'))){
                    printf("Error! Confirma baja? (S/N): ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                }

                if(confirma == 'S'){
                    vec[indice].isEmpty = 1;
                    printf("Baja exitosa.\n");
                }
                else{
                    printf("Baja cancelada.\n");
                }
            }
            rtn = 1;
        }
    }
    return rtn;
}

int modifMoto(eMoto vec[], int tam, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor){
    int rtn = 0;
    int indice;
    int id;
    char confirma;
    char auxCad[100];
    int auxInt;
    int vInt;
    int idTipo;
    int idColor;
    if(vec && vecTipo && vecColor && tam > 0 && tamTipo > 0 && tamColor > 0){
        system("cls");
        printf("                       - EDITAR MOTO -                        \n");
        listarMoto(vec, tam, vecTipo, tamTipo, vecColor, tamColor);
        printf("\nIngrese ID: ");
        scanf("%d", &id);

        if(buscarMotoPorId(vec, tam, id, &indice)){
            if(indice == -1){
            printf("\nNo existe un pasajero con ID: %d en el sistema.\nVolviendo al menu principal\n", id);
            }
            else{
                printf("-----------------------------------------------------------------------------\n");
                printf(" ID                 MARCA             CILINDRADA  PUNTAJE    TIPO       COLOR\n");
                printf("-----------------------------------------------------------------------------\n");
                mostrarMoto(vec[indice], vecTipo, tamTipo, vecColor, tamColor); // Muestro el empleado
                switch(modifMotoMenu()){
                    case 1:
                        printf("Ingrese marca: ");
                        fflush(stdin);
                        gets(auxCad);
                        while(strlen(auxCad) >= 20){
                            printf("Nombre demasiado largo! Reingrese: ");
                            fflush(stdin);
                            gets(auxCad);
                        }
                        while(validarStr(auxCad)){
                            printf("Error! Reingrese marca: ");
                            fflush(stdin);
                            gets(auxCad);
                        }
                        printf("\nConfirma modificacion? (S/N): ");
                        fflush(stdin);
                        scanf("%c", &confirma);
                        confirma = toupper(confirma);
                        while(!(validarChar(confirma, 'S', 'N'))){
                            printf("Error! Confirma baja? (S/N): ");
                            fflush(stdin);
                            scanf("%c", &confirma);
                            confirma = toupper(confirma);
                        }
                        if(confirma == 'S'){
                            strcpy(vec[indice].marca, auxCad);
                            guardarStr(vec[indice].marca);
                            rtn = 1;
                            printf("Modificacion exitosa.\n");
                        }
                        else{
                            printf("Modificacion cancelada.\n");
                        }
                        break;
                    case 2:
                        printf("Ingrese cilindrada de la moto (50 - 125 - 500 - 600 - 750): ");
                        fflush(stdin);
                        vInt = scanf("%d", &auxInt);
                        if(!(auxInt == 50 || auxInt == 125 || auxInt == 500 || auxInt == 600 || auxInt == 750)){
                            printf("Error! Ingrese cilindrada de la moto (50 - 125 - 500 - 600 - 750): ");
                            fflush(stdin);
                            vInt = scanf("%d", &auxInt);
                        }
                        printf("\nConfirma modificacion? (S/N): ");
                        fflush(stdin);
                        scanf("%c", &confirma);
                        confirma = toupper(confirma);
                        while(!(validarChar(confirma, 'S', 'N'))){
                            printf("Error! Confirma baja? (S/N): ");
                            fflush(stdin);
                            scanf("%c", &confirma);
                            confirma = toupper(confirma);
                        }
                        if(confirma == 'S'){
                            vec[indice].cilindrada = auxInt;
                            rtn = 1;
                            printf("Modificacion exitosa.\n");
                        }
                        else{
                            printf("Modificacion cancelada.\n");
                        }
                        break;
                    case 3:
                        printf("Ingrese puntaje de la moto (1 al 10): ");
                        fflush(stdin);
                        vInt = scanf("%d", &auxInt);
                        while(!(validarIntRango(vInt, auxInt, 1, 10))){
                            printf("Ingrese puntaje de la moto (1 al 10): ");
                            fflush(stdin);
                            vInt = scanf("%d", &auxInt);
                        }
                        printf("\nConfirma modificacion? (S/N): ");
                        fflush(stdin);
                        scanf("%c", &confirma);
                        confirma = toupper(confirma);
                        while(!(validarChar(confirma, 'S', 'N'))){
                            printf("Error! Confirma baja? (S/N): ");
                            fflush(stdin);
                            scanf("%c", &confirma);
                            confirma = toupper(confirma);
                        }
                        if(confirma == 'S'){
                            vec[indice].puntaje = auxInt;
                            rtn = 1;
                            printf("Modificacion exitosa.\n");
                        }
                        else{
                            printf("Modificacion cancelada.\n");
                        }
                        break;
                    case 4:
                        listarTipo(vecTipo, tamTipo);
                        printf("Ingrese el ID del tipo de moto: ");
                        fflush(stdin);
                        scanf("%d", &idTipo);

                        while(!validarTipo(vecTipo, tamTipo, idTipo)){
                            printf("Error! Ingrese el ID de su destino: ");
                            fflush(stdin);
                            scanf("%d", &idTipo);
                        }
                        printf("\nConfirma modificacion? (S/N): ");
                        fflush(stdin);
                        scanf("%c", &confirma);
                        confirma = toupper(confirma);
                        while(!(validarChar(confirma, 'S', 'N'))){
                            printf("Error! Confirma baja? (S/N): ");
                            fflush(stdin);
                            scanf("%c", &confirma);
                            confirma = toupper(confirma);
                        }
                        if(confirma == 'S'){
                            vec[indice].idTipo = idTipo;
                            rtn = 1;
                            printf("Modificacion exitosa.\n");
                        }
                        else{
                            printf("Modificacion cancelada.\n");
                        }
                        break;
                    case 5:
                        listarColor(vecColor, tamColor);
                        printf("Ingrese el ID del color de la moto: ");
                        fflush(stdin);
                        scanf("%d", &idColor);

                        while(!validarColor(vecColor, tamColor, idColor)){
                            printf("Error! Ingrese el ID del color de la moto: ");
                            fflush(stdin);
                            scanf("%d", &idColor);
                        }
                        printf("\nConfirma modificacion? (S/N): ");
                        fflush(stdin);
                        scanf("%c", &confirma);
                        confirma = toupper(confirma);
                        while(!(validarChar(confirma, 'S', 'N'))){
                            printf("Error! Confirma baja? (S/N): ");
                            fflush(stdin);
                            scanf("%c", &confirma);
                            confirma = toupper(confirma);
                        }
                        if(confirma == 'S'){
                            vec[indice].idColor = idColor;
                            rtn = 1;
                            printf("Modificacion exitosa.\n");
                        }
                        else{
                            printf("Modificacion cancelada.\n");
                        }
                        break;
                }
            }
        }
    }
    return rtn;
}

int ordenarMotoTipoId(eMoto vec[], int tam){
    int rtn = 0;
    eMoto aux;
    if(vec != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            for(int j = i + 1; j < tam; j++){
                if((vec[i].idTipo == vec[j].idTipo && vec[i].id < vec[j].id)
                || (vec[i].idTipo != vec[j].idTipo && vec[i].idTipo > vec[j].idTipo)){
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
        rtn = 1;
    }
    return rtn;
}

int hardcodearMotos(eMoto vec[], int tam, int cant, int* pNextId){ // cant: Cantidad de pasajeros que quiero cargar a pesar de que el array sea de 10
    int rtn = 0;
    eMoto moto[10] = {
        {0, "Yamaha", 1000, 10040, 125, 9, 0},
        {0, "Benelli", 1010, 10010, 500, 1, 0},
        {0, "Honda", 1020, 10020, 600, 7, 0},
        {0, "Motora", 1010, 10030, 50, 10, 0},
        {0, "Motomel", 1020, 10030, 125, 3, 0},
        {0, "Honda", 1010, 10010, 700, 5, 0},
        {0, "Yamaha", 1030, 10040, 125, 2, 0},
        {0, "Suzuki", 1020, 10000, 700, 2, 0},
        {0, "Motomel", 1000, 10020, 50, 4, 0},
        {0, "Yamaha", 1030, 10020, 125, 1, 0},
    };
    if(vec != NULL && pNextId != NULL && tam > 0 && tam <= 50 && cant <= tam){
        for(int i = 0; i < cant; i++){
            vec[i] = moto[i];
            vec[i].id = *pNextId;
            (*pNextId)++;
        }
        rtn = 1;
    }
    return rtn;
}
