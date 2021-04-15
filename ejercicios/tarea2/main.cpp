#include <stdio.h>
#include <string.h>

int main(){

    //interfaz
    int opcion;do{
    printf("Tarea: SELECTOR DE CALCULO\n\n\n");
    printf("1) Mayor de 2 numeros.\n");
    printf("2) Numero par.\n");
    printf("3) Mayor de 3 numeros.\n");
    printf("4) Suma de arreglos\n");
    printf("5) Divisores de x.\n");
    printf("6) Test de numero primo.\n");
    printf("7) Texto a mayus.\n\n");
    printf("Qué opción desea elegir?:");
    scanf("%d", &opcion);
    printf("%d", opcion);
    }while((opcion < 1)||(opcion > 7));

    //iniciamos un switch para sintetizar varios programas en 1 solo
    switch(opcion){
        case 1:{
            //informamos por pantalla
            printf("MAYOR DE 2 NUMEROS ENTEROS.\n\n");
            printf("Ingrese el primer numero: ");
            int numero1;scanf("%d", &numero1);
            printf("\nIngrese el segundo numero: ");
            int numero2;scanf("%d", &numero2);
            //mayor de 2 numeros
            if(numero1 < numero2){
                printf("Numero 2 es mayor.");
            }else if(numero2 < numero1){
                printf("Numero 1 es mayor.");
            }else{
                printf("Los numeros son iguales.");
            }
            opcion = 0;

        }case 2:{

            printf("DETECTOR DE PRIMOS.\n\n");
            printf("Ingrese un numero entero: ");
            int numero;scanf("%d", &numero);
            int resto = numero % 2;
            if (resto == 0){
                printf("El numero es par.");
            }else{
                printf("El numero es impar.");
            }

        }case 3:{

            printf("MAYOR DE 3 NUMEROS.\n\n");
            printf("Ingrese el primer numero: ");
            int numero1;scanf("%d", &numero1);
            printf("Ingrese el segundo numero: ");
            int numero2;scanf("%d", &numero2);
            printf("Ingrese el tercer numero: ");
            int numero3;scanf("%d", &numero3);

            if( (numero1 > numero2)&&(numero1 > numero3) ){
                printf("El primer numero es mayor.");
            }else if( (numero2 > numero1)&&(numero2 > numero3) ){
                printf("El segundo numero es mayor.");
            }else if( (numero3 > numero1)&&(numero3 > numero2)){
                printf("El tercer numero es mayor.");
            }else{
                printf("Hay 2 o mas numeros iguales.");
            }
            
        }case 4:{

            printf("SUMA DE ARREGLOS.\n\n");
            printf("Escriba una palabra o frase: ");
            char frase[100];
            scanf("%s", frase);
            printf("Escriba otra palabra o frase: ");
            char frase2[100];
            scanf("%s", frase2);
            strcat(frase,frase2);
            printf("Resultado: %s", frase);

        }case 5:{/*

            printf("DIVISORES DE X.\n\n");
            printf("Valor de X (entero): ");
            int numero;scanf("%d", &numero);
            printf("%d", numero);
            char cadena[numero];
            for(int i = 1; i < numero; i++){
                int aux;
                int u =  2 * i;
                aux = numero % i;
                if(aux == 0){
                    strcat(cadena,i);
                    strcat(cadena,",");
                }
            }
            printf("%s", cadena);*/

        }case 6:{

            printf("DETECTOR DE PRIMOS.\n\n");
            printf("Inserte un numero entero: ");
            int numero;scanf("%d", &numero);

            int c = 0;
			printf("Analizando...\n");
    		for(int i = 2; i < numero; i++){
    			if(((numero % i) == 0)){
    				c++;
    			}	
	    	}if(c == 0){
                printf("\nEl numero %d es primo.", numero);
            }else{
                printf("\nEl numero %d no es primo.", numero);
            }

        }case 7:{

        }
    }
    
    return 0;
}