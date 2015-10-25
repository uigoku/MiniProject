#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"chess.h"
#include"io.h"

int main(int argc, char **argv){
	cboard board;
	
	initboard(&board);
	
	srandom(time(NULL));
	startgame(&board);
	printerror();
	doneboard(&board);
	
	return 0;
}
