#include "lista.h"
#include <stdio.h>

//implementaciones
bool vacia(Lista lista){
    return (lista == NULL);
}

int primero(Lista lista){
    return 1;
}

int fin(Lista lista){
    if(vacia(lista)){
        return primero(lista);
    }
    else{
        return 1 + fin(lista-> next);
    }
}

int anterior(int p, Lista lista){
    if(p > fin(lista) || p <= primero(lista)){
        printf("Error en la funcion ANTERIOR!\n");
        return 0;
    }
    else{
        return p - 1;
    }
}

int siguiente(int p, Lista lista){
    if(p >= fin(lista) || p < primero(lista)){
        printf("Error en la funcion SIGUIENTE!\n");
    }
    else{
        return p + 1;
    }
}

int inserta(tipoDato x, int p, Lista &lista){
    if( p > fin(lista) || p < primero(lista)){
        printf("Error en la funcion INSERTA!\n");
        return;
    }

    //cuadrado verde
    nodo* n = new nodo;
    //lista = 15
    Lista aux = lista;

    n->dato = x;

    if(p == primero(lista)){
        lista = n;
        lista->next = aux;
    }
    else{
        for(int i = 0; i < p-2; i++){
            aux = aux->next;
        }
        n->next = aux -> next;
        aux->next = n;
    }

}
