#Archivo Makefile simple	
#Explicacion: Podemos cambiar la lista de archivos fuente .C en una lista de archivos objeto remplazando el sufijo ".C" con ".o".
PROYECTO=principal
OBJECTS:=$(patsubst %.c,%.o,$(wildcard *.c))
DESTDIR=/usr/local/bin
CFLAGS=-Wall
LFLAGS=-lm
CC=gcc

all: $(PROYECTO)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

#$(PROYECTO): muestreo.o archivos.o procesamiento.o
#Se reemplaza la linea anterior con la siguiente
$(PROYECTO): ${OBJECTS}
	$(CC) $^ -o $@ $(LFLAGS)

.PHONY: clean 

install: all
	if [ ! -d $(DESTDIR) ]; then \
		sudo mkdir $(DESTDIR); \
	fi; \
	sudo cp $(PROYECTO) $(DESTDIR)
unistall:
	sudo rm $(DESTDIR)/$(PROYECTO)
clean:
	rm -f *.o $(PROYECTO) *.dat
