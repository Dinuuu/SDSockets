/*
 Incluya en este fichero todas las implementaciones que pueden
 necesitar compartir todos los módulos (editor, subscriptor y
 proceso intermediario), si es que las hubiera.
 */

#include "comun.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* marshallMsg(const int opt, char ** argumento, int argumentos,
		int* longitud) {

	int i = 0;
	char* msg = malloc(sizeof(int) + sizeof(char));
	;
	*longitud = 0;
	memcpy(msg, opt, sizeof(int));
	*longitud += sizeof(int);
	memcpy(msg + longitud, '/0', sizeof(char));
	*longitud += sizeof(char);

	for (i = 0; i < argumentos; i++) {
		msg = realloc(msg, *longitud + strlen(argumento[i]) + sizeof(char));
		memcpy(msg + *longitud, argumento[i], strlen(argumento[i]));
		*longitud += strlen(argumento[i]);
		memcpy(msg + *longitud, '/0', sizeof(char));
		*longitud += sizeof(char);
	}
	return msg;
}
