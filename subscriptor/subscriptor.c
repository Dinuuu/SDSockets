#include "subscriptor.h"
#include "comun.h"
#include "edsu_comun.h"
#include <stdio.h>
#include <stdlib.h>

int alta_subscripcion_tema(const char *tema) {
	return enviarMensaje(ALTA, tema);
}

int baja_subscripcion_tema(const char *tema) {
	return enviarMensaje(BAJA, tema);
}

int inicio_subscriptor(void (*notif_evento)(const char *, const char *),
		void (*alta_tema)(const char *), void (*baja_tema)(const char *)) {
	return 0;
}

int fin_subscriptor() {
	return 0;
}

static void notificacion_evento(const char *t, const char *e) {
	printf("\n-> Recibido evento %s con valor %s\n", t, e);
}

int int main(int argc, char **argv) {

	inicio_subscriptor(notificacion_evento, NULL, NULL );
}
