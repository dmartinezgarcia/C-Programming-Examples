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

/*********************************************************
    Exercise 4
        Write a program that calculates the average of an array of 10 floating-point values.
*********************************************************/

//#include <stdio.h>
//
//int main()
//{
//    float vals[10] = {0, 0, 0}, sum = 0.0F;
//    int index = 0;
//
//
//    for (index = 0; index < 10; index++)
//    {
//        printf("\nIntroduce a number (%2i/10): ", index + 1);
//        scanf("%f", &vals[index]);
//        printf("Number introduced: %.3f\n", vals[index]);
//        sum += vals[index];
//    }
//
//    printf("\n\nThe average of the numbers introduced is: %.3f.\n", sum / 10.0F);
//
//    return 0;
//}

/*********************************************************
    Exercise 5
        What output do you expect from the following program?
*********************************************************/

// The output is: 1 1 2 4 8 16 32 64 128 256

//#include <stdio.h>
//
//int main (void)
//{
//    int numbers[10] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//    int  i, j;
//
//    for ( j = 0;  j < 10;  ++j )
//        for ( i = 0;  i < j;  ++i )
//            numbers[j]  +=  numbers[i];
//
//    for ( j = 0;  j < 10;  ++j )
//        printf ("%i ", numbers[j]);
//
//    printf ("\n");
//    return 0;
//}

/*********************************************************
    Exercise 6
        You don’t need to use an array to generate Fibonacci numbers. You can simply use three variables: two to store the previous two Fibonacci numbers and one to store the current one. Rewrite Program 6.3 so that arrays are not used. Because you’re no longer using an array, you need to display each Fibonacci number as you generate it.
*********************************************************/

//#include <stdio.h>
//
//int main (void)
//{
//    int  F_0, F_1, F_2, i;
//
//    printf("This program will generate the first 15 Fibonacci numbers.\n");
//    F_0 = 0;    // by definition
//    F_1 = 1;    // ditto
//
//    for ( i = 2;  i < 15;  ++i )
//    {
//        F_2 = F_0 + F_1;
//        printf("%i ", F_2);
//        F_0 = F_1;
//        F_1 = F_2;
//    }
//
//    printf("\n");
//
//    return 0;
//}

/*********************************************************
    Exercise 7
        Prime numbers can also be generated by an algorithm known as the Sieve of Eratosthenes. The algorithm for this procedure is presented here. Write a program that implements this algorithm. Have the program find all prime numbers up to n = 150. What can you say about this algorithm as compared to the ones used in the text for calculating prime numbers?
        Sieve of Eratosthenes Algorithm
        To Display All Prime Numbers Between 1 and n
            Step 1: Define an array of integers P. Set all elements Pi to 0, 2 <= i <= n.
            Step 2: Set i to 2.
            Step 3: If i > n, the algorithm terminates.
            Step 4: If Pi is 0, then i is prime.
            Step 5: For all positive integer values of j, such that i x j ≤ n, set Pixj to 1.
            Step 6: Add 1 to i and go to step 3.
*********************************************************/

//#include <stdio.h>
//
//int main()
//{
//    int P[151] = {0}, i = 2, j = 1, m = 0;
//
//    for (i = 2; !(i > 150); i++)
//    {
//        if (!(P[i]))
//            printf("Number %i is prime.\n", i);
//
//        while ((m = i * j) <= 150)
//        {
//            P[m] = 1;
//            j++;
//        }
//        j = 1;
//    }
//}

/*********************************************************
    Exercise 8
        Find out if your compiler supports variable-length arrays. If it does, write a small program to test the feature out.
*********************************************************/

//int main()
//{
//    int x = 5;
//    int y[x+1];
//}
