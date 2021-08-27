#include <stdio.h>
#include <string.h>
#include "validacion.h"


void titulo(){
	printf("                                _                 __           ____       ___              __    _                 \n");
	printf("  ____  _________ _____ _____  (_)___  ____ _____/ /___  _____/ __ \\___  /   |  __________/ /_  (_)   ______  _____\n");
	printf(" / __ \\/ ___/ __ `/ __ `/ __ \\/ /_  / / __ `/ __  / __ \\/ ___/ / / / _ \\/ /| | / ___/ ___/ __ \\/ / | / / __ \\/ ___/\n");
	printf("/ /_/ / /  / /_/ / /_/ / / / / / / /_/ /_/ / /_/ / /_/ / /  / /_/ /  __/ ___ |/ /  / /__/ / / / /| |/ / /_/ (__  ) \n");
	printf("\\____/_/   \\__, /\\__,_/_/ /_/_/ /___/\\__,_/\\__,_/\\____/_/  /_____/\\___/_/  |_/_/   \\___/_/ /_/_/ |___/\\____/____/  \n");
	printf("          /____/                                                                                                   \n\n\n");

	printf("	Bienvenido a \"organizadorDeArchivos\", un programa creado para facilitar la descarga de los documentos de las plataformas\n");
	printf("educacionales.\n");
	printf("	Este programa descargará automaticamente los archivos de tus ramos inscritos y los ordenará por ramos/secciones/archivos.\n\n");
}


void ingresoDeDatos(char *x, char *y){
	char nombre[30], contra[30];
	printf("Ingrese usuario: ");
	scanf("%s", nombre);
	printf("Ingrese contrasena: ");
	scanf("%s", contra);
	strcpy(x,nombre);
	strcpy(y,contra);
	return;
}

int verificacion(int &codigo_usr, int iteraciones, char usuario[], char usuarioDB[][25], char contra[], char contraDB[][16]){
	int verif = 0;
	
	for(int i = 0; i < iteraciones; i++){	
		//se comprueba si el usuario y la contraseña ingresadas corresponden con el dato "i" de la matriz, siendo i la fila de la matriz
		if((strcmp(usuario, usuarioDB[i]) == 0) && (strcmp(contra, contraDB[i]) == 0)){
			//al ser verdadera la condición definimos un bool como 1 para guardar que el nombre de usuario ingresado corresponde con alguno de los datos de la matriz
			codigo_usr = i;
			printf("\n	Ingreso exitoso.\n\n"); //impresión para pruebas
			verif = 1;
			return 1;
		//en caso de que no coincida el nombre de usuario y la contraseña la variable verificado se mantiene 0 para indicar al pregrama que no conciden
		}else{
			continue;
		}
	}
	//detectamos si la verificación es invalida, para imprimir un mensaje de error 
	if(verif == 0){
		return 0;
	}
	return 0;
}
