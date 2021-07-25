#include <stdio.h>

void pedirLados(int* lado1, int* lado2, int* lado3);

bool verificarTriangulo(int lado1, int lado2, int lado3);

void clasificarTriangulo(int lado1, int lado2, int lado3);

int main(){
    int a,b,c;
    pedirLados(&a,&b,&c);
    if(verificarTriangulo(a,b,c)){
        printf("Triangulo verificado.\n");
        clasificarTriangulo(a,b,c);
    }else{
        printf("Los lados son inválidos.\n");
    }

    return 0;
}

void pedirLados(int* lado1, int* lado2, int* lado3){
    printf("Ingrese el primer lado:");
    scanf("%d", lado1);
    printf("Ingrese el segundo lado:");
    scanf("%d", lado2);
    printf("Ingrese el tercer lado:");
    scanf("%d", lado3);
}

bool verificarTriangulo(int lado1, int lado2, int lado3){
    if((lado1 + lado2 > lado3)&&(lado1 + lado3 > lado2)&&(lado2 + lado3 > lado1)){
        return true;
    }else{
        return false;
    }
}

void clasificarTriangulo(int lado1, int lado2, int lado3){
    if(lado1 == lado2 && lado2 == lado3){
        printf("Equilatero\n");
    }else if((lado1 == lado2)|| (lado2 == lado3) || (lado1==lado3)){
        printf("Isosceles\n");
    }else{
        printf("Escaleno\n");
    }
}