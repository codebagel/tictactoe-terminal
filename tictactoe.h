#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdio.h>
#include <string.h>

// Represents the current state of every cell on the field
// Space means that cell empty
// 'O' means that cell is filled with zero
// 'X' means that cell is filled with X
char field[9];

// 'O' or 'X' for each player
char player1, player2;

// Counter of already filled cells
// Game stops then it turns to 9
int filled_cells;

// Counter of incorrect inputs (e.g. no-number inputs or wrong numbers)
// when expecting to input a cell number form a player
// Game stops after five incorrect inputs following one by one
int failed_inputs;

// Draws the current state of field in the terminal
// Param cell_order is used when game first launched to show the order of cells 
void draw_field(int cell_order);

// Returns 1 if the game is over (three neighbour cells are filled with O or X)
// Returns 0 otherwise
int game_is_over();

// Set 'X' for player 1 and 'O' for player 2 if no option passed
// or does vice versa if option "-o" was passed in arguments list
// Then draws a plan of field with numbers of cells and does other preparations
void prepare_game(char* option);

// Major logical unit of the game 
// This is recursive function which reads a new input (number of cell to 
// fill with 'O' or 'X') and makes next turn
// Param figure is 'O' or 'X' depending on player 1 or player 2 makes a turn
void make_turn(char figure);

#endif
