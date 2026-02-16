#include "q6.h"
/* Apply the move: update b[pos-1] to player (which is 'X' or 'O') */
void changeboard(int pos, char player)
{
    
    if (board[pos - 1] != 'O' && board[pos - 1] != 'X')
    {
        board[pos - 1] = player;
        printBoard();
    }
    else
        printf("Position already occupied!\n");
}

/* Print the board in a 3x3 format */
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
/* Check if the move is valid: pos in [1,9] and b[pos-1] is not already X/O */
int checkMove(int ind)
{
    if (ind < 1 || ind > 9)
        {printf("Not an eligible position!\n");
        return 0;}
    
    if (board[ind-1] == 'X' || board[ind-1] == 'O'){
        printf("Already have a move at that position!\n");
        return 0;}
    return 1;
}
/* Check all rows, columns, and diagonals for a winner */
int checkWin(void)
{
    for(int i = 0;i<3;i++){
        if (board[3*i]==board[3*i+1] &&board[3*i+2]==board[3*i+1]){
            return 1;
        }
        if (board[i]==board[i+3] &&board[i+3]==board[i+6]){
            return 1;
        }
    };
    if (board[0]==board[4] &&board[4]==board[8]){
            return 1;}
    if (board[2]==board[4] &&board[4]==board[6]){
            return 1;}
    return 0;
}