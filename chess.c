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
	if(board->node == NULL)
		return board;
	if(board->node->data == NULL){
		free(board->node);
		return board;
	}
	
	((move*)board->node->data)->src = 0;
	((move*)board->node->data)->trg = 0;
	((move*)board->node->data)->cost = 0;
	((move*)board->node->data)->change = 0;
	
	//Initialization of all pieces
	for(i = 0; i < 8; i++){
		figinit(board->white[i], CPAWN, PAWN, A2+i, PM, CFALSE);
		ch_figure_init(board->black[i], CBLACK_PAWN, BLACK_PAWN, A7+i, PM, CFALSE);
	}
	ch_figure_init(board->white[8], CROOK, ROOK, A1, VH, CTRUE);
	ch_figure_init(board->white[9], CROOK, ROOK, H1, VH, CTRUE);
	ch_figure_init(board->black[8], CBLACK_ROOK, BLACK_ROOK, A8, VH, CTRUE);
	ch_figure_init(board->black[9], CBLACK_ROOK, BLACK_ROOK, H8, VH, CTRUE);
	ch_figure_init(board->white[10], CKNIGHT, KNIGHT, B1, KM, CFALSE);
	ch_figure_init(board->white[11], CKNIGHT, KNIGHT, G1, KM, CFALSE);
	ch_figure_init(board->black[10], CBLACK_KNIGHT, BLACK_KNIGHT, B8, KM, CFALSE);
	ch_figure_init(board->black[11], CBLACK_KNIGHT, BLACK_KNIGHT, G8, KM, CFALSE);
	ch_figure_init(board->white[12], CBISHOP, BISHOP, C1, DIAG, CTRUE);
	ch_figure_init(board->white[13], CBISHOP, BISHOP, F1, DIAG, CTRUE);
	ch_figure_init(board->black[12], CBLACK_BISHOP, BLACK_BISHOP, C8, DIAG, CTRUE);
	ch_figure_init(board->black[13], CBLACK_BISHOP, BLACK_BISHOP, CF8, CDIAG, CTRUE);
	ch_figure_init(board->white[14], CQUEEN, QUEEN, D1, DIAG|VH, CTRUE);
	ch_figure_init(board->white[15], CKING, KING, E1, DIAG|VH, CFALSE);
	ch_figure_init(board->black[14], CBLACK_QUEEN, BLACK_QUEEN, D8, DIAG|VH, CTRUE);
	ch_figure_init(board->black[15], CBLACK_KING, BLACK_KING, E8, DIAG|VH, CFALSE);
	
	}
}
