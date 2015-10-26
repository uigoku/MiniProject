#include"chess.h"
#define CH_MAX_MOV_LEN 80

extern char *getmove(char *src, char *trg);

//printed chessboard on the place of the figures is their value
extern void printbfp(cboard* board);

//prints all possible moves
extern void printmoves(cboard* board);

//function displaying error messages
extern void printerror(void);

//prints the values of the players field
extern void printcentable(cboard *board);

//lists simple table playing fields
extern void printfigval(cboard *board);

//lists the type of black and white figures
extern void figprint(cboard *board);
