#include "tictactoe.h"

void draw_field(int cell_order)
{
    int i,j;
    puts("");
    for (i = 0; i < 3; ++i)
    {
        puts("+---+---+---+");
        
        for (j = 0; j < 3; ++j)
        {   
            // If cell order is non-zero we print the number of cell (1-9)
            // ASCII code of 1 is 49, so we add it to current index (i*3+j)
            // If cell_order is zero (used while playing) we just print the
            // content of char with corresponding index from variable 'field'
            printf("| %c ", cell_order ?  i*3+j+49 : field[i*3+j]);
        }
        
        puts("|");
    }
    puts("+---+---+---+\n");
}

int game_is_over()
{
    // Where are 8 combinations of three neighbour cells with same meaning
    // that leads to end of the game
    // Apart from being filled with 'O' or 'X' the cells might be filled 
    // with space (be empty), so we check it instead of just returning 'true'
    
    // First row
    if (field[0] == field[1] && field[0] == field[2]) return field[0] != ' ';
    // Second row
    if (field[3] == field[4] && field[3] == field[5]) return field[3] != ' ';
    // Third row
    if (field[2] == field[5] && field[2] == field[8]) return field[2] != ' ';
    // First column
    if (field[0] == field[3] && field[0] == field[6]) return field[0] != ' ';
    // Second column
    if (field[1] == field[4] && field[1] == field[7]) return field[1] != ' ';
    // Third column
    if (field[6] == field[7] && field[6] == field[8]) return field[6] != ' ';
    // Main diagonal
    if (field[0] == field[4] && field[0] == field[8]) return field[0] != ' ';
    // Antidiagonal
    if (field[2] == field[4] && field[2] == field[6]) return field[2] != ' '; 
    // Game is still not over
    return 0;
}

void prepare_game(char* option)
{
    if (option != NULL && strcmp(option, "-o") == 0)
    {
        player1 = 'O';
        player2 = 'X';
    }
    else
    {
        player1 = 'X';
        player2 = 'O';
    }
    
    memset((void*)field, ' ', 9);
    filled_cells = failed_inputs = 0;
    draw_field(1);
    puts("Enter the number of cell to make a turn");
    printf("Starting with %c\n", player1);   
    make_turn(player1);
}

void make_turn(char figure)
{
    if (failed_inputs == 5)
    {
        puts("It seems, you are not going to play by rules.");
        return;
    }

    if (filled_cells == 9)
    {
        puts("It is a withdraw");
        return;
    }
    
    printf("player %d> ", figure == player1 ? 1 : 2);
    
    // Read the number of cell to be filled
    // Initial value for 'turn' is necessary in case
    // digit is not read and the value is not set 
    // while-loop clears the buffer
    int turn = 0;
    scanf("%d", &turn);
    while (getc(stdin) != '\n');

    // We accept only numbers form 1 to 9
    if (turn < 1 || turn > 9) 
    {  
        ++failed_inputs;
        puts("Enter number from 1 to 9 to fill a cell");
        make_turn(figure);
    }
    
    // If the number of cell is corrent, check of this cell is empty
    else if (field[turn-1] != ' ')
    {
        ++failed_inputs;
        puts("This cell is already filled. Try another number");
        make_turn(figure);
    }
    
    // Cell is empty. Make a new turn
    else
    {
        field[turn-1] = figure;
        ++filled_cells;
        failed_inputs = 0;
        draw_field(0);
        
        // Allow another player to make a next turn if the game isn't over 
        if (!game_is_over()) 
        {
            make_turn(figure == 'O' ? 'X' : 'O');
        }
        
        // Otherwise show who has won
        else
        {
            printf("Player %d won\n", figure == player1 ? 1 : 2);
        }
    }
}
