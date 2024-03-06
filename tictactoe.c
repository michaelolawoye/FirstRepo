#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 3
#define WINCON 3
#define USERMOVE 1
#define COMPMOVE 2



void displayBoard(int positions[ROWS][COLUMNS]);
void playerMove(int positions[ROWS][COLUMNS], int user);
int isValidMove(int positions[ROWS][COLUMNS], int move);
int checkWin(int positions[ROWS][COLUMNS]);
int winConditionCheck(int array[WINCON], int playercheck);


int main(void) {

    srand(time(NULL));

    int win_con = 0;
    int turn = 0;
    int pos[ROWS][COLUMNS] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

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
                default:
                    printf("?");
                    break;
            }

            if (column < COLUMNS-1)
                printf("|");
        }

        if (row < ROWS-1)
            printf("\n_____\n");
    }
}

int isValidMove(int positions[ROWS][COLUMNS], int move) {

    // 1 is minused from move because user input is 1-9, but index of board is 0-8
    int i = (move-1) / ROWS;
    int j = (move-1) % COLUMNS;

    if (positions[i][j] != 0)
        return 1;
    
    return 0;
}

void playerMove(int positions[ROWS][COLUMNS], int user) {

    int user_input;
    int used_move = 0;

    if (user % 2 == 0) {
        do {
            printf("Enter desired position(1-%d):\n",  ROWS*COLUMNS);
            scanf("%d", &user_input);

            if (isValidMove(positions, user_input)) {
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
            user_input = (rand() % (ROWS*COLUMNS)) + 1;
            if (isValidMove(positions, user_input))
                used_move = 1;
            else
                used_move = 0;
        } while (used_move);
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (user_input == (ROWS*i + j + 1)) {
                if (user % 2 == 0) {
                    positions[i][j] = USERMOVE;
                }
                else {
                    positions[i][j] = COMPMOVE;
                }
            }
        }
    }
}

int checkWin(int positions[ROWS][COLUMNS]) {

    int columnwin[COLUMNS][ROWS];
    int diagonalwin;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
        columnwin[i][j] = positions[j][i];
        }
    }

    for (int j = 0; j < ROWS; j++) {
        if (winConditionCheck(positions[j], USERMOVE)) {
            return 1;
        }
        else if (winConditionCheck(positions[j], COMPMOVE)) {
            return 2;
        }
        else {
            return 0;
        }
        
    }

}


int winConditionCheck(int array[WINCON], int playerpoint) {

    for (int i = 0; i < WINCON-1; i++) {
        if (!(array[i] == playerpoint) || !(array[i] == array[i+1])) {
            return 0;
        }
    }

    return 1;
}


