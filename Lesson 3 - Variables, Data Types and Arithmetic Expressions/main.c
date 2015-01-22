/* NOTE: Select an exercise and use CTRL+MAYUS+C to comment it. Select an exercise and use CTRL+MAYUS+X to uncomment it. */

/*********************************************************
    Exercise 1
        Type in and run the five programs presented in this chapter. Compare the output produced by each program with the output presented after each program in the text.
*********************************************************/

// All the inputs from all the programs are the same as in the book.

/*********************************************************
    Exercise 2
        Which of the following are invalid variable names? Why?
            Int             char        6_05
            Calloc          Xx          alpha_beta_routine
            floating        _1312       z
            ReInitialize    _           a$
*********************************************************/

// Int - Valid.
// Calloc - Valid.
// floating - Valid.
// Reinitialize - Valid.
// char - Not valid, reserved keyword.
// Xx - Valid.
// _1312 - Valid.
// _ - Valid.
// 6_05 - Not valid, starts with a number.
// alpha_beta_routine - Valid.
// z - Valid.
// a$ - Not valid, $ is not a valid character.

/*********************************************************
    Exercise 3
        Which of the following are invalid constants? Why?
            123.456
            0001
            0Xab05
            123.5e2
            98.6F
            0996
            1234uL
            1.234L
            0XABCDEFL
            0x10.5
            0xFFFF
            0L
            .0001
            98.7U
            -12E-12
            1.2Fe-7
            197u
            0xabcu
            0X0G1
            123L
            -597.25
            +12
            17777s
            07777
            15,000
            100U
            +123
*********************************************************/

// 123.456 - Valid.
// 0001 - Valid.
// 0Xab05 - Valid.
// 123.5e2 - Valid.
// 98.6F - Valid.
// 0996 - Valid.
// 1234uL - Valid.
// 1.234L - Valid.
// 0XABCDEFL - Valid.
// 0x10.5 - Not valid, this is not the correct way to express hex floating constants.
// 0xFFFF - Valid.
// 0L - Valid.
// .0001 - Valid.
// 98.7U - Not valid, U can't be used with floating constants.
// -12E-12 - Valid.
// 1.2Fe-7 - Not valid, F should be at the end of the word (suffix).
// 197u - Valid.
// 0xabcu - Valid.
// 0X0G1 - Not valid, G1 is not a valid suffix.
// 123L - Valid.
// -597.25 - Valid.
// +12 - Valid.
// 17777s - Not valid, S s is not a valid suffix.
// 07777 - Valid.
// 15,000 - Not valid, decimal mark should be a dot and not a comma.
// 100U - Valid.
// +123 - Valid.

/*********************************************************
    Exercise 4
        Write a program that converts 27® from degrees Fahrenheit (F) to degrees Celsius (C) using the following formula:
            C = (F - 32) / 1.8
*********************************************************/

//#include <stdio.h>
//
//int main() {
//    printf("27 Fahrenheit degrees equals %g Celsius Degrees.\n", (27 - 32) / 1.8F);
//    return 0;
//}

/*********************************************************
    Exercise 5
        What output would you expect from the following program?

            #include <stdio.h>
            int main (void)
            {
                char c, d;
                c = 'd';
                d = c;
                printf ("d = %c\n", d);
                return 0;
            }
*********************************************************/

// The output is "d = d".

/*********************************************************
    Exercise 6
        Write a program to evaluate the polynomial shown here:
            3x^3-5x^2+6=0.
        for x=2.55.
*********************************************************/

//#include <stdio.h>
//#include <math.h>
//
//int main() {
//    printf("The value of the polynomial for x = 2.55 is: %g.\r\n", 3 * powf(2.55F, 3.0F) - 5 * (2.55F, 2.0F) + 6);
//    return 0;
//}

/*********************************************************
    Exercise 7
        Write a program that evaluates the following expression and displays the results (remember to use the exponential format to display the result):
            (3.31 * 10 ^ (-8) * 2.01 * 10 ^ (-7)) / (7.16 * 10 ^ (-6) + 2.01 * 10 ^ (-8))
*********************************************************/

//#include <stdio.h>
//
//int main() {
//    printf("The result of the expression above is the following: %g.\r\n", 3.31F * 10e-8 * 2.01F * 10e-7 / (7.16F * 10e-6 + 2.01F * 10e-8));
//    return 0;
//}

/*********************************************************
    Exercise 8 and 9
        To round off an integer i to the next largest even multiple of another integer j, the following formula can be used:
            Next_Multiple = i + j - i % j
        For example, to round off 256 days to the next largest number of days evenly divisible by a week, values of i = 256 and j = 7 can be substituted into the preceding formula as follows:
            Next_Multiple = 256 + 7 - 256 % 7
                          = 256 + 7 -4
                          = 259
        Write a program to find the next largest even multiple for the following values of i and j:
            i = 365, j = 7 | i = 12.258, j = 21 | i = 996, j = 4
*********************************************************/

//#include <stdio.h>
//
//int main() {
//    printf("i = 365, j = 7. Next largest integer is: %i.\n", 365 + 7 - 365 % 7);
//    printf("i = 12.258, j = 21. Next largest integer is %i.\n", (int)12.258F + 21 - (int)12.258F % 21);
//    printf("i = 996, j = 4. Next largest integer is %i.\n", 996 + 4 - 996 % 4);
//}
