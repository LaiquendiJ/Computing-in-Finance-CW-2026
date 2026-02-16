/*
Write a program that allows two users to play noughts and crosses. The program should ask for moves alternately from player X and player O. The program displays the game positions as
123
456
789

The players enter their moves by providing the position number. After each move the program displays the changed board. A sample board configuration is
XXO
OX6
7X0
*/
#include "q6.h"
/* Initializae board: 9 chars: index 0..8 corresponds to positions 1..9 */
char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main(void)
{
    char player = 'X';
    int pos,win;
    printBoard();
    int count = 0;
    while (count < 9)
    {
        if (player == 'X')
            {
                printf("Player 1, give your move: ");
               
            }
            else
            {
                printf("Player 2, give your move: ");
            };
        scanf("%d", &pos);
        while (!checkMove(pos))
        {   
            printf("Please give a new position: ");
            scanf("%d", &pos);
        }

        changeboard(pos, player);
        count++;
        win = checkWin();
        if (win)
        {
            if (player == 'X')
            {
                printf("Player 1 wins the game!");
               
            }
            else
            {
                printf("Player 2 wins the game!");
            };
            break;
        }
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
        
    }
    if (!win)printf("It is a draw!");
}