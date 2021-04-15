#include <stdio.h>

int main(){

    //interfaz
    printf("Tarea: SELECTOR DE CALCULO\n\n\n");
    printf("1) Mayor de 2 numeros.\n");
    printf("2) Numero par.\n");
    printf("3) Mayor de 3 numeros.\n");
    printf("4) Suma de arreglos\n");
    printf("5) Divisores de x.\n");
    printf("6) Test de numero primo.\n");
    printf("7) Texto a mayus.\n\n");
    printf("Qué opción desea elegir?:");
    int opcion;
    scanf("%d", &opcion);
    printf("%d", opcion);

    //iniciamos un switch para sintetizar varios programas en 1 solo
    switch(opcion){
        case 1:{
            //informamos por pantalla
            printf("MAYOR DE 2 NUMEROS\n\n");
            printf("Ingrese el primer numero: ");
            int numero1;scanf("%d", &numero1);
            printf("\nIngrese el segundo numero: ");


        }case 2:{

        }case 3:{
            
        }case 4:{

        }case 5:{

        }case 6:{

        }case 7:{

        }
    }
    
    return 0;
}