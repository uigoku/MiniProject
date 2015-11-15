DSA MiniProject

Aditya B Karamchandani, S.Y.B.Tech I.T, 111408067

CHESS (PLAYER v/s COMPUTER)

I. FILE LIST
-------------

	main.c		Starts the Game, calls the functions whoch start the game.
	io.c		The Display, i/o of the Board, figures, score, errors.
	io.h		Defines the Chessboard Layout.
	chess.c		Game Implementation File
	chess.h		Defines the chess figures
	gen.c		Generates moves, submoves, thier costs.
	gen.h		Declaration for gen.c
	tree.c		Tree Implementation.
	tree.h		Tree Header.

II. ABOUT GAME
---------------

	Chess, is a simple Computer v/s Player game written in C uses the Data Structure of a Tree to maintain figures, i.e Their Position, Moves.
	It calculates possible moves based on predefined moves set for each figure, finds out errors and counts the moves the User has played.

III. DESIGN
------------

	On running the game, the chessboard gets printed on the screen of the terminal. The game is without GUI (it doesnt require ncurses.h header file)
	
	Game starts with the User's move since it is regarded as white by default, after successfully placing of the figure the control shifts over to the Computer for it's turn. Once successful moves are detected and the figures are displaced the control switches to user. This gous on till the game gets over.
	
	Trees are used to maintain the chain of chess figures. Data comtains the figure value, used to calculate possible moves of the figure. If the figure is the Computer, it is aslo used to identify dangers and costs. Then move which has minmum cost or maximum advantage is executed and rest all possibilities are removed. "gen.c" handles this task of generating moves and submoves, thier costs as well.
	
	"io.c" maintains the display part of the game. Once the player has decided his/her move by entering starting(source) coordinates and destination(target), as an argument, if its a valid or a legal move, then the figure gets printed there and is hence moved there.
	
	"chess.c" file handles the initaialization of chess figure which includes type, value, position, moves and multiplicity of each figure of both the players(player and system). 'cfield' contains the information of value and danger of each player which helps to find whether figure is safe or not whith the move.chessboard typedef contains all the details like white and black figure posotions, moves, players, players turn, white's cost, black's cost and the node pointer.
	
	To facilitate the Undo move function for the game, trees are used, which maintains the moves taken by the player. Every time when a player takes a move a node with player's figure data is created and pushed into the tree. At the time of undo the node is popped and changes the other pointers accordingly.


IV. ERROR TYPES
----------------
	
	NOERR		Indicates that the move is possoble and there are no errors.
	NOMEM		Indicates failure of memory allocation by malloc()
	POINTERNULL	Indicates that a specific pointer is NULL
	ILLEGAL		Indicates that the move selected is Illegal and cannot be exeuted.
