#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct suscriptor {

//Aca va la informacion para conectarse

} suscriptor;

typedef suscriptor * suscript;

typedef struct tema {
	char * tema;
	int cantSuscript;
	suscript * suscriptores;
} tema;

typedef struct lista_temas {
	tema** temas;
	int cant_temas;
} lista_temas;

#define BLOQUE 5
void imprimir_temas(const lista_temas* temas);
void imprimir_tema(const tema* tema);
lista_temas* inicializar_temas(const char* archivo);
tema* crear_tema(const char* tematica);
int agregar_tema(lista_temas* temas, const char* tematica);

lista_temas* inicializar_temas(const char* archivo) {

	lista_temas* resp = malloc(sizeof(lista_temas));
	resp->cant_temas = 0;
	resp->temas = NULL;

	FILE* file = fopen(archivo, "r");
	char* tematica = NULL;
	int longitud = 0;
	int c;
	while ((c = getc(file)) != -1) {
		if (c == '\n') {
			tematica[longitud] = '\0';

			agregar_tema(resp, tematica);

			longitud = 0;
		} else {
			if (longitud % BLOQUE == 0)
				tematica = realloc(tematica,
						(longitud + BLOQUE) * sizeof(char));
			tematica[longitud++] = c;
		}

	}
	free(tematica);
	fclose(file);
	return resp;
}

int agregar_tema(lista_temas* temas, const char* tematica) {
	if (temas->cant_temas % BLOQUE == 0) {
		temas->temas = realloc(temas->temas,
				(temas->cant_temas + BLOQUE) * sizeof(tema*));
	}

	temas->temas[temas->cant_temas] = crear_tema(tematica);
	temas->cant_temas++;

	return 1;
}

tema* crear_tema(const char* tematica) {

	tema * resp = malloc(sizeof(tema));
	resp->cantSuscript = 0;
	resp->suscriptores = malloc(sizeof(suscript *));
	resp->tema = NULL;
	int i = 0;
	while (tematica[i] != '\0') {
		if (i % BLOQUE == 0)
			resp->tema = realloc(resp->tema, (i + BLOQUE) * sizeof(char));
		resp->tema[i] = tematica[i];
		i++;
	}
	resp->tema[i] = '\0';
	return resp;
}

void imprimir_temas(const lista_temas* temas) {
	int i = 0;
	printf("Hay %d temas disponibles \n", temas->cant_temas);
	for (i = 0; i < temas->cant_temas; i++) {
		imprimir_tema(temas->temas[i]);
	}
}

void imprimir_tema(const tema* tema) {
	printf("El nombre del tema es %s y hay %d procesos suscriptos \n",
			tema->tema, tema->cantSuscript);

}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Uso: %s puerto fichero_temas\n", argv[0]);
		return 1;
	}
	char * port = argv[1];
	char* archivo = argv[2];
	lista_temas* listaTemas = inicializar_temas(archivo);
	imprimir_temas(listaTemas);
	return 0;
}
