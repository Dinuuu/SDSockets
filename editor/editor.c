#include "editor.h"
#include "comun.h"
#include "edsu_comun.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int generar_evento(const char *tema, const char *valor) {

	return enviarMensaje(MENSAJE, tema, valor);
}

