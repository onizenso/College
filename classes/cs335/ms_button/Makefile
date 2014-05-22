CFLAGS = -pthread -O1
LIB    = libglfw.a
LFLAGS = $(LIB) -lrt -lX11 -lGLU -lGL -pthread -lm #-lXrandr

all: ms_button

ms_button: ms_button.o cfonts.o fonttex.o log.o libglfw.a
	gcc ms_button.o cfonts.o fonttex.o log.o $(LFLAGS) -o ms_button

ms_button.o: ms_button.c
	gcc -c $(CFLAGS) ms_button.c

cfonts.o: cfonts.c
	gcc -c $(CFLAGS) cfonts.c

fonttex.o: fonttex.c
	gcc -c $(CFLAGS) fonttex.c

log.o: log.c
	gcc -c $(CFLAGS) log.c

clean:
	rm -f ms_button
	rm -f *.o

