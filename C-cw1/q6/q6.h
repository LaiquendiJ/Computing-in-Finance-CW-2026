// Purpose: Header for Tic-Tac-Toe board functions.

#ifndef Q6_H
#define Q6_H

extern char board[9];

void changeboard(int pos, char player);
void printBoard(void);
int checkMove(int pos);
int checkWin(void);

#endif