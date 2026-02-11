#include "q6.h"
char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main(void)
{
    char player = 'X';
    int pos;
    printBoard();
    while (checkBoard())
    {
        scanf("%d", &pos);
        changeboard(pos, player);
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }
}