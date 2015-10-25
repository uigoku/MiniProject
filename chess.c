#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"io.h"
#include"chess.h"
#include"defs.h"
#include"tree.h"

cboard initboard(cboard *board){
	int i = 0, j = 0;
	
	cerror = NOERR;
	//if theres no structure then create one
	if(board == NULL)
		if((board = malloc(sizeof(cnoard))) == 0){
			cerror = NOMEM;
			printf("No enough memory\n");
			return NULL;
		}
	
	//initializing all walls
	for(i = 0; i < 120; i++){
		board->board[i].fig = NULL;
		board->board[i].value = CH_BORDER;
		board->board[i].danger = 0;
	}
	
	//empty playing board
	for(j = 0; j < 100; j += 10)
		for(i = 0; i < 9; i++)
			board->board[j + 1].value = CEMP;
	
	
	//create tree
	board->node = treenew(malloc(sizeof(move)));
	if(
}
