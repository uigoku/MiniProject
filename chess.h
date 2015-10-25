#ifndef __CH_CHESS_H__
#define __CH_CHESS_H__

#include"tree.h"

typedef int player;

//CHECK HERE !!!!!!!!!!!!!!!!!!!!
typedef struct cfig{
	char type;
	int value;
	char position;
	char move;
	char multiply;
}

//CHECK HERE !!!!!!!!!!!!!!!!!!!!
typedef struct cfield{
	cfig *fig;
	char value;
	int danger; //whether the field is safe or not
}

typedef struct cboard{
	cfig white[16]; //for white pieces
	cfig black[16]; //for black pieces
	cfig board[120]; //chessboard
	char move;
	
	player whitep;
	player blackp;
	player pl;
	
	int cost;
	int wcost;
	int bcost;
	
	tree *node;
}cboard;

typedef enum{
	NOERR, NOMEM, POINTERNULL, ILLEGAL, ENDOF
}enumerror;

//CHECK HERE !!!!!!!!!!!!!!!!!!!!
extern enumerror cerror;

cboard initboard(cboard *board);

void doneboard(cboard *board);

void startgame(cboard *board);

cfig* cfigmove(cboard *board, char src, char target, int flag);

void undomove(cboard *board);

#endif
