#ifndef __CH_CHESS_H__
#define __CH_CHESS_H__

#include"tree.h"

//Macros for initializing of figures
#define fig_init(fig, typ, val, pos, mov, multi) \
	(fig).type = (char)(typ); \
	(fig).value = (int)(val); \
	(fig).position = (char)(pos); \
	(fig).cmove = (char)(mov); \
	(fig).multiply = (char)(multi)

#define figset(b, f) ((b)[(int)(f)->position].figure != NULL || \
	(b)[(int)(f)->position].value == CH_BORDER || \
	(f)->position < 0 || (f)->position > 119) ? \
	(b)[(int)(f)->position].figure : \
	((b)[(int)(f)->position].figure = f)

#define errprint() if (cerror!=NOERR) printerror()

typedef int player;

//structure describing the piece
typedef struct cfig{
	char type;	//the type of the figure
	int value;	//its value
	char position;	//current or latest position
	char cmove;
	char multiply;	//if multiple steps are taken
}

typedef struct cfield{
	cfig *fig;
	char value;
	int danger; //whether the field is safe or not
}cfield;

typedef struct cboard{
	cfig white[16]; //for white pieces
	cfig black[16]; //for black pieces
	cfig board[120]; //chessboard
	char cmove;
	
	player wp;
	player bp;
	player pl;
	
	int cost;
	int wcost;
	int bcost;
	
	tree *node;
}cboard;

typedef enum{
	NOERR, NOMEM, POINTERNULL, ILLEGAL, ENDOF
}enumerror;

extern enumerror cerror;

extern cboard initboard(cboard *board);

extern void doneboard(cboard *board);

extern void startgame(cboard *board);

extern inline cfig* cfigcmove(cboard *board, char src, char target, int flag);

extern void undocmove(cboard *board);

#endif
