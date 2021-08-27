#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "descarga.h"



int calculoRamosUsuario( int ramos[][9], int usuario){

	int contador = 0;
	for (int u = 0; u < 9 ; u++){
		if (ramos[usuario][u] >= 1){
			contador ++;
		}else{
			break;
		}
	}
	return contador;
}

void imprimirRamos(char nombreRamos[][9], int ramos[][9], int usuario, int cantidad){
	for(int j = 0; j < cantidad ; j++){
		printf("%s", nombreRamos[ramos[usuario][j] - 1]);
		if(j < cantidad - 1){
			printf(", ");
		}
	}
}

void descargaDeArchivos(char nombreDeUsuario[][25], int cantidad_numeroDe_ramos, int codigo_usuario, int ramos_usuario[][9], int secciones_por_ramo[][3], int documentos_por_seccion[][2], char ramos[][9], char nombre_secciones[][15], char nombre_documentos[][31]) {
	
	struct stat st = {0};

	FILE * archivo;

	char ruta[30];
	char raiz[30]= "UFRO";
	strcpy(ruta, raiz);
	if (stat(ruta, &st) == -1) {
		mkdir(ruta, 0700);
	}

	printf("%s\n", ruta);
	

	for(int ramo = 0; ramo < cantidad_numeroDe_ramos; ramo++){
		printf("	%s/", ramos[ramos_usuario[codigo_usuario][ramo] - 1]);
		printf("\n");

		strcat(ruta, "/");
		strcat(ruta, ramos[ramos_usuario[codigo_usuario][ramo] - 1]);

		if (stat(ruta, &st) == -1) {
			mkdir(ruta, 0700);
		}

		char ruta_ramo[30];
		strcpy(ruta_ramo, ruta);

		for(int seccion = 0; seccion < 3; seccion++){
			printf("		%s/", nombre_secciones[secciones_por_ramo[ramos_usuario[codigo_usuario][ramo] - 1][seccion] - 1]);
			printf("\n");

			strcat(ruta, "/");
			strcat(ruta, nombre_secciones[secciones_por_ramo[ramos_usuario[codigo_usuario][ramo] - 1][seccion] - 1]);

			if (stat(ruta, &st) == -1) {
				mkdir(ruta, 0700);
			}

			char ruta_seccion[40];
			strcpy(ruta_seccion, ruta);


			for(int documento = 0; documento < 2; documento++){
				printf("			%s"	, nombre_documentos[documentos_por_seccion[secciones_por_ramo[ramos_usuario[codigo_usuario][ramo] - 1][seccion] - 1][documento] - 1]);
				printf("\n");

				strcat(ruta, "/");
				strcat(ruta, nombre_documentos[documentos_por_seccion[secciones_por_ramo[ramos_usuario[codigo_usuario][ramo] - 1][seccion] - 1][documento] - 1]);
			
				archivo = fopen(ruta,"w");

				if(archivo == NULL){
					fprintf(stdout,"Error.\n");
				} 
                   else {
					fclose(archivo);
				}	

				strcpy(ruta, ruta_seccion);

			}
			strcpy(ruta, ruta_ramo);

		}
		
		strcpy(ruta, raiz);
		printf("\n");
	
	}

	return;
}
