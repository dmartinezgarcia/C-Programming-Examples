/* NOTE: Select an exercise and use CTRL+MAYUS+C to comment it. Select an exercise and use CTRL+MAYUS+X to uncomment it. */

/*********************************************************
    Exercise 1
		Type in and run the 15 programs presented in this chapter. Compare the output produced by each program with the output presented after each program in the text.
*********************************************************/

/*********************************************************
    Exercise 2
		Write a function called insertEntry() to insert a new entry into a linked list. Have the procedure take as arguments a pointer to the list entry to be inserted (of type struct entry as defined in this chapter), and a pointer to an element in the list after which the new entry is to be inserted.
*********************************************************/

/*********************************************************
    Exercise 3
		The function developed in exercise 2 only inserts an element after an existing element in the list, thereby preventing you from inserting a new entry at the front of the list. How can you use this same function and yet overcome this problem? (Hint: Think about setting up a special structure to point to the beginning of the list.)
*********************************************************/

/*********************************************************
    Exercise 4
		Write a function called removeEntry() to remove an entry from a linked list. The sole argument to the procedure should be a pointer to the list. Have the function remove the entry after the one pointed to by the argument. (Why can’t you remove the entry pointed to by the argument?) You need to use the special structure you set up in exercise 3 to handle the special case of removing the first element from the list.
*********************************************************/

/*********************************************************
    Exercise 5
		A doubly linked list is a list in which each entry contains a pointer to the preceding entry in the list as well as a pointer to the next entry in the list. Define the appropriate structure definition for a doubly linked list entry and then write a small program that implements a small doubly linked list and prints out the elements of the list.
*********************************************************/

/*********************************************************
    Exercise 6
		Develop insertEntry() and removeEntry() functions for a doubly linked list that are similar in function to those developed in previous exercises for a singly linked list. Why can your removeEntry() function now take as its argument a direct pointer to the entry to be removed from the list?
*********************************************************/

/*********************************************************
    Exercise 7
		Write a pointer version of the sort() function from Chapter 7, “Working with Functions.” Be certain that pointers are exclusively used by the function, including index variables in the loops.
*********************************************************/

/*********************************************************
    Exercise 8
		Write a function called sort3() to sort three integers into ascending order. (This function is not to be implemented with arrays.)
*********************************************************/

/*********************************************************
    Exercise 9
		Rewrite the readLine() function from Chapter 9 so that it uses a character pointer rather than an array.
*********************************************************/

/*********************************************************
    Exercise 10
		Rewrite the compareStrings() function from Chapter 9 to use character pointers instead of arrays.
*********************************************************/

/*********************************************************
    Exercise 11
		Given the definition of a date structure as defined in this chapter, write a function called dateUpdate() that takes a pointer to a date structure as its argument and that updates the structure to the following day (see Program 8.4).
*********************************************************/

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


