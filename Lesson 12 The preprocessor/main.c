/* NOTE: Select an exercise and use CTRL+MAYUS+C to comment it. Select an exercise and use CTRL+MAYUS+X to uncomment it. */

/*********************************************************
    Exercise 1
		Type in and run the three programs presented in this chapter, remembering to type in the .h include file associated with Program 12.3. Compare the output produced by each program with the output presented in the text.
*********************************************************/

// The output is the same.

/*********************************************************
    Exercise 2
		Locate the system header files <stdio.h>, <limits.h>, and <float.h> on your system (on Unix systems, look inside the /usr/include directory). Examine the files to see what’s in them.
*********************************************************/

// These files are located at the codeblocks directory, particularly in the MinGW compiler directory.

/*********************************************************
    Exercise 3
		Define a macro MIN that gives the minimum of two values. Then write a program to test the macro definition.
*********************************************************/

//#include <stdio.h>
//
//#define MIN(a, b)   ( (a) < (b) ? (a) : (b) )
//
//int main (void)
//{
//    int a = 5, b = 8;
//
//    printf("The first number is %i and the second numbre is %i, the minimum value is %i.\n", a, b, MIN(a, b));
//
//    return 0;
//}

/*********************************************************
    Exercise 4
		Define a macro MAX3 that gives the maximum of three values. Write a program to test the definition.
*********************************************************/

//#include <stdio.h>
//
//#define MAX3(a, b, c)   ( (a) > (b) ? ( (a) > (c) ? (a) : (c) ) : ( (b) > (c) ? (b) : (c) ) )
//
//int main (void)
//{
//    int a = 10, b = 8, c = 12;
//
//    printf("The first number is %i and the second number is %i and the third number is %i, the maximum value is %i.\n", a, b, c, MAX3(a, b, c));
//
//    return 0;
//}

/*********************************************************
    Exercise 5
		Write a macro SHIFT to perform the identical purpose as the shift function of Program 11.3.
*********************************************************/

//#include <stdio.h>
//
//#define SHIFT(val, n)   ( ((n) > 0) ? ((val) << (n)) : ((val) >> (-(n))) )
//
//unsigned int  shift (unsigned int  value, int  n)
//{
//    if ( n > 0 )     // left shift
//        value <<= n;
//    else             // right shift
//        value >>= -n;
//
//    return value;
//}
//
//int main (void)
//{
//    unsigned int h = 30U;
//    signed int z = -20;
//
//    printf("Function result: %i.\n", shift(h, z));
//    printf("Macro result: %i.\n", SHIFT(h, z));
//
//    return 0;
//}

/*********************************************************
    Exercise 6
		Write a macro IS_UPPER_CASE that gives a nonzero value if a character is an uppercase letter.
*********************************************************/

//#include <stdio.h>
//
//#define IS_UPPER_CASE(x)    ( ((x) <= 'Z' && (x) >= 'A') ? 1 : 0)
//
//int main (void)
//{
//    char c = 'A';
//
//    printf("Is %c upper case? %i.\n", c, IS_UPPER_CASE(c));
//
//    return 0;
//}

/*********************************************************
    Exercise 7
		Write a macro IS_ALPHABETIC that gives a nonzero value if a character is an alphabetic character. Have the macro use the IS_LOWER_CASE macro defined in the chapter text and the IS_UPPER_CASE macro defined in exercise 6.
*********************************************************/

//#include <stdio.h>
//
//#define IS_LOWER_CASE(x)    ( ((x) <= 'z' && (x) >= 'a') ? 1 : 0)
//#define IS_UPPER_CASE(x)    ( ((x) <= 'Z' && (x) >= 'A') ? 1 : 0)
//#define IS_ALPHABETIC(x)    ( (IS_LOWER_CASE(x) || IS_UPPER_CASE(x)) ? 1 : 0 )
//
//int main (void)
//{
//    char c = '1';
//
//    printf("Is %c upper case? %i.\n", c, IS_ALPHABETIC(c));
//
//    return 0;
//}

/*********************************************************
    Exercise 8
		Write a macro IS_DIGIT that gives a nonzero value if a character is a digit '0' through '9'. Use this macro in the definition of another macro IS_SPECIAL, which gives a nonzero result if a character is a special character; that is, not alphabetic and not a digit. Be certain to use the IS_ALPHABETIC macro developed in exercise 7.
*********************************************************/

//#include <stdio.h>
//
//#define IS_LOWER_CASE(x)    ( ((x) <= 'z' && (x) >= 'a') ? 1 : 0)
//#define IS_UPPER_CASE(x)    ( ((x) <= 'Z' && (x) >= 'A') ? 1 : 0)
//#define IS_ALPHABETIC(x)    ( (IS_LOWER_CASE(x) || IS_UPPER_CASE(x)) ? 1 : 0 )
//#define IS_DIGIT(x)         ( ((x) >= '0' && (x) <= '9') ? 1 : 0 )
//#define IS_SPECIAL(x)       ( (IS_DIGIT(x) || IS_ALPHABETIC(x)) ? 0 : 1 )
//
//int main (void)
//{
//    char c = '1';
//
//    printf("Is %c an special character? %i.\n", c, IS_SPECIAL(c));
//
//    return 0;
//}

/*********************************************************
    Exercise 9
		Write a macro ABSOLUTE_VALUE that computes the absolute value of its argument. Make certain that an expression such as

            ABSOLUTE_VALUE (x + delta)

        is properly evaluated by the macro.
*********************************************************/

//#include <stdio.h>
//
//#define ABSOLUTE_VALUE(x)   ( (x) < 0 ? (-(x)) : (x) )
//
//int main (void)
//{
//    signed int a = 12;
//    signed int b = 40;
//
//    printf("The absolute value of %i is %i.\n", a - b, ABSOLUTE_VALUE(a - b));
//
//    return 0;
//}

/*********************************************************
    Exercise 10
        Consider the definition of the printx macro from this chapter:

            #define printint(n)  printf ("%i\n", x ## n)

        Could the following be used to display the values of the 100 variables x1–x100? Why or why not?

            for (i = 1; i < 100; ++i)
                printx (i);
*********************************************************/

// No it can't. It's not the value of the variable that it's concatenated to x but the name of the variable i.

//#include <stdio.h>
//
//#define printx(n)  printf ("%i\n", x ## n)
//
//int main (void)
//{
//    int x1 = 1, x2 = 2, x3 = 3, x4 = 4, x5 = 5, x6 = 6;
//    int i = 0;
//
//    for (i = 1; i < 100; ++i)
//        printx (i);
//
//    return 0;
//}

/*********************************************************
    Exercise 11
        Test the system library functions that are equivalent to the macros you developed in the preceding three exercises. The library functions are called isupper, isalpha, and isdigit. You need to include the system header file <ctype.h> in your program in order to use them.
*********************************************************/

// They produce the same results.
