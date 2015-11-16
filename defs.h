#ifndef __CH_DEFS_H__
#define __CH_DEFS_H__

//The Identification Values of each type of Players
//Positive is for the White Player and Negative is for the Opponent
#define CEMP 0
#define CPAWN 1
#define CBLACK_PAWN -1
#define CKNIGHT 2
#define CBLACK_KNIGHT -2
#define CBISHOP 3
#define CBLACK_BISHOP -3
#define CROOK 4
#define CBLACK_ROOK -4
#define CQUEEN 5
#define CBLACK_QUEEN -5
#define CKING 6
#define CBLACK_KING -6
#define CBORDER 100

//Their values
#define PAWN 100
#define BLACK_PAWN 100
#define KNIGHT 330
#define BLACK_KNIGHT -330
#define BISHOP 330
#define BLACK_BISHOP -330
#define ROOK 520
#define BLACK_ROOK -520
#define QUEEN 980
#define BLACK_QUEEN -980
#define KING 12000
#define BLACK_KING 12000

#define A1 21
#define A2 31
#define A3 41
#define A4 51
#define A5 61
#define A6 71
#define A7 81
#define A8 91
#define B1 22
#define B2 32
#define B3 42
#define B4 52
#define B5 62
#define B6 72
#define B7 82
#define B8 92
#define C1 23
#define C2 33
#define C3 43
#define C4 53
#define C5 63
#define C6 73
#define C7 83
#define C8 93
#define D1 24
#define D2 34
#define D3 44
#define D4 54
#define D5 64
#define D6 74
#define D7 84
#define D8 94
#define E1 25
#define E2 35
#define E3 45
#define E4 55
#define E5 65
#define E6 75
#define E7 85
#define E8 95
#define F1 26
#define F2 36
#define F3 46
#define F4 56
#define F5 66
#define F6 76
#define F7 86
#define F8 96
#define G1 27
#define G2 37
#define G3 47
#define G4 57
#define G5 67
#define G6 77
#define G7 87
#define G8 97
#define H1 28
#define H2 38
#define H3 48
#define H4 58
#define H5 68
#define H6 78
#define H7 88
#define H8 98

//colours
#define CWHITE 1
#define CBLACK -1

//boolean
#define CTRUE 1
#define CFALSE 0

//movements
#define DIAG 1
#define VH 2
#define KM 4
#define PM 8
#define WHITE_BASE_LINE 30
#define BLACK_BASE_LINE 80
#define WHITE_CHANGE_LINE 90
#define BLACK_CHANGE_LINE 20

//Flags
#define TEST 0
#define DOIT 1
#define HUMAN 0
#define CPU 1

#define GET_COLOR(x) (((x)<0)?CBLACK:CWHITE)

#endif
