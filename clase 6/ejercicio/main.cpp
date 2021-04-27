#include <stdio.h>

struct cliente{
    char nombre[30];
    char apellido[30];
    long rut;
    char clave[50];
    char correo[50];
    char direccion[120];
    long telefono;
};

void ingresar(cliente *a);

cliente crearCliente();

int main(){
    cliente usuario;
    ingresar(&usuario);
    printf("%s\n", usuario.nombre);
    printf("%s\n", usuario.correo);
    return 0;
}

void ingresar(cliente *a){
    printf("Ingrese su nombre: ");
    scanf("%s", a->nombre);
    printf("Ingrese su apellido: ");
    scanf("%s", a->apellido);
    printf("Ingrese su rut: ");
    scanf("%lu", *(a->rut));
    printf("Ingrese su clave: ");
    scanf("%s", a->clave);
    printf("Ingrese su correo: ");
    scanf("%s", a->correo);
    printf("Ingrese su direccion: ");
    scanf("%s", a->direccion);
    printf("Ingrese su telefono: ");
    scanf("%lu", *(a->telefono));
    return;
}

cliente crearCliente(){
    cliente a;
    printf("Ingrese su nombre: ");
    scanf("%s", a.nombre);
    printf("Ingrese su apellido: ");
    scanf("%s", a.apellido);
    printf("Ingrese su rut: ");
    scanf("%lu", *(a.rut));
    printf("Ingrese su clave: ");
    scanf("%s", a.clave);
    printf("Ingrese su correo: ");
    scanf("%s", a.correo);
    printf("Ingrese su direccion: ");
    scanf("%s", a.direccion);
    printf("Ingrese su telefono: ");
    scanf("%lu", *(a.telefono));
    return a;
}