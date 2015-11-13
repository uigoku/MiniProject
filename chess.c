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
		figinit(board->black[i], CBLACK_PAWN, BLACK_PAWN, A7+i, PM, CFALSE);
	}
	figinit(board->white[8], CROOK, ROOK, A1, VH, CTRUE);
	figinit(board->white[9], CROOK, ROOK, H1, VH, CTRUE);
	figinit(board->black[8], CBLACK_ROOK, BLACK_ROOK, A8, VH, CTRUE);
	figinit(board->black[9], CBLACK_ROOK, BLACK_ROOK, H8, VH, CTRUE);
	figinit(board->white[10], CKNIGHT, KNIGHT, B1, KM, CFALSE);
	figinit(board->white[11], CKNIGHT, KNIGHT, G1, KM, CFALSE);
	figinit(board->black[10], CBLACK_KNIGHT, BLACK_KNIGHT, B8, KM, CFALSE);
	figinit(board->black[11], CBLACK_KNIGHT, BLACK_KNIGHT, G8, KM, CFALSE);
	figinit(board->white[12], CBISHOP, BISHOP, C1, DIAG, CTRUE);
	figinit(board->white[13], CBISHOP, BISHOP, F1, DIAG, CTRUE);
	figinit(board->black[12], CBLACK_BISHOP, BLACK_BISHOP, C8, DIAG, CTRUE);
	figinit(board->black[13], CBLACK_BISHOP, BLACK_BISHOP, CF8, CDIAG, CTRUE);
	figinit(board->white[14], CQUEEN, QUEEN, D1, DIAG|VH, CTRUE);
	figinit(board->white[15], CKING, KING, E1, DIAG|VH, CFALSE);
	figinit(board->black[14], CBLACK_QUEEN, BLACK_QUEEN, D8, DIAG|VH, CTRUE);
	figinit(board->black[15], CBLACK_KING, BLACK_KING, E8, DIAG|VH, CFALSE);
	
	}
	
	//init figures
	for(i = 0; i < 16; i++){
		figset(board->board, &board->white[i]);
		figset(board->board, &board->black[i]);
	}
	
	i = A1;
	board->board[i++].value = 4;
	board->board[i++].value = 0;
	board->board[i++].value = 8;
	board->board[i++].value = 12;
	board->board[i++].value = 12;
	board->board[i++].value = 8;
	board->board[i++].value = 0;
	board->board[i++].value = 4;
	i=A2;
	board->board[i++].value = 4;
	board->board[i++].value = 8;
	board->board[i++].value = 12;
	board->board[i++].value = 16;
	board->board[i++].value = 16;
	board->board[i++].value = 12;
	board->board[i++].value = 8;
	board->board[i++].value = 4;
	i=A3;
	board->board[i++].value = 8;
	board->board[i++].value = 12;
	board->board[i++].value = 16;
	board->board[i++].value = 20;
	board->board[i++].value = 20;
	board->board[i++].value = 16;
	board->board[i++].value = 12;
	board->board[i++].value = 8;
	i=A4;
	board->board[i++].value = 12;
	board->board[i++].value = 16;
	board->board[i++].value = 20;
	board->board[i++].value = 24;
	board->board[i++].value = 24;
	board->board[i++].value = 20;
	board->board[i++].value = 16;
	board->board[i++].value = 12;
	i=A5;
	board->board[i++].value = 12;
	board->board[i++].value = 16;
	board->board[i++].value = 20;
	board->board[i++].value = 24;
	board->board[i++].value = 24;
	board->board[i++].value = 20;
	board->board[i++].value = 16;
	board->board[i++].value = 12;
	i=A6;
	board->board[i++].value = 8;
	board->board[i++].value = 12;
	board->board[i++].value = 16;
	board->board[i++].value = 20;
	board->board[i++].value = 20;
	board->board[i++].value = 16;
	board->board[i++].value = 12;
	board->board[i++].value = 8;
	i=A7;
	board->board[i++].value = 4;
	board->board[i++].value = 8;
	board->board[i++].value = 12;
	board->board[i++].value = 16;
	board->board[i++].value = 16;
	board->board[i++].value = 12;
	board->board[i++].value = 8;
	board->board[i++].value = 4;
	i=A8;
	board->board[i++].value = 4;
	board->board[i++].value = 0;
	board->board[i++].value = 8;
	board->board[i++].value = 12;
	board->board[i++].value = 12;
	board->board[i++].value = 8;
	board->board[i++].value = 0;
	board->board[i++].value = 4;
	
	//initiallly nobosy has a check
	board->check = 0;
	
	//First Turn
	board->move = CWHITE;
	
	//will play as White
	board->wp = HUMAN;
	
	//black's chance
	board->bp = CPU;
	
	//Change of turn
	board->pl = board->wp;
	
	//move counted
	board->move = 1;
	
	return board;
}

//Game Over - cancles tree
void doneboard(cboard board){
	if(board == NULL)
		return;
	
	//if there's a tree
	if(board->node != NULL){
		//searches for the node
		while(board->node->root != NULL)
			board->node = board->node->root;
			
			//deletes all branches
			deltree(board->node);
			board->node == NULL;
	}
}

//Game Starts
void startgame(cboard board){
	char src = 0, trg = 0;	//used for From-To
	char *str = NULL;
	int end = 0;
	
	int found = CFALSE;
	
	if(board == NULL || board->node == NULL){
		cerror = POINTERNULL;
		return;
	}
	
	//Display Chessboard
	figprint(board);
	
	while(!end){
		found = CFALSE;
		
		if(cerror == NOERR){
			genmoves(board);
			
			gencost(board);
			
			gensubmoves(board);
			
			gendangers(board);
		}
		
		if(board->pl == HUMAN){
			str = getmove(&src, &trg);
		}
		else{
			board->node->actual = genplay(board &src, &trg);
			
			if(board->node->actual != NULL){
				found = CTRUE;
			}
			else{
				end = 1;
				continue;
			}
		}
		
		if(cerror == ENDOF || board->node->first == NULL){
			end = 1;
			continue;
		}
		else if(cerror != NOERR){
			printerror();
			continue;
		}
		
		if(str != NULL){
			if(strcmp(str, "quit\n") == 0){
				end = 1;
				continue;
			}
			else if(strcmp(str, "moves\n") == 0)
				printmoves(board);
			else if(strcmp(str, "undo\n") == 0){
				undoboard(board);
				undoboard(board);
				printbfp(board);
			}
			
			delnodes(board->node);
			continue;
			}
		}
		
		if(found = CTRUE)
			//set first move
			board->node->actual = board->node->first;
			
		while(found == CFALSE && board->node->actual != NULL){
				
			if (board->node->actual->data == NULL){
			board->node->actual = board->node->actual->next;
			continue;
			}
				
			if((((move*)(board->node->actual->data))->src == src) && (((ch_move*)(board->node->actual->data))->trg == trg))
				found=CTRUE;
				
			else
				board->node->actual = board->node->actual->next;
		}
		
		if(found = CFALSE){
			board->node->actual = board->node->first;
			cerror = ILLEGAL;
		}
		else{
			tree *p = NULL;
			
			p = remtree(board->node->actual);
			
			delnodes(board->node);
			
			treeaddfirst(board->first, p);
			
			board->node = p;
			
			found = CFALSE;
		}
		
		if(cerror != NOERR){
			if(str == NULL && cerror == ENDOF){
				end = 1;
			}
			printerror();
		}
		else{
			figmove(board->board, src, trg, DOIT);
			
			board->move = (board->move == CWHITE) ? CBLACK : CWHITE;
			
			board->pl = (board->move == CWHITE) ? board->wp : board->bp;
			
			if(cerror != NOERR)
				printerror();
			else{
				printbfp(board);
				
				printerror();
			}
		}
		
		board->move++;
	}
}

inline cfig *cfigmove(cfield board[120], char src, char target, int flag){
	cfig *tmp = NULL;
	cfig *figure = NULL;
	cfig *ret = NULL;
	
	char s;
	
	cerror = NOERR;
	
	if(board == NULL && board[(int)src.figure == NULL){
		cerror = POINTERNULL;
		return ret;
	}
	
	figure = board[(int)src].figure;
	
	s = figure->position;
	
	if(figure->type == CKING || figure->type == BLACK_KING){
		if(board[(int)target].danger == 0 || (board[(int)target.danger < 0 && figure->type < 0) || (board[(int)target].danger > 0 && figure->type > 0)){
			tmp = figset(board, figure);
		}
		else{
			cerror = ILLEGAL;
			figure->position = s;
			return ret;
		}
	}
	else{
		tmp = figset(board, figure);
	}
	
	if(tmp == NULL){
		cerror = ILLEGAL;
		figure->position = s;
		return ret;
	}
	
	if(tmp != figure){
		if((tmp->type > 0 && figure->type > 0) || (tmp->type < 0 && figure->type < 0)){
			cerror = ILLEGAL;
			figure->position = s;
			return ret;
		}
		else{
			ret = tmp;
			if(flag & DOIT){
				tmp->position = 0;
			}
		}
	}
	
	if(flag & DOIT){
		baord[(int)target].figure = figure;
		board[(int)s].figure = NULL;
	}
	else{
		figure->position = s;
		if(tmp == figure){
			board[(int)target].figure = NULL;
		}
	}
	
	return ret;
}

void undoboard(cboard board){
	move *mve;
	
	if(board == NULL || borad->node == NULL ||board->node->root == NULL){
		cerror = POINTERNULL;
		return;
	}
	
	mve = (move *)board->node->data;
	
	figmove(board->board, mve->trg, mve->src, DOIT);
	
	if(mve->take != NULL){
		printf("Hello");
		
		mve->take->position = mve->trg;
		board->board[(int)mve->take->position].figure = mve->take;
	}
	
	board->node = board->node->root;
	delnodes(board->node);
	
}
