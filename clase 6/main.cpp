#include <stdio.h>

int main (){
    FILE* lectura = fopen("data.dat", "r");
    FILE* escritura = fopen("numeros.txt","w");

    int x;

    while(!feof(lectura)){ //controlamos una condición que devuelve el estado de finalizacion del archivo.
    // tenemos que ! transforma la condición a su inversa entonces
    // la condución es valida mientras no estemos en el final del archivo
        fscanf(lectura, "%d", &x);
        printf("%d\n", x);
        fprintf(escritura, "%d -> ", x);

        //Comprobar paridad
        if(x % 2 == 0){
            //par
            fprintf(escritura, "Par - ");
        }else{
            //impar
            fprintf(escritura, "Impar - ");
        }
        int c = 0;
    	for(int i = 2; i < x; i++){
    		if(((x % i) == 0)){
    			c++;
    		}	
	   	}if(c == 0){
            fprintf(escritura, "Primo.\n");
        }else{
            fprintf(escritura, "No primo.\n");
        }

    }

    fclose(lectura);
    fclose(escritura);

    return 0;
}