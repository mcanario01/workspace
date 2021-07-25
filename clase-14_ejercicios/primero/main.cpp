#include <stdio.h>

int main(){
    int numero1;
    int numero2;

    printf("Ingrese un numero entero: ");
    scanf("%d",&numero1);
    printf("Ingrese otro numero entero: ");
    scanf("%d",&numero2);
    if(numero1>numero2){
        printf("El numero %d es mayor que %d.", numero1, numero2);
    }else if (numero2>numero1){
        printf("El numero %d es mayor que %d.", numero2, numero1);
    }else{
        printf("Los numeros son iguales.");
    }
    
    return 0;
}