#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 3
#define WINCON 3
#define X 1
#define O 2


void single_turn(int pos[ROWS][COLUMNS], int turn);
void displayBoard(int positions[ROWS][COLUMNS]);
void playerMove(int positions[ROWS][COLUMNS], int move, int x_or_o);
int isValidMove(int positions[ROWS][COLUMNS], int move);


int main(void) {
    srand(time(NULL));

    int turn = 0;
    int pos[ROWS][COLUMNS] = {0};

    while (pos[0][0] == 0) {
        single_turn(pos, turn);
    }

    return 0;
}

void single_turn(int pos[ROWS][COLUMNS], int turn) {

    int valid_move = 0;

    do {
        int move;

        displayBoard(pos);

        if (valid_move == -1)
            puts("Position already used");
        else if (valid_move == -2)
            puts("Position entered is out of range");

        puts("Enter a position:");
        scanf("%d", &move);
        system("cls");

        // move is not used
        if (isValidMove(pos, move)) {

            // store move in grid using playerMove func and display grid
            playerMove(pos, move, turn);
            displayBoard(pos);
            valid_move = 1;
        }

        // makes sure move isn't out of range
        else if (move > ROWS*COLUMNS) {
            valid_move = -2;
        }

        // position already used
        else {
            valid_move = -1;
        }
    } while (valid_move != 1);
}

void playerMove(int positions[ROWS][COLUMNS], int move, int x_or_o) {

    // loops through every position in grid, checks if move is equal to the index
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {

            // j increments symbolize moving horizontally, increasing index by one
            // i increments by COLUMN symbolizes moving down to next row, resetting j and increasing i by number of columns counted
            if (move == i*COLUMNS + j + 1) {
                if (x_or_o % 2 == 0)
                    positions[i][j] = X;
                else
                    positions[i][j] = O;
            }
        }
    }
}



int isValidMove(int positions[ROWS][COLUMNS], int move) {

    if (move > ROWS*COLUMNS)
        return 0;
    // nested loop to find move index match
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {

            // same algo as playerMove func tp check if move is equal to index in grid
            if (move == i*COLUMNS + j + 1) {

                // 0 signifies empty position, so if not 0, position used
                if (positions[i][j] != 0)
                    return 0;

                else
                    return 1;
            }
        }
    }
    return -1;
}

void displayBoard(int positions[ROWS][COLUMNS]) {
    system("cls");

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
    puts("");
}