/*   This a simple version of the arcade game tron
   Copyright (C) 2015  Aditya Karamchandani
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
   
*/

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
