#include <stdio.h>
#include <stdlib.h>
extern char board[9];

void changeboard(int pos, char player);
void printBoard(void);
int checkMove(int pos);
int checkWin(void);