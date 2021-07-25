#include <stdio.h>

int sumasSucesivas(int a, int b);

int main(){
    
    return 0;
}

int sumasSucesivas(int a, int b){
    if(b == 0){
        return 0;
    }else if(b == 1){
        return a;
    }else{
        return a + sumasSucesivas( a, b - 1);
    }
}

int cuartoCliente(){
    
}