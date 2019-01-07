/*
--------------------------------------------------------------------------------
Tic-tac-toe - a little game to play via terminal
Developed by Rumiantsev Daniil
Visit www.codebagel.com for more information
--------------------------------------------------------------------------------
*/

#include "tictactoe.h"

int main(int argc, char* argv[])
{
    // We expect calling the program with no options or with one option
    
    if (argc > 2)
    {
        puts("Usage:");
        puts("tictactoe to start playing with x");
        puts("tictactoe -o to start playing with zeros");
        puts("tictactoe --version to get info");
        return 0;
    }
    
    // In case "--version" argument is passed, just show info about the game
    
    else if (argc == 2 && strcmp(argv[1], "--version") == 0)
    {
        puts("Tic-tac-toe 1.0 (Terminal version)");
        puts("Vendor: Rumiantsev Daniil");
        puts("Visit www.codebagel.com for more information");
        return 0;
    }
    
    // Otherwise launch the game
    // If option "-o" is passed, first player starts with zeros
    
    prepare_game(argv[1]); 
    return 0;
}
