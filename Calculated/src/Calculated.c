
#include <stdio.h>
#include <stdlib.h>
float first, second, result , k;
char operation, next_time;
int main(int argc , char *argv[] ) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    next_time = 'y';
    while (next_time == 'y')            // Repeat
    {
        puts("Enter the first number ");
        scanf("%f", &first);
        puts("Enter your operation  ");
        scanf(" %c", &operation);
        k = first ;
        if (operation == '+')           // Addition
        {
            puts("Enter the second  number ");
            scanf("%f", &second);
            result = first + second ;
        }
        else if (operation == '*')      // Multiplication
        {
            puts("Enter the second  number ");
            scanf("%f", &second);
            result = first * second ;
        }
        else if (operation == '/')      // Division
        {
            puts("Enter the second  number ");
            scanf("%f", &second);
            result = first / second ;
        }
        else if (operation == '-')      // Difference
        {
            puts("Enter the second  number ");
            scanf("%f", &second);
            result = first - second ;
        }
        else if (operation == '^')      // Power
        {
            puts("Enter the second  number ");
            scanf("%f", &second);
            while (second >1)
            {
                first = first * k;
                second = second - 1;
            }
            result = first ;
        }
        else if (operation == '!')      // Factorial
        {
            while (k > 1 )
            {
                k = k - 1;
                first = first *k ;
            }
            result = first;
        }
        printf("%f" , result );          // Result
        puts("Repeat it? (enter \"y\" to continue)");
        scanf(" %c", &next_time);
    }
    return 0;
}
