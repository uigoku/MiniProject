#include<stdio.h>

#include"io.h"
#include"chess.h"
#include"gen.h"

char movestr[MAXMOV + 1];

char *getmove(char *src, char *trg);

void printbfp(ch_board* board){
	
	int i = 0, j = 0;

	cerror = NOERR;

	if(board == NULL){
		cerror = POINTERNULL;
		return;
	}

	//printing chessboard
	printf("\nCounter: %d\n", board->move);
	printf("    a    b    c    d    e    f    g    h\n");
	printf("-------------------------------------------\n");
	for(j = 90; j > 10; j -= 10){
		printf("%d|", (j/10) - 1);
		for(i = 1; i < 9; i++)
			(board->board[j+i].figure != NULL) ?
				printf("%3d |", (int)board->board[j+i].figure->type) :
				printf("    |");
		printf("%d\n", (j/10) -1);
		printf("-------------------------------------------\n");
	}
	printf("    a    b    c    d    e    f    g    h\n");
}

extern void printmoves(cboard* board){
	
}

extern void printerror(void){
	if(cerror == ENDOF) {
		cerror = NOERR;
		return;
	}

	printf("ERROR: ");
	switch(cerror) {
		case NOMEM:
			printf("can not allocate enough memmory\n");
			break;
		case POINTERNULL:
			printf("reference pointer is null\n");
			break;
		case ILLEGAL:
			printf("illegal move\n");
			break;
		default:
			printf("no errors\n");
			break;
	}
}

extern void printcentable(cboard *board){
	int i = 0, j = 0;

	cerror = NOERR;
	if(board == NULL){
		cerror = POINTERNULL;
		return;
	}

	putchar('\n');
	for(j = 90; j > 10; j -= 10){
		for(i = 1; i < 9; i++)
			printf("%2d", (int)board->board[j+i].value);
		putchar('\n');
	}
	putchar('\n');
}

extern void printfigval(cboard *board){
	int i = 0, j = 0;

	cerror = NOERR;
	if(board == NULL){
		cerror = POINTERNULL;
		return;
	}

	putchar('\n');
	for(j = 90; j > 10; j -= 10){
		for(i = 1; i < 9; i++)
			(board->board[j+i].figure != NULL) ?
				printf("%5d", (int)board->board[j+i].figure->value) :
				printf("     ");
		putchar('\n');
	}
	putchar('\n');
}

extern void figprint(cboard *board){
	
}
