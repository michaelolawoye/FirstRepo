#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 3



void displayBoard(int positions[ROWS][COLUMNS]);
void playerMove(int positions[ROWS][COLUMNS], int user);
int checkMoves(int positions[ROWS][COLUMNS], int move);
int checkWin(int positions[ROWS][COLUMNS]);


int main(void) {

    srand(time(NULL));

    int win_con = 0;
    int turn = 0;
    int pos[ROWS][COLUMNS] = {{0, 0, 0}, {0, 0, 1}, {0, 0, 0}};

//    while (!win_con) {
        playerMove(pos, turn+rand());
        displayBoard(pos);
//    }
    
    return 0;
}


void displayBoard(int positions[ROWS][COLUMNS]) {

    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {

            switch (positions[row][column]) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("X");
                    break;
                case 2:
                    printf("O");
                    break;
            }

            if (column < COLUMNS-1)
                printf("|");
        }

        if (row < ROWS-1)
            printf("\n_____\n");
    }
}

int checkMoves(int positions[ROWS][COLUMNS], int move) {

    // 1 is minused from move because user input is 1-9, but index of board is 0-8
    int i = (move-1) / 3;
    int j = (move-1) % 3;

    if (positions[i][j] != 0)
        return 1;
    
    return 0;
}

void playerMove(int positions[ROWS][COLUMNS], int user) {

    int user_input;
    int used_move = 0;

    if (user % 2 == 0) {
        do {
            puts("Enter desired position(1-9): ");
            scanf("%d", &user_input);

            if (checkMoves(positions, user_input)) {
                puts("Position already taken");
                used_move = 1;
            }
            else {
                used_move = 0;
            }
        } while(used_move);
    }

    else {
        do {
            user_input = (rand() % 9) + 1;
            if (checkMoves(positions, user_input))
                used_move = 1;
            else
                used_move = 0;
        } while (used_move);
    }
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (user_input == (3*i + j + 1)) {
                if (user % 2 == 0) {
                    positions[i][j] = 1;
                }
                else {
                    positions[i][j] = 2;
                }
            }
        }
    }
}

int checkWin(int positions[ROWS][COLUMNS]) {
    
}


