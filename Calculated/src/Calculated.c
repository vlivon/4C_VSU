#include <stdio.h>
#include <stdlib.h>

float first, second, result , power, *v1, *v2, *res;
char operation, next_time, choice;
int size;


int main(int argc , char *argv[] )
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    next_time = 'y';
    while (next_time == 'y')                           // This allows us to use the program several times
    {
        puts("Choose your calculator (\"c\" for numbers or \"v\" for vectors): ");  // Choosing how the calculator works
        scanf(" %c", &choice);


        switch(choice)                                              // Choice between work with numbers or vectors
        {
            case 'c':                                              // Work with numbers
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

                printf("%f\n" , result);                             // Outputting the result
                puts("Enter \"y\" to repeat program)");            // Repeat the program
                scanf(" %c", &next_time);
                break;




            case 'v':                                                 // Work with vectors
                printf("Enter size of vectors: ");
                scanf("%i", &size);
                v1=malloc(size*sizeof(int));                         //
                v2=malloc(size*sizeof(int));                        // Memory allocation for variables
                res=malloc(size*sizeof(int));                      //
                printf("Enter first vector: ");
                for (int i=0; i<size; i++) scanf("%f", &v1[i]);         // Entering coordinates of first vector
                puts("Enter your operation (+ - *): ");                 // Entering operation
                scanf(" %c", &operation);

                switch(operation);                              // Selecting an operation on vectors
                {
                    case '+':                                               // Summation
                        printf("Enter second vector: ");
                        for (int i=0; i<size; i++) scanf("%f", &v2[i]);    // Entering coordinates of second vector
                        printf("Result of adding vectors: ");
                        for (int i=0; i<size; i++) printf("%f ", v1[i]+v2[i]);
                        printf("\n");
                        free(v1);                                       //
                        free(v2);                                      //  Freeing a memory cell
                        free(res);                                    //
                        break;
                    case '-':                                                        // Subtraction
                        printf("Enter second vector: ");
                        for (int i=0; i<size; i++) scanf("%f", &v2[i]);             // Entering coordinates of second vector
                        printf("The result of the subtraction of vectors: ");
                        for (int i=0; i<size; i++) printf("%f ", v1[i]-v2[i]);
                        printf("\n");
                        free(v1);                                   //
                        free(v2);                                  //  Freeing a memory cell
                        free(res);                                //
                        break;
                    case '*':                                                   // Scalar multiplication
                        printf("Enter second vector: ");
                        for (int i=0; i<size; i++) scanf("%f", &v2[i]);             // Entering coordinates of second vector
                        printf("Result of scalar multiplication of vectors: ");
                        for (int i=0; i<size; i++) printf("%f ", v1[i]*v2[i]);
                        printf("\n");
                        free(v1);                                           //
                        free(v2);                                          //  Freeing a memory cell
                        free(res);                                        //
                        break;
                }
        }
    }
    return 0;
}
