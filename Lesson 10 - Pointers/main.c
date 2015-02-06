/* NOTE: Select an exercise and use CTRL+MAYUS+C to comment it. Select an exercise and use CTRL+MAYUS+X to uncomment it. */

/*********************************************************
    Exercise 1
		Type in and run the 15 programs presented in this chapter. Compare the output produced by each program with the output presented after each program in the text.
*********************************************************/

// The output is the same.

/*********************************************************
    Exercise 2
		Write a function called insertEntry() to insert a new entry into a linked list. Have the procedure take as arguments a pointer to the list entry to be inserted (of type struct entry as defined in this chapter), and a pointer to an element in the list after which the new entry is to be inserted.
*********************************************************/

//#include <stdio.h>
//
//struct entry
//{
//    int value;
//    struct entry* next;
//};
//
//void insertEntry (struct entry* insEntry, struct entry* aftEntry)
//{
//    insEntry->next = aftEntry->next;
//    aftEntry->next = insEntry;
//}
//
//int main (void)
//{
//    struct entry n0, n1, n2;
//    struct entry n1_2;
//    struct entry* pointer = &n0;
//
//    n0 = (struct entry) {0, &n1};
//    n1 = (struct entry) {1, &n2};
//    n2 = (struct entry) {2, (struct entry*) 0};
//    n1_2 = (struct entry) {3, (struct entry*) 0};
//
//
//    printf("Before the insertion: \n");
//    while (pointer)
//    {
//        printf("Value in linked list entry: %i.\n", pointer->value);
//        pointer = pointer->next;
//    }
//    printf("\n");
//
//    insertEntry(&n1_2, &n2);
//    pointer = &n0;
//
//    printf("After the insertion: \n");
//    while (pointer)
//    {
//        printf("Value in linked list entry: %i.\n", pointer->value);
//        pointer = pointer->next;
//    }
//    printf("\n");
//
//    return 0;
//}

/*********************************************************
    Exercise 3
		The function developed in exercise 2 only inserts an element after an existing element in the list, thereby preventing you from inserting a new entry at the front of the list. How can you use this same function and yet overcome this problem? (Hint: Think about setting up a special structure to point to the beginning of the list.)
*********************************************************/

// The approach taken in this exercise was to set the first element of the linked list as a dummy element, the first important element on the list starts at index 1, so to speak.

//#include <stdio.h>
//
//struct entry
//{
//    int value;
//    struct entry* next;
//};
//
//void insertEntry (struct entry* insEntry, struct entry* aftEntry)
//{
//    insEntry->next = aftEntry->next;
//    aftEntry->next = insEntry;
//}
//
//int main (void)
//{
//    struct entry begin, n0, n1, n2;
//    struct entry n1_2;
//    struct entry* pointer;
//
//    begin = (struct entry) {0, &n0};
//    n0 = (struct entry) {1, &n1};
//    n1 = (struct entry) {2, &n2};
//    n2 = (struct entry) {3, (struct entry*) 0};
//    n1_2 = (struct entry) {4, (struct entry*) 0};
//
//    pointer = begin.next;
//
//    printf("Before the insertion: \n");
//    while (pointer)
//    {
//        printf("Value in linked list entry: %i.\n", pointer->value);
//        pointer = pointer->next;
//    }
//    printf("\n");
//
//    insertEntry(&n1_2, &begin);
//    pointer = begin.next;
//
//    printf("After the insertion: \n");
//    while (pointer)
//    {
//        printf("Value in linked list entry: %i.\n", pointer->value);
//        pointer = pointer->next;
//    }
//    printf("\n");
//
//    return 0;
//}

/*********************************************************
    Exercise 4
		Write a function called removeEntry() to remove an entry from a linked list. The sole argument to the procedure should be a pointer to the list. Have the function remove the entry after the one pointed to by the argument. (Why can’t you remove the entry pointed to by the argument?) You need to use the special structure you set up in exercise 3 to handle the special case of removing the first element from the list.
*********************************************************/

// The entry passed as argument can't be removed because you need to provide the precedent entry, which contains the pointer to the structure.

//#include <stdio.h>
//
//struct entry
//{
//    int value;
//    struct entry* next;
//};
//
//void removeEntry (struct entry* remEntry)
//{
//    remEntry->next = remEntry->next->next;
//}
//
//int main (void)
//{
//    struct entry begin, n0, n1, n2;
//    struct entry* pointer;
//
//    begin = (struct entry) {0, &n0};
//    n0 = (struct entry) {1, &n1};
//    n1 = (struct entry) {2, &n2};
//    n2 = (struct entry) {3, (struct entry*) 0};
//
//    pointer = begin.next;
//
//    printf("Before the removal: \n");
//    while (pointer)
//    {
//        printf("Value in linked list entry: %i.\n", pointer->value);
//        pointer = pointer->next;
//    }
//    printf("\n");
//
//    removeEntry(&n0);
//    pointer = begin.next;
//
//    printf("After the removal: \n");
//    while (pointer)
//    {
//        printf("Value in linked list entry: %i.\n", pointer->value);
//        pointer = pointer->next;
//    }
//    printf("\n");
//
//    return 0;
//}

/*********************************************************
    Exercise 5
		A doubly linked list is a list in which each entry contains a pointer to the preceding entry in the list as well as a pointer to the next entry in the list. Define the appropriate structure definition for a doubly linked list entry and then write a small program that implements a small doubly linked list and prints out the elements of the list.
*********************************************************/

//#include <stdio.h>
//
//struct entry
//{
//    struct entry* previous;
//    int value;
//    struct entry* next;
//};
//
//int main (void)
//{
//    struct entry n0, n1, n2;
//    struct entry* pointer;
//
//    n0 = (struct entry) {(struct entry*) 0, 1, &n1};
//    n1 = (struct entry) {&n0, 2, &n2};
//    n2 = (struct entry) {&n1, 3, (struct entry*) 0};
//
//    pointer = &n0;
//
//    printf("Normal sequence: \n");
//    while (pointer)
//    {
//        printf("Value in linked list entry: %i.\n", pointer->value);
//        pointer = pointer->next;
//    }
//    printf("\n");
//
//    pointer = &n2;
//
//    printf("Reverse sequence: \n");
//    while (pointer)
//    {
//        printf("Value in linked list entry: %i.\n", pointer->value);
//        pointer = pointer->previous;
//    }
//    printf("\n");
//
//    return 0;
//}

/*********************************************************
    Exercise 6
		Develop insertEntry() and removeEntry() functions for a doubly linked list that are similar in function to those developed in previous exercises for a singly linked list. Why can your removeEntry() function now take as its argument a direct pointer to the entry to be removed from the list?
*********************************************************/

// Now you can remove the entry passed as argument because the pointer to the previous element is passed along with the structure.

//#include <stdio.h>
//
//struct entry
//{
//    struct entry* previous;
//    int value;
//    struct entry* next;
//};
//
//void insertEntry (struct entry* insEntry, struct entry* aftEntry)
//{
//    insEntry->previous = aftEntry;
//    insEntry->next = aftEntry->next;
//    aftEntry->next->previous = insEntry;
//    aftEntry->next = insEntry;
//}
//
//void removeEntry (struct entry* remEntry)
//{
//    remEntry->next->previous = remEntry->previous;
//    remEntry->previous->next = remEntry->next;
//}
//
//int main (void)
//{
//    struct entry begin, n0, n1, n2;
//    struct entry n1_2;
//    struct entry* pointer;
//
//    begin = (struct entry) {(struct entry*) 0, 0, &n0};
//    n0 = (struct entry) {&begin, 1, &n1};
//    n1 = (struct entry) {&n0, 2, &n2};
//    n2 = (struct entry) {&n1, 3, (struct entry*) 0};
//
//    n1_2 = (struct entry) {(struct entry*) 0, 4, (struct entry*) 0};
//
//    pointer = begin.next;
//
//    printf("Normal: \n");
//    while (pointer)
//    {
//        printf("Value in linked list entry: %i.\n", pointer->value);
//        pointer = pointer->next;
//    }
//    printf("\n");
//
//    insertEntry(&n1_2, &begin);
//    pointer = begin.next;
//
//    printf("After add: \n");
//    while (pointer)
//    {
//        printf("Value in linked list entry: %i.\n", pointer->value);
//        pointer = pointer->next;
//    }
//    printf("\n");
//
//    removeEntry(&n1_2);
//    pointer = begin.next;
//
//    printf("Removed: \n");
//    while (pointer)
//    {
//        printf("Value in linked list entry: %i.\n", pointer->value);
//        pointer = pointer->next;
//    }
//    printf("\n");
//
//    return 0;
//}

/*********************************************************
    Exercise 7
		Write a pointer version of the sort() function from Chapter 7, “Working with Functions.” Be certain that pointers are exclusively used by the function, including index variables in the loops.
*********************************************************/

// Program to sort an array of integers into ascending order
//
//#include <stdio.h>
//
//void  sort (int* a, int* n)
//{
//    int i, *iPtr = &i;
//    int j, *jPtr = &j;
//    int temp, *tempPtr = &temp;
//
//    for ( *iPtr = 0;  *iPtr < *n - 1;  ++*iPtr )
//        for ( *jPtr = *iPtr + 1;  *jPtr < *n;  ++*jPtr )
//            if ( *(a + *iPtr) > *(a + *jPtr) )
//            {
//                *tempPtr = *(a + *iPtr);
//                *(a + *iPtr) = *(a + *jPtr);
//                *(a + *jPtr) = *tempPtr;
//            }
//}
//
//int main (void)
//{
//    int  i, n = 16;
//    int  array[16] = {34, -5, 6, 0, 12, 100, 56, 22, 44, -3, -9, 12, 17, 22, 6, 11};
//
//    printf ("The array before the sort:\n");
//    for ( i = 0;  i < 16;  ++i )
//        printf ("%i ", array[i]);
//
//    sort (array, &n);
//
//    printf ("\n\nThe array after the sort:\n");
//    for ( i = 0;  i < 16;  ++i )
//        printf ("%i ", array[i]);
//    printf ("\n");
//
//    return 0;
//}

/*********************************************************
    Exercise 8
		Write a function called sort3() to sort three integers into ascending order. (This function is not to be implemented with arrays.)
*********************************************************/

//#include <stdio.h>
//
//void sort3 (int* a)
//{
//    // Bubble method from before, limited to 3 chars. Could be done better but for the sake of simplicity the above method was used.
//    int i, *iPtr = &i;
//    int j, *jPtr = &j;
//    int temp, *tempPtr = &temp;
//
//    for ( *iPtr = 0;  *iPtr < 3 - 1;  ++*iPtr )
//        for ( *jPtr = *iPtr + 1;  *jPtr < 3;  ++*jPtr )
//            if ( *(a + *iPtr) > *(a + *jPtr) )
//            {
//                *tempPtr = *(a + *iPtr);
//                *(a + *iPtr) = *(a + *jPtr);
//                *(a + *jPtr) = *tempPtr;
//            }
//}
//
//int main (void)
//{
//    int array[] = {0, 2, -2};
//    int i = 0;
//
//    printf ("The array before the sort:\n");
//    for ( i = 0;  i < 3;  ++i )
//        printf ("%i ", array[i]);
//
//    sort3 (array);
//
//    printf ("\n\nThe array after the sort:\n");
//    for ( i = 0;  i < 3;  ++i )
//        printf ("%i ", array[i]);
//    printf ("\n");
//
//    return 0;
//}

/*********************************************************
    Exercise 9
		Rewrite the readLine() function from Chapter 9 so that it uses a character pointer rather than an array.
*********************************************************/

#include <stdio.h>

// Function to read a line of text from the terminal
//
//void  readLine (char* buffer)
//{
//    char  character;
//    int   i = 0;
//
//    do
//    {
//        character = getchar ();
//        *(buffer + i) = character;
//        ++i;
//    }  while ( character != '\n' );
//
//    *(buffer + i - 1) = '\0';
//}
//
//int main (void)
//{
//    int   i;
//    char  line[81];
//
//    printf("Key your line of text: \n");
//    for ( i = 0; i < 3; ++i )
//    {
//        readLine (line);
//        printf ("%s\n\n", line);
//    }
//
//    return 0;
//}

/*********************************************************
    Exercise 10
		Rewrite the compareStrings() function from Chapter 9 to use character pointers instead of arrays.
*********************************************************/

//#include <stdio.h>
//
//int  compareStrings (const char*  s1, const char*  s2)
//{
//    int  i = 0, answer;
//
//    while ( *(s1 + i) == *(s2 + i) && *(s1 + i) != '\0'&& *(s2 + i) != '\0' )
//        ++i;
//
//    if ( *(s1 + i) < *(s2 + i) )
//        answer = -1;               /* s1 < s2  */
//    else if ( *(s1 + i) == *(s2 + i) )
//        answer = 0;                 /* s1 == s2 */
//    else
//        answer = 1;                 /* s1 > s2  */
//
//    return answer;
//}
//
//int main (void)
//{
//    const char string1[] = "HOLA";
//    const char string2[] = "ADIOS";
//    const char string3[] = "HOLA";
//
//    printf("Result of comparing \"%s\" and \"%s\" is: %i.\n", string1, string2, compareStrings(string1, string2));
//    printf("Result of comparing \"%s\" and \"%s\" is: %i.\n", string1, string3, compareStrings(string1, string3));
//    printf("Result of comparing \"%s\" and \"%s\" is: %i.\n", string2, string3, compareStrings(string2, string3));
//
//    return 0;
//}

/*********************************************************
    Exercise 11
		Given the definition of a date structure as defined in this chapter, write a function called dateUpdate() that takes a pointer to a date structure as its argument and that updates the structure to the following day (see Program 8.4).
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
//void dateUpdate (struct date*  today)
//{
//    int  numberOfDays (struct date  d);
//
//    if ( today->day != numberOfDays (*today) )
//    {
//        today->day = today->day + 1;
//        today->month = today->month;
//        today->year = today->year;
//    }
//    else if ( today->month == 12 )        // end of year
//    {
//        today->day = 1;
//        today->month = 1;
//        today->year = today->year + 1;
//    }
//    else                                 // end of month
//    {
//        today->day = 1;
//        today->month = today->month + 1;
//        today->year = today->year;
//    }
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
//    if ( (d.year % 4 == 0  &&  d.year % 100 != 0)  || d.year % 400 == 0 )
//        leapYearFlag = true;   // It's a leap year
//    else
//        leapYearFlag = false;  // Not a leap year
//
//    return leapYearFlag;
//}
//
//int main (void)
//{
//    void  dateUpdate (struct date*  today);
//    struct date  Day;
//
//    printf ("Enter today's date (mm dd yyyy): ");
//    scanf ("%i%i%i", &Day.month, &Day.day, &Day.year);
//    dateUpdate (&Day);
//    printf ("Tomorrow's date is %i/%i/%.2i.\n", Day.month, Day.day, Day.year % 100);
//
//    return 0;
//}

/*********************************************************
    Exercise 12
		Given the following declarations:

            char  *message = "Programming in C is fun\n";
            char  message2[] = "You said it\n";
            char  *format  = "x = %i\n";
            int   x = 100;

        determine whether each printf() call from the following sets is valid and produces the same output as other calls from the set.

            // Set 1
            printf ("Programming in C is fun\n");
            printf ("%s", "Programming in C is fun\n");
            printf ("%s", message);
            printf (message);
            // Set 2
            printf ("You said it\n");
            printf ("%s", message2);
            printf (message2);
            printf ("%s", &message2[0]);
            // Set 3
            printf ("said it\n");
            printf (message2 + 4);
            printf ("%s", message2 + 4);
            printf ("%s", &message2[4]);
            // Set 4
            printf ("x = %i\n", x);
            printf (format, x);
*********************************************************/

//#include <stdio.h>
//
//int main (void)
//{
//    char  *message = "Programming in C is fun\n";
//    char  message2[] = "You said it\n";
//    char  *format  = "x = %i\n";
//    int   x = 100;
//
//    // Set 1
//    printf("\n\n SET 1\n");
//    printf ("Programming in C is fun\n");
//    printf ("%s", "Programming in C is fun\n");
//    printf ("%s", message);
//    printf (message);
//    // Set 2
//    printf("\n\n SET 2\n");
//    printf ("You said it\n");
//    printf ("%s", message2);
//    printf (message2);
//    printf ("%s", &message2[0]);
//    // Set 3
//    printf("\n\n SET 3\n");
//    printf ("said it\n");
//    printf (message2 + 4);
//    printf ("%s", message2 + 4);
//    printf ("%s", &message2[4]);
//    // Set 4
//    printf("\n\n SET 4\n");
//    printf ("x = %i\n", x);
//    printf (format, x);
//
//    return 0;
//}
//

