#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#include"io.h"
#include"chess.h"
#include"defs.h"
#include"gen.h"
#include"tree.h"

//initially there is no error
enumerror cerror = NOERR;

//initializes the board
cboard *initboard(cboard *board){
	int i = 0, j = 0;
	
	cerror = NOERR;
	//if theres no structure then create one
	if(board == NULL)
		if((board = malloc(sizeof(cboard))) == 0){
			cerror = NOMEM;
			printf("No enough memory\n");
			return NULL;
		}
	
	//initializing all walls
	for(i = 0; i < 120; i++){
		board->board[i].fig = NULL;
		board->board[i].value = CBORDER;
		board->board[i].danger = 0;
	}
	
	//empty playing board
	for(j = 20; j < 100; j += 10)
		for(i = 1; i < 9; i++)
			board->board[j + i].value = CEMP;
	
	
	//create tree
	board->node = treenew(malloc(sizeof(cmove)));
	if(board->node == NULL)
		return board;
	if(board->node->data == NULL){
		free(board->node);
		return board;
	}
	
	((cmove*)board->node->data)->src = 0;
	((cmove*)board->node->data)->trg = 0;
	((cmove*)board->node->data)->cost = 0;
	((cmove*)board->node->data)->change = 0;
	
	//Initialization of all pieces
	for(i = 0; i < 8; i++){
		fig_init(board->white[i], CPAWN, PAWN, A2+i, PM, CFALSE);
		fig_init(board->black[i], CBLACK_PAWN, BLACK_PAWN, A7+i, PM, CFALSE);
	}
	fig_init(board->white[8], CROOK, ROOK, A1, VH, CTRUE);
	fig_init(board->white[9], CROOK, ROOK, H1, VH, CTRUE);
	fig_init(board->black[8], CBLACK_ROOK, BLACK_ROOK, A8, VH, CTRUE);
	fig_init(board->black[9], CBLACK_ROOK, BLACK_ROOK, H8, VH, CTRUE);
	fig_init(board->white[10], CKNIGHT, KNIGHT, B1, KM, CFALSE);
	fig_init(board->white[11], CKNIGHT, KNIGHT, G1, KM, CFALSE);
	fig_init(board->black[10], CBLACK_KNIGHT, BLACK_KNIGHT, B8, KM, CFALSE);
	fig_init(board->black[11], CBLACK_KNIGHT, BLACK_KNIGHT, G8, KM, CFALSE);
	fig_init(board->white[12], CBISHOP, BISHOP, C1, DIAG, CTRUE);
	fig_init(board->white[13], CBISHOP, BISHOP, F1, DIAG, CTRUE);
	fig_init(board->black[12], CBLACK_BISHOP, BLACK_BISHOP, C8, DIAG, CTRUE);
	fig_init(board->black[13], CBLACK_BISHOP, BLACK_BISHOP, F8, DIAG, CTRUE);
	fig_init(board->white[14], CQUEEN, QUEEN, D1, DIAG|VH, CTRUE);
	fig_init(board->white[15], CKING, KING, E1, DIAG|VH, CFALSE);
	fig_init(board->black[14], CBLACK_QUEEN, BLACK_QUEEN, D8, DIAG|VH, CTRUE);
	fig_init(board->black[15], CBLACK_KING, BLACK_KING, E8, DIAG|VH, CFALSE);
	
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
	i = A2;
	board->board[i++].value = 4;
	board->board[i++].value = 8;
	board->board[i++].value = 12;
	board->board[i++].value = 16;
	board->board[i++].value = 16;
	board->board[i++].value = 12;
	board->board[i++].value = 8;
	board->board[i++].value = 4;
	i = A3;
	board->board[i++].value = 8;
	board->board[i++].value = 12;
	board->board[i++].value = 16;
	board->board[i++].value = 20;
	board->board[i++].value = 20;
	board->board[i++].value = 16;
	board->board[i++].value = 12;
	board->board[i++].value = 8;
	i = A4;
	board->board[i++].value = 12;
	board->board[i++].value = 16;
	board->board[i++].value = 20;
	board->board[i++].value = 24;
	board->board[i++].value = 24;
	board->board[i++].value = 20;
	board->board[i++].value = 16;
	board->board[i++].value = 12;
	i = A5;
	board->board[i++].value = 12;
	board->board[i++].value = 16;
	board->board[i++].value = 20;
	board->board[i++].value = 24;
	board->board[i++].value = 24;
	board->board[i++].value = 20;
	board->board[i++].value = 16;
	board->board[i++].value = 12;
	i = A6;
	board->board[i++].value = 8;
	board->board[i++].value = 12;
	board->board[i++].value = 16;
	board->board[i++].value = 20;
	board->board[i++].value = 20;
	board->board[i++].value = 16;
	board->board[i++].value = 12;
	board->board[i++].value = 8;
	i = A7;
	board->board[i++].value = 4;
	board->board[i++].value = 8;
	board->board[i++].value = 12;
	board->board[i++].value = 16;
	board->board[i++].value = 16;
	board->board[i++].value = 12;
	board->board[i++].value = 8;
	board->board[i++].value = 4;
	i = A8;
	board->board[i++].value = 4;
	board->board[i++].value = 0;
	board->board[i++].value = 8;
	board->board[i++].value = 12;
	board->board[i++].value = 12;
	board->board[i++].value = 8;
	board->board[i++].value = 0;
	board->board[i++].value = 4;
	
	//initiallly nobody has a check
	board->check = 0;
	
	//First Turn
	board->cmove = CWHITE;
	
	//will play as White
	board->wp = HUMAN;
	
	//black's chance
	board->bp = CPU;
	
	//Change of turn
	board->pl = board->wp;
	
	//cmove counted
	board->cmove = 1;
	
	return board;
}

//Game Over - cancles tree
void doneboard(cboard *board){
	if(board == NULL)
		return;
	
	//if there's a tree
	if(board->node != NULL){
		//searches for the node
		while(board->node->root != NULL)
			board->node = board->node->root;
			
		//deletes all branches
		deltree(board->node);
		board->node = NULL;
	}
}


void undoboard(cboard *board){
	cmove *mve;
	
	if(board == NULL || board->node == NULL ||board->node->root == NULL){
		cerror = POINTERNULL;
		return;
	}
	
	mve = (cmove *)board->node->data;
	
	cfigmove(board->board, mve->trg, mve->src, DOIT);
	
	if(mve->take != NULL){
		printf("Hello");
		
		mve->take->position = mve->trg;
		board->board[(int)mve->take->position].fig = mve->take;
	}
	
	board->node = board->node->root;
	delnodes(board->node);
	
}

//Game Starts
void startgame(cboard *board){
	char src = 0, trg = 0;	//used for From-To
	char *str = NULL;
	char *str1 = "start";
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
			//generate all possible cmoves for a given position
			genmoves(board);
			
			gencost(board);
			
			gensubmoves(board);
			
			gendangers(board);
		}
		
		//will take input
		if(board->pl == HUMAN){
			str = getmove(&src, &trg);
			if(str != NULL){
				str1 = str;
			}
		}
		else{
			board->node->actual = genplay(board, &src, &trg);
			
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
		
		//if the entered string was a command and not a cmove
		if(strcmp(str1, "start") != 0){
			if(strcmp(str, "quit\n") == 0){
				end = 1;
				cerror = NOERR;
				return;
			}
			else if(strcmp(str, "cmoves\n") == 0){
				printmoves(board);
			}
			else if(strcmp(str, "undo\n") == 0){
				undoboard(board);
				undoboard(board);
				printbfp(board);
			}
			
			delnodes(board->node);
			continue;
		}
		
		if(found != CTRUE)
			//set first cmove
			board->node->actual = board->node->first;
			
		while(found == CFALSE && board->node->actual != NULL){
				
			if (board->node->actual->data == NULL){
				board->node->actual = board->node->actual->next;
				continue;
			}
				
			if((((cmove*)(board->node->actual->data))->src == src) && (((cmove*)(board->node->actual->data))->trg == trg))
				found=CTRUE;
				
			else
				board->node->actual = board->node->actual->next;
		}
		
		//if its invalid cmove
		if(found == CFALSE){
			board->node->actual = board->node->first;
			cerror = ILLEGAL;
		}
		else{
			//the cmove is set in tree
			tree *p = NULL;
			
			p = rem(board->node->actual);
			
			//removing unnecessary nodes to save memory
			delnodes(board->node);
			
			//add the cmove
			treeaddfirst(board->node, p);
			
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
			cfigmove(board->board, src, trg, DOIT);
			
			board->cmove = (board->cmove == CWHITE) ? CBLACK : CWHITE;
			
			//which is on cmove
			board->pl = (board->cmove == CWHITE) ? board->wp : board->bp;
			
			if(cerror != NOERR)
				printerror();
			else{
				printbfp(board);
				
				printerror();
			}
		}
		
		//cmove to take another counter
		board->cmove++;
	}
}

//cmove Figure
inline cfig *cfigmove(cfield board[120], char src, char target, int flag){
	cfig *tmp = NULL;
	cfig *figure = NULL;
	cfig *ret = NULL;
	
	char s;
	
	cerror = NOERR;
	
	if(board == NULL && board[(int)src].fig == NULL){
		cerror = POINTERNULL;
		return ret;
	}
	
	figure = board[(int)src].fig;
	
	s = figure->position;
	
	//test if the king is not dragged to a vulnerable position
	if(figure->type == CKING || figure->type == BLACK_KING){
		if(board[(int)target].danger == 0 || (board[(int)target].danger < 0 && figure->type < 0) || (board[(int)target].danger > 0 && figure->type > 0)){
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
		board[(int)target].fig = figure;
		board[(int)s].fig = NULL;
	}
	else{
		figure->position = s;
		if(tmp == figure){
			board[(int)target].fig = NULL;
		}
	}
	
	return ret;
}
