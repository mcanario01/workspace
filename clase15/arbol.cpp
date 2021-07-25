#include "arbol.h"
#include <stdio.h>

Arbol creaRaiz(datoArbol u){
    Arbol r;
    tipoDato n;
    n.dato = u;
    inserta(n, primero(r), r);
    return r;
}

Arbol& listaHijos(Arbol n){
    return n.primero->dato.hijos;
}

void insertaHijoMasIqz(Arbol& n, Arbol & Ti){
    Arbol& hijos = listaHijos (n);
    tipoDato raizTi = recupera(primero(Ti), Ti);
    inserta(raizTi, primero(hijos), hijos);
    anula((Lista&)Ti);
}

