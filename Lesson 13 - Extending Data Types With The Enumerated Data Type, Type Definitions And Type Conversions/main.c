/* NOTE: Select an exercise and use CTRL+MAYUS+C to comment it. Select an exercise and use CTRL+MAYUS+X to uncomment it. */

/*********************************************************
    Exercise 1
		Define a type FunctionPtr() (using typedef) that represents a pointer to a function that returns an int and that takes no arguments. Refer to Chapter 10, “Pointers,” for the details on how to declare a variable of this type.
*********************************************************/

//#include <stdio.h>
//
//typedef int (*fPtr)(void);
//
//int Function (void)
//{
//    return 5;
//}
//
//int main (void)
//{
//    fPtr function1;
//
//    function1 = Function;
//
//    printf("The result of function is: %i.\n", function1());
//
//    return 0;
//}

/*********************************************************
    Exercise 2
		Write a function called monthName() that takes as its argument a value of type enum month (as defined in this chapter) and returns a pointer to a character string containing the name of the month. In this way, you can display the value of an enum month variable with a statement such as:

            printf ("%s\n", monthName (aMonth));
*********************************************************/

//#include <stdio.h>
//
//typedef enum {January, February, March, April, May, June, July, August, September, October, November, December} month;
//
//char* monthName (month a)
//{
//    switch (a)
//    {
//    case January:
//        return "January";
//    case February:
//        return "February";
//    case March:
//        return "March";
//    case April:
//        return "April";
//    case May:
//        return "May";
//    case June:
//        return "June";
//    case July:
//        return "July";
//    case August:
//        return "August";
//    case September:
//        return "September";
//    case October:
//        return "October";
//    case November:
//        return "November";
//    case December:
//        return "December";
//    default:
//        return "";
//    }
//}
//
//int main (void)
//{
//    month month1 = October;
//
//    printf("The month specified is %s.\n", monthName(month1));
//
//    return 0;
//}

/*********************************************************
    Exercise 3
		Given the following variable declarations:

            float     f = 1.00;
            short int i = 100;
            long int  l = 500L;
            double    d = 15.00;

        and the seven steps outlined in this chapter for conversion of operands in expressions, determine the type and value of the following expressions:

            f + i
            l / d
            i / l + f
            l * i
            f / 2
            i / (d + f)
            l / (i * 2.0)
            l + i / (double) l
*********************************************************/

// Easy to do following the rules described in this chapter.
