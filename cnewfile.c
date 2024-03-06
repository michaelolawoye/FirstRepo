#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#define SIZE 10


int findmod(int arr[], size_t size, int pos, int mod);
int gcd(int a, int b);


int main(void) {

    enum days {january=1, february, march, april, may, june, july, august, september, october, november, december};
    enum days date;
    
    for (int i = 1; i <= 12; i++) {
        if (date == i) {
            printf("idk");
        }
    }

    return 0;
}


int findmod(int arr[], size_t size, int pos, int mod) {

    int sum = 0, finalnum;

    for (size_t i = 0; i < size+1; i++) {
        if (pos == i) {
            
        }
        else {
            sum += (arr[i] * (i+1));
        }
    }
    sum = sum % mod;
    finalnum = mod - sum;

    return finalnum;

}


int gcd(int a, int b) {

    int r_val = 0;

    while ((a != 0) && (b != 0)) {
        if (a > b) {
            a = a - (a/b) * b;
        }
        else if (b > a) {
            b = b - (b/a) * a;
        }
        else {
            r_val = a;
            return r_val;
        }
    }

    if (a == 0) {
        r_val = b;
    }
    else if (b == 0) {
        r_val = a;
    }

    return r_val;
}


// red = 3, green = 5, blue = 8
// N = 16, n = 3
