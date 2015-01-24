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

//#include <stdio.h>
//
//int main ()
//{
//    int a = 0, b = 0;
//
//    printf("Please input two integer positive numbers: ");
//    scanf("%i %i", &a, &b);
//
//    if (!(a % b))
//        printf("\n%i is evenly divisable by %i", a, b);
//    else
//        printf("\n%i is NOT evenly divisable by %i", a, b);
//
//    return 0;
//}

/*********************************************************
    Exercise 3
        Write a program that accepts two integer values typed in by the user. Display the result of dividing the first integer by the second, to three-decimal-place accuracy. Remember to have the program check for division by zero.
*********************************************************/

//#include <stdio.h>
//
//int main ()
//{
//    int a = 0, b = 0;
//
//    printf("Please input two integer positive numbers: ");
//    scanf("%i %i", &a, &b);
//
//    (b > 0) ?
//            printf("Result of %i / %i is %.3f.\n", a, b, (float)a / b)
//            : printf("Division by zero not allowed.\n");
//
//    return 0;
//}

/*********************************************************
    Exercise 4
        Write a program that acts as a simple "printing" calculator. The program should allow the user to type in expressions of the form:
            number operator
        The following operators should be recognized by the program:
            + - * / S E
        The S operator tells the program to set the accumulator to the typed-in number. The E operator tells the program that execution is to end.
        The arithmetic operations are performed on the contents of the accumulator with the number that was keyed in acting as second operand.
        The following is a sample run showing how the program should operate
            Begin calculations
            10 S                Set accumulator to 10
            = 10.000000         Contents of accumulator
            2 /                 Divide by 2
            = 5.000000          Contents of accumulator
            55 -                Substract 55
            -50.000000
            100.25 S            Set accumulator to 100.25
*********************************************************/

//#include <stdio.h>
//#include <stdbool.h>
//
//int main ()
//{
//    float n = 0;
//    float acc = 0.0F;
//    bool exit = false;
//    char op = '0';
//
//    while (!exit)
//    {
//        printf("Please enter a number and an operator (+-*/SE): ");
//        scanf("%f %c", &n, &op);
//        printf("\n");
//        printf("%.3f %c          ", n, op);
//
//        switch (op)
//        {
//        case '+':
//            acc += n;
//            printf("Add %f to accumulator.", n);
//            break;
//        case '-':
//            acc -= n;
//            printf("Substract %f to accumulator.", n);
//            break;
//        case '*':
//            acc *= n;
//            printf("Multiply by %f accumulator.", n);
//            break;
//        case '/':
//            if (n != 0)
//            {
//                acc /= n;
//                printf("Divide by %f accumulator.", n);
//            }
//            else
//                printf("Division by zero not allowed.");
//            break;
//        case 'S':
//            printf("Set to %f accumulator.", n);
//            acc = n;
//            break;
//        case 'E':
//            printf("Exit from program.");
//            exit = true;
//            break;
//        default:
//            printf("Unknown operator.");
//            break;
//        }
//
//        printf("\n= %.6f          Contents of the accumulator.\n", acc);
//    }
//
//    return 0;
//}


/*********************************************************
    Exercise 5
        You developed Program 4.9 to reverse the digits of an integer typed in from the terminal.
        However, this program does not function well if you type in a negative number.
        Find out what happens in such a case and then modify the program so that negative numbers are correctly handled.
        For example, if the number −8645 is typed in, the output of the program should be 5468−.
*********************************************************/

//#include <stdio.h>
//
//int main ()
//{
//    int  number, right_digit;
//    _Bool isNeg = 0;
//
//    printf ("Enter your number.\n");
//    scanf ("%i", &number);
//
//    if (number < 0)
//    {
//        number = -number;
//        isNeg = 1;
//    }
//
//    do
//    {
//        right_digit = number % 10;
//        printf ("%i", right_digit);
//        number = number / 10;
//    } while ( number != 0 );
//
//    if (isNeg)
//        printf("-");
//
//    printf ("\n");
//    return 0;
//}

/*********************************************************
    Exercise 6
        Write a program that takes an integer keyed in from the terminal and extracts and displays each digit of the integer in English. So, if the user types in 932, the program should display
            nine three two
        Remember to display “zero” if the user types in just a 0. (Note: This exercise is a hard one!)
*********************************************************/

//#include <stdio.h>
//
//int main ()
//{
//    int n = 0, digit = 0, op = 1;
//
//    printf("Please input an integer number: ");
//    scanf("%i", &n);
//
//    while (n >= op || (n == 0 && op == 1))
//        op = op * 10;
//
//    do
//    {
//        op /= 10;
//        digit = n / op;
//
//        switch (digit)
//        {
//        case 1:
//            printf("one ");
//            break;
//        case 2:
//            printf("two ");
//            break;
//        case 3:
//            printf("three ");
//            break;
//        case 4:
//            printf("four ");
//            break;
//        case 5:
//            printf("five ");
//            break;
//        case 6:
//            printf("six ");
//            break;
//        case 7:
//            printf("seven ");
//            break;
//        case 8:
//            printf("eight ");
//            break;
//        case 9:
//            printf("nine ");
//            break;
//        case 0:
//            printf("zero ");
//            break;
//        }
//
//        n = n % op;
//    } while (n);
//
//    printf("\n");
//    return 0;
//}

/*********************************************************
    Exercise 7
        Program 5.10 has several inefficiencies. One inefficiency results from checking even numbers.
        Because it is obvious that any even number greater than 2 cannot be prime, the program could simply skip all even numbers as possible primes and as possible divisors.
        The inner for loop is also inefficient because the value of p is always divided by all values of d from 2 through p−1.
        This inefficiency could be avoided by adding a test for the value of isPrime in the conditions of the for loop.
        In this manner, the for loop could be set up to continue as long as no divisor was found and the value of d was less than p.
        Modify Program 5.10 to incorporate these two changes. Then run the program to verify its operation.
        (Note: In Chapter 6, you discover even more efficient ways of generating prime numbers.)
*********************************************************/

//  Program to generate a table of prime numbers

//#include <stdio.h>
//#include <stdbool.h>
//
//int main (void)
//{
//    int   p, d;
//    bool  isPrime;
//
//    for ( p = 2;  p <= 50; p++)
//    {
//        if (!(p % 2) && p > 2)
//            continue;
//
//        isPrime = true;
//
//        for ( d = 2;  d < p;  ++d )
//        {
//            if (!(d % 2))
//                continue;
//
//            if ( p % d  ==  0 )
//            {
//                isPrime = false;
//                break;
//            }
//        }
//
//        if ( isPrime != false )
//            printf ("%i  ", p);
//    }
//
//    printf ("\n");
//    return 0;
//}
