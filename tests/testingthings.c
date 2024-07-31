#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main(void) {
    srand(time(NULL));
    
    int words_array[][5] = {0};
    // main print loop
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            
            int r_int = rand() % 26 + 'a';
            printf("%c ", r_int);
        }
        puts("");
    }
    int hexa = 0xFFA123;
    printf("%d", hexa);
    return 0;
}