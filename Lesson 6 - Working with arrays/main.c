/* NOTE: Select an exercise and use CTRL+MAYUS+C to comment it. Select an exercise and use CTRL+MAYUS+X to uncomment it. */

/*********************************************************
    Exercise 1
		Type in and run the eight programs presented in this chapter. Compare the output produced by each program with the output presented after each program in the text.
*********************************************************/

// The output is the same.

/*********************************************************
    Exercise 2
		Modify Program 6.1 so that the elements of the array values are initially set to 0. Use a for loop to perform the initialization.
*********************************************************/

//#include <stdio.h>
//
//int main (void)
//{
//     int  values[10];
//     int  index;
//
//     for (index = 0; index < 10; ++index)
//        values[index] = 0;
//
//     for ( index = 0;  index < 10;  ++index )
//          printf ("values[%i] = %i\n", index, values[index]);
//
//     return 0;
//}

/*********************************************************
    Exercise 3
		Program 6.2 permits only 20 responses to be entered. Modify that program so that any number of responses can be entered. So that the user does not have to count the number of responses in the list, set up the program so that the value 999 can be keyed in by the user to indicate that the last response has been entered. (Hint: You can use the break statement here if you want to exit your loop.)
*********************************************************/

//#include <stdio.h>
//
//int main (void)
//{
//    int  ratingCounters[11], i, response, num;
//
//    for ( i = 1;  i <= 10;  ++i )
//        ratingCounters[i] = 0;
//
//    printf ("Enter the number of responses: ");
//    scanf("%i", &num);
//    printf ("\nEnter your responses\n");
//
//    for ( i = 1;  i <= num;  ++i )
//    {
//        scanf ("%i", &response);
//
//        if (response == 999)
//        {
//            num = i - 1;
//            printf("Last response entered.\n");
//            break;
//        }
//        else if (response < 1 || response > 10)
//            printf ("Bad response: %i\n", response);
//        else
//            ++ratingCounters[response];
//    }
//
//    printf ("\n\nRating   Number of Responses\n");
//    printf ("------ -------------------\n");
//
//    for ( i = 1;  i <= num;  ++i )
//        printf ("%4i%14i\n", i, ratingCounters[i]);
//
//    return 0;
//}
