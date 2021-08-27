
/*
* Nombre de la función: calculoRamosUsuario.
* Tipo de función: int.
* Parámetros: 	"ramos" de tipo int. (matrix)
*				“usuario” de tipo int.
* Dato de retorno: “cantidad_numeroDe_usuario" de tipo int.
* Descripción de la función: 	La funcion obtiene el código del usuario para obtener la cantidad
								de ramos que éste tiene inscritos y retornar dicho valor.
*/

int calculoRamosUsuario( int ramos[][9], int usuario);




/*
* Nombre de la función: imprimirRamos.
* Tipo de función: void.
* Parámetros: 	“a” de tipo int.
*				“b” de tipo int.
* Dato de retorno: “resultado” de tipo int;
* Descripción de la función: 	La función suma() pide dos parámetros de tipo
* 								entero para sumarlos y devolver el resultado
*								al programa principal a través de la variable
*								resultado.
*/

void imprimirRamos(char nombreRamos[][9], int ramos[][9], int usuario, int cantidad);




/*
* Nombre de la función: descargaDeArchivos.
* Tipo de función: void.
* Parámetros: 	"cantidad_numeroDe_ramos" de tipo int 
				"codigo_usuario" de tipo int
				"ramos_usuario" de tipo int (matriz)
				"secciones_por_ramo" de tipo int (matriz)
				"documentos_por_seccion" de tipo int (matriz)
				"ramos" de tipo chat (matriz)
				"nombre_secciones" de tipo chat (matriz)
				"nombre_documentos" de tipo chat (matriz)
* Dato de retorno: ninguno, crea todos los archivos.
* Descripción de la función: 	Esta función descarga los archivos según el usuario que haya ingresado
								y los ordena dependiendo de los ramos que éste tenga inscrito en 
								secciones y subsecciones.
*/

void descargaDeArchivos(char nombreDeUsuario[][25], int cantidad_numeroDe_ramos, int codigo_usuario, int ramos_usuario[][9], int secciones_por_ramo[][3], int documentos_por_seccion[][2], char ramos[][9], char nombre_secciones[][15], char nombre_documentos[][31]);
