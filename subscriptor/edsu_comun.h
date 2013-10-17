/*
 Incluya en este fichero todas las definiciones que pueden
 necesitar compartir los módulos editor y subscriptor,
 si es que las hubiera.
 */

typedef struct intermediario {
	char* servidor;
	int puerto;
} intermediario;

int conectarIntermediario();

int enviarMensaje(int opt, ...);

