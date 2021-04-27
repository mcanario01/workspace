#include <stdio.h>
#include <string.h>

struct cliente{
    char nombre[15];
    int edad;
};

int main(){
    cliente c, d;
    c.edad = 23;
    strcpy(c.nombre, "Jose");
    d = c;
    printf("%s\n", d.nombre);
    return 0;
}