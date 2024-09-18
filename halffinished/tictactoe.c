#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define ROWS 3
#define COLUMNS 3
#define WINCON 3
#define X 1
#define O 2


void single_turn(int pos[ROWS][COLUMNS]);
void displayBoard(int positions[ROWS][COLUMNS]);
int playerMove(int positions[ROWS][COLUMNS], int move, int x_or_o);
int compMove(int positions[ROWS][COLUMNS], int x_or_o);
int isValidMove(int positions[ROWS][COLUMNS], int move);
int checkWin(int position[ROWS][COLUMNS]);
int checkpos(int pos[ROWS]);


int main(void) {
    srand(time(NULL));

    int xoro;
    int pos[ROWS][COLUMNS] = {0};
    // pos[0][2] = 1; 
    puts("Would you like to be X or O (X=1, O=2)?");
    scanf("%d", &xoro);
    do {
        single_turn(pos);
    } while (0);

    return 0;
}

void single_turn(int pos[ROWS][COLUMNS]) {

}


void displayBoard(int positions[ROWS][COLUMNS]) {

    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLUMNS; col++) {
            if (positions[row][col] == 1)
                printf("X");
            else if (positions[row][col] == 2)
                printf("O");
            else if (positions[row][col] == 0)
                printf(" ");
            else 
                printf("?");
            if (col != COLUMNS-1)
                printf("|");
                
        }
        if (row != ROWS-1)
            printf("\n_____\n");
    }
}

int playerMove(int positions[ROWS][COLUMNS], int move, int x_or_o) {

    int x = ((move-1) % COLUMNS);
    int y = ceil((float)move/ROWS);
    if (isValidMove(positions, move)) {
        if (x_or_o == X) { positions[x][y] == X;}
        else { positions[x][y] == O;}
        return 1;
    }

}

int compMove(int positions[ROWS][COLUMNS], int x_or_o) {

    int move = rand() % (ROWS*COLUMNS);
    int x = ((move-1) % COLUMNS);
    int y = ceil((float)move/ROWS);
    if (isValidMove(positions, move)) {
        if (x_or_o == X) { positions[x][y] == O;}
        else {positions[x][y] == X;}
        return 1;
    }
    
}


int isValidMove(int positions[ROWS][COLUMNS], int move) {

    move--;
    int col = move % ROWS;
    int row = ceil((float)move/ROWS);

    if (positions[row][col] != 0) {
        return 0;
    }
        return 1;
    
    
}