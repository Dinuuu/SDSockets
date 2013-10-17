CFLAGS=-Wall

all: test_editor

edsu_comun.o: edsu_comun.h

comun.o: comun.h

editor.o: comun.h editor.h edsu_comun.h

test_editor.o: editor.h

test_editor: test_editor.o editor.o edsu_comun.o comun.o
	$(CC) -o $@ test_editor.o editor.o edsu_comun.o comun.o -lpthread

clean:
	rm *.o test_editor
