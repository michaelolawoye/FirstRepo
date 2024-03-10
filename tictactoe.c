#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 3
#define WINCON 3




void displayBoard(int positions[ROWS][COLUMNS]);
void playerMove(int positions[ROWS][COLUMNS], int move, int x_or_o);
void isValidMove(int positions[ROWS][COLUMNS], int move);



int main(void) {

    srand(time(NULL));

    int win_con = 0;
    int turn = 0;
    int pos[ROWS][COLUMNS] = {0};

//    while (!win_con) {
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

void playerMove(int positions[ROWS][COLUMNS], int move, int x_or_o) {

    // loops through every position in grid, checks if move is equal to the index
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (move == i*COLUMNS + j + 1) {

                // if x_or_o is even, put 1, which means 'x' and else put 2, which means 'o'
                if (x_or_o % 2 == 0)
                    positions[i][j] = 1;
                else
                    positions[i][j] = 2;
            }
        }
    }

}
