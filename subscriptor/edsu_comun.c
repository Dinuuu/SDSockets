/*
 Incluya en este fichero todas las implementaciones que pueden
 necesitar compartir los módulos editor y subscriptor,
 si es que las hubiera.
 */

#include "edsu_comun.h"
#include "comun.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

intermediario* getIntermediario() {

	intermediario* resp = malloc(sizeof(intermediario));
	resp->servidor = getenv("SERVIDOR");
	char* puerto = getenv("PUERTO");
	resp->puerto = atoi(puerto);
	return resp;
}

int conectarIntermediario() {

	struct hostent *host_info;
	intermediario* inter = getIntermediario();
	struct sockaddr_in dir;
	int s;
	host_info = gethostbyname(inter->servidor);
	memcpy(&dir.sin_addr.s_addr, host_info->h_addr, host_info->h_length);
	dir.sin_port = htons(inter->puerto);
	dir.sin_family = PF_INET;

	if ((s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		perror("error creando socket");
		free(inter);
		return -1;
	}

	if (connect(s, (struct sockaddr *) &dir, sizeof(dir)) < 0) {
		perror("error en connect");
		close(s);
		free(inter);
		return -1;
	}
	free(inter);
	return s;
}

int enviarMensaje(int opt, ...) {

	int longitud = 0;
	int rpta;
	char* mensaje = NULL;
	int s;
	int i;
	if ((s = conectarIntermediario()) < 0) {
		return s;
	}

	va_list ap;
	va_start(ap, opt);
	char** argumento = NULL;
	int argumentos;

	switch (opt) {
	case MENSAJE:
		argumentos = 2;
		break;
	case BAJA:
		argumentos = 1;
		break;
	case ALTA:
		argumentos = 1;
		break;
	}
	argumento = malloc(argumentos * sizeof(char*));
	for (i = 0; i < argumentos; i++) {
		argumento = va_arg(ap,char*);
	}

	mensaje = marshallMsg(opt, argumento, argumentos, &longitud);

	if (write(s, mensaje, longitud) < 0) {
		perror("error en write");
		close(s);
		free(mensaje);
		return -1;
	}

	//TODO PREGUNTAR COMO HACER CON LA RESPUESTA!!

	close(s);
	free(mensaje);
	return rpta;

}
