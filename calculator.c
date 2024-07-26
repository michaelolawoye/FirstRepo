#include <stdio.h>
#include <stdlib.h>

#define add 1
#define subtract 2
#define multiply 3
#define divide 4

double op(int, int, double);

int main(void) {

    int op1, num1;
    double num2;
    puts("Enter the 2 numbers (separate):");
    scanf("%d %lf", &num1, &num2);
    puts("What operation would you like to use?");
    puts("Add (1), Subtract (2), Multiply (3), Divide (4):");
    scanf("%d", &op1);
    printf("Result: %.2lf\n", op(op1, num1, num2));
    

    return 0;
}

double op(int op, int num1, double num2) {

    switch(op) {
        case 1:
            return num1 + num2;
            break;
        case 2:
            return num1 - num2;
            break;
        case 3:
            return num1 * num2;
            break;
        case 4:
            return num1/num2;
            break;
        default:
            puts("Operation must be 1-4");
            break;
    }

}