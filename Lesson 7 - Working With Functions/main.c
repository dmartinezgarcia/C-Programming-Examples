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
//float  squareRoot (float x)
//{
//    const float  epsilon = .00001F;
//    float        guess   = 1.0F;
//    float        ratio = 0.0F;
//
//
//    if (x == 0.0F)
//    {
//        printf("[ERROR] The value can't be zero.\n");
//        return -1.0;
//    }
//
//
//    while (ratio < (1.0F - epsilon) || ratio > (1.0F + epsilon))
//    {
//        guess = ( x / guess + guess ) / 2.0;
//        ratio = absoluteValue((guess * guess) / x);
//        printf("Ratio: %f\n", ratio);
//    }
//
//    return guess;
//}
//
//int main (void)
//{
//    printf ("squareRoot (2.0) = %f\n", squareRoot (2.0));
//    printf ("squareRoot (144.0) = %f\n", squareRoot (144.0));
//    printf ("squareRoot (17.5) = %f\n", squareRoot (17.5));
//    return 0;
//}

/*********************************************************
    Exercise 6
        Modify Program 7.8 so that the squareRoot() function accepts a double precision argument and returns the result as a double precision value.
        Be certain to change the value of the variable epsilon to reflect the fact that double precision variables are now being used.
*********************************************************/

// Function to calculate the absolute value of a number

//#include <stdio.h>
//
//double  absoluteValue (double x)
//{
//    if ( x < 0 )
//        x = -x;
//    return (x);
//}
//
//// Function to compute the square root of a number
//
//double  squareRoot (double x)
//{
//    const double  epsilon = .00001;
//    double        guess   = 1.0;
//
//    while  ( absoluteValue (guess * guess - x) >= epsilon )
//        guess = ( x / guess + guess ) / 2.0;
//
//    return guess;
//}
//
//int main (void)
//{
//    printf ("squareRoot (2.0) = %f\n", squareRoot (2.0));
//    printf ("squareRoot (144.0) = %f\n", squareRoot (144.0));
//    printf ("squareRoot (17.5) = %f\n", squareRoot (17.5));
//    return 0;
//}

/*********************************************************
    Exercise 7
        Write a function that raises an integer to a positive integer power.
        Call the function x_to_the_n() taking two integer arguments x and n.
        Have the function return a long int, which represents the results of calculating xn.
*********************************************************/

//#include <stdio.h>
//
//long int x_to_the_n(int x, int n)
//{
//    int i;
//    long int sum;
//
//    for (i = 1, sum = 1; i <= n; i++)
//        sum *= x;
//
//    printf("The result of %i to the %i is %li.\n", x, n, sum);
//
//    return (sum);
//}
//
//int main()
//{
//    int i;
//
//    for (i = 0; i <= 10; i++)
//        x_to_the_n(2, i);
//
//    return 0;
//}

/*********************************************************
    Exercise 8
        An equation of the form:

            ax^2 + bx + c = 0

        is known as a quadratic equation. The values of a, b and c in the preceding exampe represent constant values. So

            4x^2 - 17x - 15 = 0

        represents a quadratic equation where a = 4, b = -17 and c = -15. The values of x that satisfy a particular quadratic equation, known as the roots of the equation, can be calculated by substituting the values of a, b and c into the following two formulas:

            x = (-b +- sqrt(b^2 - 4 * ac)) / (2 * a)

        If the value of b^2 - 4 * a * c, called the discriminant, is less than zero, the roots of the equation, x1 and x2, are imaginary numbers.

        Write a program to solve a quadratic equation. The program should allow the user to enter the values for a, b and c. If the discriminant is less than zero, a message should be displayed that the roots of the imaginary; otherwise, the program should then proceed to calculate and display the two roots of the equation. (Note: Be certain to make use of the squareRoot() function that you developed in this chapter.)
*********************************************************/

//#include <stdio.h>
//
//float  absoluteValue (float x)
//{
//    if ( x < 0 )
//        x = -x;
//    return (x);
//}
//
//float  squareRoot (float x)
//{
//    const float  epsilon = .00001F;
//    float        guess   = 1.0F;
//    float        ratio = 0.0F;
//
//
//    if (x == 0.0F)
//    {
//        printf("[ERROR] The value can't be zero.\n");
//        return -1.0;
//    }
//
//
//    while (ratio < (1.0F - epsilon) || ratio > (1.0F + epsilon))
//    {
//        guess = ( x / guess + guess ) / 2.0;
//        ratio = absoluteValue((guess * guess) / x);
//    }
//
//    return guess;
//}
//
//void solveEquation (float a, float b, float c)
//{
//    float discriminant, sol1, sol2;
//
//    discriminant = b * b - 4.0F * a * c;
//
//    if (discriminant < 0)
//        printf("The equation has imaginary roots.\n");
//    else if (a == 0.0F)
//    {
//        printf("The equation provided is not a second grade equation.\n");
//    }
//    else
//    {
//        sol1 = (- b + squareRoot(discriminant)) / (2 * a);
//        sol2 = (- b - squareRoot(discriminant)) / (2 * a);
//        printf("Solution 1 is %.3f and solution 2 is %.3f.\n", sol1, sol2);
//    }
//
//    return;
//}
//
//int main ()
//{
//    float a, b, c;
//    printf("Enter the value for term x^2: ");
//    scanf("%f", &a);
//    printf("\nEnter the value for term x: ");
//    scanf("%f", &b);
//    printf("\nEnter the value for the independent term: ");
//    scanf("%f", &c);
//
//    solveEquation(a, b, c);
//
//    return 0;
//}

/*********************************************************
    Exercise 9
        The least common multiple (lcm) of two positive integers u and v is the smallest positive integer that is evenly divisible by both u and v.
        Thus, the lcm of 15 and 10, written lcm (15, 10), is 30 because 30 is the smallest integer divisible by both 15 and 10.
        Write a function lcm() that takes two integer arguments and returns their lcm.
        The lcm() function should calculate the least common multiple by calling the gcd() function from Program 7.6 in accordance with the following identity:

            lcm(u, v) = (u * v) / gcd(u, V)         u, v >= 0
*********************************************************/

//#include <stdio.h>
//
//int lcm(int u, int v)
//{
//    int gcd(int, int);
//    int lcm;
//
//    if (v >= 0 && u >= 0)
//        lcm = (u * v) / gcd(u, v);
//    else
//    {
//        lcm = -1;
//        printf("Values must be higher than zero or equal to zero.\n");
//    }
//
//    return lcm;
//}
//
//int  gcd (int u, int v)
//{
//    int  temp;
//
//    while ( v != 0 )
//    {
//        temp = u % v;
//        u = v;
//        v = temp;
//    }
//
//    return u;
//}
//
//int main ()
//{
//    int a, b;
//
//    printf("\nEnter the first positive integer value: ");
//    scanf("%i", &a);
//    printf("\nEnter the second positive integer value: ");
//    scanf("%i", &b);
//    printf("\nThe least common multiple of the values entered is %i.\n", lcm(a, b));
//
//    return 0;
//}

/*********************************************************
    Exercise 10
        Write a function prime() that returns 1 if its argument is a prime number and returns 0 otherwise.
*********************************************************/
//
//#include <stdio.h>
//
//int prime(int n)
//{
//    int i, prime = 1;
//
//    for (i = 2; i <= (n / 2); i++)
//        if (!(n % i))
//        {
//            prime = 0;
//            break;
//        }
//
//    return prime;
//}
//
//int main ()
//{
//    int n;
//
//    for (n = 1; n <= 100; n++)
//        prime(n) ? printf("The number %i is prime.\n", n) : 0;
//
//    return 0;
//}

/*********************************************************
    Exercise 11
        Write a function called arraySum() that takes two arguments: an integer array and the number of elements in the array.
        Have the function return as its result the sum of the elements in the array.
*********************************************************/

//#include <stdio.h>
//
//int arraySum (int a[], int n)
//{
//    int i, sum;
//
//    for (i = 0, sum = 0; i < n; i++)
//        sum += n;
//
//    return sum;
//}
//
//int main ()
//{
//    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, n = 10;
//
//    printf("The sum of the elements of the array is %i.\n", arraySum(a, n));
//
//    return 0;
//}

/*********************************************************
    Exercise 12
        A matrix M with i rows, j columns can be transposed into a matrix N having j rows and i columns by simply setting the value of Na,b equal to the value of Mb,a for all relevant values of a and b.
            a. Write a function transposeMatrix() that takes as an argument a 4 × 5 matrix and a 5 × 4 matrix. Have the function transpose the 4 × 5 matrix and store the results in the 5 × 4 matrix. Also write a main() routine to test the function.
            b. Using variable-length arrays, rewrite the transposeMatrix() function developed in exercise 12a to take the number of rows and columns as arguments, and to transpose the matrix of the specified dimensions.
*********************************************************/

//#include <stdio.h>
//
//void transposeMatrix (int nRows, int nCols, int M[nRows][nCols], int N[nCols][nRows])
//{
//    int i, j;
//
//    for (i = 0; i < nCols; i++)
//        for (j = 0; j < nRows; j++)
//            N[i][j] = M[j][i];
//}
//
//int main ()
//{
//    int M[4][5] = {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}, {6, 7, 8, 9, 10}, {10, 9, 8, 7, 6}};
//    int N[5][4];
//    int i, j;
//
//    transposeMatrix(4, 5, M, N);
//
//    printf("Original Matrix M: \n");
//    for (i = 0; i < 4; i++)
//    {
//        for (j = 0; j < 5; j++)
//            printf("%i ", M[i][j]);
//        printf("\n");
//    }
//
//    printf("\nTransposed Matrix N: \n");
//    for (i = 0; i < 5; i++)
//    {
//        for (j = 0; j < 4; j++)
//            printf("%i ", N[i][j]);
//        printf("\n");
//    }
//    printf("\n");
//
//    return 0;
//}

/*********************************************************
    Exercise 13
        Modify the sort() function from Program 7.12 to take a third argument indicating whether the array is to be sorted in ascending or descending order.
        Then modify the sort() algorithm to correctly sort the array into the indicated order.
*********************************************************/

//#include <stdio.h>
//#include <stdbool.h>
//
//void  sort (int  a[], int  n, bool ascending)
//{
//    int  i, j, temp;
//
//    for ( i = 0;  i < n - 1;  ++i )
//        for ( j = i + 1;  j < n;  ++j )
//        {
//            if (ascending ? a[i] > a[j] : a[i] < a[j])
//            {
//                temp = a[i];
//                a[i] = a[j];
//                a[j] = temp;
//            }
//        }
//}
//
//int main (void)
//{
//    int  i;
//    int  array[16] = { 34, -5, 6, 0, 12, 100, 56, 22,
//                       44, -3, -9, 12, 17, 22, 6, 11
//                     };
//    void sort (int [], int , bool);
//
//    printf ("The array before the sort:\n");
//
//    for ( i = 0;  i < 16;  ++i )
//        printf ("%i ", array[i]);
//
//    sort (array, 16, false);
//
//    printf ("\n\nThe array after the sort:\n");
//
//    for ( i = 0;  i < 16;  ++i )
//        printf ("%i ", array[i]);
//
//    printf ("\n");
//
//    return 0;
//}

/*********************************************************
    Exercise 15
        Modify Program 7.14 so that the user is asked again to type in the value of the base if an invalid base is entered. The modified program should continue to ask for the value of the base until a valid response is given.
*********************************************************/

//// Program to convert a positive integer to another base
//
//#include <stdio.h>
//
//int       convertedNumber[64];
//long int  numberToConvert;
//int       base;
//int       digit = 0;
//
//void  getNumber (void)
//{
//    printf ("Number to be converted? ");
//    scanf ("%li", &numberToConvert);
//}
//
//void getBase (void)
//{
//    printf ("Base? ");
//    scanf ("%i", &base);
//
//    if  ( base < 2  ||  base > 16 )
//    {
//        printf ("Bad base - must be between 2 and 16\n");
//        getBase();
//    }
//}
//
//void  convertNumber (void)
//{
//    do
//    {
//        convertedNumber[digit] = numberToConvert % base;
//        ++digit;
//        numberToConvert /= base;
//    } while  ( numberToConvert != 0 );
//}
//
//void  displayConvertedNumber (void)
//{
//    const char  baseDigits[16] =
//    {
//        '0', '1', '2', '3', '4', '5', '6', '7',
//
//        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
//    };
//    int   nextDigit;
//
//    printf ("Converted number = ");
//
//    for (--digit;  digit >= 0; --digit )
//    {
//        nextDigit = convertedNumber[digit];
//        printf ("%c", baseDigits[nextDigit]);
//    }
//
//    printf ("\n");
//}
//
//int main (void)
//{
//    void getNumber (void);
//    void getBase (void);
//    void convertNumber (void);
//    void displayConvertedNumber (void);
//
//    getNumber ();
//    getBase ();
//    convertNumber ();
//    displayConvertedNumber ();
//
//    return 0;
//}

/*********************************************************
    Exercise 16
        Modify Program 7.14 so that the user can convert any number of integers. Make provision for the program to terminate when a zero is typed in as the value of the number to be converted.
*********************************************************/

//// Program to convert a positive integer to another base
//
//#include <stdio.h>
//
//int       convertedNumber[64];
//long int  numberToConvert;
//int       base;
//int       digit = 0;
//
//int getNumber (void)
//{
//    printf ("Number to be converted? ");
//    scanf ("%li", &numberToConvert);
//    return numberToConvert;
//}
//
//void getBase (void)
//{
//    printf ("Base? ");
//    scanf ("%i", &base);
//
//    if  ( base < 2  ||  base > 16 )
//    {
//        printf ("Bad base - must be between 2 and 16\n");
//        getBase();
//    }
//}
//
//void  convertNumber (void)
//{
//    do
//    {
//        convertedNumber[digit] = numberToConvert % base;
//        ++digit;
//        numberToConvert /= base;
//    } while  ( numberToConvert != 0 );
//}
//
//void  displayConvertedNumber (void)
//{
//    const char  baseDigits[16] =
//    {
//        '0', '1', '2', '3', '4', '5', '6', '7',
//
//        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
//    };
//    int   nextDigit;
//
//    printf ("Converted number = ");
//
//    for (--digit;  digit >= 0; --digit )
//    {
//        nextDigit = convertedNumber[digit];
//        printf ("%c", baseDigits[nextDigit]);
//    }
//
//    printf ("\n");
//}
//
//int main (void)
//{
//    int getNumber (void);
//    void getBase (void);
//    void convertNumber(void);
//    void displayConvertedNumber(void);
//
//    while (getNumber()) {
//        getBase ();
//        convertNumber ();
//        displayConvertedNumber ();
//    }
//
//    return 0;
//}
