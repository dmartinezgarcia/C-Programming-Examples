/* NOTE: Select an exercise and use CTRL+MAYUS+C to comment it. Select an exercise and use CTRL+MAYUS+X to uncomment it. */

/*********************************************************
    Exercise 1
        Type in and run the 12 programs presented in this chapter. Compare the output produced by each program with the output presented after each program in the text.
        Try experimenting with each program by keying in values other than those shown.
*********************************************************/

// The results are the same.

/*********************************************************
    Exercise 2
        Write a program that asks the user to type in two integer values at the terminal. Test these two numbers to determine if the first is evenly divisible by the second, and then display an appropriate message at the terminal.
*********************************************************/

#include <stdio.h>

int main ()
{
    int a = 0, b = 0;

    printf("Please input two integer positive numbers: ");
    scanf("%i %i", &a, &b);

    if (!(a % b))
        printf("\n%i is evenly divisable by %i", a, b);
    else
        printf("\n%i is NOT evenly divisable by %i", a, b);

    return 0;
}
