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
//    printf("\nType the value of the first date ([d]d/[m]m/yyyy): ");
//    scanf("%i/%i/%i", &a.day, &a.month, &a.year);
//    printf("You entered: %i/%i/%i.\n", a.day, a.month, a.year);
//    printf("\nType the value of the second date ([d]d/[m]m/yyyy): ");
//    scanf("%i/%i/%i", &b.day, &b.month, &b.year);
//    printf("You entered: %i/%i/%i.\n", b.day, b.month, b.year);
//
//    printf("\nThe days between the dates entered by the user is: %i.\n", calculateDiffDays(a, b));
//
//        return 0;
//}
//

/*********************************************************
    Exercise 3
    Write a function elapsed_time that takes as its arguments two time structures and returns a time structure that represents the elapsed time (in hours, minutes, and seconds) between the two times. So the call

        elapsed_time (time1, time2)

    where time1 represents 3:45:15 and time2 represents 9:44:03, should return a time structure that represents 5 hours, 58 minutes, and 48 seconds. Be careful with times that cross midnight.
*********************************************************/

//#include <stdio.h>
//
//struct time
//{
//    int hour;
//    int minute;
//    int second;
//};
//
//struct time elapsedTime (struct time firstTime, struct time secondTime)
//{
//    signed short int seconds = 0, minutes = 0, hours = 0;
//    struct time elapsedTime;
//
//    if ((seconds = secondTime.second - firstTime.second) < 0)
//        seconds += 60, minutes -= 1;
//
//    if ((minutes += secondTime.minute - firstTime.minute) < 0)
//        minutes += 60, hours -= 1;
//
//    if ((hours += secondTime.hour - firstTime.hour) < 0)
//        hours += 24;
//
//    elapsedTime = (struct time) {hours, minutes, seconds};
//
//    return elapsedTime;
//}
//
//int main ()
//{
//    struct time a = {12, 44, 03}, b = {12, 21, 33}, c = {0, 0, 0};
//
//    c = elapsedTime(a, b);
//
//    printf("The elapsed time is: %.2i:%.2i:%.2i.\n", c.hour, c.minute, c.second);
//
//    return 0;
//}

/*********************************************************
    Exercise 4
        If you take the value of N as computed in exercise 2, subtract 621,049 from it, and then take that result modulo 7, you get a number from 0 to 6 that represents the day of the week (Sunday through Saturday, respectively) on which the particular day falls. For example, the value of N computed for August 8, 2004, is 732,239 as derived previously. 732,239 − 621,049 gives 111,190, and 111,190 % 7 gives 2, indicating that this date falls on a Tuesday.

        Use the functions developed in the previous exercise to develop a program that displays the day of the week on which a particular date falls. Make certain that the program displays the day of the week in English (such as “Monday”).
*********************************************************/

// The example above is wrong, it should be 198 days.

//#include <stdio.h>
//
//struct date
//{
//    int day;
//    int month;
//    int year;
//    char dayName[10];
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
//// Can be improved by using features explained in later lessons.
//struct date createDate (int day, int month, int year)
//{
//    static const int constant = 621049;
//    static const char week[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//    struct date r = {day, month, year, {0, 0}};
//    int dayIndex = 0, i = 0;
//
//    dayIndex = (calculateN(r) - constant) % 7;
//
//    printf("\n%i\n", calculateN(r));
//
//    for (i = 0; week[dayIndex][i]; i++)
//        r.dayName[i] = week[dayIndex][i];
//
//    return r;
//}
//
//int main ()
//{
//    struct date a, b;
//    int day, month, year;
//
//    printf("\nType the value of the first date ([d]d/[m]m/yyyy): ");
//    scanf("%i/%i/%i", &day, &month, &year);
//    a = createDate(day, month, year);
//    printf("You entered: %i/%i/%i, which falls on %s.\n", a.day, a.month, a.year, a.dayName);
//    printf("\nType the value of the second date ([d]d/[m]m/yyyy): ");
//    scanf("%i/%i/%i", &day, &month, &year);
//    b = createDate(day, month, year);
//    printf("You entered: %i/%i/%i, which falls on %s.\n", b.day, b.month, b.year, b.dayName);
//
//    printf("The days between the dates entered by the user is: %i.\n", calculateDiffDays(a, b));
//
//    return 0;
//}

/*********************************************************
    Exercise 5
        Write a function called clockKeeper() that takes as its argument a dateAndTime structure as defined in this chapter. The function should call the timeUpdate() function, and if the time reaches midnight, the function should call the dateUpdate function to switch over to the next day. Have the function return the updated dateAndTime structure.
*********************************************************/

//#include <stdio.h>
//#include <stdbool.h>
//
//struct date
//{
//    int day;
//    int month;
//    int year;
//};
//
//struct time
//{
//    int seconds;
//    int minutes;
//    int hour;
//};
//
//struct timeAndDate
//{
//    struct date Date;
//    struct time Time;
//};
//
//struct time  timeUpdate (struct time  now)
//{
//    ++now.seconds;
//
//    if ( now.seconds == 60 )        // next minute
//    {
//        now.seconds = 0;
//        ++now.minutes;
//
//        if ( now.minutes == 60 )    // next hour
//        {
//            now.minutes = 0;
//            ++now.hour;
//
//            if ( now.hour == 24 ) // midnight
//                now.hour = 0;
//        }
//    }
//    return now;
//}
//
//bool  isLeapYear (struct date  d)
//{
//    bool  leapYearFlag;
//
//    if ( (d.year % 4 == 0  &&  d.year % 100 != 0)  ||
//            d.year % 400 == 0 )
//        leapYearFlag = true;   // It's a leap year
//    else
//        leapYearFlag = false;  // Not a leap year
//
//    return leapYearFlag;
//}
//
//int  numberOfDays  (struct date  d)
//{
//    int  days;
//    bool isLeapYear (struct date  d);
//    const int  daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//    if ( isLeapYear (d)  &&  d.month == 2 )
//        days = 29;
//    else
//        days = daysPerMonth[d.month - 1];
//
//    return days;
//}
//
//struct date  dateUpdate (struct date  today)
//{
//    struct date  tomorrow;
//    int  numberOfDays (struct date  d);
//
//    if ( today.day != numberOfDays (today) )
//    {
//        tomorrow.day = today.day + 1;
//        tomorrow.month = today.month;
//        tomorrow.year = today.year;
//    }
//    else if ( today.month == 12 )      // end of year
//    {
//        tomorrow.day = 1;
//        tomorrow.month = 1;
//        tomorrow.year = today.year + 1;
//    }
//    else                               // end of month
//    {
//        tomorrow.day = 1;
//        tomorrow.month = today.month + 1;
//        tomorrow.year = today.year;
//    }
//
//    return tomorrow;
//}
//
//struct timeAndDate clockKeeper (struct timeAndDate td)
//{
//    if ((td.Time.hour == 23) && (td.Time.minutes == 59) && (td.Time.seconds == 59))
//        td.Date = dateUpdate(td.Date);
//
//    td.Time = timeUpdate(td.Time);
//
//    return td;
//}
//
//int main ()
//{
//    struct time tdtime = {.seconds = 59, .minutes = 59, .hour = 23};
//    struct date tddate = {.day = 31, .month = 12, .year = 2014};
//    struct timeAndDate td = {.Time = tdtime, .Date = tddate};
//
//    printf("Date before: %.2i/%.2i/%.2i || Time Before: %.2i:%.2i:%.2i.\n", td.Date.day, td.Date.month, td.Date.year, td.Time.hour, td.Time.minutes, td.Time.seconds);
//
//    td = clockKeeper(td);
//
//    printf("Date after: %.2i/%.2i/%.2i || Time after: %.2i:%.2i:%.2i.\n", td.Date.day, td.Date.month, td.Date.year, td.Time.hour, td.Time.minutes, td.Time.seconds);
//
//    return 0;
//}

/*********************************************************
    Exercise 6
        Replace the dateUpdate() function from Program 8.4 with the modified one that uses compound literals as presented in the text. Run the program to verify its proper operation.
*********************************************************/

// Program to determine tomorrow's date

//#include <stdio.h>
//#include <stdbool.h>
//
//struct  date
//{
//    int  month;
//    int  day;
//    int  year;
//};
//
//// Function to calculate tomorrow's date
//
//struct date  dateUpdate (struct date  today)
//{
//    struct date  tomorrow;
//    int  numberOfDays (struct date  d);
//
//    if ( today.day != numberOfDays (today) )
//    {
//        tomorrow = (struct date) {.day = today.day + 1, .month = today.month, .year = today.year};
//    }
//    else if ( today.month == 12 )      // end of year
//    {
//        tomorrow = (struct date) {.day = 1, .month = 1, .year = today.year + 1};
//    }
//    else                               // end of month
//    {
//        tomorrow = (struct date) {.day = 1, .month = today.month + 1, .year = today.year};
//    }
//
//    return tomorrow;
//}
//
//// Function to find the number of days in a month
//
//int  numberOfDays  (struct date  d)
//{
//    int  days;
//    bool isLeapYear (struct date  d);
//    const int  daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//    if ( isLeapYear (d)  &&  d.month == 2 )
//        days = 29;
//    else
//        days = daysPerMonth[d.month - 1];
//
//    return days;
//}
//
//// Function to determine if it's a leap year
//
//bool  isLeapYear (struct date  d)
//{
//    bool  leapYearFlag;
//
//    if ( (d.year % 4 == 0  &&  d.year % 100 != 0)  ||
//            d.year % 400 == 0 )
//        leapYearFlag = true;   // It's a leap year
//    else
//        leapYearFlag = false;  // Not a leap year
//
//    return leapYearFlag;
//}
//
//int main (void)
//{
//    struct date  dateUpdate (struct date  today);
//    struct date  thisDay, nextDay;
//
//    printf ("Enter today's date (mm dd yyyy): ");
//    scanf ("%i%i%i", &thisDay.month, &thisDay.day, &thisDay.year);
//
//    nextDay = dateUpdate (thisDay);
//    printf ("Tomorrow's date is %i/%i/%.2i.\n",nextDay.month, nextDay.day, nextDay.year % 100);
//
//    return 0;
//}
