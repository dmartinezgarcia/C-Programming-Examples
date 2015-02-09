/* NOTE: Select an exercise and use CTRL+MAYUS+C to comment it. Select an exercise and use CTRL+MAYUS+X to uncomment it. */

/*********************************************************
    Exercise 1
		Type in and run the three programs presented in this chapter, remembering to type in the .h include file associated with Program 12.3. Compare the output produced by each program with the output presented in the text.
*********************************************************/



/*********************************************************
    Exercise 2
		Locate the system header files <stdio.h>, <limits.h>, and <float.h> on your system (on Unix systems, look inside the /usr/include directory). Examine the files to see what’s in them.
*********************************************************/

/*********************************************************
    Exercise 3
		Define a macro MIN that gives the minimum of two values. Then write a program to test the macro definition.
*********************************************************/

/*********************************************************
    Exercise 4
		Define a macro MAX3 that gives the maximum of three values. Write a program to test the definition.
*********************************************************/

/*********************************************************
    Exercise 5
		Write a macro SHIFT to perform the identical purpose as the shift function of Program 11.3.
*********************************************************/

/*********************************************************
    Exercise 6
		Write a macro IS_UPPER_CASE that gives a nonzero value if a character is an uppercase letter.
*********************************************************/

/*********************************************************
    Exercise 7
		Write a macro IS_ALPHABETIC that gives a nonzero value if a character is an alphabetic character. Have the macro use the IS_LOWER_CASE macro defined in the chapter text and the IS_UPPER_CASE macro defined in exercise 6.
*********************************************************/

/*********************************************************
    Exercise 8
		Write a macro IS_DIGIT that gives a nonzero value if a character is a digit '0' through '9'. Use this macro in the definition of another macro IS_SPECIAL, which gives a nonzero result if a character is a special character; that is, not alphabetic and not a digit. Be certain to use the IS_ALPHABETIC macro developed in exercise 7.
*********************************************************/

/*********************************************************
    Exercise 9
		Write a macro ABSOLUTE_VALUE that computes the absolute value of its argument. Make certain that an expression such as

            ABSOLUTE_VALUE (x + delta)

        is properly evaluated by the macro.
*********************************************************/

/*********************************************************
    Exercise 10
        Consider the definition of the printint macro from this chapter:

            #define printint(n)  printf ("%i\n", x ## n)

        Could the following be used to display the values of the 100 variables x1–x100? Why or why not?

            for (i = 1; i < 100; ++i)
                printx (i);
*********************************************************/

/*********************************************************
    Exercise 11
        Test the system library functions that are equivalent to the macros you developed in the preceding three exercises. The library functions are called isupper, isalpha, and isdigit. You need to include the system header file <ctype.h> in your program in order to use them.
*********************************************************/

