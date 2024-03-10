#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 3
#define WINCON 3
#define X 1
#define O 2


void displayBoard(int positions[ROWS][COLUMNS]);
void playerMove(int positions[ROWS][COLUMNS], int move, int x_or_o);
int isValidMove(int positions[ROWS][COLUMNS], int move);


int main(void) {

    srand(time(NULL));

    int used_move = 0, turn = 0, move;
    int pos[ROWS][COLUMNS] = {0};

    do {
        puts("Enter a position:");
        scanf("%d", &move);
        
        // checks if index in grid is already used
        if (isValidMove(pos, move)) {

            // store move in grid using playerMove func and display grid
            playerMove(pos, move, turn);
            displayBoard(pos);

            // set used_move to 0 so loop terminates
            used_move = 0;
        }
        else {
            puts("Position entered is already used");

            // set used_move to 1 so loop repeats
            used_move = 1;
        }
    } while (used_move);


    
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