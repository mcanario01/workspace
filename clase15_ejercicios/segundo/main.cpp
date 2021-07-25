//FUNCIONES RECURSIVAS
#include <stdio.h>

int numeroDivisores(int numero, int divisor);

int main(){
    return 0;
}


int numeroDivisores(int numero, int divisor){
    if(divisor == 1){
        return 1;
    }else if{
        return 1 + numeroDivisores(numero, divisor - 1);
    }else{
        return numeroDivisores(numero, divisor - 1);
    }
}