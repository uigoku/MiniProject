CC=gcc
TARGET=project
SRC=main.c chess.c io.c gen.c tree.c
OBJ=main.o chess.o io.o gen.o tree.o
CFLAGS=-g -Wall# -DDEBUG
#LIBS=-lefence

all:$(TARGET)

$(TARGET):$(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBS)

.SUFFIXES:.c.o
.c.o:
	$(CC) -c $(CFLAGS) $<
	
main.o:main.c chess.h
chess.o:chess.c chess.h defs.h gen.c gen.h
draggen.o:gen.c gen.h tree.c tree.h io.h
io.o:io.c io.h
tree.o:tree.c tree.h

rebuild:clean $(TARGET)

clean:
	-rm *.o $(TARGET)
