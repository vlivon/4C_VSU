#include <stdio.h>
#include <stdlib.h>

float first, second, result , power;
char operation, next_time;

int main(int argc , char *argv[] )
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    next_time = 'y';
    while (next_time == 'y')                           // This allows us to use the program several times
    {
        puts("Enter the first number: ");                  // Entering the first number
        scanf("%f", &first);
        puts("Enter your operation (+ * / - ^ !): ");      // Entering operation
        scanf(" %c", &operation);
        power = first;                                     // This will help us with exponentiation and factorial

        switch(operation)                                  // Selecting an operation
        {
            case '+':                                          // Summation
            {   puts("Enter the second  number: ");            // Entering the second number
                scanf("%f", &second);
                result = first + second ;
                break;
            }
            case '*':                                          // Multiplication
                puts("Enter the second  number: ");            // Entering the second number
                scanf("%f", &second);
                result = first * second ;
                break;
            case '-':                                          // Subtraction
                puts("Enter the second  number: ");            // Entering the second number
                scanf("%f", &second);
                result = first - second;
                break;
            case '/':                                          // Division
                puts("Enter the second  number: ");            // Entering the second number
                scanf("%f", &second);
                result = first / second;
                break;
            case '^':                                          // Degree
                puts("Enter the second  number: ");            // Entering the second number
                scanf("%f", &second);
                while (second >1)
                {
                    first = first * power;                         // Using variable power which we announced before selecting an operation
                    second = second - 1;
                }
                result = first;
                break;
            case '!':                                          // Factorial
                while (power > 1)
                {
                    power = power - 1;                             // Using variable power which we announced before selecting an operation
                    first = first * power;
                }
                result = first;
                break;
        }

        printf("%f" , result);                             // Outputting the result
        puts("Enter \"y\" to repeat program)");            // Repeat the program
        scanf(" %c", &next_time);
    }
    return 0;
}
