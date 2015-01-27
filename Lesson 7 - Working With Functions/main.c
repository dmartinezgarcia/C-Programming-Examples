/* NOTE: Select an exercise and use CTRL+MAYUS+C to comment it. Select an exercise and use CTRL+MAYUS+X to uncomment it. */

/*********************************************************
    Exercise 1
		Type in and run the 17 programs presented in this chapter. Compare the output produced by each program with the output presented after each program in the text.
*********************************************************/

// They all produce the same output.

/*********************************************************
    Exercise 2
		Modify Program 7.4 so the value of triangularNumber is returned by the function. Then go back to Program 4.5 and change that program so that it calls the new version of the calculateTriangularNumber() function.
*********************************************************/

//#include <stdio.h>
//
//int calculateTriangularNumber (int n)
//{
//    int  i, triangularNumber = 0;
//
//    for ( i = 1;  i <= n;  ++i )
//        triangularNumber += i;
//
//    printf ("Triangular number %i is %i\n", n, triangularNumber);
//
//    return triangularNumber;
//}
//
//int main (void)
//{
//    int  n, number, triangularNumber, counter;
//
//    for ( counter = 1;  counter <= 5;  ++counter )
//    {
//        printf ("What triangular number do you want? ");
//        scanf  ("%i", &number);
//        calculateTriangularNumber(number);
//    }
//    return 0;
//}

/*********************************************************
    Exercise 3
		Modify Program 7.8 so that the value of epsilon is passed as an argument to the function. Try experimenting with different values of epsilon to see the effect that it has on the value of the square root.
*********************************************************/

//// The bigger epsilon, less precision in the result.
//
//// Function to calculate the absolute value of a number
//
//#include <stdio.h>
//
//float  absoluteValue (float x)
//{
//    if ( x < 0 )
//        x = -x;
//
//    return (x);
//}
//
//// Function to compute the square root of a number
//
//float  squareRoot (float x, const float epsilon)
//{
//    float        guess   = 1.0;
//
//    while  ( absoluteValue (guess * guess - x) >= epsilon )
//        guess = ( x / guess + guess ) / 2.0;
//
//    return guess;
//}
//
//int main (void)
//{
//    const float epsilon[] = {0.0001F, 0.001F, 0.01F, 0.1F, 1.0F};
//    int i = 0;
//
//    for (i = 0; i < 5; i++)
//    {
//        printf("\nEpsilon value: %f\n\n", epsilon[i]);
//        printf("squareRoot (2.0) = %f\n", squareRoot (2.0F, epsilon[i]));
//        printf("squareRoot (144.0) = %f\n", squareRoot (144.0F, epsilon[i]));
//        printf("squareRoot (17.5) = %f\n", squareRoot (17.5F, epsilon[i]));
//    }
//
//    return 0;
//}

/*********************************************************
    Exercise 4
        Modify Program 7.8 so that the value of guess is printed each time through the while loop.
        Notice how quickly the value of guess converges to the square root.
        What conclusions can you reach about the number of iterations through the loop, the number whose square root is being calculated, and the value of the initial guess?
*********************************************************/

// Function to calculate the absolute value of a number

//#include <stdio.h>
//
//float  absoluteValue (float x)
//{
//     if ( x < 0 )
//         x = -x;
//
//     return (x);
//}
//
//// Function to compute the square root of a number
//
//float  squareRoot (float x)
//{
//     const float  epsilon = .00001;
//     float        guess   = 1.0;
//
//     while  ( absoluteValue (guess * guess - x) >= epsilon )
//     {
//        guess = ( x / guess + guess ) / 2.0;
//        printf("Guess for %.3f is %.3f.\n", x, guess);
//     }
//
//     return guess;
//}
//
//int main (void)
//{
//     printf ("squareRoot (2.0) = %f\n", squareRoot (2.0));
//     printf ("squareRoot (144.0) = %f\n", squareRoot (144.0));
//     printf ("squareRoot (17.5) = %f\n", squareRoot (17.5));
//     return 0;
//}

/*********************************************************
    Exercise 5
        The criteria used for termination of the loop in the squareRoot() function of Program 7.8 is not suitable for use when computing the square root of very large or very small numbers.
        Rather than comparing the difference between the value of x and the value of guess2, the program should compare the ratio of the two values to 1.
        The closer this ratio gets to 1, the more accurate the approximation of the square root.
        Modify Program 7.8 so this new termination criteria is used.
*********************************************************/

// Function to calculate the absolute value of a number

#include <stdio.h>

float  absoluteValue (float x)
{
    if ( x < 0 )
        x = -x;

    return (x);
}

// Function to compute the square root of a number

float  squareRoot (float x)
{
    const float  epsilon = .00001;
    float        guess   = 1.0;

    while  ( absoluteValue (guess * guess - x) >= epsilon )
    {
        guess = ( x / guess + guess ) / 2.0;
    }

    return guess;
}

int main (void)
{
    printf ("squareRoot (2.0) = %f\n", squareRoot (2.0));
    printf ("squareRoot (144.0) = %f\n", squareRoot (144.0));
    printf ("squareRoot (17.5) = %f\n", squareRoot (17.5));
    return 0;
}
