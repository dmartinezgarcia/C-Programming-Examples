/* NOTE: Select an exercise and use CTRL+MAYUS+C to comment it. Select an exercise and use CTRL+MAYUS+X to uncomment it. */

/*********************************************************
    Exercise 1
		Type in and run the seven programs presented in this chapter. Compare the output produced by each program with the output presented after each program in the text.
*********************************************************/

// The output is the same as in the book.

/*********************************************************
    Exercise 2
		In certain applications, particularly in the financial area, it is often necessary to calculate the number of elapsed days between two dates. For example, the number of days between July 2, 2015, and July 16, 2015, is obviously 14. But how many days are there between August 8, 2014, and February 22, 2015? This calculation requires a bit more thought.

Luckily, a formula can be used to calculate the number of days between two dates. This is affected by computing the value of N for each of the two dates and then taking the difference, where N is calculated as follows:

N = 1461 x f(year, month) / 4 + 153 x g(month) / 5  + day

where:

f(year, month)    =    year - 1          if  month <= 2
                       year              otherwise

g(month)  =       month + 13        if month <= 2
                  month + 1         otherwise

As an example of applying the formula, to calculate the number of days between August 8, 2004, and February 22, 2005, you can calculate the values of N1 and N2 by substituting the appropriate values into the preceding formula as shown:

N1    = 1461 x f(2004, 8) / 4  +  153 x g(8) / 5  +  3
      = (1461 x 2004) / 4  +  (153 x 9) / 5  +  3
      = 2,927,844 / 4  +  1,377 / 5  +  3
      = 731,961 + 275 + 3
      = 732,239

N2    = 1461 x f(2005, 2) / 4  +  153 x g(2) / 5  +  21
      = (1461 x 2004) / 4  +  (153 x 15) / 5  +  21
      = 2,927,844 / 4  +  2295 / 5  +  21
      = 731,961 + 459 + 21
      = 732,441

Number of elapsed days = N2-N1 = 732.441 - 732.239 = 202

So the number of days between the two dates is shown to be 202. The preceding formula is applicable for any dates after March 1, 1900 (1 must be added to N for dates from March 1, 1800, to February 28, 1900, and 2 must be added for dates between March 1, 1700, and February 28, 1800).

Write a program that permits the user to type in two dates and then calculates the number of elapsed days between the two dates. Try to structure the program logically into separate functions. For example, you should have a function that accepts as an argument a date structure and returns the value of N computed as shown previously. This function can then be called twice, once for each date, and the difference taken to determine the number of elapsed days.
*********************************************************/

// The example above is wrong, it should be 198 days.

//#include <stdio.h>
//
//struct date
//{
//    int day;
//    int month;
//    int year;
//};
//
//int calculateN (struct date d)
//{
//    int N;
//    int f, g;
//
//    if (d.month <= 2)
//    {
//        f = d.year - 1;
//        g = d.month + 13;
//    }
//    else
//    {
//        f = d.year;
//        g = d.month + 1;
//    }
//
//    N = ( 1461 * f / 4 ) + ( 153 * g / 5) + d.day;
//
//    printf("%i\n", N);
//
//    return N;
//}
//
//int calculateDiffDays (struct date firstDate, struct date secondDate)
//{
//    int Days;
//
//    Days = (calculateN(firstDate) - calculateN(secondDate));
//
//    return Days;
//}
//
//int main ()
//{
//    struct date a = {0, 0, 0}, b = {0, 0, 0};
//
//    printf("\nType the value of the first date (dd/mm/yyyy): ");
//    scanf("%i/%i/%i", &a.day, &a.month, &a.year);
//    printf("You entered: %i/%i/%i.\n", a.day, a.month, a.year);
//    printf("\nType the value of the second date (dd/mm/yyyy): ");
//    scanf("%i/%i/%i", &b.day, &b.month, &b.year);
//    printf("You entered: %i/%i/%i.\n", b.day, b.month, b.year);
//
//    printf("\nThe days between the dates entered by the user is: %i.\n", calculateDiffDays(a, b));
//
//    return 0;
//}
//


