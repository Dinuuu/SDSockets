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

int conectarIntermediario() {

	struct hostent *host_info;
	char* servidor = getenv("SERVIDOR");
	char* puerto = getenv("PUERTO");
	struct sockaddr_in dir;
	int s;
	host_info = gethostbyname(servidor);
	memcpy(&dir.sin_addr.s_addr, host_info->h_addr, host_info->h_length);
	dir.sin_port = htons(atoi(puerto));

	dir.sin_family = PF_INET;

	if ((s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		perror("error creando socket");
		return -1;
	}

	if (connect(s, (struct sockaddr *) &dir, sizeof(dir)) < 0) {
		perror("error en connect");
		close(s);
		return -1;
	}
	return s;
}

int enviarMensaje(int opt, ...) {

	int longitud = 0;
	int rpta = 0;
	char buf[5];
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
	case ALTA:
	case CREAR:
	case ELIMINAR:
		argumentos = 1;
		break;
	case INICIO:
	case APAGADO:
		argumentos = 0;
		break;
	}

	argumento = malloc(argumentos * sizeof(char*));
	for (i = 0; i < argumentos; i++) {
		argumento[i] = (char*) va_arg(ap,char*);
	}
	int puerto;
	if (opt == BAJA || opt == ALTA || opt == APAGADO || opt == INICIO) {
		puerto = va_arg(ap,int);
		char* numero = malloc(sizeof(int) + sizeof(char));
		memcpy((void*) numero, (void*) &puerto, sizeof(int));
		numero[sizeof(int)] = 0;
		argumento[argumentos] = numero;
	}

	mensaje = marshallMsg(opt, argumento, argumentos, &longitud);

	if (write(s, mensaje, longitud) < 0) {
		perror("error en write");
		close(s);
		free(mensaje);
		return -1;
	}
	shutdown(s, SHUT_WR);
	int leido = 0;
	if ((leido = read(s, buf, TAMANIO_RESPUESTA)) < 0) {
		perror("Error en read de respuesta");
	}

	memcpy((void *) &rpta, (void*) buf, sizeof(int));
	close(s);
	free(mensaje);
	return rpta;

}
