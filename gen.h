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

#ifndef __CH_GENERATOR_H_
#define __CH_GENERATOR_H_

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

#endif
