#include <stdio.h>
#include <math.h>

struct Punto{
    float x;
    float y;
    Punto () {x = 0; y = 0;}
    Punto (float a) {x = a; y = a;}
    Punto (float a, float b) {x = a; y = b;}
};

struct Recta{
    float m;
    float b;
};

//ya que no se necesitan cambiar los valores de las variables
//que estamos ocupando en esta función, no ocupamos
//punteros.
float distanciaDosPuntos(Punto a, Punto b);

bool perteneceRecta(Recta r, Punto p);


int main(){
    Punto p1 = {2.5, 7.2};
    Punto p2 = {4.5, 3.6};
    Recta r1 = {3.6, 8.9};


    printf("Hola, selecciona una opcion:\n\n");
    printf("1. Calcular distancia entre 2 puntos.\n");
    printf("2. Comprobar si el punto pertenece a la recta\n");
    int opcion;scanf("%d", &opcion);

    switch(opcion){
        case 1:{
            float distancia = distanciaDosPuntos(p1, p2);
            printf("La distancia es de: %f", distancia);
            //%(.X)f (x es el numero de decimales)
            break;
        }
        case 2:{
            bool pertenece = perteneceRecta(r1,p2);
            printf("%d\n", pertenece);
            break;
        }
        default: {printf("La opcion no es valida.\n");}
    }
}

float distanciaDosPuntos(Punto a, Punto b){
    return sqrt(pow(b.x - a.x, 2) + pow(b.y- a.y, 2));
}


bool perteneceRecta(Recta r, Punto p){
//podríamos hacer una variable, guardar la respuesta
//en ella y luego retornar esa respuesta, pero podemos
//directamente retornar la respuesta ya que funcionará
//EN ESTE CASO como si fuera una comparación.
//
    return (p.y == r.m * p.x + r.b);
}