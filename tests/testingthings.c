#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


int main(void) {

    int a = 0x00008BCD;
    printf("LOWORD: %d\n", ((WORD)(a)));
    printf("HIWORD: %d\n", (WORD)(((DWORD)(a >> 15)) & 0xFFFF));
    // 6 -> 110
    // 3 -> 011
    // 00008BCD -> 0000 0000 0000 0000 0100 0111 1000 1001
    int* array = malloc(sizeof(int)*2);
    array[0] = 1;
    array[1] = 2;
    printf("%d", array[1]);
    return 0;
}
