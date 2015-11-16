#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "gen.h"
#include "defs.h"
#include "io.h"

char coffset[] = {
	-9, -11, 9, 11,	// 0, 1, 2, 3, diagonal cmove
	-1, 10, 1, -10,	//4, 5, 6, 7, horizontal and vertical cmove
	19, 21, 12, -8, -19, -21, -12, 8, //8, 9, 10, 11, 12, 13, 14, 15 knight
	10,
	20,
	11,
	9,
	-10,
	-20,
	-11,
	-9
};

void gendangers(cboard *board){
	int i;
	cfig *figure = NULL;
	
	if(board == NULL || board->node == NULL){
		cerror = POINTERNULL;
		return;
	}
	
	figure = (board->cmove == CWHITE) ? board->white : board->black;
	
	//clearing current status
	for(i = 0; i < 120; i++)
		board->board[i].danger = 0;
	
	board->node->actual = board->node->first;
	
	while(board->node->actual != NULL){
		board->board[(int)((cmove *)(board->node->actual->data))->trg].danger = board->cmove;
		
		board->node->actual = board->node->actual->next;

	}
}

//generates all possible positions for all possible cmoves
void genmoves(cboard *board){
	int start = 0, end = 0, i = 0, j = 0;
	char typ = 0;
	cfig *ret = NULL;
	cfig *figure = NULL;
	cmove *mve = NULL;
	
	cerror = NOERR;
	
	if(board == NULL || board->node == NULL){
		cerror = POINTERNULL;
		return;
	}
	
	if(board->node->first != NULL)
		return;
#ifdef DEBUG
	printf("Searching for Legal cmoves for %d\n", board->cmove);
#endif
	figure = (board->cmove == CWHITE) ? board->white : board->black;
	
	for(i = 0; i < 16; i++){
		int multi = 1;
		
		if(board->board[(int)figure[i].position].value == CBORDER)
			continue;
		
		typ = (figure[i].type >= 0) ? figure[i].type : (-1 * figure[i].type);
		
		start = (typ == CQUEEN || typ == CKING || typ == CBISHOP) ? 0 : ((typ == CROOK) ? 4 : ((typ == CKNIGHT) ? 8 : 0));
		
		end = (typ == CQUEEN || typ == CKING || typ == CROOK) ? 7 : ((typ == CBISHOP) ? 3 : ((typ == CKNIGHT) ? 15 : 0));
		
		if(typ != CPAWN){
			for(j = start; j <= end; j++){
				int multiply = figure[i].multiply;
				
				multi = 1;
				cerror = NOERR;
				
				do{
					ret = cfigmove(board->board, figure[i].position, figure[i].position + coffset[j] * multi, TEST);
					
					if(cerror == NOERR){
						mve = (cmove *)malloc(sizeof(cmove));
					
						if(mve == NULL){
							cerror = NOMEM;
#ifdef DEBUG
							printf("\n\nIn ch_gen_cmoves();\nLine: 68\nTyp: %d\nch_error == %d\n\n", typ, ch_error);
#endif
							return;
						}
						
						mve->src = figure[i].position;
						mve->trg = figure[i].position + coffset[j] * multi;
						mve->change = 0;
						mve->take = ret;
						
						mve->cost = (int)(figure[i].value) + (int)(board->board[(int)mve->trg].value);
						
						push(board->node, (void *)mve);
#ifdef DEBUG
						printf("F%dS%dT%dC%d,", typ, mve->src, mve->trg, mve->cost);
#endif
					}
					else if(cerror != ILLEGAL){
#ifdef DEBUG
						printf("\n\nIn genmoves();\nLine: 68\nTyp: %d\ncerror == %d\n\n", typ, cerror);
#endif
						return;
					}
					
					if(ret != NULL)
						multiply = CFALSE;
					
					multi++;
				}
				while(multiply == CTRUE && cerror == NOERR);
			}
		}
		else{
			char tmppos = figure[i].position;
			
			int fw = (figure[i].type > 0) ? 16 : 20,
				fw2 = (figure[i].type > 0) ? 17 : 21,
				fwt1 = (figure[i].type > 0) ? 18 : 22,
				fwt2 = (figure[i].type > 0) ? 19 : 23,
				basln = (figure[i].type > 0) ? tmppos - WHITE_BASE_LINE : tmppos - BLACK_BASE_LINE;
				
			ret = cfigmove(board->board, tmppos, tmppos + coffset[fw], TEST);
			if(cerror == NOERR && ret == NULL){
				
				mve = (cmove *)malloc(sizeof(cmove));
				
				if(mve == NULL){
					cerror = NOMEM;
					printf("\n\nIn genmoves();\ntypL %d\nmve == NULL\n\n", typ);
				}
				
				mve->src = tmppos;
				mve->trg = tmppos + coffset[fw] * multi;
				mve->change = 0;
				mve->take = ret;
				mve->cost = (int)(figure[i].value) + (int)(board->board[(int)mve->trg].value);
				
				push(board->node, (void *)mve);
#ifdef DEBUG
				printf("F%dS%dT%dC%d,",typ,cmove->src, cmove->trg, cmove->cost);
#endif

			}
			else if(cerror != NOERR && cerror != ILLEGAL){
				printf("\n\nIn genmoves();\nLine: 100\nTyp: %d\nch_error == %d\n\n", typ, cerror);
				return;
			}
			
			if(basln < 10 && basln > 0 && board->board[tmppos + coffset[fw]].fig == NULL){
				
				ret = cfigmove(board->board, tmppos, tmppos + coffset[fw2], TEST);
				
				if(cerror == NOERR && ret == NULL){
					
					mve = (cmove *)malloc((sizeof(cmove)));
					if(mve == NULL){
						cerror = NOMEM;
						printf("\n\nIn genmoves();\nTyp: %d\ncerror == %d\nin 0<basln<10", typ, cerror);
						return;
					}
					mve->src = tmppos;
					mve->trg = tmppos + (coffset[fw2] * multi);
					mve->change = 0;
					mve->take = ret;
					mve->cost = (int)(figure[i].value) + (int)(board->board[(int)mve->trg].value);
					
					push(board->node, (void *)mve);
#ifdef DEBUG
					printf("F%dS%dT%dC%d,",typ,cmove->src, cmove->trg, cmove->cost);
#endif
					
				}
				else if(cerror != NOERR && cerror != ILLEGAL){
					printf("\n\nIn genmoves();\nTyp: %d\nch_error == %d\nin 0<basln<10 -- second\n\n", typ, cerror);
					return;
				}
			}
			
			for(j = fwt1; j <= fwt2; j++){
				ret = cfigmove(board->board, tmppos, tmppos + coffset[j], TEST);
				
				if(ret != NULL){
					mve = (cmove *)malloc(sizeof(cmove));
					
					if(mve == NULL){
						cerror = NOMEM;
						printf("\n\nIn cgencmoves();\nTyp: %d\ncerror == %d\nin 0<basln<10 -- second\n\n", typ, cerror);
						return;
					}
					mve->src = tmppos;
					mve->trg = tmppos + coffset[j];
					mve->change = 0;
					mve->take = ret;
					mve->cost = (int)(figure[i].value) + (int)(board->board[(int)mve->trg].value);
					
					push(board->node, (void *)mve);
#ifdef DEBUG
					printf("F%dS%dT%dC%d,", typ, mve->src, mve->trg, mve->cost);
#endif
					
				}
			}	
		}
		
		cerror = NOERR;
	}
#ifdef DEBUG
	printbfp(board);
#endif
	
}

void gensubmoves(cboard *board){
	int best = 0;
	cmove *mve = NULL;
	
	if(board == NULL || board->node == NULL || board->node->first == NULL){
		cerror = POINTERNULL;
			printf("gensubmoves: null pointer %s\n", (board) ? ((board->node) ? "board->node->first" : "board->node") : "board");
	}
	
	gencosts(board);
	
	board->cmove = (board->cmove == CWHITE) ? CBLACK : CWHITE;
	
	board->node->actual = board->node->first;
	
	while(board->node->actual != NULL){
		board->node = board->node->actual;
		
		mve = (cmove *)board->node->data;
		
		cfigmove(board->board, mve->src, mve->trg, DOIT);
		
		genmoves(board);
		
		gencosts(board);
		
		if(board->node->first == NULL)
			break;
		
		board->node->actual = board->node->first;
		
		best = ((cmove *)board->node->actual->data)->cost;
		
		while(board->node->actual != NULL){
			if(best < ((cmove *)board->node->actual->data)->cost)
				best = ((cmove *)board->node->actual->data)->cost;
			board->node->actual = board->node->actual->next;
		}
		
		cfigmove(board->board, mve->trg, mve->src, DOIT);
		
		if(mve->take != NULL){
			mve->take->position = mve->trg;
			board->board[(int)mve->take->position].fig = mve->take;
		}
		
		board->node = board->node->root;
		
		((cmove *)board->node->actual->data)->cost += -1 * best;
		
		board->node->actual = board->node->actual->next;
	}
	
	board->cmove = (board->cmove == CWHITE) ? CBLACK : CWHITE;
	
	board->node->actual = board->node->first;
	
}

void gencost(cboard *board){
	int i = 0;
	
	if(board == NULL){
		cerror = POINTERNULL;
		return;
	}
	
	board->wcost = 0;
	board->bcost = 0;
	
	for(i = 0; i < 16; i++){
		if(board->white[i].position != 0)
			board->wcost += board->white[i].value + CWHITE * board->board[(int)board->white[i].position].value;
		
		if(board->black[i].position != 0)
			board->bcost += board->black[i].value + CBLACK * board->board[(int)board->black[i].position].value;
	}
	
	board->cost = board->wcost + board->bcost;
	
#ifdef DEBUG
	printf("\nWhite Cost: %d\nBlack Cost: %d\nCost: %d\n", board->wcost, board->bcost, board->cost);
#endif

}

void gencosts(cboard *board){
	tree *node = NULL; //pointer to tree
	
	cmove *mve = NULL; // pointer to cmove
	int colour = 0; // colour of the player
	cfield *b = NULL; //pointer to the plying fields
	
	if(board == NULL || board->node == NULL || board->node->first == NULL || board->node->first->data == NULL){
		cerror = POINTERNULL;	
		printf("gencosts: %s\n", board ? ((board->node) ? "board->node->first" : "board->node") : "board");
		return;
	}
	
	node = board->node->first;
	b = board->board;
	
	colour = board->cmove;
	
	//untill all the walks are covered
	while(node != NULL){
		mve = (cmove *)(node->data);
		
		//
		mve->cost = b[(int)(mve->trg)].value - b[(int)(mve->src)].value;
		
		if(b[(int)(mve->trg)].fig != NULL){
			mve->cost += (-1 * colour) * b[(int)(mve->trg)].fig->value;
		}
#ifdef DEBUG
		printf("F%dS%dT%dC%d,",b[(int)(mve->src)].figure->type, mve->src, mve->trg, moe->cost);
#endif
		
		node = node->next;
	}
}

tree *genplay(cboard *board, char *s, char *t){
	tree *node = NULL;
	tree *best = NULL;
	
	if(board == NULL || board->node == NULL || board->node->first == NULL){
		cerror = POINTERNULL;
		return best;
	}
	
	node = board->node;
	node->actual = node->first;
	best = node->actual;
	
	while(node->actual != NULL){
		if(((cmove *)(best->data))->cost < ((cmove *)(node->actual->data))->cost){
			best = node->actual;
		}
		else if(((cmove *)(best->data))->cost == ((cmove *)(node->actual->data))->cost && random() % 2 == 0){
			best = node->actual;
		}
		node->actual = node->actual->next;
	}
	
	board->node->actual = node->first;
	
	if(best == NULL){
		*s = 0;
		*t = 0;
	}
	else{
		*s = ((cmove *)(best->data))->src;
		*t = ((cmove *)(best->data))->trg;
	}
	
	return best;
}
