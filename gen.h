#include"chess.h"

typedef struct cmove{
	char src;
	char trg;
	int cost;
	char change;
	
	cfig *take;
}cmove;

extern char coffset[];

extern void gendangers(cboard *board);

extern void genmoves(cboard *board);

extern void gensubmoves(cboard *board);

extern void gencost(cboard *board);

extern void gencosts(cboard *board);

extern tree *genplay(cboard *board, char *s, char *t);
