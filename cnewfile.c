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


// 1281x = 14 mod 679
// ax = b mod n
// ax - b = 0
// ax - b = ny
// ax - ny = b
// if gcd(a, n)|b, then a integer sol. for x exists


// a == 76, b == 10
// a == 76 - 7(10) = 6, b == 10
// a == 6, b == 10 - 6 = 4
// a == 6 - 4 = 2, b == 4

// 2 = 6 - 4
//   = 6 - (10 - 6)
//   = 2(76 - 7(10)) - 10
//   = 2(76) - 15(10)