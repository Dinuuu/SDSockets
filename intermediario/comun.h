/*
 Incluya en este fichero todas las definiciones que pueden
 necesitar compartir todos los módulos (editor, subscriptor y
 proceso intermediario), si es que las hubiera.
 */

#define BLOQUE 5
#define TAM 64
#define MAX_LISTEN 64
#define TAMANIO_RESPUESTA sizeof(int)+sizeof(char)
#define ALTA 1
#define BAJA 2
#define MENSAJE 3
#define APAGADO 4
#define CREAR 5
#define ELIMINAR 6
#define INICIO 7
typedef struct notificacion {
	int opt;
	char* tema;
	char* mensaje;
	int puerto;
	struct sockaddr_in * cliente;
} notificacion;

typedef notificacion * notif;

char* marshallMsg(const int opt, char ** argumento, int argumentos,
		int * longitud);

notif unMarshallMsg(char* mensaje);
