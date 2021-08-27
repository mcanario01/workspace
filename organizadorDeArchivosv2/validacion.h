
/*
* Nombre de la función: titulo.
* Tipo de función: void.
* Parámetros: 	ninguno.
* Dato de retorno: ninguno
* Descripción de la función: 	Esta función imprime el titulo del programa por la consola.
*/

void titulo();



/*
* Nombre de la función: ingresoDeDatos.
* Tipo de función: void.
* Parámetros: 	"x" de tipo char. (puntero)
*				"y" de tipo char. (puntero)
* Dato de retorno: ninguno, modifica vectores a travez de punteros;
* Descripción de la función: 	Esta función imprime por pantalla las indicaciones para
*								que el usuario introduzca sus datos de usuario y contraseña.
*/

void ingresoDeDatos(char *x, char *y);




/*
* Nombre de la función: verificacion.
* Tipo de función: int.
* Parámetros: 	"&codigo_usr" de tipo int (direccion de memoria)
*				"iteraciones" de tipo int
				"usuario"	 de tipo char (vector)
				"usuarioDB"	de tipo char (matriz)
				"contra" de tipo char (vector)
				"contraDB" de tipo char (matriz)
* Dato de retorno: "verificado" de tipo int.
* Descripción de la función: 	Esta funcion obtiene los parametros introducidos por el usuario
								para compararlos con los datos de la base de datos y verificarlos
								positivamente o negativamente dependiendo de la validez de éstos.
*/

int verificacion(int &codigo_usr, int iteraciones, char usuario[], char usuarioDB[][25], char contra[], char contraDB[][16]);



