#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"chess.h"
#include"io.h"

int main(int argc, char **argv){
	cboard board;
	
	ch_board_init(&board);
	
	srandom(time(NULL));
	ch_game_start(&board);
	ch_error_print();
	ch_board_done(&board);
	
	return 0;
}
