#include <stdio.h>
#include <stdlib.h>

int validarPos(int fila, int columna, int tablero[9][9], int numero);

typedef struct _validos{
    int numero[9];
    int cantidad;
    int fila, columna;
}validos;

typedef struct _listVacios{
    int fila, columna;
    int cantidad, iteracion;
    struct _listVacios* next;
    struct _listVacios* prev;
    int numeros[];
}listVacios;

typedef listVacios *SlistaVacios;

void imprimir_tablero(int tablero[9][9]){
    int contadorF = 0, contadorC = 0;
    printf("------- ------ -------");
    printf("\n");
    for(int i = 0; i < 9; i++){
    printf("|");
        for(int j = 0; j < 9; j++){
            printf("%d ", tablero[i][j]);
            contadorC++;

        if(contadorC == 3){
            printf("|");
            contadorC = 0;
            }

        }
            contadorF++;
        printf("\n");
        if(contadorF == 3){

            printf("------- ------ -------");
            printf("\n");
            contadorF = 0;
        }
    }
}

int cant_vacios(int tablero[9][9]){
    int contador = 0;
    for (int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(tablero[i][j] == 0) contador++;
        }
    }
    return contador; 
}

SlistaVacios crearLista(){ return NULL;}

SlistaVacios aggInicio(SlistaVacios lista, int fila, int columna, int tablero[9][9]){
    int contador = 0;
    SlistaVacios nuevoNodo = malloc(sizeof(listVacios));
    if(lista != NULL) lista->prev = nuevoNodo;
    nuevoNodo->fila = fila;
    nuevoNodo->columna = columna;
    nuevoNodo->prev = NULL;
    // printf("fila %d, col %d, ", fila+1, columna+1);
    for(int i = 1; i < 10; i++){
        if(validarPos(fila, columna, tablero, i)){
            nuevoNodo->numeros[contador] = i;
            // printf("%d ", nuevoNodo->numeros[contador]);
            contador++;
        }
    }
    nuevoNodo->cantidad = contador;
    // printf(" contador %d", nuevoNodo->cantidad);
    // puts("");
    nuevoNodo->next = lista;
    return nuevoNodo;
}

SlistaVacios eliminarNodo(SlistaVacios lista){
    if(lista->next == NULL) return lista->prev;
    if(lista->prev == NULL) return lista->next;
    lista->prev->next = lista->next;
    lista->next->prev = lista->prev;
    return lista;

}

int validarPos(int fila, int columna, int tablero[9][9], int numero){

    int filaTest, columnaTest;
    if(fila < 3) filaTest = 0;
    else if(fila < 6) filaTest = 3;
    else if(fila < 9) filaTest = 6;

    if(columna < 3) columnaTest = 0;
    else if(columna < 6) columnaTest = 3;
    else if(columna < 9) columnaTest = 6;

    for(int i = 0; i < 9; i++){
        if ((columna != i) & (tablero[fila][i] == numero)) return 0;
        if ((fila != i) & (tablero[i][columna] == numero)) return 0;        
    }

    for(int i = filaTest; i < filaTest + 3; i++){
        for(int j = columnaTest; j < columnaTest+3; j++){
            if(tablero[i][j] == numero){
                return 0;
            }
        }
    }
    return 1;
}

SlistaVacios completarLista(int tablero[9][9], SlistaVacios lista){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(tablero[i][j] == 0){
                lista = aggInicio(lista, i, j, tablero);
                // printf("fila %d, columna %d, ", lista->fila, lista->columna);
                // for(int k = 0; k < lista->cantidad; k++){
                //     printf("%d ", lista->numeros[k]);
                // }
                // puts("");
            }
        }
    }
    return lista;
}

void imprimirLista(SlistaVacios lista){
    for(listVacios *nodo = lista; nodo != NULL; nodo = nodo->next){
        printf("fila %d, columna %d, posibles ", nodo->fila + 1, nodo->columna + 1);
                for(int k = 0; k < nodo->cantidad; k++){
                    printf("%d ", nodo->numeros[k]);
                }
                puts("");
    }
}

int completar(int tablero[9][9], SlistaVacios lista){

    // ordenar lista aca

    listVacios *nodo = lista;

    for(; nodo != NULL; nodo = nodo->next){
        // if(nodo->cantidad == 1) tablero[nodo->fila][nodo->columna] = nodo->numeros[0];
        if(nodo->cantidad == nodo->iteracion-1){
            tablero[nodo->fila][nodo->columna] = nodo->numeros[nodo->iteracion];
            nodo = eliminarNodo(nodo);
            continue;
        }
        if(cant_vacios(tablero) == 0) return** tablero;
    nodo->iteracion++;
    if(nodo->iteracion-1 == nodo->cantidad) { // restar 1 si da error
        nodo->iteracion = 0;
        **tablero = completar(tablero, nodo->prev);
    }
    tablero[nodo->fila][nodo->columna] = nodo->numeros[nodo->iteracion++];    

    }
    imprimir_tablero(tablero);
    return** tablero;
}

int main(){
     int tablero[9][9] = { {4, 3, 0, 0, 0, 0, 0, 0, 0},
                           {0, 5, 0, 0, 3, 0, 0, 4, 8},
                           {0, 0, 6, 9, 8, 4, 3, 0, 0},
                           {0, 0, 3, 0, 0, 0, 8, 0, 0},
                           {9, 1, 2, 0, 0, 0, 6, 7, 4},
                           {0, 0, 4, 0, 0, 0, 0, 0, 0},
                           {0, 0, 1, 6, 7, 0, 2, 0, 0},
                           {0, 0, 0, 0, 9, 0, 0, 1, 5},
                           {0, 9, 0, 0, 4, 0, 0, 3, 0} };
    imprimir_tablero(tablero);

    // int vacios = cant_vacios(tablero);

    SlistaVacios lista = crearLista();

    // for(int i = 0; i < 9; i++){
    //     for(int j = 0; j < 9; j++){
    //         if(tablero[i][j] == 0)
    //             lista = aggInicio(lista, i, j, tablero);
    //     }
    // }

    lista = completarLista(tablero, lista);
    //imprimirLista(lista);
    // **tablero = completar(tablero, lista);

    // imprimir_tablero(tablero);



    // for(listVacios *nodo = lista; nodo != NULL; nodo = nodo->next){
    //     printf("fila %d, columna %d, posibles numeros", nodo->fila+1, nodo->columna+1);
    //     for(int i = 0; i < nodo->cantidad; i++) printf(", %d", nodo->numeros[i]);
    //     printf("\n");
    // }

    // printf("%d\n", cant_vacios(tablero));
    return 0;
}
