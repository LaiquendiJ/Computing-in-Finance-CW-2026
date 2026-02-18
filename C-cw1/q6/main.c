// Purpose: Main logic for Tic-Tac-Toe game.

#include <stdio.h>
#include <stdlib.h>
#include "q6.h"

// Initializae board: 9 chars: index 0..8 corresponds to positions 1..9.
char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main(void)
{
    char player = 'X';
    int pos, win;
    printBoard();
    int count = 0;

    while (count < 9)
    {
        // Prompt the current player for their move and read the position.
        if (player == 'X'){
            printf("Player 1, give your move: "); 
        }
        else{
            printf("Player 2, give your move: ");
        }
        scanf("%d", &pos);
        while (!checkMove(pos))
        {   
            printf("Please give a new position: ");
            scanf("%d", &pos);
        }

        // Apply the move, update the board, and check for a win.
        changeboard(pos, player);
        count++;
        win = checkWin();

        // If there's a win, announce the winner and break the loop. Otherwise, switch players.
        if (win)
        {
            if (player == 'X'){
                printf("Player 1 wins the game!\n");
            }
            else{
                printf("Player 2 wins the game!\n");
            }
            break;
        }
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
        
    }
    
    // If the loop ends without a win, it's a draw.
    if (!win)printf("It is a draw!\n");

    return EXIT_SUCCESS;
}