#include <stdio.h>
#include "usuario.h"
#include "usuarioStruct.h"

int main(){
    saludo();
    despedida();
    printf("a\n");
    User a;
    a.edad = 20;
    printf("la edad es %d\n", a.edad);
    return 0;
}
