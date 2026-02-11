#include "q6.h"

void changeboard(int pos, char player)
{
    if (pos < 1 || pos > 9)
        printf("Not an eligible position!\n");
    if (board[pos - 1] != 'O' && board[pos - 1] != 'X')
    {
        board[pos - 1] = player;
        printBoard();
    }
    else
        printf("Position already occupied!\n");
}

void printBoard(void)
{
    for (int i = 0; i < 9; i++)
    {
        printf("%c", board[i]);
        if ((i + 1) % 3 == 0)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
    }
}

int checkBoard(void)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == 'X' || board[i] == 'O')
            continue;
        else
            return 1;
    }
    return 0;
}