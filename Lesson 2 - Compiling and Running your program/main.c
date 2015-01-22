/* NOTE: Select an exercise and use CTRL+MAYUS+C to comment it. Select an exercise and use CTRL+MAYUS+X to uncomment it. */

/*********************************************************
    Exercise 1
        Type in and run the six programs presented in this chapter. Compare the output produced by each program with the output presented after each program in the text.
*********************************************************/

// All the inputs from all the programs are the same as in the book.

/*********************************************************
    Exercise 2
        Write a program that prints the following text.
            - In C, lowercase letters are significant.
            - main() is where program execution begins.
            - Opening and closing braces enclose program statements in a routine.
            - All program statements must be terminated by a semicolon.
*********************************************************/

//#include <stdio.h>
//
//int main()
//{
//    printf("In C, lowercase letters are significant.\n"
//           "main() is where program execution begins.\n"
//           "Opening and closing braces enclose program statements in a routine.\n"
//           "All program statements must be terminated by a semicolon.\n");
//    return 0;
//}

/*********************************************************
    Exercise 3
        What output would you expect from the following program?

        #include <stdio.h>
        int main (void)
        {
            printf ("Testing...");
            printf ("....1");
            printf ("...2");
            printf ("..3");
            printf ("\n");
            return 0;
        }
*********************************************************/

// This is the output I expect: Testing.......1...2..3(new line).

/*********************************************************
    Exercise 4
        Write a program that subtracts the value 15 from 87 and displays the result, together with an appropriate message, at the terminal.
*********************************************************/

//#include <stdio.h>
//
//int main()
//{
//    printf("87 - 15 = %i", 87 - 15);
//    return 0;
//}

/*********************************************************
    Exercise 5
        Identify the syntactic errors in the following program. Then type in and run the corrected program to ensure you have correctly identified all the mistakes.

        #include <stdio.h>
        int main (Void)
        (
            INT  sum;
            /* COMPUTE RESULT
            sum = 25 + 37 - 19
            /* DISPLAY RESULTS //
            printf ("The answer is %i\n" sum);
            return 0;
        }

*********************************************************/

// This is the correct program:

//#include <stdio.h>
//
//int main()
//{
//    int sum;
//    /* COMPUTE RESULT */
//    sum = 25 + 37 - 19;
//    /* DISPLAY RESULT */
//    printf("The answer is %i\n", sum);
//    return 0;
//}

/*********************************************************
    Exercise 6
        What output might you expect from the following program?

        #include <stdio.h>
        int main (void)
        {
            int answer, result;
            answer = 100;
            result = answer - 10;
            printf ("The result is %i\n", result + 5);
            return 0;
        }

*********************************************************/

// The program prints the following output: "The result is 95(new line)"
