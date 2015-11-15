project:chess.o gen.o io.o main.o tree.o
	cc main.o gen.o io.o tree.o -o project

main.o:main.c chess.h
	cc -c main.c

chess.o:chess.c chess.h defs.h gen.c gen.h
	cc -c chess.c
	cc -c gen.c

gen.o:gen.c gen.h tree.c tree.h io.h
	cc -c gen.c
	cc -c tree.c

io.o:io.c io.h
	cc -c io.c

tree.o:tree.c tree.h
	cc -c tree.c

clean:
	rm *.o
