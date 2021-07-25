#include <stdio.h>

int main(){
    int numero1;
    int numero2;
    int numero3;
    printf("Ingres el primer numero: ");
    scanf("%d", &numero1);
    printf("Ingres el segundo numero: ");
    scanf("%d", &numero2);
    printf("Ingres el tercer numero: ");
    scanf("%d", &numero3);
    int aux = 0;
    if(numero1 == numero2 && numero2 == numero3){
        printf("Los 3 numeros son iguales.")
    }
    if(aux < numero1){
        aux = numero1;
    }
    if(aux < numero2){
        aux = numero2;
    }
    if(aux < numero3){
        aux = numero3;
    }
    

    return 0;
}