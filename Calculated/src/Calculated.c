/*
 ============================================================================
 Name        : Calculated.c
 Author      : vlivon
 Version     :
 Copyright   : no
 Description : Calculator working w/ files
 
 In this version of the calculator, 
 it became possible to perform scalar and vector calculations with reading from a file and writing to a file. 
 You can choose between the console and file management "Choose between file and console [f/c]: ". 
 Type "f" to choose to work with files or "c" to work in the console. 
 In the console version, if you chose work with numbers, you should follow what appears on the screen: 
 enter the first number, enter one of the following operations: [*]multiplication, [/]division, 
 [+]addition, [-]subtraction, [^]exponentiation, [!]factorial, and then enter the second number (not for factorial). 
 Also in console mode you can work with vectors: enter size of vectors, enter first vector, enter your operation (+, - or *) 
 and enter second vector. 
 
 If you work with files, then you shold follow next rules:
 Information format must be like: - s 3 2 for operations on numbers or * v 3 4 5 5 -1 2 -7 for operations with vectors 
 where at 1st place - operation type, then mode type(s - num. operations, v - operations with vectors), then:
 a) If you choose number operations then enter 2 numbers, splitting space, or 1 number if you want counting factorial.
 b) If you choose vector operations then enter coordinate system type(n-dimensional), 
 and then needful quantity of numbers like that (x1 y1 z1 x2 y2 z2)
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

float first, second, result , power, *v1, *v2, *res;
char operation, next_time, choice, consoleFile, inputFileName[254+1], outputFileName[254+1];
int size;
FILE *input, *output; // define files
int main(int argc , char *argv[] )
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    next_time = 'y';
    while (next_time == 'y')                           // This allows us to use the program several times
    {
        printf("Choose between file and console [f/c]: ");
        scanf(" %c", &consoleFile);
        switch(consoleFile)                                     //  Choose with where are you want to work, console or file
        {
            case 'f':
                printf("\nNow you can choose names of input and output files: ");
                printf("Enter name of input file: ");
                scanf(" %s", inputFileName);
                printf("Enter name of output file: ");
                scanf(" %s", outputFileName);
                input = fopen(inputFileName,"r");                                 // Open all files that we need
                output = fopen(outputFileName, "w");
                fscanf(input, " %c", &operation);                               // Scan operation
                fscanf(input, " %c", &choice);                                  // Scan vector or number
                switch(choice)                                                  // Choose vector or number
                {
                    case 's':                                                   // Reading operation
                        switch(operation)
                        {
                            case '+':
                                fscanf(input, " %f", &first);                   // Reading numbers
                                fscanf(input, " %f", &second);
                                fprintf(output, "%f + %f = %f", first, second, first+second);   // Writing result to file
                                break;
                            case '-':
                                fscanf(input, " %f", &first);
                                fscanf(input, " %f", &second);
                                fprintf(output, "%f - %f = %f", first, second, first-second);
                                break;
                            case '/':
                                fscanf(input, " %f", &first);
                                fscanf(input, " %f", &second);
                                fprintf(output, "%f / %f = %f", first, second, first/second);
                                break;
                            case '*':
                                fscanf(input, " %f", &first);
                                fscanf(input, " %f", &second);
                                fprintf(output, "%f * %f = %f", first, second, first*second);
                                break;
                            case '^':
                                fscanf(input, " %f", &first);
                                fscanf(input, " %f", &second);
                                result = 1;
                                for (int i=0; i<second; i++) result = result*first;
                                fprintf(output, "%f ^ %f = %f", first, second, result);
                                break;
                            case '!':
                                result = 1;
                                fscanf(input," %f",&first);
                                if (first >= 0) for (int i=first; i!=1; i--) result = result*i;   // Calculate factorial from back
                                else fprintf(output, "This number is below zero. Please, try again.");
                                fprintf(output, "!%f = %f", first, result);
                                break;
                        }
                        break;
                    case 'v':
                        v1=malloc(size*sizeof(int));                                        // Memory allocation for variables
                        v2=malloc(size*sizeof(int));
                        switch(operation)                                                  // Choose operation
                        {
                            case '+':                                     
                                fscanf(input, " %i", &size);                              //
                                for(int i=0;i<size;i++)                                  //
                                fscanf(input, " %f",&v1[i]);                            // Reading from file
                                for(int i=0;i<size;i++)                                //
                                fscanf(input, " %f",&v2[i]);                          //


                                fprintf(output, "( ");                                 
                                for(int i=0;i<size;i++)
                                fprintf(output, "%.0f ", v1[i]);
                                fprintf(output, ") + ( ");
                                for(int i=0;i<size;i++)
                                fprintf(output, "%.0f ", v2[i]);
                                fprintf(output, ") = ( ");
                                for(int i=0;i<size;i++)
                                fprintf(output, "%.0f ",v1[i]+v2[i]);                // Writing result to file
                                fprintf(output, ")");
                                free(v1);                                            // Freeing a memory cell
                                free(v2);
                                break;
                            case '-':
                                fscanf(input, " %i", &size);
                                for(int i=0;i<size;i++)
                                fscanf(input, " %f",&v1[i]);
                                for(int i=0;i<size;i++)
                                fscanf(input, " %f",&v2[i]);


                                fprintf(output, "( ");
                                for(int i=0;i<size;i++)
                                fprintf(output, "%.0f ", v1[i]);
                                fprintf(output, ") - ( ");
                                for(int i=0;i<size;i++)
                                fprintf(output, "%.0f ", v2[i]);
                                fprintf(output, ") = ( ");
                                for(int i=0;i<size;i++)
                                fprintf(output, "%.0f ",v1[i]-v2[i]);
                                fprintf(output, ")");
                                free(v1);
                                free(v2);
                                break;
                            case '*':
                                fscanf(input, " %i", &size);
                                for(int i=0;i<size;i++)
                                fscanf(input, " %f",&v1[i]);
                                for(int i=0;i<size;i++)
                                fscanf(input, " %f",&v2[i]);


                                fprintf(output, "( ");
                                for(int i=0;i<size;i++)
                                fprintf(output, "%.0f ", v1[i]);
                                fprintf(output, ") * (");
                                for(int i=0;i<size;i++)
                                fprintf(output, "%.0f ", v2[i]);
                                fprintf(output, ") = ( ");
                                for(int i=0;i<size;i++)
                                fprintf(output, "%.0f ",v1[i]*v2[i]);
                                fprintf(output, ")");
                                free(v1);
                                free(v2);
                                break;
                        }
                        break;
                }
                break;



            case 'c':
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
                                puts("Enter the second  number: ");            // Entering the second number
                                scanf("%f", &second);
                                result = first + second ;
                                break;

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
                break;
        }
        puts("Enter \"y\" to repeat program: ");            // Repeat the program
        scanf(" %c", &next_time);
    }
    return 0;
}
