#########################################
CC     = gcc
##CFLAGS = -I../../include   -pthread -O2 -Wall
CFLAGS = -I../include -pthread -O1
LIB       = ../lib/x11/libglfw.a
LFLAGS    = $(LIB) -lrt -lX11 -lGLU -lGL -pthread -lm
## -lXrandr

all: rain

rain: rain.o cfonts.o fonttex.o
	gcc $(CFLAGS) rain.o cfonts.o fonttex.o $(LFLAGS) -o rain

rain.o: rain.c
	gcc $(CFLAGS) -c rain.c
	
cfonts.o: cfonts.c
	gcc $(CFLAGS) -c cfonts.c

fonttex.o:
	gcc $(CFLAGS) -c fonttex.c $(LFLAGS)

clean:
	rm -f rain
	rm -f rain.o

