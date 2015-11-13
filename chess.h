#ifndef __CH_CHESS_H__
#define __CH_CHESS_H__

#include"tree.h"

//Macros for initializing of figures
#define figinit(fig, typ, val, pos, mov, multi) \
	(fig).type = (char)(typ); \
	(fig).value = (int)(val); \
	(fig).position = (char)(pos); \
	(fig).move = (char)(mov); \
	(fig).multiply = (char)(multi)

#define figset(b, f) ((b)[(int)(f)->position].figure != NULL || \
	(b)[(int)(f)->position].value == CH_BORDER || \
	(f)->position < 0 || (f)->position > 119) ? \
	(b)[(int)(f)->position].figure : \
	((b)[(int)(f)->position].figure = f)

#define errprint() if (cerror!=NOERR) printerror()

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
}cfield;

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

extern cboard initboard(cboard *board);

extern void doneboard(cboard *board);

extern void startgame(cboard *board);

extern inline cfig* cfigmove(cboard *board, char src, char target, int flag);

extern void undomove(cboard *board);

#endif
