/*Universidad de La Frontera
* Departamento de Ingeniería Eléctrica
*
* ICC-202 PROGRAMACION DE COMPUTADORES
*
* Tarea 2
*
* Autores:  Luciano Heyer Muñoz l.heyer01@ufromail.cl
*           Ignacio Piucol Gallardo i.piucol01@ufromail.cl
*           Esteban Reyes e.reyes08@ufromail.cl
*           Martin Canario Dauros m.canario01@ufromail.cl
*
* Fecha: 9 de Septiembre del 2020.
*
* Descripción general del programa:

	La idea principal de éste programa es facilitar la descarga y sincronización de los documentos de las
	plataformas educacionales, para que cuando ést os documentos mencionados se usen, se haga de forma expedita
	y evitar tener que estár descargandolos al momento de ocuparlos o durante una reunión sincrónica.

	Éste programa sirve para descargar automaticamente los documentos de una plataforma educacional.
	Funciona en 3 bloques pricipales:
		Validación:
			El programa valida los datos de usuario y contraseña.

		Obtención de datos:
			Ya validados los datos de autentificación, se reciben del servidor las bases de datos de los
			archivos.

		Descarga de archivos:
			El programa descarga los archivos correspondientes al usuario y a la vez, los ordena por
			ramos/seccion/documentos.
*/

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "validacion.h"
#include "descarga.h"

//definiciones previas
#define numeroDe_usuarios 6						//5+1   //numero de usuarios inscritos en la plataforma	#identificador
#define maximoDeCaracteres_nombreDeUsuario 25	//24+1  //maximo de caracteres en nombresDeUsuario
#define maximoDeCaracteres_contrasena 16		//15+1  //maximo de caracteres en contraseña
#define numeroDe_ramos 9						//8+1   //numero de ramos totales						#idenfiticador
#define maximoDeCaracteres_ramos 9				//8+1   //maximo de caracteres del codigo de ramo
#define numeroDe_secciones 25					//24+1	//numero de secciones totales					#identificador
#define maximoDeCaracteres_secciones 15			//14+1	//maximo de caracteres de nombre de secciones
#define numeroDe_documentos 49					//48+1  //numero de documentos totales					#identificador
#define maximoDeCaracteres_documentos 31		//30+1	//maximo de caracteres del nombre de documentos

//simulacion de la base de datos de la Universidad
//se colocan 5 correos de prueba y con un máximo de  30 caracteres

/*
void descargaDeArchivos(int cantidad_numeroDe_ramos, int codigo_usuario, int ramos_usuario[][numeroDe_ramos], int secciones_por_ramo[][numeroDe_secciones], int documentos_por_seccion[][numeroDe_documentos], char nombre_documentos[][maximoDeCaracteres_documentos]);

*/



char nombreDeUsuario[numeroDe_usuarios][maximoDeCaracteres_nombreDeUsuario] ={
	{'m','.','c','a','n','a','r','i','o','0','1','@','u','f','r','o','m','a','i','l','.','c','l'},	//m.canario01@ufromail.cl //usuario 1
	{'l','.','h','e','y','e','r','@','u','f','r','o','m','a','i','l','.','c','l'},					//l.heyer01@ufromail.cl   //usuario 2
	{'e','.','r','e','y','e','s','0','8','@','u','f','r','o','m','a','i','l','.','c','l'},			//e.reyes08@ufromail.cl   //usuario 3
	{'i','.','p','i','u','c','o','l','0','1','@','u','f','r','o','m','a','i','l','.','c','l'}, 		//i.piucol01@ufromail.cl  //usuario 4
	{'f','.','a','l','v','a','r','e','z','1','1','@','u','f','r','o','m','a','i','l','.','c','l'}		//f.alvarez11@ufromail.cl //usuario 5
};

//se declaran 5 contraseñas correspondientes a los 5 correos de prueba
char contrasena[numeroDe_usuarios][maximoDeCaracteres_contrasena] = {
	{'1','2','3','4','5','6','7'},   //usuario 1 //contraseña 1 //m.canario01@ufromail.cl  //1234567
	{'h','o','l','a','.','a'},       //usuario 2 //contraseña 2 //l.heyer@ufromail.cl      //hola.a
	{'p','a','p','a','r','e','d'},   //usuario 3 //contraseña 3 //e.reyes08@ufromail.cl    //papared
	{'m','a','r','c','o','s','s'},   //usuario 4 //contraseña 4 //i.piucol01@ufromail.cl   //marcoss
	{'a','a','a','a','a','a','a'},   //usuario 5 //contraseña 5 //f.alvarez11@ufromail.cl  //aaaaaaa
};


// ramos en cual el usuario participa, cada liena coresponde a los ramos de un usuario
int ramos_usuario[numeroDe_usuarios][numeroDe_ramos] = {  //el orden en que estan determina a que usuario corresponde, cada ramo tiene un numero asignado para idenfiticadorlo, con el numero final 0 como un codigo que indica que ya no tiene mas ramos inscritos
	{1,2,3,4,5,6,7,8},   //ramos usuario 1
	{1,2,3,5,6,7,8},     //ramos usuario 2
	{2,3},               //ramos usuario 3
	{2,3,6,7},           //ramos usuario 4
	{1,2,3,4,5},         //ramos usuario 5
};


char ramos[numeroDe_ramos][maximoDeCaracteres_ramos] = {
	{'I','C','F','0','2','5','-','2'}, //IFM025-2 //Fundamentos de física
	{'I','C','C','2','0','2','-','5'}, //ICC202-5 //Programacion de computadores
	{'D','F','I','1','0','0','-','2'}, //DFI100-2 //Herramientas de la comunicación
	{'E','D','O','3','0','2','-','2'}, //EDO302-2 //Ecuaciones Diferenciales
	{'I','C','F','0','5','8','-','4'}, //ICF058-4 //Fisica 1
	{'I','M','E','0','5','6','-','0'}, //IME056-0 //Algebra Lineal
	{'I','C','F','1','4','1','-','1'}, //ICF141-1 //Fisica aplicada
	{'D','F','I','1','0','2','-','1'}, //DFI102-1 //Competencia para la vida universitaria
};

//matrices de secciones por ramo
int secciones_por_ramo[numeroDe_ramos][3] = {
	{1,2,3},
	{4,5,6},
	{7,8,9},
	{10,11,12},
	{13,14,15},
	{16,17,18},
	{19,20,21},
	{22,23,24},
};

char nombre_secciones[numeroDe_secciones][maximoDeCaracteres_secciones] = {
	//secciones ramo 1
	{'i','n','i','c','i','o'},						//seccion 1
	{'s','e','m','a','n','a','s'},				//seccion 2
	{'p','a','u','t','a','s'},						//seccion 3

	//secciones ramo 2
	{'i','n','i','c','i','o'},						//seccion 4
	{'s','e','m','a','n','a','s'},				//seccion 5
	{'m','.','s','u','p','l','e','n','t','a','l'},	//seccion 6

	//secciones ramo 3
	{'i','n','i','c','i','o'},						//seccion 7
	{'s','e','m','a','n','a','s'},				//seccion 8
	{'t','a','r','e','a','s'},						//seccion 9

	//secciones ramo 4
	{'i','n','i','c','i','o'},						//seccion 10
	{'s','e','m','a','n','a','s'},				//seccion 11
	{'a','p','o','y','o','s'},						//seccion 12

	//secciones ramo 5
	{'i','n','i','c','i','o'},						//seccion 13
	{'s','e','m','a','n','a','s'},				//seccion 14
	{'m','.','s','u','p','l','e','n','t','a','l'},	//seccion 15

	//secciones ramo 6
	{'i','n','i','c','i','o'},						//seccion 16
	{'s','e','m','a','n','a','s'},				//seccion 17
	{'t','a','r','e','a','s'},						//seccion 18

	//secciones ramo 7
	{'i','n','i','c','i','o'},						//seccion 19
	{'s','e','m','a','n','a','s'},				//seccion 20
	{'p','p','t','s'},								    //seccion 21

	//secciones ramo 8
	{'i','n','i','c','i','o'},						//seccion 22
	{'s','e','m','a','n','a','s'},				//seccion 23
	{'p','r','u','e','b','a'},						//seccion 24
};

int documentos_por_seccion[numeroDe_secciones][2] = {
	{1,2},
	{3,4},
	{5,6},
	{7,8},
	{9,10},
	{11,12},
	{13,14},
	{15,16},
	{17,18},
	{19,20},
	{21,22},
	{23,24},
	{25,26},
	{27,28},
	{29,30},
	{31,32},
	{33,34},
	{35,36},
	{37,38},
	{39,40},
	{41,42},
	{43,44},
	{45,46},
	{47,48},
};

char nombre_documentos[numeroDe_documentos][maximoDeCaracteres_documentos] = {
	//secciones ramo 1
		//documentos seccion 1
		{'o','b','j','e','t','i','v','o',' ','d','e','l',' ','c','u','r','s','o','.','d','c','x'},
		{'l','i','n','k',' ','d','e',' ','z','o','o','m','.','d','c','x'},
	
		//documentos seccion 
		{'g','u','i','a',' ','t','r','i','g','o','n','o','m','e','t','r','i','a',' ','1','.','p','d','f'},
		{'g','u','i','a',' ','t','r','i','g','o','n','o','m','e','t','r','i','a',' ','2','.','p','d','f'},

		//documentos seccion 
		{'c','o','n','t','r','o','l',' ','1','.','p','d','f'},
		{'p','r','u','e','b','a',' ','1','.','p','d','f'},




	//secciones ramo 2
		//documentos seccion 
		{'r','e','g','l','a','m','e','n','t','o',' ','d','e','l',' ','r','a','m','o','.','d','c','x'},
		{'-','-'},
	
		//documentos seccion 
		{'c','o','n','t','r','o','l',' ','1','.','p','d','f'},
		{'c','o','n','t','r','o','l',' ','2','.','p','d','f'},

		//documentos seccion 
		{'l','i','b','r','o',' ','d','e',' ','a','r','d','u','i','n','o','.','t','x','t'},
		{'l','i','n','k','s',' ','d','e',' ','y','o','u','t','u','b','e','.','t','x','t'},
		



//secciones ramo 3
	//documentos seccion 
	{'N','o','v','e','d','a','d','e','s','.','d','c','x'},
	{'-','-'},
	
	//documentos seccion 
	{'p','r','e','s','e','n','t','a','c','i','o','n',' ','1','.','p','p','t'},
	{'p','r','e','s','e','n','t','a','c','i','o','n',' ','2','.','p','p','t'},
	
	//documentos seccion 
	{'p','a','u','t','a',' ','t','a','r','e','a',' ','1','.','p','d','f'},
	{'p','a','u','t','a',' ','t','a','r','e','a',' ','2','.','p','d','f'},
	


//secciones ramo 4
	//documentos seccion 
	{'c','a','l','e','n','d','a','r','i','o','.','d','c','x'},
	{'e','v','e','n','t','o','s','.','d','c','x'},
	
	//documentos seccion 
	{'t','e','m','a','r','i','o',' ','s','e','m','a','n','a','1','.','d','c','x'},
	{'t','e','m','a','r','i','o',' ','s','e','m','a','n','a','2','.','d','c','x'},
	
	//documentos seccion 
	{'l','i','b','r','o',' ','d','e',' ','a','l','g','b','r','a','1','.','p','d','f'},
	{'l','i','b','r','o',' ','d','e',' ','a','l','g','b','r','a','2','.','p','d','f'},
	
	
//secciones ramo 5
	//documentos seccion 
	{'s','a','l','a',' ','d','e',' ','z','o','o','m','.','t','x','t'},
	{'-','-'},
	
	//documentos seccion 
	{'r','e','t','r','o',' ','a','l','i','m','e','n','t','a','c','i','o','n',' ','1','.','p','p','t'},
	{'r','e','t','r','o',' ','a','l','i','m','e','n','t','a','c','i','o','n',' ','2','.','p','p','t'},
	
	//documentos seccion 
	{'l','i','s','t','a',' ','d','e',' ','a','p','p','s',' ','d','e',' ','a','p','o','y','o','.','t','e','x','t'},
	{'-','-'},
	
	
	
//secciones ramo 6
	//documentos seccion 
	{'g','r','a','b','a','c','i','o','n','e','s',' ','d','e',' ','c','l','a','s','e','s','.','t','x','t'},
	{'-','-'},
	
	//documentos seccion 
	{'c','l','a','s','e',' ','1','.','p','p','t'},
	{'c','l','a','s','e',' ','2','.','p','p','t'},
	
	//documentos seccion 
	{'t','a','l','l','e','r',' ','1','.','p','d','f'},
	{'t','a','l','l','e','r',' ','1','.','p','d','f'},
	
	
	
//secciones ramo 7
	//documentos seccion 
	{'m','e','t','o','d','o','l','o','g','i','a','.','d','c','x'},
	{'n','o','t','a','s','.','d','c','x'},
	
	//documentos seccion 
	{'g','u','i','a',' ','s','e','m','a','n','a',' ','1'},
	{'g','u','i','a',' ','s','e','m','a','n','a',' ','2'},
	
	//documentos seccion 
	{'p','o','w','e','r',' ','p','o','i','n','t',' ','1','.','p','p','t'},
	{'p','o','w','e','r',' ','p','o','i','n','t',' ','2','.','p','p','t'},
	
	
	
//secciones ramo 8
	//documentos seccion 
	{'c','a','l','e','n','d','a','r','i','o','.','d','c','x'},
	{'n','o','t','a','s','.','x','l','s','x'},
	
	//documentos seccion 
	{'g','u','i','a',' ','s','e','m','a','n','a',' ','1','.','d','c','x'},
	{'g','u','i','a',' ','s','e','m','a','n','a',' ','2','.','d','c','x'},
	
	//documentos seccion 
	{'p','a','u','t','a',' ','d','e',' ','p','r','u','e','b','a',' ','1','.','p','d','f'},
	{'p','a','u','t','a',' ','d','e',' ','p','r','u','e','b','a',' ','2','.','p','d','f'},
};


int main(){

	titulo();

	printf("Ingreso a la plataforma...\n\n");

	//ingreso usuario y contraseña
	
	//creamos booleanos para comprobar si nombreDeUsuario existe en la base de datos
	bool verificado = 0;
	/*VERIFICACION USUARIO/CONTRASEÑA
	
	se le envía al servidor los datos de usuario y contraseña para su verificación posterior en la base de datos del servidor
	esto lo haremos de forma local por las limitaciones del programa, comprobando con el numero de fila de cada matriz, siendo el
	numero de fila el "identificador" de dato de usuario:
	el nombre de usuario de la fila "n", se corresponde con la contraseña de la fila "n"
	*/
	
	//variable para identificar el usuario que está ingresando al sistema
	int codigo_usuario;
	//ciclo do-while para pedir nombre de usuario y contraseña

	do{

		//ARREGLOS DE VERIFICACIÓN
		char check_nombreDeUsuario [maximoDeCaracteres_nombreDeUsuario];// /este areglo es para compravar si la el nombre de usuario existe en la base de dato
		char check_contrasena [maximoDeCaracteres_contrasena];//este areglo es para compravar si la contraseña existe en la base de dato
		ingresoDeDatos(check_nombreDeUsuario, check_contrasena);

		/*
		ingresoDeDatos(check_nombreDeUsuario, check_contrasena);
		*/

		//ciclo for que verifica los datos ingresados con las matrices, pasando de fila en fila N numero de veces, siendo N la cantidad de usuarios que existen en la matriz

		verificado = verificacion(codigo_usuario, numeroDe_usuarios, check_nombreDeUsuario, nombreDeUsuario , check_contrasena, contrasena);
		
		if(verificado == 0){
			printf("\nUsuario o contraseña no validos, ingrese nuevamente.\n\n");
		}
		//el ciclo para pedir datos al usuario se repite hasta que se ingresen datos que correspondan a alguna de las entradas de la matriz
	}while(verificado == 0);
	


	//
	if(verificado == 1){

		int cantidad_numeroDe_ramos = calculoRamosUsuario(ramos_usuario, codigo_usuario);

		printf("Ramos para el usuario %s:\n", nombreDeUsuario[codigo_usuario]);
		
		imprimirRamos(ramos, ramos_usuario, codigo_usuario, cantidad_numeroDe_ramos);

		printf("\n\nDESCARGANDO ARCHIVOS...\n\n");
	
		//DESCARGA DE ARCHIVOS
		
		descargaDeArchivos(nombreDeUsuario, cantidad_numeroDe_ramos, codigo_usuario, ramos_usuario, secciones_por_ramo, documentos_por_seccion, ramos, nombre_secciones, nombre_documentos);
		
	}
	return 0;
}


