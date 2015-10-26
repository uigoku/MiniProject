#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "gen.h"
#include "defs.h"
#include "list.h"
#include "io.h"

extern char coffset[] = {
	-9, -11, 9, 11,	// 0, 1, 2, 3, diagonal move
	-1, 10, 1, -10,	//4, 5, 6, 7, horizontal and vertical move
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
